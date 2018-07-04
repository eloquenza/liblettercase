#define CATCH_CONFIG_MAIN
#include "catch2/single_include/catch2/catch.hpp"

#include "liblettercase/ExceptionWords.h"
#include "liblettercase/lettercase_conversions.h"

TEST_CASE("A string is converted to Title Case", "[title-case]") {
    using namespace lettercase;
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    std::string titlecased_text = to_titlecase(text, wordList, false);
    REQUIRE(titlecased_text == "The Point Is to Get More Experience With Ranges and the Stl.");
}