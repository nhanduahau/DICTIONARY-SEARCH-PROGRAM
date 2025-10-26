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

// Load words from a file into both data structures
void loadWords(const std::string &filename, BinaryTree &tree, Trie &trie);

// Display the main menu
void displayMenu();

// Prompt user and search a word in both data structures (prints results)
void searchWord(BinaryTree &tree, Trie &trie);

// Run a batch of searches and compare performance between tree and trie
void comparePerformance(BinaryTree &tree, Trie &trie, const std::vector<std::string> &testCases);

// Display memory usage info for both data structures
void displayMemoryUsage(BinaryTree &tree, Trie &trie);

#endif
