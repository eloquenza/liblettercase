#ifndef LIBLETTERCASE_LETTERCASE_CONVERSIONS_H
#define LIBLETTERCASE_LETTERCASE_CONVERSIONS_H

#include <string>
#include <vector>

#include "ExceptionWords.h"

namespace lettercase {
    std::string to_titlecase(const std::string& text, const ExceptionWords& wordList, bool keep_abbreviations);
}

#endif //LIBLETTERCASE_LETTERCASE_CONVERSIONS_H
