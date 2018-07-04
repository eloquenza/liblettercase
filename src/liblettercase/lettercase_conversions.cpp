#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

#include "liblettercase/lettercase_conversions.h"
#include "liblettercase/ExceptionWords.h"
#include "liblettercase/helper_functions.h"

std::string lettercase::to_titlecase(const std::string& text, const ExceptionWords& wordList, bool keep_abbreviations) {
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