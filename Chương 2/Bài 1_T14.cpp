#include <stdio.h>

int main()
{
    // Bài 1: Dãy số
    int numbers[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Các số cần tìm ở bài 1
    int findNumbers[] = { 17, 35, 40, 23, 10, 36 };
    int findSize = sizeof(findNumbers) / sizeof(findNumbers[0]);

    // Tìm các số trong dãy
    printf_s("Bài 1:\n");
    for (int i = 0; i < findSize; i++) {
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (findNumbers[i] == numbers[j]) {
                printf_s("%d có trong dãy\n", findNumbers[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf_s("%d không có trong dãy\n", findNumbers[i]);
        }
    }
}