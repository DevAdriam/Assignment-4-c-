#include <stdio.h>
#include <stdlib.h>


void findWords(char findMe[50]);
bool matchedWords(char current[50], char findMe[50]);

int main() {
    char word[50] = "winhtut";
    findWords(word);
    
    return 0;
}

void findWords(char findMe[50]) {
    FILE *fp = fopen("./text.txt", "r");

    int firstCount = 0;
    char first[50] = "winhtut";

    int secondCount = 0;
    char second[50] = "NationalCyberCity";

    if(fp == NULL) {
        printf("File Not Found!\n");

        return;
    } else {
        

        char currentWord[50];

        while (fscanf(fp, "%s", currentWord) != EOF) {
            bool isFirstMatched = matchedWords(currentWord, first);
            bool isSecondMatched = matchedWords(currentWord, second);

            if(isFirstMatched) {
                printf("%s\n", currentWord);
                firstCount++;
            }

            if(isSecondMatched) {
                printf("%s\n", currentWord);
                secondCount++;
            }
        }
        
    }

    fclose(fp);

    printf("==============\n");
    printf("%s: %d\n", first, firstCount);
    printf("%s: %d\n", second, secondCount);
}

bool matchedWords(char current[50], char findMe[50]) {
    int ind = 0;

    while (findMe[ind] != NULL) {
        if(current[ind] != findMe[ind]) {
            return false;
        }

        ind++;
    }
    

    return true;
}

