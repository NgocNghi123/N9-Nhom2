#include <iostream>

using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};

// Hàm nhập phân số
void nhapPhanSo(PhanSo& ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tuSo;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mauSo;
    } while (ps.mauSo == 0);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
    cout << ps.tuSo << "/" << ps.mauSo << endl;
}

// Hàm tối giản phân số
void toiGianPhanSo(PhanSo& ps) {
    int ucln = 1;
    for (int i = 2; i <= min(abs(ps.tuSo), abs(ps.mauSo)); i++) {
        if (ps.tuSo % i == 0 && ps.mauSo % i == 0) {
            ucln = i;
        }
    }
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
}

// Hàm tính ước số chung lớn nhất (UCLN)
int ucln(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Các phép toán trên phân số
PhanSo cong(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

PhanSo tru(PhanSo ps1, PhanSo ps2) {
    // Tương tự như phép cộng, chỉ thay dấu cộng thành dấu trừ
}

PhanSo nhan(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

PhanSo chia(PhanSo ps1, PhanSo ps2) {
    // Kiểm tra mẫu số của phân số thứ hai có bằng 0 không
    if (ps2.mauSo == 0) {
        cout << "Khong the chia cho 0!" << endl;
        exit(1);
    }
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    toiGianPhanSo(ketQua);
    return ketQua;
}

int main() {
    PhanSo ps1, ps2, tong, hieu, tich, thuong;

    cout << "Nhap phan so thu nhat:\n";
    nhapPhanSo(ps1);

    cout << "Nhap phan so thu hai:\n";
    nhapPhanSo(ps2);

    tong = cong(ps1, ps2);
    hieu = tru(ps1, ps2);
    tich = nhan(ps1, ps2);
    thuong = chia(ps1, ps2);

    cout << "Tong hai phan so: ";
    xuatPhanSo(tong);

    cout << "Hieu hai phan so: ";
    xuatPhanSo(hieu);

    cout << "Tich hai phan so: ";
    xuatPhanSo(tich);

    cout << "Thuong hai phan so: ";
    xuatPhanSo(thuong);

    return 0;
}
