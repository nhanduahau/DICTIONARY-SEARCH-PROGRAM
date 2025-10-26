#include "BinaryTree.h"

// TreeNode Constructor
TreeNode::TreeNode(const Word &wd) : word(wd), left(nullptr), right(nullptr) {}

// BinaryTree Constructor
BinaryTree::BinaryTree() : root(nullptr), nodeCount(0) {}

// BinaryTree Destructor
BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode *node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Insert using BST property (left < root < right)
void BinaryTree::insert(const Word &word)
{
    root = insertHelper(root, word);
    nodeCount++;
}

TreeNode *BinaryTree::insertHelper(TreeNode *node, const Word &word)
{
    if (node == nullptr)
    {
        return new TreeNode(word);
    }

    if (word < node->word)
    {
        node->left = insertHelper(node->left, word);
    }
    else if (word > node->word)
    {
        node->right = insertHelper(node->right, word);
    }

    return node;
}

// Search using BST property
Word *BinaryTree::search(const std::string &name) const
{
    TreeNode *result = searchHelper(root, name);
    return (result != nullptr) ? &(result->word) : nullptr;
}

TreeNode *BinaryTree::searchHelper(TreeNode *node, const std::string &name) const
{
    if (node == nullptr || node->word.getWord() == name)
    {
        return node;
    }

    if (name < node->word.getWord())
    {
        return searchHelper(node->left, name);
    }
    else
    {
        return searchHelper(node->right, name);
    }
}

// Search with timing
long long BinaryTree::searchWithTiming(const std::string &name, Word *&result)
{
    auto start = std::chrono::high_resolution_clock::now();
    result = search(name);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration.count();
}

// Memory usage calculation
int BinaryTree::getMemoryUsage() const
{
    return getMemorySize(root);
}

int BinaryTree::getMemorySize(TreeNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    int currentSize = sizeof(TreeNode);
    currentSize += node->word.getWord().capacity();
    currentSize += node->word.getPartOfSpeech().capacity();
    currentSize += node->word.getDefinition().capacity();

    return currentSize + getMemorySize(node->left) + getMemorySize(node->right);
}

int BinaryTree::getNodeCount() const
{
    return nodeCount;
}

// Inorder traversal
void BinaryTree::inorderTraversal() const
{
    int count = 0;
    inorderHelper(root, count, 10);
    std::cout << "... (showing first 10 words)" << std::endl;
}

void BinaryTree::inorderHelper(TreeNode *node, int &count, int maxCount) const
{
    if (node != nullptr && count < maxCount)
    {
        inorderHelper(node->left, count, maxCount);
        if (count < maxCount)
        {
            std::cout << node->word.getWord() << std::endl;
            count++;
        }
        inorderHelper(node->right, count, maxCount);
    }
}

// Display tree structure
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
    displayTreeHelper(root, "", false, count, 10);
}

void BinaryTree::displayTreeHelper(TreeNode *node, std::string prefix, bool isLeft, int &count, int maxCount) const
{
    if (node == nullptr || count >= maxCount)
    {
        return;
    }

    std::cout << prefix;
    std::cout << (isLeft ? "|--L: " : "+--R: ");
    std::cout << node->word.getWord() << std::endl;
    count++;

    if (count >= maxCount)
    {
        return;
    }

    if (node->left != nullptr || node->right != nullptr)
    {
        if (node->left != nullptr)
        {
            displayTreeHelper(node->left, prefix + (isLeft ? "|   " : "    "), true, count, maxCount);
        }
        if (node->right != nullptr && count < maxCount)
        {
            displayTreeHelper(node->right, prefix + (isLeft ? "|   " : "    "), false, count, maxCount);
        }
    }
}
