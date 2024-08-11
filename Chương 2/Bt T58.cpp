#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    // Kiểm tra số nguyên tố
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool allDigitsOdd(int n) {
    // Kiểm tra tất cả các chữ số của n có phải là số lẻ
    while (n > 0) {
        if (n % 10 % 2 == 0) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1. Đếm số phần tử có giá trị là số nguyên tố
    int countPrime = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) countPrime++;
    }
    cout << "So phan tu la so nguyen to: " << countPrime << endl;

    // 2. Xuất các phần tử mà từng chữ số của nó là số lẻ
    cout << "Cac phan tu co tat ca chu so la so le: ";
    for (int i = 0; i < n; i++) {
        if (allDigitsOdd(a[i])) cout << a[i] << " ";
    }
    cout << endl;

    // 3. Tìm vị trí số lớn nhất (cuối cùng)
    int maxVal = a[0], maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
            maxIndex = i;
        }
    }
    cout << "Vi tri so lon nhat (cuoi cung): " << maxIndex << endl;

    // 4. Kiểm tra mảng có toàn là số chẵn không?
    bool allEven = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            allEven = false;
            break;
        }
    }
    if (allEven) {
        cout << "Mang toan la so chan" << endl;
    }
    else {
        cout << "Mang khong toan la so chan" << endl;
    }

    // 5. Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẻ không?
    bool isAlternating = true;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == a[i - 1] % 2) {
            isAlternating = false;
            break;
        }
    }
    if (isAlternating) {
        cout << "Mang la day so chan le xen ke" << endl;
    }
    else {
        cout << "Mang khong phai la day so chan le xen ke" << endl;
    }

    return 0;
}
