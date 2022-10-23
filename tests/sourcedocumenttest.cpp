#include <chrono>
#include <catch2/catch.hpp>
#include "sourcedocument.hpp"

TEST_CASE("Has Source Document Class")
{
    SourceDocument sourcedocument{};

    SECTION("That has an Id Property")
    {
        uint val = sourcedocument.Id();

        SECTION("That has an initial zero value")
        {
            REQUIRE(0 == val);

            SECTION("And can be set")
            {
                const uint newval{ 5 };
                sourcedocument.Id(newval);

                REQUIRE(newval == sourcedocument.Id());
            }
        }
    }

    SECTION("That has a Date Property")
    {
        const timepoint val = sourcedocument.Date();

        SECTION("That has an initial value of epoch 0")
        {
            REQUIRE(timepoint().time_since_epoch() == val.time_since_epoch());

            SECTION("And That Can be Set")
            {
                const timepoint newval = val + (std::chrono::seconds(5000));
                sourcedocument.Date(newval);

                REQUIRE(newval.time_since_epoch() == sourcedocument.Date().time_since_epoch());
            }
        }
    }

    SECTION("Has a Collection of Debit Transaction Relational Properties")
    {
        const std::vector<std::shared_ptr<Transaction>> &collection = sourcedocument.Transactions();

        SECTION("That is initially empty")
        {
            REQUIRE(sourcedocument.Transactions().empty());
        }
    }
}
