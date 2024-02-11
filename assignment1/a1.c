//A01079256 A01377263 A01378046

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int isAnagram(FILE *input, FILE *output) {
    int charOfWord[26] = {0};
    int charOfAnagram[26] = {0};



    int index = 0;
    char inputChar;
    while (inputChar != '\n') {
        if (inputChar == EOF) {
            fprintf(output, "error");
            exit(0);
        }
        inputChar = fgetc(input);
        index++;
    }
    char *firstString = malloc(index * sizeof(char));
    
    fseek(input, 0, SEEK_SET);

    fgets(firstString, index, input);

    int index2 = index + 1;

    fgetc(input);

    while (inputChar != EOF) {

        inputChar = fgetc(input);

        if (inputChar == '\n') {
            fprintf(output, "error");
            exit(0);
        }

        index2++;
    }

    fseek(input, index, SEEK_SET);

    index2 -= index;
    char *secondString = malloc((index2) * sizeof(char));

    fgets(secondString, index2, input);

    for (int i = 0; i < index; i++) {
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


    FILE *output = fopen(outputFile, "w");
    if (output == NULL) {
        fprintf(output, "error");
        exit(0);
    }

    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        fprintf(output, "error");
        exit(0);
    }

    if (argc != 3) {
        fprintf(output, "error");
        exit(0);
    }

    isAnagram(input, output);

    fclose(input);
    fclose(output);
    return 0;
}