#ifndef LIBLETTERCASE_HELPER_FUNCTIONS_H
#define LIBLETTERCASE_HELPER_FUNCTIONS_H

#include <vector>
#include <string>

#include "ExceptionWords.h"

namespace lettercase::detail {
    std::vector<std::string> split(const std::string& s, char delimiter);
    std::string construct_string_from_vector(const std::vector<std::string>& vec);
    bool contains_any_lowercase(const std::string& str);
    bool is_in_exceptionlist(const ExceptionWords& wordList, const std::string& str);
}

#endif //LIBLETTERCASE_HELPER_FUNCTIONS_H
