#include "businessentity.hpp"
#include "sourcedocument.hpp"
#include "transaction.hpp"
#include "account.hpp"
#include <catch2/catch_template_test_macros.hpp>
#include <repository.hpp>
#include <vector>

TEMPLATE_TEST_CASE("Repository Class", "Entity Types", Account, BusinessEntity, SourceDocument, Transaction) {
  const Repository<TestType> repository{};

  SECTION("That Has A Gets All the entities store in the Database Collection") {
    const auto all_entities = repository.GetAll();
  }
}
