#include "Trie.h"
#include <iostream>

// TrieNode Constructor
TrieNode::TrieNode() : word(nullptr), isEndOfWord(false)
{
    // No need to initialize children array - map handles it automatically
}

// TrieNode Destructor
TrieNode::~TrieNode()
{
    if (word != nullptr)
    {
        delete word;
    }
    // Map will automatically clean up
}

// Trie Constructor
Trie::Trie() : nodeCount(0)
{
    root = new TrieNode();
}

// Trie Destructor
Trie::~Trie()
{
    destroyTrie(root);
}

void Trie::destroyTrie(TrieNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    for (auto &pair : node->children)
    {
        destroyTrie(pair.second);
    }

    delete node;
}

// Insert
void Trie::insert(const Word &word)
{
    TrieNode *current = root;
    std::string name = word.getWord();

    for (char c : name)
    {
        // Convert to lowercase for case-insensitive search
        char lowerC = tolower(c);

        if (current->children.find(lowerC) == current->children.end())
        {
            current->children[lowerC] = new TrieNode();
            nodeCount++;
        }
        current = current->children[lowerC];
    }

    current->isEndOfWord = true;
    current->word = new Word(word);
}

// Search
Word *Trie::search(const std::string &name) const
{
    TrieNode *current = root;

    for (char c : name)
    {
        char lowerC = tolower(c);

        if (current->children.find(lowerC) == current->children.end())
        {
            return nullptr;
        }
        current = current->children.at(lowerC);
    }

    return (current != nullptr && current->isEndOfWord) ? current->word : nullptr;
}

// Search with timing
long long Trie::searchWithTiming(const std::string &name, Word *&result)
{
    auto start = std::chrono::high_resolution_clock::now();
    result = search(name);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration.count();
}

// Memory usage calculation
int Trie::getMemoryUsage() const
{
    return getMemorySize(root);
}

int Trie::getMemorySize(TrieNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    // Size of TrieNode object + unordered_map overhead
    int size = sizeof(TrieNode);

    // Unordered_map memory: approximately (key + value + overhead) per entry
    // unordered_map has lower overhead than map (~16 bytes vs ~32 bytes per entry)
    size += node->children.size() * (sizeof(char) + sizeof(TrieNode *) + 16); // 16 bytes overhead per map entry

    if (node->word != nullptr)
    {
        size += sizeof(Word);
        size += node->word->getWord().capacity();
        size += node->word->getPartOfSpeech().capacity();
        size += node->word->getDefinition().capacity();
    }

    for (auto &pair : node->children)
    {
        size += getMemorySize(pair.second);
    }

    return size;
}

int Trie::getNodeCount() const
{
    return nodeCount;
}

// Display all words
void Trie::displayAllWords() const
{
    int count = 0;
    getAllWordsHelper(root, "", count, 10);
    std::cout << "... (showing first 10 words)" << std::endl;
}

void Trie::getAllWordsHelper(TrieNode *node, std::string prefix, int &count, int maxCount) const
{
    if (node == nullptr || count >= maxCount)
    {
        return;
    }

    if (node->isEndOfWord && node->word != nullptr)
    {
        std::cout << node->word->getWord() << std::endl;
        count++;
        if (count >= maxCount)
        {
            return;
        }
    }

    for (auto &pair : node->children)
    {
        if (count < maxCount)
        {
            getAllWordsHelper(pair.second, prefix + pair.first, count, maxCount);
        }
    }
}

// Display tree structure
void Trie::displayTree() const
{
    if (root == nullptr)
    {
        std::cout << "Trie is empty!" << std::endl;
        return;
    }
    int count = 0;
    std::cout << "Trie Structure (showing first 10 words):" << std::endl;
    std::cout << std::endl;
    std::cout << "root" << std::endl;
    displayTreeHelper(root, "", "", count, 10);
}

void Trie::displayTreeHelper(TrieNode *node, std::string prefix, std::string charPrefix, int &count, int maxCount) const
{
    if (node == nullptr || count >= maxCount)
    {
        return;
    }

    if (node->isEndOfWord && node->word != nullptr)
    {
        std::cout << prefix << "+-- [" << node->word->getWord() << "]" << std::endl;
        count++;
        if (count >= maxCount)
        {
            return;
        }
        return;
    }

    int childCount = node->children.size();
    int currentChild = 0;

    for (auto &pair : node->children)
    {
        if (count >= maxCount)
            break;

        currentChild++;
        bool isLast = (currentChild == childCount);

        std::cout << prefix;
        std::cout << (isLast ? "+-- " : "|-- ");
        std::cout << "'" << pair.first << "'" << std::endl;

        displayTreeHelper(pair.second,
                          prefix + (isLast ? "    " : "|   "),
                          charPrefix + pair.first,
                          count,
                          maxCount);
    }
}
