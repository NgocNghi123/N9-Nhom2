#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct MonHoc {
    string maMon;
    string tenMon;
    int soTinChi;
    float diem;
};

struct SinhVien {
    string maSo;
    string hoTen;
    vector<MonHoc> cacMonHoc;
    float diemTrungBinhTichLuy;
};

void nhapMonHoc(MonHoc &mon) {
    cout << "Nhap ma mon: ";
    cin >> mon.maMon;
    cout << "Nhap ten mon: ";
    cin.ignore();
    getline(cin, mon.tenMon);
    cout << "Nhap so tin chi: ";
    cin >> mon.soTinChi;
    cout << "Nhap diem: ";
    cin >> mon.diem;
}

void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap ma so sinh vien: ";
    cin >> sv.maSo;
    cout << "Nhap ho ten sinh vien: ";
    cin.ignore();
    getline(cin, sv.hoTen);
    int soMon;
    cout << "Nhap so luong mon hoc: ";
    cin >> soMon;
    sv.cacMonHoc.resize(soMon);
    for (int i = 0; i < soMon; ++i) {
        cout << "Nhap thong tin mon hoc thu " << i + 1 << ": " << endl;
        nhapMonHoc(sv.cacMonHoc[i]);
    }
    cout << "Nhap diem trung binh tich luy: ";
    cin >> sv.diemTrungBinhTichLuy;
}

void xuatMonHoc(const MonHoc &mon) {
    cout << "Ma mon: " << mon.maMon << ", Ten mon: " << mon.tenMon
         << ", So tin chi: " << mon.soTinChi << ", Diem: " << mon.diem << endl;
}

void xuatSinhVien(const SinhVien &sv) {
    cout << "Ma so: " << sv.maSo << ", Ho ten: " << sv.hoTen
         << ", Diem trung binh tich luy: " << sv.diemTrungBinhTichLuy << endl;
    for (const auto &mon : sv.cacMonHoc) {
        xuatMonHoc(mon);
    }
}

void nhapDanhSachSinhVien(vector<SinhVien> &danhSach) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    danhSach.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
        nhapSinhVien(danhSach[i]);
    }
}

void xuatDanhSachSinhVien(const vector<SinhVien> &danhSach) {
    for (const auto &sv : danhSach) {
        xuatSinhVien(sv);
    }
}

SinhVien* timSinhVienTheoMa(vector<SinhVien> &danhSach, const string &maSo) {
    for (auto &sv : danhSach) {
        if (sv.maSo == maSo) {
            return &sv;
        }
    }
    return nullptr;
}

SinhVien timSinhVienCoDiemCaoNhat(const vector<SinhVien> &danhSach) {
    return *max_element(danhSach.begin(), danhSach.end(),
                        [](const SinhVien &a, const SinhVien &b) {
                            return a.diemTrungBinhTichLuy < b.diemTrungBinhTichLuy;
                        });
}

void themSinhVien(vector<SinhVien> &danhSach, const SinhVien &sv) {
    danhSach.push_back(sv);
}

void xoaSinhVien(vector<SinhVien> &danhSach, const string &maSo) {
    danhSach.erase(remove_if(danhSach.begin(), danhSach.end(),
                             [&maSo](const SinhVien &sv) { return sv.maSo == maSo; }),
                   danhSach.end());
}

void sapXepSinhVienTangTheoDiemTB(vector<SinhVien> &danhSach) {
    sort(danhSach.begin(), danhSach.end(),
         [](const SinhVien &a, const SinhVien &b) {
             return a.diemTrungBinhTichLuy < b.diemTrungBinhTichLuy;
         });
}

void sapXepSinhVienGiamTheoDiemTB(vector<SinhVien> &danhSach) {
    sort(danhSach.begin(), danhSach.end(),
         [](const SinhVien &a, const SinhVien &b) {
             return a.diemTrungBinhTichLuy > b.diemTrungBinhTichLuy;
         });
}

string xepLoaiHocTap(float diemTB) {
    if (diemTB >= 9.0) return "Xuat sac";
    if (diemTB >= 8.0) return "Gioi";
    if (diemTB >= 7.0) return "Kha";
    if (diemTB >= 6.0) return "TB Kha";
    if (diemTB >= 5.0) return "Trung binh";
    return "Yeu";
}

void thongKeSoMonDauRot(const SinhVien &sv, int &soMonDau, int &soMonRot) {
    soMonDau = 0;
    soMonRot = 0;
    for (const auto &mon : sv.cacMonHoc) {
        if (mon.diem >= 5.0) {
            ++soMonDau;
        } else {
            ++soMonRot;
        }
    }
}

int main() {
    vector<SinhVien> danhSachSinhVien;
    int luaChon;

    do {
        cout << "\n--- Quan ly sinh vien ---\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. Tim sinh vien theo ma so\n";
        cout << "4. Tim sinh vien co diem trung binh cao nhat\n";
        cout << "5. Them sinh vien\n";
        cout << "6. Xoa sinh vien\n";
        cout << "7. Sap xep sinh vien tang theo diem trung binh\n";
        cout << "8. Sap xep sinh vien giam theo diem trung binh\n";
        cout << "9. Xep loai hoc tap cua sinh vien\n";
        cout << "10. Thong ke so mon dau rot\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                nhapDanhSachSinhVien(danhSachSinhVien);
                break;
            case 2:
                xuatDanhSachSinhVien(danhSachSinhVien);
                break;
            case 3: {
                string maSo;
                cout << "Nhap ma so sinh vien can tim: ";
                cin >> maSo;
                SinhVien *sv = timSinhVienTheoMa(danhSachSinhVien, maSo);
                if (sv != nullptr) {
                    xuatSinhVien(*sv);
                } else {
                    cout << "Khong tim thay sinh vien voi ma so: " << maSo << endl;
                }
                break;
            }
            case 4: {
                if (!danhSachSinhVien.empty()) {
                    SinhVien sv = timSinhVienCoDiemCaoNhat(danhSachSinhVien);
                    cout << "Sinh vien co diem trung binh cao nhat: " << endl;
                    xuatSinhVien(sv);
                } else {
                    cout << "Danh sach sinh vien rong." << endl;
                }
                break;
            }
            case 5: {
                SinhVien sv;
                cout << "Nhap thong tin sinh vien moi: " << endl;
                nhapSinhVien(sv);
                themSinhVien(danhSachSinhVien, sv);
                break;
            }
            case 6: {
                string maSo;
                cout << "Nhap ma so sinh vien can xoa: ";
                cin >> maSo;
                xoaSinhVien(danhSachSinhVien, maSo);
                break;
            }
            case 7:
                sapXepSinhVienTangTheoDiemTB(danhSachSinhVien);
                break;
            case 8:
                sapXepSinhVienGiamTheoDiemTB(danhSachSinhVien);
                break;
            case 9: {
                for (const auto &sv : danhSachSinhVien) {
                    cout << "Sinh vien: " << sv.hoTen << ", Xep loai: " << xepLoaiHocTap(sv.diemTrungBinhTichLuy) << endl;
                }
                break;
            }
            case 10: {
                for (const auto &sv : danhSachSinhVien) {
                    int soMonDau, soMonRot;
                    thongKeSoMonDauRot(sv, soMonDau, soMonRot);
                    cout << "Sinh vien: " << sv.hoTen << ", So mon dau: " << soMonDau << ", So mon rot: " << soMonRot << endl;
                }
                break;
            }
            return 0;
