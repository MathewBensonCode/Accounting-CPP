#include <catch2/catch.hpp>
#include "transaction.hpp"
#include "account.hpp"
#include "memory"

TEST_CASE("Has Transaction Class")
{
    Transaction transaction{};

    SECTION("That has an Id Property")
    {
        uint val = transaction.Id();

        SECTION("That has an initial zero value")
        {
            REQUIRE(0 == val);

            SECTION("And can be set")
            {
                const uint newval{5};
                transaction.Id(newval);

                REQUIRE(newval == transaction.Id());
            }
        }
    }

    SECTION("That has an Double Amount Property")
    {
        double val = transaction.Amount();

        SECTION("That is initially zero")
        {
            REQUIRE(0.0 == val);
        }

        SECTION("And That Can Be Set")
        {
            const double newval{ 10.02 };
            transaction.Amount(newval);

            REQUIRE(newval == transaction.Amount());
        }
    }

    SECTION("That has a Debit Account Property")
    {
        std::shared_ptr<Account> value = transaction.DebitAccount();

        SECTION("That is initially null")
        {
            REQUIRE(nullptr == value);
        }

        SECTION("And can be set")
        {
            auto newptr = std::make_shared<Account>();  
            transaction.DebitAccount(newptr);

            REQUIRE(newptr == transaction.DebitAccount());
        }
    }

    SECTION("That has a Credit Account Property")
    {
        std::shared_ptr<Account> value = transaction.CreditAccount();

        SECTION("That is initially null")
        {
            REQUIRE(nullptr == value);
        }

        SECTION("And can be set")
        {
            auto newptr = std::make_shared<Account>();  
            transaction.CreditAccount(newptr);

            REQUIRE(newptr == transaction.CreditAccount());
        }
    }
}
