#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

#include "liblettercase/helper_functions.h"

namespace lettercase::detail {
    using std::vector;
    using std::string;
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    string construct_string_from_vector(const vector<string>& vec) {
        std::ostringstream ret;
        std::copy(vec.begin(), vec.end()-1,
                  std::ostream_iterator<string>(ret, " "));
        ret << vec.back();
        return ret.str();
    }

    bool contains_any_lowercase(const string& str) {
        return std::any_of(str.begin(), str.end(),
                    [](unsigned char c) {
                        return std::islower(c);
                    });
    }

    bool is_in_exceptionlist(const ExceptionWords& wordList, const std::string& str) {
        const auto& words_kept_in_lowercase = wordList.wordsToBeLeftInLowerCase;
        return std::find(words_kept_in_lowercase.begin(), words_kept_in_lowercase.end(), str) != words_kept_in_lowercase.end();
    }
}