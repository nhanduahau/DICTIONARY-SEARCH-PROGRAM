#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "BinaryTree.h"
#include "Trie.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// =========================================
// FILE LOADING
// =========================================

/**
 * Loads words from a dictionary file into both data structures
 * File format: Word|PartOfSpeech|Definition (pipe-delimited)
 * @param filename: Path to the dictionary file
 * @param tree: BinaryTree reference to insert words into
 * @param trie: Trie reference to insert words into
 */
void loadWords(const std::string &filename, BinaryTree &tree, Trie &trie);

// =========================================
// USER INTERFACE
// =========================================

/**
 * Displays the main menu with all available options
 * Shows options for searching, displaying structures, comparing performance, etc.
 */
void displayMenu();

// =========================================
// SEARCH OPERATIONS
// =========================================

/**
 * Prompts user for a word and searches in both data structures
 * Displays results and timing comparison for both BST and Trie
 * @param tree: BinaryTree to search in
 * @param trie: Trie to search in
 */
void searchWord(BinaryTree &tree, Trie &trie);

// =========================================
// PERFORMANCE COMPARISON
// =========================================

/**
 * Runs a batch of test searches and compares performance
 * Measures and displays search times for each structure
 * Calculates averages and determines which structure is faster
 * @param tree: BinaryTree to test
 * @param trie: Trie to test
 * @param testCases: Vector of words to search for
 */
void comparePerformance(BinaryTree &tree, Trie &trie, const std::vector<std::string> &testCases);

// =========================================
// MEMORY ANALYSIS
// =========================================

/**
 * Displays memory usage information for both data structures
 * Shows node count, total memory used, and percentage comparison
 * @param tree: BinaryTree to analyze
 * @param trie: Trie to analyze
 */
void displayMemoryUsage(BinaryTree &tree, Trie &trie);

#endif
