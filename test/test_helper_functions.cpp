#include <string>

#include "catch2/catch.hpp"

#include "liblettercase/ExceptionWords.h"
#include "liblettercase/helper_functions.h"

using namespace lettercase;
using namespace lettercase::detail;

TEST_CASE("A string contains any lowercase character", "[helper-functions, contains-any-lowercase, string]") {
    std::string str = "Lowercase";

    REQUIRE(contains_any_lowercase(str) == true);

    SECTION("A string does not contain any lowercase character") {
        std::string upper_str = "LOWERCASE";

        REQUIRE(contains_any_lowercase(upper_str) == false);
    }

    SECTION("Punctuation should not be counted, therefore it should not contain any lowercase char.") {
        std::string punctuation = ",.:;><?/|\\&^%$#@!*()-_=+";

        REQUIRE(contains_any_lowercase(punctuation) == false);
    }
}

TEST_CASE("A concatenated string is created from a vector<string>", "[construct-string-from-vector]") {
    const std::vector<std::string> vec = {
            "This", "is", "a", "complete", "sentence."
    };

    REQUIRE(construct_string_from_vector(vec) == "This is a complete sentence.");

    SECTION("A string can be concatenated with a different delimiter than space") {
        REQUIRE(construct_string_from_vector(vec, "_") == "This_is_a_complete_sentence.");
    }
}

TEST_CASE("A string can be splitted into a vector of strings", "[split]") {
    std::string str = "This is a complete sentence.";
    std::vector<std::string> comparison_vec = {
            "This", "is", "a", "complete", "sentence."
    };

    REQUIRE(split(str, " ") == comparison_vec);

    SECTION("A string can be split with a different delimiter than space") {
        std::string str2 = "This_is_a_complete_sentence.";
        std::vector<std::string> comparison_vec = {
                "This", "is", "a", "complete", "sentence."
        };
        REQUIRE(split(str2, "_") == comparison_vec);
    }
}

TEST_CASE("A word can be found in the exception list", "[exception-list]") {
    auto ew = ExceptionWords();
    auto exceptionList = ew.wordList;
    std::string word = "and";

    REQUIRE(std::find(exceptionList.begin(), exceptionList.end(), word) != exceptionList.end());

    SECTION("A word can NOT be found in the exception list") {
        word = "cannot-be-found";

        REQUIRE(std::find(exceptionList.begin(), exceptionList.end(), word) == exceptionList.end());
    }
}

//
//TEST_CASE("", "") {
//    SECTION("") {
//
//    }
//}