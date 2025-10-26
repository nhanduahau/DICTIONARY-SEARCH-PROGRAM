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
projectFinal/
├── main.cpp              # Main program and menu system
├── BinaryTree.h          # BST class declaration
├── BinaryTree.cpp        # BST implementation
├── Trie.h                # Trie class declaration
├── Trie.cpp              # Trie implementation
├── Word.h                # Word class declaration
├── Word.cpp              # Word class implementation
├── dictionary.txt        # Dictionary data file
└── README.md             # This file
```

## 🔧 Requirements

- **Compiler**: C++11 or higher
- **Operating System**: Windows/Linux/macOS
- **Libraries**: Standard C++ Library (no external dependencies)

## 🚀 Installation

### 1. Compile the Program

#### Using g++:

```powershell
g++ -std=c++11 main.cpp BinaryTree.cpp Trie.cpp Word.cpp -o dictionary_search
```

#### Using MSVC (Visual Studio):

```powershell
cl /EHsc main.cpp BinaryTree.cpp Trie.cpp Word.cpp /Fe:dictionary_search.exe
```

### 2. Run the Program

```powershell
.\dictionary_search
```

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

### Word Class

- Stores word, part of speech, and definition
- Implements comparison operators for BST ordering

### TreeNode Class

- Represents a node in the BST
- Contains Word object and left/right pointers

### TrieNode Class

- Represents a node in the Trie
- Uses `unordered_map<char, TrieNode*>` for children
- Stores Word pointer at end-of-word nodes

### BinaryTree Class

- Implements BST with standard insert and search
- Provides performance timing and memory analysis

### Trie Class

- Implements prefix tree with character-by-character storage
- Case-insensitive search capability
- Optimized memory usage with unordered_map

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
- **Institution**: TXST

## 🐛 Known Limitations

- Tree structure display limited to first 10 words (for readability)
- BST not self-balancing (AVL or Red-Black tree could improve worst-case performance)
- Trie memory usage is higher due to character-level storage

## 🔮 Future Improvements

- [ ] Implement AVL or Red-Black tree for balanced BST
- [ ] Add autocomplete functionality using Trie
- [ ] Support for fuzzy search
- [ ] Export performance metrics to CSV
- [ ] GUI interface
- [ ] Additional data structures (Hash Table, B-Tree)

## 📄 License

This is an educational project for CS 3358 course.

## 👤 Author

Ly Huu Nhan To - Harry To

---

**Note**: Ensure `dictionary.txt` is in the same directory as the executable when running the program.
