#include "Main.h"

using namespace std;

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