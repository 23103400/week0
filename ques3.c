#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char paragraph[1000];
    char words[1000][50];
    int freq[1000] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, 1000, stdin);

    // Remove newline character from input if present
    paragraph[strcspn(paragraph, "\n")] = '\0';

    // Tokenize the paragraph by spaces
    char *token = strtok(paragraph, " ");
    while (token != NULL) {
        // Clean the token: convert to lowercase and remove punctuation
        char cleanedWord[50];
        int idx = 0;
        for (int i = 0; token[i] != '\0' && idx < 49; i++) {
            if (isalnum(token[i])) {
                cleanedWord[idx++] = tolower(token[i]);
            }
        }
        cleanedWord[idx] = '\0';

        if (idx == 0) {
            // Skip empty words after cleaning
            token = strtok(NULL, " ");
            continue;
        }

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], cleanedWord) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the list
        if (!found && wordCount < 1000) {
            strcpy(words[wordCount], cleanedWord);
            freq[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ");
    }

    // Print word frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
