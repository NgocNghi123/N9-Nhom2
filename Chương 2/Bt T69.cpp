#include <iostream>

using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};

// Hàm nhập danh sách các phân số
void nhapDanhSachPhanSo(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ":" << endl;
        cout << "Tu so: ";
        cin >> a[i].tuSo;
        do {
            cout << "Mau so (khac 0): ";
            cin >> a[i].mauSo;
        } while (a[i].mauSo == 0);
    }
}

// Hàm xuất danh sách các phân số
void xuatDanhSachPhanSo(PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].tuSo << "/" << a[i].mauSo << " ";
    }
    cout << endl;
}

// Hàm tìm phân số lớn nhất (tương tự cho phân số nhỏ nhất)
PhanSo timPhanSoLonNhat(PhanSo a[], int n) {
    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].tuSo * max.mauSo > max.tuSo * a[i].mauSo) {
            max = a[i];
        }
    }
    return max;
}

// Hàm tính tổng các phân số (tương tự cho tích)
PhanSo tinhTong(PhanSo a[], int n) {
    PhanSo tong;
    tong.tuSo = 0;
    tong.mauSo = a[0].mauSo;
    for (int i = 0; i < n; i++) {
        tong.tuSo += a[i].tuSo * (tong.mauSo / a[i].mauSo);
        tong.mauSo = tong.mauSo / ucln(tong.mauSo, a[i].mauSo) * a[i].mauSo;
    }
    return tong;
}

// Hàm tính ước chung lớn nhất (UCLN)
int ucln(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Hàm tìm nghịch đảo của một phân số
PhanSo nghichDao(PhanSo ps) {
    PhanSo ketQua;
    ketQua.tuSo = ps.mauSo;
    ketQua.mauSo = ps.tuSo;
    return ketQua;
}

// Hàm sắp xếp mảng phân số tăng dần (sử dụng thuật toán sắp xếp nổi bọt)
void sapXepTangDan(PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].tuSo * a[j].mauSo > a[j].tuSo * a[i].mauSo) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Hàm sắp xếp mảng phân số giảm dần (tương tự)

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PhanSo a[n];

    nhapDanhSachPhanSo(a, n);
    cout << "Danh sach phan so vua nhap: ";
    xuatDanhSachPhanSo(a, n);

    // Gọi các hàm để thực hiện các yêu cầu còn lại

    return 0;
}
