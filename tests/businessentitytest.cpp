#include <catch2/catch.hpp>
#include "businessentity.hpp"

TEST_CASE("Has Business Entity Class")
{
    BusinessEntity businessentity{};

    SECTION("That has an Id Property")
    {

        SECTION("That has an initial zero value")
        {
            REQUIRE(0 == businessentity.Id());

            SECTION("And can be set")
            {
                const uint newval{ 5 };
                businessentity.Id(newval);

                REQUIRE(newval == businessentity.Id());
            }
        }
    }
    
    SECTION("That has a Name Property")
    {
        const std::string_view business_entity_name = businessentity.Name();

        SECTION("That has an initial blank string value")
        {
            REQUIRE(business_entity_name.empty());

            SECTION("And that can be set")
            {
                const std::string new_business_entity_name{"new name"};

                businessentity.Name(new_business_entity_name);

                REQUIRE(new_business_entity_name == businessentity.Name());
            }
        }
    }

    SECTION("Should Have A Collection of SourceDocuments Related Property")
    {
        const std::vector<std::weak_ptr<SourceDocument>> &sourcedocuments = businessentity.SourceDocuments();

        SECTION("That is initially empty"){
            REQUIRE(sourcedocuments.empty());
        }
    }
}
