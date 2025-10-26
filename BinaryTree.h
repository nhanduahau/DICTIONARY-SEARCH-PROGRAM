#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Word.h"
#include <chrono>
#include <queue>

class TreeNode
{
public:
    Word word;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const Word &wd);
};

class BinaryTree
{
private:
    TreeNode *root;
    int nodeCount;

    // Helper functions
    TreeNode *insertHelper(TreeNode *node, const Word &word);
    TreeNode *searchHelper(TreeNode *node, const std::string &name) const;
    void destroyTree(TreeNode *node);
    int getMemorySize(TreeNode *node) const;
    void inorderHelper(TreeNode *node, int &count, int maxCount) const;
    void displayTreeHelper(TreeNode *node, std::string prefix, bool isLeft, int &count, int maxCount) const;

public:
    // Constructor & Destructor
    BinaryTree();
    ~BinaryTree();

    // Main operations - insert using level-order (complete binary tree)
    void insert(const Word &word);
    Word *search(const std::string &name) const;

    // Performance metrics
    long long searchWithTiming(const std::string &name, Word *&result);
    int getMemoryUsage() const;
    int getNodeCount() const;

    // Display
    void inorderTraversal() const;
    void displayTree() const;
};

#endif
