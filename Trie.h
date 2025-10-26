#ifndef TRIE_H
#define TRIE_H

#include "Word.h"
#include <chrono>
#include <unordered_map>

class TrieNode
{
public:
    std::unordered_map<char, TrieNode *> children; // Using unordered_map for better memory efficiency
    Word *word;
    bool isEndOfWord;

    TrieNode();
    ~TrieNode();
};

class Trie
{
private:
    TrieNode *root;
    int nodeCount;

    // Helper functions
    void destroyTrie(TrieNode *node);
    int getMemorySize(TrieNode *node) const;
    void getAllWordsHelper(TrieNode *node, std::string prefix, int &count, int maxCount) const;
    void displayTreeHelper(TrieNode *node, std::string prefix, std::string charPrefix, int &count, int maxCount) const;

public:
    // Constructor & Destructor
    Trie();
    ~Trie();

    // Main operations
    void insert(const Word &word);
    Word *search(const std::string &name) const;

    // Performance metrics
    long long searchWithTiming(const std::string &name, Word *&result);
    int getMemoryUsage() const;
    int getNodeCount() const;

    // Display
    void displayAllWords() const;
    void displayTree() const;
};

#endif
