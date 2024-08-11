#include <iostream>
#include <string>

using namespace std;

template <typename T>
void interchangeSortTang(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
void interchangeSortGiam(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    // Ví dụ với mảng số nguyên
    int arr1[] = { 5, 2, 8, 1, 9 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    interchangeSortTang(arr1, n1);

    cout << "Mang sau khi sap xep tang dan: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Ví dụ với mảng chuỗi ký tự
    string arr2[] = { "apple", "banana", "cherry", "date" };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    interchangeSortGiam(arr2, n2);

    cout << "Mang sau khi sap xep giam dan: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
