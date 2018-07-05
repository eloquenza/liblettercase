#ifndef LIBLETTERCASE_LETTERCASE_CONVERSIONS_H
#define LIBLETTERCASE_LETTERCASE_CONVERSIONS_H

#include <string>
#include <vector>

#include "ExceptionWords.h"

namespace lettercase {
    std::string to_titlecase(const std::string& text, const ExceptionWords& wordList, bool keep_abbreviations);
    std::string to_lowercase(const std::string& text);
    std::string to_uppercase(const std::string& text);
    std::string to_snake_case(const std::string& text);
    std::string to_camelcase(const std::string& text);
}

#endif //LIBLETTERCASE_LETTERCASE_CONVERSIONS_H
