#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::string construct_string_from_vector(const std::vector<std::string>& vec) {
    std::ostringstream ret;
    std::copy(vec.begin(), vec.end()-1,
              std::ostream_iterator<std::string>(ret, " "));
    ret << vec.back();
    return ret.str();
}

std::string to_titlecase(const std::string& text) {
    auto wordsToBeLeftInLowerCase = {
            "a", "an", "the", "at", "by", "for", "in", "of",
            "on", "to", "and", "as", "or"
    };

    auto splitted_text = split(text, ' ');
    for (std::string& str: splitted_text) {
        if (std::find(wordsToBeLeftInLowerCase.begin(), wordsToBeLeftInLowerCase.end(), str) != wordsToBeLeftInLowerCase.end())  {
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

int main() {

}