#define CATCH_CONFIG_MAIN
#include "catch2/single_include/catch2/catch.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

#include "liblettercase/ExceptionWords.h"
#include "liblettercase/helper_functions.h"

std::string to_titlecase(const std::string& text, const ExceptionWords& wordList, bool keep_abbreviations) {
    auto splitted_text = lettercase::detail::split(text, ' ');
    auto& words_kept_in_lowercase = wordList.wordsToBeLeftInLowerCase;
    for (std::string& str: splitted_text) {
        if (keep_abbreviations) {
            auto is_any_lowercased = std::any_of(str.begin(), str.end(),
                 [](unsigned char c) {
                    return std::islower(c);
                 });
            if (!is_any_lowercased) {
                continue;
            }
        }
        if (std::find(words_kept_in_lowercase.begin(), words_kept_in_lowercase.end(), str) != words_kept_in_lowercase.end())  {
            continue;
        } else {
            std::transform(str.begin(), str.end(), str.begin(),
                           [](unsigned char c) {
                               return std::tolower(c);
                           });
            str[0] = std::toupper(str[0]);
        }
    }
    return lettercase::detail::construct_string_from_vector(splitted_text);
}

TEST_CASE("A string is converted to Title Case", "[title-case]") {
    std::string text = "The point is to get more experience with ranges and the STL.";
    auto wordList = ExceptionWords();

    std::string titlecased_text = to_titlecase(text, wordList, false);
    REQUIRE(titlecased_text == "The Point Is to Get More Experience With Ranges and the Stl.");
}