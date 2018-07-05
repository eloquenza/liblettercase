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
    using detail::conversion_loop;

    std::string to_titlecase(const std::string& text, const ExceptionWords& wordList, bool keep_abbreviations) {
        auto body = [&wordList, &keep_abbreviations](std::string& str) {
            using namespace lettercase::detail;
            if (keep_abbreviations) {
                if (!contains_any_lowercase(str)) {
                    return;
                }
            }
            if (is_in_exceptionlist(str, wordList))  {
                return;
            } else {
                std::transform(str.begin(), str.end(), str.begin(),
                               [](unsigned char c) {
                                   return std::tolower(c);
                               });
                str[0] = std::toupper(str[0]);
            }
        };

        return conversion_loop(text, body);
    }

    std::string to_lowercase(const std::string& text) {
        auto body = [](std::string& str) {
            std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
                return std::tolower(c);
            });
        };

        return conversion_loop(text, body);
    }

    std::string to_uppercase(const std::string& text) {
        auto body = [](std::string& str) {
            std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
                return std::toupper(c);
            });
        };

        return conversion_loop(text, body);
    }

    std::string to_snake_case(const std::string& text) {
        auto body = [](std::string& str) {
            str.erase(
                    std::remove_if(str.begin(), str.end(), [](unsigned char c) {
                        return std::ispunct(c);
                    }),
                    str.end()
            );
        };

        return conversion_loop(text, body, "_");
    }

    std::string to_camelcase(const std::string& text) {
        auto body = [](std::string& str) {
            str[0] = std::toupper(str[0]);
        };

        return conversion_loop(text, body, "");
    }

    std::string to_startcase(const std::string& text) {
        auto body = [](std::string& str) {
            str[0] = std::toupper(str[0]);
        };

        return conversion_loop(text, body);
    }
}
