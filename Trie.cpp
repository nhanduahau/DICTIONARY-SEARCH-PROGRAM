#include "Trie.h"

// =========================================
// TRIENODE IMPLEMENTATION
// =========================================

/**
 * TrieNode Constructor
 * Initializes a new node with no word data and not marked as end of word
 */
TrieNode::TrieNode() : word(nullptr), isEndOfWord(false)
{
    // No need to initialize children map - unordered_map handles it automatically
}

/**
 * TrieNode Destructor
 * Cleans up the Word object if this node stores one
 * The unordered_map automatically cleans up its entries
 */
TrieNode::~TrieNode()
{
    if (word != nullptr)
    {
        delete word;
    }
    // Children map will be automatically cleaned up by unordered_map destructor
}

// =========================================
// TRIE IMPLEMENTATION
// =========================================

/**
 * Trie Constructor
 * Creates an empty Trie with a root node
 */
Trie::Trie() : nodeCount(0)
{
    root = new TrieNode();
}

/**
 * Trie Destructor
 * Destroys the entire Trie tree starting from root
 */
Trie::~Trie()
{
    destroyTrie(root);
}

/**
 * Recursively destroys all nodes in the Trie
 * Post-order traversal: destroys children first, then parent
 * @param node: Current node to destroy
 */
void Trie::destroyTrie(TrieNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    // Recursively destroy all child nodes first
    for (auto &pair : node->children)
    {
        destroyTrie(pair.second);
    }

    // Then destroy the current node
    delete node;
}

// =========================================
// INSERTION OPERATION
// =========================================

/**
 * Inserts a word into the Trie structure
 * Converts each character to lowercase for case-insensitive searching
 * Time Complexity: O(m) where m is the length of the word
 * @param word: Word object containing the word, part of speech, and definition
 */
void Trie::insert(const Word &word)
{
    TrieNode *current = root;
    std::string name = word.getWord();

    // Traverse through each character of the word
    for (char c : name)
    {
        // Convert to lowercase for case-insensitive search capability
        char lowerC = tolower(c);

        // If child node for this character doesn't exist, create it
        if (current->children.find(lowerC) == current->children.end())
        {
            current->children[lowerC] = new TrieNode();
            nodeCount++; // Increment total node count
        }
        
        // Move to the child node
        current = current->children[lowerC];
    }

    // Mark the last node as end of a valid word
    current->isEndOfWord = true;
    
    // Store a copy of the complete Word object at this node
    current->word = new Word(word);
}

// =========================================
// SEARCH OPERATION
// =========================================

/**
 * Searches for a word in the Trie
 * Case-insensitive search by converting to lowercase
 * Time Complexity: O(m) where m is the length of the word
 * @param name: The word to search for
 * @return: Pointer to the Word object if found, nullptr otherwise
 */
Word *Trie::search(const std::string &name) const
{
    TrieNode *current = root;

    // Traverse through each character of the search word
    for (char c : name)
    {
        // Convert to lowercase to match insertion format
        char lowerC = tolower(c);

        // If the character path doesn't exist, word is not in the Trie
        if (current->children.find(lowerC) == current->children.end())
        {
            return nullptr; // Word not found
        }
        
        // Move to the next node in the path
        current = current->children.at(lowerC);
    }

    // Return the word only if we're at a valid end-of-word node
    return (current != nullptr && current->isEndOfWord) ? current->word : nullptr;
}

// =========================================
// PERFORMANCE MEASUREMENT
// =========================================

/**
 * Searches for a word and measures the time taken
 * Uses high-resolution clock for precise nanosecond measurement
 * @param name: The word to search for
 * @param result: Reference parameter to store the search result
 * @return: Time taken for the search in nanoseconds
 */
long long Trie::searchWithTiming(const std::string &name, Word *&result)
{
    // Record start time with high precision
    auto start = std::chrono::high_resolution_clock::now();
    
    // Perform the search
    result = search(name);
    
    // Record end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in nanoseconds
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration.count();
}

// =========================================
// MEMORY USAGE CALCULATION
// =========================================

/**
 * Calculates total memory usage of the Trie
 * @return: Total memory in bytes
 */
int Trie::getMemoryUsage() const
{
    return getMemorySize(root);
}

/**
 * Recursively calculates memory size of the Trie starting from a node
 * Includes: node size, map overhead, Word object size, and string capacities
 * @param node: Current node being measured
 * @return: Memory size in bytes
 */
int Trie::getMemorySize(TrieNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    // Base size of the TrieNode structure
    int size = sizeof(TrieNode);

    // Memory for the children map
    // Unordered_map has approximately 16 bytes overhead per entry (more efficient than map's ~32 bytes)
    // Each entry contains: key (char) + value (TrieNode*) + internal bookkeeping
    size += node->children.size() * (sizeof(char) + sizeof(TrieNode *) + 16);

    // If this node stores a complete word, add its memory
    if (node->word != nullptr)
    {
        size += sizeof(Word);
        // Add the actual string storage capacity (not just length)
        size += node->word->getWord().capacity();
        size += node->word->getPartOfSpeech().capacity();
        size += node->word->getDefinition().capacity();
    }

    // Recursively add memory of all child nodes
    for (auto &pair : node->children)
    {
        size += getMemorySize(pair.second);
    }

    return size;
}

/**
 * Returns the total number of nodes in the Trie
 * @return: Node count
 */
int Trie::getNodeCount() const
{
    return nodeCount;
}

// =========================================
// DISPLAY FUNCTIONS
// =========================================

/**
 * Displays the Trie structure in a tree-like format
 * Shows only the first 10 words to prevent overwhelming output
 */
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
    
    // Start recursive display from root
    displayTreeHelper(root, "", "", count, 10);
}

/**
 * Recursive helper function to display the Trie structure
 * Displays in a tree format with branches showing character relationships
 * @param node: Current node being displayed
 * @param prefix: Formatting string for tree branches
 * @param charPrefix: Accumulated characters from root (for debugging)
 * @param count: Current count of words displayed (reference)
 * @param maxCount: Maximum number of words to display
 */
void Trie::displayTreeHelper(TrieNode *node, std::string prefix, std::string charPrefix, int &count, int maxCount) const
{
    // Base cases: null node or reached display limit
    if (node == nullptr || count >= maxCount)
    {
        return;
    }

    // If this node marks the end of a word, display the complete word
    if (node->isEndOfWord && node->word != nullptr)
    {
        std::cout << prefix << "+-- [" << node->word->getWord() << "]" << std::endl;
        count++;
        if (count >= maxCount)
        {
            return;
        }
        return; // Don't show children of complete words for cleaner output
    }

    // Process all child nodes
    int childCount = node->children.size();
    int currentChild = 0;

    for (auto &pair : node->children)
    {
        if (count >= maxCount)
            break;

        currentChild++;
        bool isLast = (currentChild == childCount);

        // Display the character with appropriate tree branch symbol
        std::cout << prefix;
        std::cout << (isLast ? "+-- " : "|-- ");
        std::cout << "'" << pair.first << "'" << std::endl;

        // Recursively display child node with updated prefix for tree formatting
        displayTreeHelper(pair.second,
                          prefix + (isLast ? "    " : "|   "),
                          charPrefix + pair.first,
                          count,
                          maxCount);
    }
}
