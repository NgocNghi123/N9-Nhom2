#include <iostream>

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

bool isPalindrome(int arr[], int n) {
    // Kiểm tra mảng đối xứng
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isIncreasing(int arr[], int n) {
    // Kiểm tra mảng tăng dần
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isDecreasing(int arr[], int n) {
    // Kiểm tra mảng giảm dần
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
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

    // 1. Kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
    bool allPrime = true;
    for (int i = 0; i < n; i++) {
        if (!isPrime(a[i])) {
            allPrime = false;
            break;
        }
    }
    if (allPrime) {
        cout << "Mang chi chua cac so nguyen to." << endl;
    }
    else {
        cout << "Mang co chua so khong phai so nguyen to." << endl;
    }

    // 2. Kiểm tra mảng có đối xứng hay không
    if (isPalindrome(a, n)) {
        cout << "Mang doi xung." << endl;
    }
    else {
        cout << "Mang khong doi xung." << endl;
    }

    // 3. Kiểm tra mảng có tăng dần/giảm dần/không tăng không giảm
    if (isIncreasing(a, n)) {
        cout << "Mang tang dan." << endl;
    }
    else if (isDecreasing(a, n)) {
        cout << "Mang giam dan." << endl;
    }
    else {
        cout << "Mang khong tang khong giam." << endl;
    }

    return 0;
}
