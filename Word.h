#ifndef WORD_H
#define WORD_H

#include <string>
#include <iostream>

/**
 * Word - Represents a dictionary word entry
 * Stores the word text, its part of speech, and definition
 */
class Word
{
private:
    std::string word;           // The word itself (e.g., "Apple")
    std::string partOfSpeech;   // Part of speech (e.g., "n." for noun, "v." for verb)
    std::string definition;     // The word's definition

public:
    // === CONSTRUCTORS ===
    
    /**
     * Default constructor
     * Creates an empty Word with all fields as empty strings
     */
    Word();
    
    /**
     * Parameterized constructor
     * Creates a Word with specified values
     * @param word: The word text
     * @param partOfSpeech: Part of speech label
     * @param definition: The word's definition
     */
    Word(const std::string &word, const std::string &partOfSpeech,
         const std::string &definition);

    // === GETTERS ===
    
    /**
     * Gets the word text
     * @return: The word as a string
     */
    std::string getWord() const;
    
    /**
     * Gets the part of speech
     * @return: Part of speech as a string
     */
    std::string getPartOfSpeech() const;
    
    /**
     * Gets the definition
     * @return: Definition as a string
     */
    std::string getDefinition() const;

    // === SETTERS ===
    
    /**
     * Sets the word text
     * @param word: New word text
     */
    void setWord(const std::string &word);
    
    /**
     * Sets the part of speech
     * @param partOfSpeech: New part of speech
     */
    void setPartOfSpeech(const std::string &partOfSpeech);
    
    /**
     * Sets the definition
     * @param definition: New definition
     */
    void setDefinition(const std::string &definition);

    // === DISPLAY ===
    
    /**
     * Displays the complete word information
     * Prints word, part of speech, and definition to console
     */
    void display() const;

    // === COMPARISON OPERATORS ===
    // Used by BST for maintaining alphabetical ordering
    
    /**
     * Less than operator
     * Compares words alphabetically
     * @param other: Word to compare with
     * @return: True if this word comes before other alphabetically
     */
    bool operator<(const Word &other) const;
    
    /**
     * Greater than operator
     * Compares words alphabetically
     * @param other: Word to compare with
     * @return: True if this word comes after other alphabetically
     */
    bool operator>(const Word &other) const;
    
    /**
     * Equality operator
     * Compares words for exact match
     * @param other: Word to compare with
     * @return: True if words are identical
     */
    bool operator==(const Word &other) const;
};

#endif
