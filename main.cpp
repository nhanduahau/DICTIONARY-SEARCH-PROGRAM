/**
 * DICTIONARY SEARCH PROGRAM
 *
 * This program demonstrates and compares two fundamental data structures
 * for dictionary word lookups:
 * 1. Binary Search Tree (BST) - Traditional tree-based approach
 * 2. Trie (Prefix Tree) - Optimized for string searching
 *
 * Features:
 * - Load dictionary from file into both structures
 * - Search for words with timing comparison
 * - Display visual representations of both structures
 * - Performance comparison with multiple test cases
 * - Memory usage analysis and comparison
 *
 * Course: CS 3358 - Data Structures
 * Semester: Fall 2025
 */

#include "Main.h"

using namespace std;

/**
 * Main program entry point
 * Initializes both data structures, loads dictionary, and runs menu loop
 */
int main()
{
    // Initialize both data structures
    BinaryTree tree; // Binary Search Tree
    Trie trie;       // Trie (Prefix Tree)

    // Display welcome banner
    cout << "========================================" << endl;
    cout << "  DICTIONARY SEARCH PROGRAM INITIALIZED" << endl;
    cout << "========================================" << endl;

    // Load dictionary words into both structures
    loadWords("dictionary.txt", tree, trie);

    // Test cases for performance comparison
    // These are pre-selected words that exist in the dictionary
    vector<string> testCases = {
        "Awfully", "Chirographer", "Luminate", "Hexastich", "Preoccupy",
        "Stanzaic", "Whot", "Restorationism", "Inkhornism", "Copper-nickel"};

    int choice;

    // Main program loop - display menu and process user choices
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1: // Search for a word
            searchWord(tree, trie);
            break;

        case 2: // Display Binary Tree structure
            cout << "\n--- BINARY TREE STRUCTURE ---" << endl;
            tree.displayTree();
            break;

        case 3: // Display Trie structure
            cout << "\n--- TRIE STRUCTURE ---" << endl;
            trie.displayTree();
            break;

        case 4: // Compare performance
            comparePerformance(tree, trie, testCases);
            break;

        case 5: // Display memory usage
            displayMemoryUsage(tree, trie);
            break;

        case 0: // Exit program
            cout << "\nThank you for using the program!" << endl;
            break;

        default: // Invalid choice
            cout << "\nInvalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}