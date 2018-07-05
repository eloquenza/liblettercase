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

namespace lettercase {
    std::string to_titlecase(const std::string& text, const ExceptionWords& wordList, bool keep_abbreviations) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (std::string& str: splitted_text) {
            if (keep_abbreviations) {
                if (!contains_any_lowercase(str)) {
                    continue;
                }
            }
            if (is_in_exceptionlist(wordList, str))  {
                continue;
            } else {
                std::transform(str.begin(), str.end(), str.begin(),
                               [](unsigned char c) {
                                   return std::tolower(c);
                               });
                str[0] = std::toupper(str[0]);
            }
        }
        return construct_string_from_vector(splitted_text);
    }

    std::string to_lowercase(const std::string& text) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (std::string& str: splitted_text) {
            std::transform(str.begin(), str.end(), str.begin(),
                           [](unsigned char c) {
                               return std::tolower(c);
                           });
        }
        return construct_string_from_vector(splitted_text);
    }

    std::string to_uppercase(const std::string& text) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (std::string& str: splitted_text) {
            std::transform(str.begin(), str.end(), str.begin(),
                           [](unsigned char c) {
                               return std::toupper(c);
                           });
        }
        return construct_string_from_vector(splitted_text);
    }

    std::string to_snake_case(const std::string& text) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (std::string& str: splitted_text) {
            str.erase(
                    std::remove_if(str.begin(), str.end(), [](unsigned char c) {
                        return std::ispunct(c);
                    }),
                    str.end()
            );
        }

        return construct_string_from_vector(splitted_text, "_");
    }

    std::string to_camelcase(const std::string& text) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (std::string& str: splitted_text) {
            str[0] = std::toupper(str[0]);
        }

        return construct_string_from_vector(splitted_text, "");
    }

    std::string to_startcase(const std::string& text) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (std::string& str: splitted_text) {
            str[0] = std::toupper(str[0]);
        }

        return construct_string_from_vector(splitted_text);
    }
}
