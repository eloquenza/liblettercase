#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <initializer_list>
#include <functional>

#include "liblettercase/helper_functions.h"

namespace lettercase::detail {
    using std::vector;
    using std::string;

    string conversion_loop(const string& text, std::function<void(string&)> body, const char* delimiter) {
        using namespace lettercase::detail;
        auto splitted_text = split(text, ' ');

        for (string& str: splitted_text) {
            body(str);
        }

        return construct_string_from_vector(splitted_text, delimiter);
    }

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

    string construct_string_from_vector(const vector<string>& vec, const char* new_delimiter) {
        std::ostringstream ret;
        std::copy(vec.begin(), vec.end()-1,
                  std::ostream_iterator<string>(ret, new_delimiter));
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