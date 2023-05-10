#include <catch2/catch_template_test_macros.hpp>
#include "account.hpp"
#include <memory>
#include <cstdint>

TEMPLATE_TEST_CASE("Account Class", "Accounts", Account) {
    TestType account{};

    SECTION("that has an Id Property")
    {
        const std::size_t val = account.Id();

        SECTION("that is initially zero")
        {
            REQUIRE(0 == val);

            SECTION("and that can be set")
            {
                const int newval = 5;
                account.Id(newval);

                REQUIRE(newval == account.Id());
            }
        }
    }

    SECTION("has name property")
    {
        const auto account_name = account.Name();

        SECTION("that is initially empty")
        {
            REQUIRE(account_name.empty());

            SECTION("and that can be set to a differant value")
            {
                const auto *new_account_name = "new name";
                account.Name(new_account_name);
                REQUIRE(new_account_name == account.Name());
            }
        }
    }

    SECTION("Has a Collection of Debit Transaction Relational Properties")
    {
        const std::vector<std::weak_ptr<Transaction>> &account_debit_transactions = account.Debits();

        SECTION("That is initially empty")
        {
            REQUIRE(account_debit_transactions.empty());
        }
    }

    SECTION("Has a Collection of Credit Transaction Relational Properties")
    {
        const std::vector<std::weak_ptr<Transaction>> &account_credit_transactions = account.Credits();

        SECTION("That is initially empty")
        {
            REQUIRE(account_credit_transactions.empty());
        }
    }
}
