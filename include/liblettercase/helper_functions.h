#ifndef LIBLETTERCASE_HELPER_FUNCTIONS_H
#define LIBLETTERCASE_HELPER_FUNCTIONS_H

#include <vector>
#include <string>

namespace lettercase::detail {
    std::vector<std::string> split(const std::string& s, char delimiter);
    std::string construct_string_from_vector(const std::vector<std::string>& vec);
}

#endif //LIBLETTERCASE_HELPER_FUNCTIONS_H
