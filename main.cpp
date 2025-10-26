#include "BinaryTree.h"
#include "Trie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

// Function to load words from file
void loadWords(const string &filename, BinaryTree &tree, Trie &trie)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(file, line))
    {
        stringstream ss(line);
        string word, partOfSpeech, definition;

        if (getline(ss, word, '|') &&
            getline(ss, partOfSpeech, '|') &&
            getline(ss, definition))
        {

            Word med(word, partOfSpeech, definition);
            tree.insert(med);
            trie.insert(med);
            count++;
        }
    }

    file.close();
    cout << "Successfully loaded " << count << " words from dictionary!" << endl;
    cout << "========================================" << endl
         << endl;
}

// Function to display menu
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

// Function to search word
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

// Function to compare performance
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

    cout << left << setw(20) << "Word"
         << setw(15) << "Tree (ns)"
         << setw(15) << "Trie (ns)"
         << setw(15) << "Winner" << endl;
    cout << string(65, '-') << endl;

    for (const string &testCase : testCases)
    {
        Word *resultTree = nullptr;
        Word *resultTrie = nullptr;

        long long timeTree = tree.searchWithTiming(testCase, resultTree);
        long long timeTrie = trie.searchWithTiming(testCase, resultTrie);

        totalTimeTree += timeTree;
        totalTimeTrie += timeTrie;

        if (resultTree != nullptr)
            successTree++;
        if (resultTrie != nullptr)
            successTrie++;

        cout << left << setw(20) << testCase
             << setw(15) << timeTree
             << setw(15) << timeTrie;

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

    cout << string(65, '-') << endl;
    cout << "\n--- SUMMARY ---" << endl;
    cout << "Total time (Tree): " << totalTimeTree << " ns" << endl;
    cout << "Total time (Trie): " << totalTimeTrie << " ns" << endl;
    cout << "Average (Tree): " << (totalTimeTree / testCases.size()) << " ns" << endl;
    cout << "Average (Trie): " << (totalTimeTrie / testCases.size()) << " ns" << endl;
    cout << "Found (Tree): " << successTree << "/" << testCases.size() << endl;
    cout << "Found (Trie): " << successTrie << "/" << testCases.size() << endl;

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

// Function to display memory usage
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
             << " bytes (" << fixed << setprecision(2) << percent << "%)" << endl;
    }
    else
    {
        double percent = ((double)(treeMemory - trieMemory) / treeMemory) * 100;
        cout << "Trie uses less memory by " << (treeMemory - trieMemory)
             << " bytes (" << fixed << setprecision(2) << percent << "%)" << endl;
    }
}

int main()
{
    BinaryTree tree;
    Trie trie;

    cout << "========================================" << endl;
    cout << "  DICTIONARY SEARCH PROGRAM INITIALIZED" << endl;
    cout << "========================================" << endl;

    // Load words from file
    loadWords("dictionary.txt", tree, trie);

    // Test cases for performance comparison - words that exist in the dictionary
    vector<string> testCases = {
        "Awfully", "Chirographer", "Luminate", "Hexastich", "Preoccupy",
        "Stanzaic", "Whot", "Restorationism", "Inkhornism", "Copper-nickel"};

    int choice;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            searchWord(tree, trie);
            break;
        case 2:
            cout << "\n--- BINARY TREE STRUCTURE ---" << endl;
            tree.displayTree();
            break;
        case 3:
            cout << "\n--- TRIE STRUCTURE ---" << endl;
            trie.displayTree();
            break;
        case 4:
            comparePerformance(tree, trie, testCases);
            break;
        case 5:
            displayMemoryUsage(tree, trie);
            break;
        case 0:
            cout << "\nThank you for using the program!" << endl;
            break;
        default:
            cout << "\nInvalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
