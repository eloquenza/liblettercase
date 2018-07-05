#ifndef LIBLETTERCASE_EXCEPTIONWORDS_H
#define LIBLETTERCASE_EXCEPTIONWORDS_H

#include <string>
#include <vector>

namespace lettercase {
    class ExceptionWords {
    public:
        std::vector<std::string> wordList;
        ExceptionWords() {
            wordList = {
                    "a", "an", "the", "at", "by", "for", "in", "of",
                    "on", "to", "and", "as", "or"
            };
        }
        explicit ExceptionWords(std::vector<std::string> newList) :
                wordList(newList) {}

        void add(const std::string new_word);
        void remove(const std::string& word_to_delete);
    };
}

#endif //LIBLETTERCASE_EXCEPTIONWORDS_H
