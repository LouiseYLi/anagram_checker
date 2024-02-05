#include <stdio.h>

// For testing
void printArray(char arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("")
    }
}

void reverseArray(char arr[], int arrSize) {
    char temp;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
}

int main() {
    char c[] = "cool";
    reverseArray(c, 4);
    return 0;
}