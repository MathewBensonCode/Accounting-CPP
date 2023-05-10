#include <catch2/catch_test_macros.hpp>
#include "sourcedocument.hpp"
#include "transaction.hpp"
#include "account.hpp"
#include <memory>

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
                const uint newval{ 5 };
                transaction.Id(newval);

                REQUIRE(newval == transaction.Id());
            }
        }
    }

    SECTION("That has an Double Amount Property")
    {
        const double val = transaction.Amount();

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
        const std::shared_ptr<Account> &value = transaction.DebitAccount();

        SECTION("That is initially null")
        {
            REQUIRE(value == nullptr);
        }

        SECTION("And can be set")
        {
            auto newptr = std::make_shared<Account>();
            transaction.DebitAccount(newptr);

            REQUIRE(newptr == value);
        }
    }

    SECTION("That has a Credit Account Property")
    {
        const std::shared_ptr<Account> &value = transaction.CreditAccount();

        SECTION("That is initially null")
        {
            REQUIRE(value == nullptr);
        }

        SECTION("And can be set")
        {
            auto newptr = std::make_shared<Account>();
            transaction.CreditAccount(newptr);

            REQUIRE(newptr == value);
        }
    }

    SECTION("Credit and Debit Accounts Should Be Separate Values")
    {
        auto new_debitaccount = std::make_shared<Account>();
        auto new_creditaccount = std::make_shared<Account>();

        SECTION("When Debit is set")
        {
            transaction.DebitAccount(new_debitaccount);
            REQUIRE(transaction.DebitAccount() != transaction.CreditAccount());
        }

        SECTION("When Credit is set")
        {
            transaction.CreditAccount(new_creditaccount);
            REQUIRE(transaction.DebitAccount() != transaction.CreditAccount());
        }
    }

    SECTION("Should Have a SourceDocument Property")
    {
        const std::shared_ptr<SourceDocument> &sourcedocument = transaction.Sourcedocument();

        SECTION("That is initially Null")
        {
            REQUIRE(nullptr == sourcedocument);
        }
    }
}
