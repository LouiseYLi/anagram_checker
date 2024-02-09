#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int isAnagram(FILE *input, FILE *output) {
    int charOfWord[26] = {0};
    int charOfAnagram[26] = {0};



    int index = 0;
    char inputChar;
    while (inputChar != '\n') {
        inputChar = fgetc(input);

        index++;
    }
    char *firstString = malloc(index * sizeof(char));
    
    fseek(input, 0, SEEK_SET);

    fgets(firstString, index, input);

    int index2 = index + 1;
    while (inputChar != EOF) {
        inputChar = fgetc(input);

        index2++;
    }

    fseek(input, index, SEEK_SET);

    index2 -= index;
    char *secondString = malloc((index2) * sizeof(char));

    fgets(secondString, index2, input);

    printf("first: %s second: %s\n", firstString,secondString);

    for (int i = 0; i < index; i++) {
        printf("%c\n", firstString[i]);
        if (firstString[i] >= 'a' && firstString[i] <= 'z') {
            charOfWord[firstString[i] - 'a']++;
        }
        else if (firstString[i] >= 'A' && firstString[i] <= 'Z') {
            charOfWord[firstString[i] - 'A']++;
        }
    }

    for (int i = 0; i < index; i++) {
        if (secondString[i] >= 'a' && secondString[i] <= 'z') {
            charOfAnagram[secondString[i] - 'a']++;
        }
        else if (secondString[i] >= 'A' && secondString[i] <= 'Z') {
            charOfAnagram[secondString[i] - 'A']++;
        }
    }

    free(firstString);
    free(secondString);

    for (int i = 0; i < 26; i++) {
        printf("first: %d second: %d\n", charOfWord[i], charOfAnagram[i]);
        if(charOfWord[i] != charOfAnagram[i]) {
            fprintf(output, "0! not anagram");
            return 0;
        }
    }

    fprintf(output, "1! anagram");
    return 1;
}

int main(int argc, char **argv){
    char *inputFile = argv[1];
    char *outputFile = argv[2];

    FILE *input = fopen(inputFile, "r");

    FILE *output = fopen(outputFile, "w");

    isAnagram(input, output);

    fclose(input);
    fclose(output);
}