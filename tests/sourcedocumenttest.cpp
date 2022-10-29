#include <chrono>
#include <vector>
#include <catch2/catch.hpp>
#include "sourcedocument.hpp"
#include "transaction.hpp"
#include "businessentity.hpp"

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

    SECTION("That Has a Property with a Collection of Transaction Relational Properties")
    {
        const std::vector<std::shared_ptr<Transaction>> &collection = sourcedocument.Transactions();

        SECTION("That is initially empty")
        {
            REQUIRE(collection.empty());

            SECTION("And can be set")
            {
                std::vector<std::shared_ptr<Transaction>> newcollection{std::make_shared<Transaction>(), std::make_shared<Transaction>()};
                sourcedocument.Transactions(newcollection);
            }
        }

    }

    SECTION("That has a property of Business Entity")
    {
        const std::weak_ptr<BusinessEntity> &businessentity = sourcedocument.Business_Entity();

        SECTION("That is initially null")
        {
            REQUIRE(businessentity.lock().get() == nullptr);

            SECTION("And can be set")
            {
                std::shared_ptr<BusinessEntity> newentity = std::make_shared<BusinessEntity>();
                sourcedocument.Business_Entity(newentity);

                REQUIRE(businessentity.lock().get() == newentity.get());
            }
       }
        
    }
}
