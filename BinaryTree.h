#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Word.h"
#include <chrono>
#include <queue>

/**
 * TreeNode - Node in the Binary Search Tree
 * Each node stores a complete Word object and pointers to left/right children
 */
class TreeNode
{
public:
    Word word;          // Complete word data (word, part of speech, definition)
    TreeNode *left;     // Pointer to left child (words alphabetically before this word)
    TreeNode *right;    // Pointer to right child (words alphabetically after this word)

    /**
     * Constructor
     * @param wd: Word object to store in this node
     */
    TreeNode(const Word &wd);
};

/**
 * BinaryTree - Binary Search Tree implementation
 * Maintains BST property: left child < parent < right child (alphabetically)
 * Time Complexity: O(log n) average case, O(n) worst case for unbalanced tree
 */
class BinaryTree
{
private:
    TreeNode *root;      // Root node of the BST
    int nodeCount;       // Total number of nodes in the tree

    // === PRIVATE HELPER FUNCTIONS ===
    
    /**
     * Recursive helper to insert a word into the BST
     * Maintains BST property during insertion
     * @param node: Current node being examined
     * @param word: Word object to insert
     * @return: Pointer to the (possibly new) root of this subtree
     */
    TreeNode *insertHelper(TreeNode *node, const Word &word);
    
    /**
     * Recursive helper to search for a word in the BST
     * Uses binary search based on alphabetical comparison
     * @param node: Current node being examined
     * @param name: Word to search for
     * @return: Pointer to the node containing the word, or nullptr if not found
     */
    TreeNode *searchHelper(TreeNode *node, const std::string &name) const;
    
    /**
     * Recursively destroys all nodes in the tree
     * Post-order traversal: destroys children first, then parent
     * @param node: Current node to destroy
     */
    void destroyTree(TreeNode *node);
    
    /**
     * Recursively calculates memory usage of the tree
     * @param node: Current node being measured
     * @return: Memory size in bytes
     */
    int getMemorySize(TreeNode *node) const;
    
    /**
     * Recursive helper to display tree structure visually
     * @param node: Current node being displayed
     * @param prefix: Formatting string for tree branches
     * @param isLeft: Whether this node is a left child
     * @param count: Current count of nodes displayed (reference)
     * @param maxCount: Maximum number of nodes to display
     */
    void displayTreeHelper(TreeNode *node, std::string prefix, bool isLeft, int &count, int maxCount) const;

public:
    // === CONSTRUCTOR & DESTRUCTOR ===
    BinaryTree();
    ~BinaryTree();

    // === MAIN OPERATIONS ===
    
    /**
     * Inserts a word into the BST
     * Maintains BST property: left < parent < right (alphabetically)
     * @param word: Word object to insert
     */
    void insert(const Word &word);
    
    /**
     * Searches for a word in the BST
     * Case-sensitive search using binary search algorithm
     * @param name: Word to search for
     * @return: Pointer to Word object if found, nullptr otherwise
     */
    Word *search(const std::string &name) const;

    // === PERFORMANCE METRICS ===
    
    /**
     * Searches for a word and measures execution time
     * @param name: Word to search for
     * @param result: Reference parameter to store search result
     * @return: Search time in nanoseconds
     */
    long long searchWithTiming(const std::string &name, Word *&result);
    
    /**
     * Gets the total memory usage of the BST
     * @return: Memory used in bytes
     */
    int getMemoryUsage() const;
    
    /**
     * Gets the total number of nodes in the BST
     * @return: Node count
     */
    int getNodeCount() const;

    // === DISPLAY ===
    
    /**
     * Displays the BST structure in a tree-like format
     * Shows left (L) and right (R) relationships
     * Limited to first 10 nodes to prevent overwhelming output
     */
    void displayTree() const;
};

#endif
