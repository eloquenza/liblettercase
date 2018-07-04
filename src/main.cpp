#define CATCH_CONFIG_MAIN
#include "catch2/single_include/catch2/catch.hpp"

#include "liblettercase/ExceptionWords.h"
#include "liblettercase/lettercase_conversions.h"

TEST_CASE("A string is converted to ...", "[lettercase, lettercase-conversions]") {
    using namespace lettercase;
    std::string text = "The point is to get more experience with ranges and the STL.";

    SECTION("... Title Case ...") {
        auto wordList = ExceptionWords();

        SECTION("... keeping abbreviations intact.") {

            REQUIRE(to_titlecase(text, wordList, true) == "The Point Is to Get More Experience With Ranges and the STL.");
        }
        SECTION("... changing abbreviations.") {

            REQUIRE(to_titlecase(text, wordList, false) == "The Point Is to Get More Experience With Ranges and the Stl.");
        }
    }
    SECTION("... UPPER CASE.") {
        REQUIRE(to_uppercase(text) == "THE POINT IS TO GET MORE EXPERIENCE WITH RANGES AND THE STL.");
    }
    SECTION("... lower case.") {
        REQUIRE(to_lowercase(text) == "the point is to get more experience with ranges and the stl.");
    }
}