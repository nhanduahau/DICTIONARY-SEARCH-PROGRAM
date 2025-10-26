#include "Functions.h"

using namespace std;

// =========================================
// FILE LOADING FUNCTION
// =========================================

/**
 * Loads words from a dictionary file into both data structures
 * Reads pipe-delimited file format: Word|PartOfSpeech|Definition
 * Each successfully parsed line creates a Word object inserted into both BST and Trie
 * @param filename: Path to the dictionary text file
 * @param tree: BinaryTree reference to insert words into
 * @param trie: Trie reference to insert words into
 */
void loadWords(const string &filename, BinaryTree &tree, Trie &trie)
{
    // Open the dictionary file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    string line;
    int count = 0;

    // Read file line by line
    while (getline(file, line))
    {
        stringstream ss(line);
        string word, partOfSpeech, definition;

        // Parse pipe-delimited format: Word|PartOfSpeech|Definition
        if (getline(ss, word, '|') &&
            getline(ss, partOfSpeech, '|') &&
            getline(ss, definition))
        {
            // Create Word object and insert into both data structures
            Word med(word, partOfSpeech, definition);
            tree.insert(med);  // Insert into Binary Search Tree
            trie.insert(med);  // Insert into Trie
            count++;
        }
    }

    file.close();
    
    // Display success message with count
    cout << "Successfully loaded " << count << " words from dictionary!" << endl;
    cout << "========================================" << endl
         << endl;
}

// =========================================
// USER INTERFACE FUNCTIONS
// =========================================

/**
 * Displays the main menu of the program
 * Shows all available operations and prompts for user choice
 */
void displayMenu()
{
    cout << "\n========================================" << endl;
    cout << "     DICTIONARY SEARCH PROGRAM" << endl;
    cout << "========================================" << endl;
    cout << "1. Search for a word" << endl;
    cout << "2. Display Binary Tree structure" << endl;
    cout << "3. Display Trie structure" << endl;
    cout << "4. Compare performance: Binary Tree vs Trie" << endl;
    cout << "5. Display memory usage" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

// =========================================
// SEARCH OPERATIONS
// =========================================

/**
 * Searches for a user-specified word in both data structures
 * Displays results and timing comparison between BST and Trie
 * Shows which structure performed faster for this particular search
 * @param tree: BinaryTree to search in
 * @param trie: Trie to search in
 */
void searchWord(BinaryTree &tree, Trie &trie)
{
    string name;
    cout << "\nEnter word to search: ";
    cin.ignore();
    getline(cin, name);

    cout << "\n--- BINARY TREE SEARCH RESULT ---" << endl;
    Word *resultTree = nullptr;
    long long timeTree = tree.searchWithTiming(name, resultTree);

    if (resultTree != nullptr)
    {
        resultTree->display();
        cout << "Search time: " << timeTree << " nanoseconds" << endl;
    }
    else
    {
        cout << "Word not found in dictionary!" << endl;
    }

    cout << "\n--- TRIE SEARCH RESULT ---" << endl;
    Word *resultTrie = nullptr;
    long long timeTrie = trie.searchWithTiming(name, resultTrie);

    if (resultTrie != nullptr)
    {
        resultTrie->display();
        cout << "Search time: " << timeTrie << " nanoseconds" << endl;
    }
    else
    {
        cout << "Word not found in dictionary!" << endl;
    }

    if (resultTree != nullptr || resultTrie != nullptr)
    {
        cout << "\n--- COMPARISON ---" << endl;
        cout << "Binary Tree: " << timeTree << " ns" << endl;
        cout << "Trie: " << timeTrie << " ns" << endl;
        if (timeTree < timeTrie)
        {
            cout << "Binary Tree is faster by " << (timeTrie - timeTree) << " ns" << endl;
        }
        else
        {
            cout << "Trie is faster by " << (timeTree - timeTrie) << " ns" << endl;
        }
    }
}

// =========================================
// PERFORMANCE COMPARISON
// =========================================

/**
 * Performs batch performance testing on predefined test cases
 * Searches each test word in both structures and compares timing
 * Calculates and displays statistics including averages and winner
 * @param tree: BinaryTree to test
 * @param trie: Trie to test
 * @param testCases: Vector of words to search for
 */
void comparePerformance(BinaryTree &tree, Trie &trie, const vector<string> &testCases)
{
    cout << "\n========================================" << endl;
    cout << "  PERFORMANCE COMPARISON: TREE vs TRIE" << endl;
    cout << "========================================" << endl;

    long long totalTimeTree = 0;
    long long totalTimeTrie = 0;
    int successTree = 0, successTrie = 0;

    cout << "\nPerforming " << testCases.size() << " searches...\n"
         << endl;

    // Display table header
    cout << left << setw(20) << "Word"
         << setw(15) << "Tree (ns)"
         << setw(15) << "Trie (ns)"
         << setw(15) << "Winner" << endl;
    cout << string(65, '-') << endl;

    // Test each word in both structures
    for (const string &testCase : testCases)
    {
        Word *resultTree = nullptr;
        Word *resultTrie = nullptr;

        // Search and time both structures
        long long timeTree = tree.searchWithTiming(testCase, resultTree);
        long long timeTrie = trie.searchWithTiming(testCase, resultTrie);

        // Accumulate totals
        totalTimeTree += timeTree;
        totalTimeTrie += timeTrie;

        // Count successful searches
        if (resultTree != nullptr)
            successTree++;
        if (resultTrie != nullptr)
            successTrie++;

        // Display individual result
        cout << left << setw(20) << testCase
             << setw(15) << timeTree
             << setw(15) << timeTrie;

        // Show winner for this search
        if (timeTree < timeTrie)
        {
            cout << "Tree +" << (timeTrie - timeTree) << " ns";
        }
        else
        {
            cout << "Trie +" << (timeTree - timeTrie) << " ns";
        }
        cout << endl;
    }

    // Display summary statistics
    cout << string(65, '-') << endl;
    cout << "\n--- SUMMARY ---" << endl;
    cout << "Total time (Tree): " << totalTimeTree << " ns" << endl;
    cout << "Total time (Trie): " << totalTimeTrie << " ns" << endl;
    cout << "Average (Tree): " << (totalTimeTree / testCases.size()) << " ns" << endl;
    cout << "Average (Trie): " << (totalTimeTrie / testCases.size()) << " ns" << endl;
    cout << "Found (Tree): " << successTree << "/" << testCases.size() << endl;
    cout << "Found (Trie): " << successTrie << "/" << testCases.size() << endl;

    // Determine overall winner with percentage
    if (totalTimeTree < totalTimeTrie)
    {
        double percent = ((double)(totalTimeTrie - totalTimeTree) / totalTimeTrie) * 100;
        cout << "\n=> Binary Tree is faster than Trie by " << fixed << setprecision(2)
             << percent << "%" << endl;
    }
    else
    {
        double percent = ((double)(totalTimeTree - totalTimeTrie) / totalTimeTree) * 100;
        cout << "\n=> Trie is faster than Binary Tree by " << fixed << setprecision(2)
             << percent << "%" << endl;
    }
}

// =========================================
// MEMORY USAGE ANALYSIS
// =========================================

/**
 * Displays detailed memory usage information for both data structures
 * Shows node count, total memory in bytes and KB, and percentage comparison
 * @param tree: BinaryTree to analyze
 * @param trie: Trie to analyze
 */
void displayMemoryUsage(BinaryTree &tree, Trie &trie)
{
    cout << "\n========================================" << endl;
    cout << "         MEMORY USAGE" << endl;
    cout << "========================================" << endl;

    int treeMemory = tree.getMemoryUsage();
    int trieMemory = trie.getMemoryUsage();

    cout << "Binary Tree:" << endl;
    cout << "  - Number of nodes: " << tree.getNodeCount() << endl;
    cout << "  - Memory used: " << treeMemory << " bytes (~"
         << (treeMemory / 1024.0) << " KB)" << endl;

    cout << "\nTrie:" << endl;
    cout << "  - Number of nodes: " << trie.getNodeCount() << endl;
    cout << "  - Memory used: " << trieMemory << " bytes (~"
         << (trieMemory / 1024.0) << " KB)" << endl;

    cout << "\n--- COMPARISON ---" << endl;
    if (treeMemory < trieMemory)
    {
        double percent = ((double)(trieMemory - treeMemory) / trieMemory) * 100;
        cout << "Binary Tree uses less memory by " << (trieMemory - treeMemory)
             << " bytes (" << fixed << setprecision(2) << percent << "% )" << endl;
    }
    else
    {
        double percent = ((double)(treeMemory - trieMemory) / treeMemory) * 100;
        cout << "Trie uses less memory by " << (treeMemory - trieMemory)
             << " bytes (" << fixed << setprecision(2) << percent << "% )" << endl;
    }
}
