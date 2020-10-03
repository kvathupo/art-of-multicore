#include "catch.hpp"
#include <vector>
#include <string>
#include "Table.h"

TEST_CASE("Chopsticks work properly", "[Table][Non-thread]") {
    std::vector<std::string> names {"Brandon",
                        "Jimmy",
                        "Mark",
                        "Alex"};
    Table meal(names);

    SECTION("Can't eat without spoons") {
        meal.eat("Jimmy");
        meal.eat("Brandon");
        meal.eat("Mark");
        
        REQUIRE( meal.get("Jimmy")->left->owner == "Jimmy" );
        REQUIRE( meal.get("Jimmy")->right->owner == "Jimmy" );
        REQUIRE( meal.get("Brandon")->right->owner == "Jimmy" );
        REQUIRE( meal.get("Brandon")->left->owner == "Brandon" );
        REQUIRE( meal.get("Mark")->left->owner == "Jimmy" );
        REQUIRE( meal.get("Mark")->right->owner == "Mark" );


        meal.think("Jimmy");
        meal.think("Jimmy");
        meal.eat("Brandon");
        meal.eat("Mark");
        meal.think("Brandon");
        meal.think("Mark");
    }
}
