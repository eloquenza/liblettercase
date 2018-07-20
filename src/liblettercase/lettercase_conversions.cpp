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

    void to_titlecase_inplace(std::string& text, const ExceptionWords& wordList, bool keep_abbreviations) {
        using namespace lettercase::detail;
        text[0] = std::toupper(text[0]);
        auto wordStart = 0;
        auto wordEnd = 0;
        for (auto i = 1; i < text.length(); i++) {
            if (std::isspace(text[i]) || i == text.length() - 1) {
                wordEnd = (i == text.length() - 1) ? i : i - 1;
                auto word = std::string(text, wordStart, wordEnd - wordStart + 1);

                if (keep_abbreviations) {
                    if (!contains_any_lowercase(word)) {
                        wordStart = i + 1;
                        continue;
                    }
                }

                if (!is_in_exceptionlist(word, wordList)) {
                    for (auto j = wordStart; j < wordEnd; j++) {
                        text[j] = std::tolower(text[j]);
                    }
                    text[wordStart] = std::toupper(text[wordStart]);
                }
                wordStart = i + 1;
            }
        }
    }

    void to_lowercase_inplace(std::string& text) {
        std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
    }

    void to_uppercase_inplace(std::string& text) {
        std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
    }

    void to_snake_case_inplace(std::string& text) {
        text.erase(
                std::remove_if(text.begin(), text.end(), [](unsigned char c) {
                    return std::ispunct(c);
                }),
                text.end()
        );
        std::transform(text.begin(), text.end(), text.begin(), [](char c) {
            if (std::isblank(c)) {
                return '_';
            }
            return c;
        });
    }

    void to_camelcase_inplace(std::string& text) {
        text[0] = std::toupper(text[0]);
        char last_char = text[0];
        for (int i = 1; i < text.length(); i++) {
            if (std::isspace(last_char)) {
                text[i] = std::toupper(text[i]);
            }
            last_char = text[i];
        }

        text.erase(std::remove_if(text.begin(), text.end(), [](unsigned char c) {
            return std::isspace(c);
        }), text.end());
    }

    void to_startcase_inplace(std::string& text) {
        text[0] = std::toupper(text[0]);
        char last_char = text[0];
        for (int i = 1; i < text.length(); i++) {
            if (std::isspace(last_char)) {
                text[i] = std::toupper(text[i]);
            }
            last_char = text[i];
        }
    }
}
