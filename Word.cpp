#include "Word.h"

// =========================================
// CONSTRUCTORS
// =========================================

/**
 * Default Constructor
 * Initializes all string fields to empty strings
 */
Word::Word() : word(""), partOfSpeech(""), definition("") {}

/**
 * Parameterized Constructor
 * Initializes Word with specified values
 * @param word: The word text
 * @param partOfSpeech: Part of speech label
 * @param definition: The word's definition
 */
Word::Word(const std::string &word, const std::string &partOfSpeech,
           const std::string &definition)
    : word(word), partOfSpeech(partOfSpeech), definition(definition) {}

// =========================================
// GETTERS
// =========================================

/**
 * Returns the word text
 * @return: The word as a string
 */
std::string Word::getWord() const
{
    return word;
}

/**
 * Returns the part of speech
 * @return: Part of speech as a string
 */
std::string Word::getPartOfSpeech() const
{
    return partOfSpeech;
}

/**
 * Returns the definition
 * @return: Definition as a string
 */
std::string Word::getDefinition() const
{
    return definition;
}

// =========================================
// SETTERS
// =========================================

/**
 * Sets the word text
 * @param word: New word text to set
 */
void Word::setWord(const std::string &word)
{
    this->word = word;
}

/**
 * Sets the part of speech
 * @param partOfSpeech: New part of speech to set
 */
void Word::setPartOfSpeech(const std::string &partOfSpeech)
{
    this->partOfSpeech = partOfSpeech;
}

/**
 * Sets the definition
 * @param definition: New definition to set
 */
void Word::setDefinition(const std::string &definition)
{
    this->definition = definition;
}

// =========================================
// DISPLAY
// =========================================

/**
 * Displays the complete word information to console
 * Outputs word, part of speech, and definition in formatted manner
 */
void Word::display() const
{
    std::cout << "Word: " << word << std::endl;
    std::cout << "Part of Speech: " << partOfSpeech << std::endl;
    std::cout << "Definition: " << definition << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

// =========================================
// COMPARISON OPERATORS
// =========================================

/**
 * Less than operator for alphabetical comparison
 * Used by BST to maintain sorted order
 * @param other: Word to compare with
 * @return: True if this word comes before other alphabetically
 */
bool Word::operator<(const Word &other) const
{
    return word < other.word;
}

/**
 * Greater than operator for alphabetical comparison
 * Used by BST to maintain sorted order
 * @param other: Word to compare with
 * @return: True if this word comes after other alphabetically
 */
bool Word::operator>(const Word &other) const
{
    return word > other.word;
}

/**
 * Equality operator for exact word matching
 * Compares only the word text, not part of speech or definition
 * @param other: Word to compare with
 * @return: True if word texts are identical
 */
bool Word::operator==(const Word &other) const
{
    return word == other.word;
}
