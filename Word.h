#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>

class Word
{
private:
    std::string word;
    std::string partOfSpeech;
    std::string definition;

public:
    // Constructor
    Word();
    Word(const std::string &word, const std::string &partOfSpeech,
         const std::string &definition);

    // Getters
    std::string getWord() const;
    std::string getPartOfSpeech() const;
    std::string getDefinition() const;

    // Setters
    void setWord(const std::string &word);
    void setPartOfSpeech(const std::string &partOfSpeech);
    void setDefinition(const std::string &definition);

    // Display
    void display() const;

    // Comparison operators for BST
    bool operator<(const Word &other) const;
    bool operator>(const Word &other) const;
    bool operator==(const Word &other) const;
};

#endif
