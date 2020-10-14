#include <vector>
#include <string>
#include <type_traits>
#include "Table.h"
#include "catch.hpp"

TEST_CASE("Table traits", "[Table][Non-thread]") {
    REQUIRE( std::is_trivially_copy_constructible<Table>::value == true );
    
}
