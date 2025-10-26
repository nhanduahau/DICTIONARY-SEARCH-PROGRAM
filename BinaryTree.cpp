#include "BinaryTree.h"

// =========================================
// TREENODE IMPLEMENTATION
// =========================================

/**
 * TreeNode Constructor
 * Initializes a new tree node with the given word
 * @param wd: Word object to store in this node
 */
TreeNode::TreeNode(const Word &wd) : word(wd), left(nullptr), right(nullptr) {}

// =========================================
// BINARYTREE IMPLEMENTATION
// =========================================

/**
 * BinaryTree Constructor
 * Creates an empty BST with no root node
 */
BinaryTree::BinaryTree() : root(nullptr), nodeCount(0) {}

/**
 * BinaryTree Destructor
 * Destroys the entire tree starting from root
 */
BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

/**
 * Recursively destroys all nodes in the BST
 * Post-order traversal: destroys children first, then parent
 * @param node: Current node to destroy
 */
void BinaryTree::destroyTree(TreeNode *node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);  // Destroy left subtree
        destroyTree(node->right); // Destroy right subtree
        delete node;              // Delete current node
    }
}

// =========================================
// INSERTION OPERATION
// =========================================

/**
 * Inserts a word into the BST
 * Maintains BST property: left < parent < right (alphabetically)
 * Time Complexity: O(log n) average, O(n) worst case
 * @param word: Word object to insert
 */
void BinaryTree::insert(const Word &word)
{
    root = insertHelper(root, word);
    nodeCount++;
}

/**
 * Recursive helper function to insert a word into the BST
 * Creates a new node if the correct position is found (nullptr)
 * Otherwise, recursively navigates left or right based on comparison
 * @param node: Current node being examined
 * @param word: Word object to insert
 * @return: Pointer to the root of this subtree (unchanged or newly created)
 */
TreeNode *BinaryTree::insertHelper(TreeNode *node, const Word &word)
{
    // Base case: found the insertion point (empty spot)
    if (node == nullptr)
    {
        return new TreeNode(word);
    }

    // Recursive case: navigate left or right based on alphabetical comparison
    if (word < node->word)
    {
        // Word comes alphabetically before current node -> go left
        node->left = insertHelper(node->left, word);
    }
    else if (word > node->word)
    {
        // Word comes alphabetically after current node -> go right
        node->right = insertHelper(node->right, word);
    }
    // If word == node->word, it's a duplicate - don't insert again

    return node;
}

// =========================================
// SEARCH OPERATION
// =========================================

/**
 * Searches for a word in the BST
 * Uses binary search algorithm based on alphabetical ordering
 * Time Complexity: O(log n) average, O(n) worst case
 * @param name: Word to search for
 * @return: Pointer to Word object if found, nullptr otherwise
 */
Word *BinaryTree::search(const std::string &name) const
{
    TreeNode *result = searchHelper(root, name);
    return (result != nullptr) ? &(result->word) : nullptr;
}

/**
 * Recursive helper function to search for a word in the BST
 * Uses binary search: compares and navigates left or right
 * @param node: Current node being examined
 * @param name: Word to search for
 * @return: Pointer to TreeNode containing the word, or nullptr if not found
 */
TreeNode *BinaryTree::searchHelper(TreeNode *node, const std::string &name) const
{
    // Base cases: empty tree or found the word
    if (node == nullptr || node->word.getWord() == name)
    {
        return node;
    }

    // Recursive case: binary search
    if (name < node->word.getWord())
    {
        // Search in left subtree (words alphabetically before)
        return searchHelper(node->left, name);
    }
    else
    {
        // Search in right subtree (words alphabetically after)
        return searchHelper(node->right, name);
    }
}

// =========================================
// PERFORMANCE MEASUREMENT
// =========================================

/**
 * Searches for a word and measures the time taken
 * Uses high-resolution clock for precise nanosecond measurement
 * @param name: Word to search for
 * @param result: Reference parameter to store search result
 * @return: Time taken for the search in nanoseconds
 */
long long BinaryTree::searchWithTiming(const std::string &name, Word *&result)
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
 * Calculates total memory usage of the BST
 * @return: Total memory in bytes
 */
int BinaryTree::getMemoryUsage() const
{
    return getMemorySize(root);
}

/**
 * Recursively calculates memory size of the BST starting from a node
 * Includes: node size, Word object size, and string capacities
 * @param node: Current node being measured
 * @return: Memory size in bytes
 */
int BinaryTree::getMemorySize(TreeNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    // Size of TreeNode structure itself
    int currentSize = sizeof(TreeNode);

    // Add the actual string storage capacity for Word's strings
    currentSize += node->word.getWord().capacity();
    currentSize += node->word.getPartOfSpeech().capacity();
    currentSize += node->word.getDefinition().capacity();

    // Recursively add memory of left and right subtrees
    return currentSize + getMemorySize(node->left) + getMemorySize(node->right);
}

/**
 * Returns the total number of nodes in the BST
 * @return: Node count
 */
int BinaryTree::getNodeCount() const
{
    return nodeCount;
}

// =========================================
// DISPLAY FUNCTIONS
// =========================================

/**
 * Displays the BST structure in a tree-like format
 * Shows left (L) and right (R) child relationships
 * Limited to first 10 nodes to prevent overwhelming output
 */
void BinaryTree::displayTree() const
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty!" << std::endl;
        return;
    }

    int count = 0;
    std::cout << "Binary Search Tree Structure (showing first 10 words):" << std::endl;
    std::cout << std::endl;

    // Start recursive display from root
    displayTreeHelper(root, "", false, count, 10);
}

/**
 * Recursive helper function to display the BST structure
 * Displays in a tree format showing left (L) and right (R) relationships
 * @param node: Current node being displayed
 * @param prefix: Formatting string for tree branches
 * @param isLeft: Whether this node is a left child (for formatting)
 * @param count: Current count of nodes displayed (reference)
 * @param maxCount: Maximum number of nodes to display
 */
void BinaryTree::displayTreeHelper(TreeNode *node, std::string prefix, bool isLeft, int &count, int maxCount) const
{
    // Base cases: null node or reached display limit
    if (node == nullptr || count >= maxCount)
    {
        return;
    }

    // Display current node with appropriate tree branch symbol
    std::cout << prefix;
    std::cout << (isLeft ? "|--L: " : "+--R: ");
    std::cout << node->word.getWord() << std::endl;
    count++;

    // Stop if we've reached the display limit
    if (count >= maxCount)
    {
        return;
    }

    // Recursively display children if they exist
    if (node->left != nullptr || node->right != nullptr)
    {
        // Display left subtree
        if (node->left != nullptr)
        {
            displayTreeHelper(node->left,
                              prefix + (isLeft ? "|   " : "    "),
                              true,
                              count,
                              maxCount);
        }

        // Display right subtree
        if (node->right != nullptr && count < maxCount)
        {
            displayTreeHelper(node->right,
                              prefix + (isLeft ? "|   " : "    "),
                              false,
                              count,
                              maxCount);
        }
    }
}
