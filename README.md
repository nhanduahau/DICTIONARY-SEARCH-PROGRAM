# Dictionary Search Program

A C++ implementation comparing the performance and memory efficiency of **Binary Search Tree (BST)** and **Trie** data structures for dictionary word lookups.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Data Structures](#data-structures)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Performance Comparison](#performance-comparison)
- [File Format](#file-format)
- [Example Output](#example-output)
- [Class Structure](#class-structure)
- [Educational Value](#educational-value)
- [Course Information](#course-information)

## 🎯 Overview

This program implements a dictionary search system using two different data structures:

- **Binary Search Tree (BST)**: Traditional tree-based approach
- **Trie (Prefix Tree)**: Optimized for string searching

The program loads a dictionary from a text file and allows users to search for words while comparing the performance metrics of both data structures in terms of search time and memory usage.

## ✨ Features

- **Dual Data Structure Implementation**: Compare BST and Trie side-by-side
- **Word Search**: Look up word definitions with part of speech
- **Performance Metrics**:
  - Search time comparison (in nanoseconds)
  - Memory usage analysis
  - Batch performance testing
- **Visual Structure Display**: View tree and trie structures
- **Case-Insensitive Search**: Trie implementation supports case-insensitive lookups
- **Interactive Menu**: User-friendly command-line interface

## 🌳 Data Structures

### Binary Search Tree (BST)

- **Time Complexity**: O(log n) average, O(n) worst case
- **Space Complexity**: O(n)
- Stores complete word objects at each node
- Efficient for sorted data traversal

### Trie (Prefix Tree)

- **Time Complexity**: O(m) where m is the length of the word
- **Space Complexity**: O(ALPHABET_SIZE × N × M)
- Uses `unordered_map` for memory efficiency
- Optimized for prefix-based searches and autocomplete
- Consistent search time regardless of dictionary size

## 📁 Project Structure

```
DICTIONARY-SEARCH-PROGRAM/
├── main.cpp              # Main program entry point and menu system
├── Main.h                # Main header with constants
├── Functions.h           # Function declarations for utilities
├── Functions.cpp         # Function implementations (load, search, compare)
├── BinaryTree.h          # BST class declaration
├── BinaryTree.cpp        # BST implementation with level-order insertion
├── Trie.h                # Trie class declaration
├── Trie.cpp              # Trie implementation with unordered_map
├── Word.h                # Word class declaration
├── Word.cpp              # Word class implementation
├── dictionary.txt        # Dictionary data file (109,999 words)
└── README.md             # Project documentation
```

## 🔧 Requirements

- **Compiler**: C++11 or higher
- **Operating System**: Windows/Linux/macOS
- **Libraries**: Standard C++ Library (no external dependencies)

## 🚀 Installation

### 1. Clone or Download the Project

```powershell
cd "d:\ACC-TXST\2025 - Fall\CS 3358\DICTIONARY-SEARCH-PROGRAM"
```

### 2. Compile the Program

#### Using g++ (MinGW on Windows):

```powershell
g++ -std=c++11 main.cpp BinaryTree.cpp Trie.cpp Word.cpp Functions.cpp -o dictionary_search.exe
```

#### Using MSVC (Visual Studio):

```powershell
cl /EHsc /std:c++17 main.cpp BinaryTree.cpp Trie.cpp Word.cpp Functions.cpp /Fe:dictionary_search.exe
```

### 3. Run the Program

```powershell
.\dictionary_search.exe
```

**Note**: Ensure `dictionary.txt` is in the same directory as the executable.

## 💻 Usage

### Menu Options

```
========================================
     DICTIONARY SEARCH PROGRAM
========================================
1. Search for a word
2. Display Binary Tree structure
3. Display Trie structure
4. Compare performance: Binary Tree vs Trie
5. Display memory usage
0. Exit
========================================
```

### 1. Search for a Word

- Enter a word to search in the dictionary
- View results from both BST and Trie
- Compare search times between both structures

### 2. Display Binary Tree Structure

- Visualize the BST structure (first 10 words)
- Shows left and right child relationships

### 3. Display Trie Structure

- Visualize the Trie prefix tree (first 10 words)
- Shows character-by-character breakdown

### 4. Compare Performance

- Runs 10 predefined test cases
- Shows individual search times
- Provides statistical summary and winner

### 5. Display Memory Usage

- Shows memory consumption for each structure
- Displays node count
- Calculates percentage difference

## 📊 Performance Comparison

### Expected Results

| Metric                  | Binary Search Tree                 | Trie                             |
| ----------------------- | ---------------------------------- | -------------------------------- |
| **Average Search Time** | ~100-500 ns                        | ~50-200 ns                       |
| **Memory Usage**        | Lower                              | Higher                           |
| **Best Use Case**       | Smaller dictionaries               | Large dictionaries, autocomplete |
| **Consistency**         | Variable (depends on tree balance) | Consistent                       |

### Test Cases Included

- Awfully
- Chirographer
- Luminate
- Hexastich
- Preoccupy
- Stanzaic
- Whot
- Restorationism
- Inkhornism
- Copper-nickel

## 📝 File Format

The `dictionary.txt` file uses pipe-delimited format:

```
Word|Part of Speech|Definition
```

**Example:**

```
Aam|n.|A Dutch and German measure of liquids
Aard-vark|n.|An edentate mammal, of the genus Orycteropus
```

## 📖 Example Output

```
========================================
  DICTIONARY SEARCH PROGRAM INITIALIZED
========================================
Successfully loaded 109999 words from dictionary!
========================================

--- BINARY TREE SEARCH RESULT ---
Word: Awfully
Part of Speech: adv.
Definition: In an awful manner; in a manner to fill with terror or awe...
Search time: 342 nanoseconds

--- TRIE SEARCH RESULT ---
Word: Awfully
Part of Speech: adv.
Definition: In an awful manner; in a manner to fill with terror or awe...
Search time: 156 nanoseconds

--- COMPARISON ---
Binary Tree: 342 ns
Trie: 156 ns
=> Trie is faster by 54.39%
```

## 🧪 Class Structure

### Word Class (`Word.h`, `Word.cpp`)

- **Attributes**:
  - `std::string name` - The word itself
  - `std::string partOfSpeech` - Grammatical classification
  - `std::string definition` - Word meaning
- **Methods**:
  - Constructors (default and parameterized)
  - Comparison operators (`<`, `>`, `==`) for BST ordering
  - Getters and display methods

### TreeNode Class (`BinaryTree.h`)

- **Attributes**:
  - `Word word` - Word data object
  - `TreeNode* left` - Left child pointer
  - `TreeNode* right` - Right child pointer
- **Purpose**: Node structure for Binary Search Tree

### BinaryTree Class (`BinaryTree.h`, `BinaryTree.cpp`)

- **Private Members**:
  - `TreeNode* root` - Root of the tree
  - `int nodeCount` - Total number of nodes
- **Key Methods**:
  - `void insert(const Word& word)` - Level-order insertion (complete binary tree)
  - `Word* search(const std::string& name)` - Search for a word
  - `long long searchWithTiming(...)` - Search with performance measurement (nanoseconds)
  - `int getMemoryUsage()` - Calculate memory footprint
  - `void displayTree()` - Visual tree structure (first 10 words)
- **Complexity**:
  - Insert: O(log n) average
  - Search: O(log n) average, O(n) worst case

### TrieNode Class (`Trie.h`)

- **Attributes**:
  - `std::unordered_map<char, TrieNode*> children` - Child nodes mapped by character
  - `Word* word` - Pointer to word data (nullptr if not end of word)
  - `bool isEndOfWord` - Flag indicating complete word
- **Purpose**: Node structure for Trie (Prefix Tree)

### Trie Class (`Trie.h`, `Trie.cpp`)

- **Private Members**:
  - `TrieNode* root` - Root of the trie
  - `int nodeCount` - Total number of nodes
- **Key Methods**:
  - `void insert(const Word& word)` - Character-by-character insertion
  - `Word* search(const std::string& name)` - Case-insensitive prefix search
  - `long long searchWithTiming(...)` - Search with performance measurement (nanoseconds)
  - `int getMemoryUsage()` - Calculate memory footprint
  - `void displayTree()` - Visual trie structure (first 10 words)
- **Complexity**:
  - Insert: O(m) where m = word length
  - Search: O(m) where m = word length

### Functions Module (`Functions.h`, `Functions.cpp`)

- `void loadWords(filename, tree, trie)` - Parse dictionary.txt and populate both structures
- `void displayMenu()` - Show interactive menu options
- `void searchWord(tree, trie)` - User input search with side-by-side comparison
- `void comparePerformance(tree, trie, testCases)` - Batch testing with 10 predefined words
- `void displayMemoryUsage(tree, trie)` - Memory analysis and comparison

## 🎓 Educational Value

This project demonstrates:

- **Data Structure Comparison**: Real-world performance differences
- **Algorithm Analysis**: Time vs space tradeoffs
- **Memory Management**: Dynamic allocation and cleanup
- **C++ Best Practices**: Classes, encapsulation, RAII
- **Performance Measurement**: Using `<chrono>` for precise timing

## 📚 Course Information

- **Course**: CS 3358 - Data Structures
- **Semester**: Fall 2025
- **Institution**: ACC-TXST (Austin Community College - Texas State University)
- **Project Type**: Final Project - Data Structure Comparison Study

## 🐛 Known Limitations

- Tree structure display limited to first 10 words for readability
- BST uses level-order insertion (not self-balancing like AVL or Red-Black tree)
- Trie memory usage is significantly higher due to character-level storage
- Case sensitivity: BST is case-sensitive, Trie is case-insensitive

## 🔮 Future Improvements

- [ ] Implement AVL or Red-Black tree for balanced BST
- [ ] Add autocomplete functionality using Trie prefix search
- [ ] Support for fuzzy search and spell-checking
- [ ] Export performance metrics to CSV or JSON
- [ ] GUI interface with graphical tree visualization
- [ ] Additional data structures (Hash Table, B-Tree, Skip List)
- [ ] Support for multiple dictionaries and languages
- [ ] Add word frequency analysis

## 📄 License

This is an educational project for CS 3358 course at ACC-TXST.

## 👤 Author

**Ly Huu Nhan To (Harry To)**

- GitHub: [@nhanduahau](https://github.com/nhanduahau)
- Repository: [DICTIONARY-SEARCH-PROGRAM](https://github.com/nhanduahau/DICTIONARY-SEARCH-PROGRAM)

---

**Last Updated**: October 26, 2025

**Note**: Ensure `dictionary.txt` is in the same directory as the executable when running the program.
