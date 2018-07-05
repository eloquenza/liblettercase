#include <algorithm>
#include <string>
#include <vector>

#include "liblettercase/ExceptionWords.h"

namespace lettercase {
    void ExceptionWords::add(const std::string new_word) {
        wordList.push_back(new_word);
    }

    void ExceptionWords::remove(const std::string &word_to_delete) {
        wordList.erase(
                std::find(wordList.begin(), wordList.end(),
                          word_to_delete));
    }
}
