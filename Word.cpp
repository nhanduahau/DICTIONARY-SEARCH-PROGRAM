#include "Word.h"

// Constructors
Word::Word() : word(""), partOfSpeech(""), definition("") {}

Word::Word(const std::string &word, const std::string &partOfSpeech,
           const std::string &definition)
    : word(word), partOfSpeech(partOfSpeech), definition(definition) {}

// Getters
std::string Word::getWord() const
{
    return word;
}

std::string Word::getPartOfSpeech() const
{
    return partOfSpeech;
}

std::string Word::getDefinition() const
{
    return definition;
}

// Setters
void Word::setWord(const std::string &word)
{
    this->word = word;
}

void Word::setPartOfSpeech(const std::string &partOfSpeech)
{
    this->partOfSpeech = partOfSpeech;
}

void Word::setDefinition(const std::string &definition)
{
    this->definition = definition;
}

// Display
void Word::display() const
{
    std::cout << "Word: " << word << std::endl;
    std::cout << "Part of Speech: " << partOfSpeech << std::endl;
    std::cout << "Definition: " << definition << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

// Comparison operators
bool Word::operator<(const Word &other) const
{
    return word < other.word;
}

bool Word::operator>(const Word &other) const
{
    return word > other.word;
}

bool Word::operator==(const Word &other) const
{
    return word == other.word;
}
