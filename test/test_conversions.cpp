#include "catch2/single_include/catch2/catch.hpp"
#include "liblettercase/ExceptionWords.h"
#include "liblettercase/lettercase_conversions.h"

TEST_CASE("A string is converted to ...", "[lettercase, lettercase-conversions]") {
    using namespace lettercase;
    std::string text = "The point is to get more experience with ranges and the STL.";

    SECTION("... Title Case ...") {
        auto wordList = ExceptionWords();

        SECTION("... keeping abbreviations intact.") {

            REQUIRE(to_titlecase(text, wordList, true) ==
                    "The Point Is to Get More Experience With Ranges and the STL.");
        }
        SECTION("... changing abbreviations.") {

            REQUIRE(to_titlecase(text, wordList, false) ==
                    "The Point Is to Get More Experience With Ranges and the Stl.");
        }
    }
    SECTION("... UPPER CASE.") {
        REQUIRE(to_uppercase(text) == "THE POINT IS TO GET MORE EXPERIENCE WITH RANGES AND THE STL.");
    }
    SECTION("... lower case.") {
        REQUIRE(to_lowercase(text) == "the point is to get more experience with ranges and the stl.");
    }
    SECTION("... snake_case.") {
        REQUIRE(to_snake_case(text) == "The_point_is_to_get_more_experience_with_ranges_and_the_STL");
    }
    SECTION("... CamelCase.") {
        REQUIRE(to_camelcase(text) == "ThePointIsToGetMoreExperienceWithRangesAndTheSTL.");
    }
}