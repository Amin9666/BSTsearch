#include "redBlackTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void displayMenu() {
    printf("\n--- Dictionary Menu ---\n");
    printf("1. Add a new word\n");
    printf("2. Search for a word\n");
    printf("3. Display all words (alphabetical order)\n");
    printf("4. Display all words (reverse order)\n");
    printf("5. Load dictionary from CSV\n");
    printf("6. Exit\n");
    printf("-----------------------\n");
    printf("Enter your choice: ");
}

void loadDictionaryFromCSV(RBTree *tree, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, ",");
        char *meaning = strtok(NULL, "\n");
        if (word && meaning) {
            insertRBTree(tree, word, meaning);
        }
    }

    fclose(file);
    printf("Dictionary loaded successfully from %s\n", filename);
}

void addNewWord(RBTree *tree) {
    char word[100], meaning[256];
    printf("Enter the new word: ");
    scanf(" %[^\n]s", word);
    printf("Enter the meaning: ");
    scanf(" %[^\n]s", meaning);
    insertRBTree(tree, word, meaning);
    printf("Word '%s' added successfully.\n", word);
}

void searchForWord(RBTree *tree) {
    char word[100];
    printf("Enter the word to search: ");
    scanf(" %[^\n]s", word);
    Node *result = searchRBTree(tree, word);
    if (result && strcmp(result->key, word) == 0) {
        printf("Meaning of '%s': %s\n", result->key, result->value);
    } else {
        printf("Word '%s' not found in the dictionary.\n", word);
    }
}

void displayAlphabetical(RBTree *tree) {
    printf("\nDictionary (Alphabetical Order):\n");
    inOrderTraversal(tree, tree->root);
}

void displayReverseOrder(RBTree *tree) {
    printf("\nDictionary (Reverse Order):\n");
    reverseOrderTraversal(tree, tree->root);
}

int main() {
    RBTree *dictionary = createRBTree();
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewWord(dictionary);
                break;
            case 2:
                searchForWord(dictionary);
                break;
            case 3:
                displayAlphabetical(dictionary);
                break;
            case 4:
                displayReverseOrder(dictionary);
                break;
            case 5:
                loadDictionaryFromCSV(dictionary, "data_structure_terms.csv");
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}