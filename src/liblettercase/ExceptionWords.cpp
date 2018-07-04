#include <algorithm>
#include <string>
#include <vector>

#include "liblettercase/ExceptionWords.h"

namespace lettercase {
    void ExceptionWords::add(const std::string new_word) {
        wordsToBeLeftInLowerCase.push_back(new_word);
    }

    void ExceptionWords::remove(const std::string &word_to_delete) {
        wordsToBeLeftInLowerCase.erase(
                std::find(wordsToBeLeftInLowerCase.begin(), wordsToBeLeftInLowerCase.end(),
                          word_to_delete));
    }
}
