#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Hàm kiểm tra số hoàn thiện
bool laSoHoanThien(int num) {
    if (num < 1) return false;
    int tong = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) tong += i;
    }
    return tong == num;
}

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm giá trị xuất hiện nhiều nhất
int giaTriXuatHienNhieuNhat(int a[][100], int m, int n) {
    int tanSuat[10000] = {0}, maxCount = 0, ketQua;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            tanSuat[a[i][j]]++;
            if (tanSuat[a[i][j]] > maxCount) {
                maxCount = tanSuat[a[i][j]];
                ketQua = a[i][j];
            }
        }
    }
    return ketQua;
}

int main() {
    int m, n, k;
    printf("Nhap so hang m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);
    
    int a[100][100];
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    // Bài 1: Liệt kê các cột có tổng nhỏ nhất
    int minTongCot = INT_MAX;
    for (int j = 0; j < n; ++j) {
        int tongCot = 0;
        for (int i = 0; i < m; ++i) {
            tongCot += a[i][j];
        }
        if (tongCot < minTongCot) {
            minTongCot = tongCot;
        }
    }
    printf("Cac cot co tong nho nhat: ");
    for (int j = 0; j < n; ++j) {
        int tongCot = 0;
        for (int i = 0; i < m; ++i) {
            tongCot += a[i][j];
        }
        if (tongCot == minTongCot) {
            printf("%d ", j);
        }
    }
    printf("\n");

    // Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất
    int maxSoHoanThien = 0;
    for (int i = 0; i < m; ++i) {
        int soHoanThien = 0;
        for (int j = 0; j < n; ++j) {
            if (laSoHoanThien(a[i][j])) {
                soHoanThien++;
            }
        }
        if (soHoanThien > maxSoHoanThien) {
            maxSoHoanThien = soHoanThien;
        }
    }
    printf("Cac dong co nhieu so hoan thien nhat: ");
    for (int i = 0; i < m; ++i) {
        int soHoanThien = 0;
        for (int j = 0; j < n; ++j) {
            if (laSoHoanThien(a[i][j])) {
                soHoanThien++;
            }
        }
        if (soHoanThien == maxSoHoanThien) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
    printf("Chi so cac dong chua toan gia tri chan: ");
    for (int i = 0; i < m; ++i) {
        bool toanChan = true;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
    int giaTriNhieuNhat = giaTriXuatHienNhieuNhat(a, m, n);
    printf("Gia tri xuat hien nhieu nhat trong ma tran: %d\n", giaTriNhieuNhat);

    // Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
    int minSoNguyenTo = INT_MAX;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(a[i][j]) && a[i][j] < minSoNguyenTo) {
                minSoNguyenTo = a[i][j];
            }
        }
    }
    if (minSoNguyenTo == INT_MAX) {
        printf("Khong co so nguyen to trong ma tran.\n");
    } else {
        printf("So nguyen to nho nhat trong ma tran: %d\n", minSoNguyenTo);
    }

    // Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
    printf("Nhap chi so dong k: ");
    scanf("%d", &k);
    if (k >= 0 && k < m) {
        int maxTrongDong = INT_MIN;
        int minTrongDong = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (a[k][j] > maxTrongDong) {
                maxTrongDong = a[k][j];
            }
            if (a[k][j] < minTrongDong) {
                minTrongDong = a[k][j];
            }
        }
        printf("Phan tu lon nhat trong dong %d: %d\n", k, maxTrongDong);
        printf("Phan tu nho nhat trong dong %d: %d\n", k, minTrongDong);
    } else {
        printf("Chi so dong k khong hop le.\n");
    }

    // Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
    printf("Nhap chi so cot k: ");
    scanf("%d", &k);
    if (k >= 0 && k < n) {
        int maxTrongCot = INT_MIN;
        int minTrongCot = INT_MAX;
        for (int i = 0; i < m; ++i) {
            if (a[i][k] > maxTrongCot) {
                maxTrongCot = a[i][k];
            }
            if (a[i][k] < minTrongCot) {
                minTrongCot = a[i][k];
            }
        }
        printf("Phan tu lon nhat trong cot %d: %d\n", k, maxTrongCot);
        printf("Phan tu nho nhat trong cot %d: %d\n", k, minTrongCot);
    } else {
        printf("Chi so cot k khong hop le.\n");
    }

    return 0;
}
