#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int wordToNum(char* word){
    if(strcmp(word, "one") == 0) return 1;
    if(strcmp(word, "two") == 0) return 2;
    if(strcmp(word, "three") == 0) return 3;
    if(strcmp(word, "four") == 0) return 4;
    if(strcmp(word, "five") == 0) return 5;
    if(strcmp(word, "six") == 0) return 6;
    if(strcmp(word, "seven") == 0) return 7;
    if(strcmp(word, "eight") == 0) return 8;
    if(strcmp(word, "nine") == 0) return 9;
    return -1;
}

void replaceWordsWithNumbers(char* str){
    char* words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < 9; i++){
        char* ptr = strstr(str, words[i]);
        while(ptr != NULL){
            *ptr = '0' + (i + 1);
            memmove(ptr + 1, ptr + strlen(words[i]), strlen(ptr) - strlen(words[i]) + 1);
            ptr = strstr(str, words[i]);
        }
    }
}

void printFirstAndLastDigit(char* str, int* sum){
    int firstDigitFound = 0;
    char firstDigit, lastDigit;
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            if(!firstDigitFound){
                firstDigit = str[i];
                firstDigitFound = 1;
            }
            lastDigit = str[i];
        }
    }
    if(firstDigitFound){
        printf("%c%c\n", firstDigit, lastDigit);
        char twoDigitStr[3] = {firstDigit, lastDigit, '\0'};
        *sum += atoi(twoDigitStr);
    }
}

int main() {
    FILE* fptr;
    fptr = fopen("input.txt", "r");
    if(fptr == NULL){
        printf("Nie mozna odczytac pliku");
        return 1;
    }

    char str[1000];
    int sum = 0;
    while(fgets(str, 1000, fptr) != NULL){
        replaceWordsWithNumbers(str);
        printFirstAndLastDigit(str, &sum);
        printf("%s", str);
    }

    printf("Suma: %d\n", sum);

    fclose(fptr);
    return 0;
}
