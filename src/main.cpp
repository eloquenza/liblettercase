#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

class ExceptionWords {
public:
    std::vector<std::string> wordsToBeLeftInLowerCase;
    ExceptionWords() {
        wordsToBeLeftInLowerCase = {
            "a", "an", "the", "at", "by", "for", "in", "of",
                    "on", "to", "and", "as", "or"
        };
    }
    explicit ExceptionWords(std::vector<std::string> newList) : wordsToBeLeftInLowerCase(newList) {}

    void add(const std::string new_word) {
        wordsToBeLeftInLowerCase.push_back(new_word);
    }

    void remove(const std::string& word_to_delete) {
        wordsToBeLeftInLowerCase.erase(
                std::find(wordsToBeLeftInLowerCase.begin(), wordsToBeLeftInLowerCase.end(),
                          word_to_delete));
    }
};

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

std::string to_titlecase(const std::string& text, const ExceptionWords& wordList) {
    auto splitted_text = split(text, ' ');
    auto& words_kept_in_lowercase = wordList.wordsToBeLeftInLowerCase;
    for (std::string& str: splitted_text) {
        if (std::find(words_kept_in_lowercase.begin(), words_kept_in_lowercase.end(), str) != words_kept_in_lowercase.end())  {
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
    std::string text = "The point is to get more experience with ranges and the STL, "
                       "design an clear API, and implement a library with expressive code. "
                       "All of which are precious tools for everyday work.";

    std::cout << "Sentence which will be Title Case'd:\n" << text
              << "\n\n";

    auto wordList = ExceptionWords();
    std::cout << "Title Case'd sentence:\n" << to_titlecase(text, wordList);
    return 0;
}