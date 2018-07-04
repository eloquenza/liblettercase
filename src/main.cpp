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

int main() {

}