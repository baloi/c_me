#include "catch.hpp"
#define CATCH_CONFIG_PATH  // tells catch to provide main (only in one file)


unsigned int Factorial( unsigned int number ) {

}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE( Factorial(1) == 1);
}
