#include <iostream>
#include <cmath>
using namespace std;

bool chuSoDauLe(int n) {
    n = abs(n);
    while (n >= 10) {
        n /= 10;
    }
    return (n % 2 != 0);
}

bool laSoHoanThien(int n) {
    if (n <= 0) return false;
    int tong = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return tong == n;
}

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int tongChuSoDauLe(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chuSoDauLe(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

void lietKeSoHoanThien(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int tongLonHonTriTuyetDoiLienSau(int a[][100], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int tongDongK(int a[][100], int m, int n, int k) {
    if (k < 0 || k >= m) return 0;
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[k][j];
    }
    return tong;
}

int tongBien(int a[][100], int m, int n) {
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[0][j] + a[m-1][j];
    }
    for (int i = 1; i < m - 1; i++) {
        tong += a[i][0] + a[i][n-1];
    }
    return tong;
}

int demTanSuat(int a[][100], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

void demPhanTu(int a[][100], int m, int n, int &chan, int &le, int &am, int &duong, int &nguyenTo) {
    chan = le = am = duong = nguyenTo = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) chan++;
            else le++;
            if (a[i][j] < 0) am++;
            else if (a[i][j] > 0) duong++;
            if (laSoNguyenTo(a[i][j])) nguyenTo++;
        }
    }
}

int main() {
    int a[100][100];
    int m, n, x, k;
    
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Tong cac phan tu co chu so dau la chu so le: " << tongChuSoDauLe(a, m, n) << endl;

    cout << "Cac so hoan thien trong ma tran: ";
    lietKeSoHoanThien(a, m, n);

    cout << "Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: " << tongLonHonTriTuyetDoiLienSau(a, m, n) << endl;

    cout << "Nhap dong k de tinh tong: ";
    cin >> k;
    cout << "Tong gia tri tren dong " << k << " cua ma tran: " << tongDongK(a, m, n, k) << endl;

    cout << "Tong cac gia tri nam tren bien cua ma tran: " << tongBien(a, m, n) << endl;

    cout << "Nhap gia tri x can dem: ";
    cin >> x;
    cout << "Tan suat xuat hien cua " << x << " trong ma tran: " << demTanSuat(a, m, n, x) << endl;

    int chan, le, am, duong, nguyenTo;
    demPhanTu(a, m, n, chan, le, am, duong, nguyenTo);
    cout << "So luong cac phan tu:\n";
    cout << "Chan: " << chan << "\nLe: " << le << "\nAm: " << am << "\nDuong: " << duong << "\nNguyen to: " << nguyenTo << endl;

    return 0;
}
