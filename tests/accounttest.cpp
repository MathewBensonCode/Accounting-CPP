#include <catch2/catch.hpp>
#include "account.hpp"
#include <memory>

TEST_CASE("Account Class")
{
    Account account{};

    SECTION("has name property")
    {
        const auto val = account.name();

        SECTION("that is initially empty")
        {
            REQUIRE("" == val);
        }

        SECTION("that can be set to a differant value")
        {
            const auto *val = "new name";
            account.name(val);
            REQUIRE(val == account.name());
        }

        SECTION("that can be initiated with a value")
        {
            const auto *val = "initial value";
            Account account2{ val };
            REQUIRE(val == account2.name());
        }
    }

    SECTION("has Amount property")
    {
        auto initialamount{ 0.0F };
        const auto amount = account.amount();

        SECTION("with initial value of 0.0")
        {
            REQUIRE(initialamount == amount);
        }

        SECTION("that Can be modified")
        {
            const auto newamount { 12.0F };
            account.amount(newamount);
            REQUIRE(newamount == account.amount());
        }
    }

    SECTION("Has a Collection of Debit Transaction Relational Properties")
    {
        const std::vector<std::shared_ptr<Transaction>>& collection = account.Debits();

        SECTION("That is initially empty")
            REQUIRE(0 == account.Debits().size());
    }

    SECTION("Has a Collection of Credit Transaction Relational Properties")
    {
        const std::vector<std::shared_ptr<Transaction>>& collection = account.Credits();

        SECTION("That is initially empty")
            REQUIRE(0 == account.Credits().size());

    }

}