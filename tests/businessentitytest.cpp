#include <catch2/catch.hpp>
#include "businessentity.hpp"


TEST_CASE("Has Business Entity Class")
{
    BusinessEntity businessentity{};

    SECTION("That has an Id Property")
    {
        uint val = businessentity.Id();

        SECTION("That has an initial zero value")
        {
            REQUIRE(0 == val);

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
        const std::string& name = businessentity.Name();

        SECTION("That has an initial blank string value")
        {
            REQUIRE(name.empty());

            SECTION("And that can be set")
            {
                const std::string newname{"new name"};

                businessentity.Name(newname);

                REQUIRE(newname == businessentity.Name());
            }
        }
    }
}
