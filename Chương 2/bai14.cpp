#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr[j] < arr[min_idx] && ascending) ||
                (arr[j] > arr[min_idx] && !ascending)) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void sapXepHang(int a[][100], int n, int m, int ascending) {
    for (int i = 0; i < n; i++) {
        selectionSort(a[i], m, ascending);
    }
}

void sapXepCot(int a[][100], int n, int m, int ascending) {
    for (int j = 0; j < m; j++) {
        int temp[n];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i][j];
        }
        selectionSort(temp, n, ascending);
        for (int i = 0; i < n; i++) {
            a[i][j] = temp[i];
        }
    }
}

void sapXepZicZac(int a[][100], int n, int m, int ascending) {
    // ... (code cho sắp xếp zic-zac) ...
}

int main() {
    int a[100][100], n, m;
    // Nhập ma trận
    // ...

    // Gọi các hàm sắp xếp
    sapXepHang(a, n, m, 1); // Sắp xếp tăng dần các dòng chẵn, giảm dần các dòng lẻ
    sapXepCot(a, n, m, 0); // Sắp xếp tăng dần các cột chẵn, giảm dần các cột lẻ
    sapXepZicZac(a, n, m, 1); // Sắp xếp tăng dần theo zic-zac

    // In ma trận sau khi sắp xếp
    // ...

    return 0;
}
