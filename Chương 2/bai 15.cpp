#include <stdio.h>

#define MAX_SIZE 100 // Kích thước tối đa của ma trận

int tinhTongDuongCheoChinh(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int tinhTongDuongCheoPhu(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - i - 1];
    }
    return sum;
}

int tinhTongPhiaTrenDuongCheoChinh(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int tinhTongPhiaTrenDuongCheoPhu(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap cap cua ma tran: ");
    scanf("%d", &n);

    int matrix[MAX_SIZE][MAX_SIZE];
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tinhTongDuongCheoChinh(matrix, n));
    printf("Tong cac phan tu tren duong cheo phu: %d\n", tinhTongDuongCheoPhu(matrix, n));
    printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", tinhTongPhiaTrenDuongCheoChinh(matrix, n));
    printf("Tong cac phan tu phia tren duong cheo phu: %d\n", tinhTongPhiaTrenDuongCheoPhu(matrix, n));

    return 0;
}
