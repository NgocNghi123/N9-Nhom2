#include <stdio.h>

// Khai báo cấu trúc phân số
typedef struct {
    int tu;   // tử số
    int mau;  // mẫu số
} PhanSo;

// Hàm nhập danh sách các phân số
void nhapDanhSachPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap tu so cua phan so thu %d: ", i + 1);
        scanf("%d", &ps[i].tu);
        printf("Nhap mau so cua phan so thu %d: ", i + 1);
        scanf("%d", &ps[i].mau);
    }
}

// Hàm xuất danh sách các phân số
void xuatDanhSachPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ps[i].tu, ps[i].mau);
    }
    printf("\n");
}

// Hàm tìm phân số có giá trị lớn nhất
PhanSo timPhanSoLonNhat(PhanSo ps[], int n) {
    PhanSo max = ps[0];
    for (int i = 1; i < n; i++) {
        if ((float)ps[i].tu / ps[i].mau > (float)max.tu / max.mau) {
            max = ps[i];
        }
    }
    return max;
}

// Hàm tìm phân số có giá trị nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo ps[], int n) {
    PhanSo min = ps[0];
    for (int i = 1; i < n; i++) {
        if ((float)ps[i].tu / ps[i].mau < (float)min.tu / min.mau) {
            min = ps[i];
        }
    }
    return min;
}

// Hàm tính tổng các phân số
PhanSo tinhTongPhanSo(PhanSo ps[], int n) {
    PhanSo tong = {0, 1};
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * ps[i].mau + ps[i].tu * tong.mau;
        tong.mau *= ps[i].mau;
    }
    return tong;
}

// Hàm tính tích các phân số
PhanSo tinhTichPhanSo(PhanSo ps[], int n) {
    PhanSo tich = {1, 1};
    for (int i = 0; i < n; i++) {
        tich.tu *= ps[i].tu;
        tich.mau *= ps[i].mau;
    }
    return tich;
}

// Hàm xuất ra nghịch đảo giá trị các phân số
void xuatNghichDaoPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ps[i].mau, ps[i].tu);
    }
    printf("\n");
}

// Hàm hoán đổi 2 phân số
void hoanDoiPhanSo(PhanSo *a, PhanSo *b) {
    PhanSo temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp mảng phân số tăng dần
void sapXepTangDan(PhanSo ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)ps[i].tu / ps[i].mau > (float)ps[j].tu / ps[j].mau) {
                hoanDoiPhanSo(&ps[i], &ps[j]);
            }
        }
    }
}

// Hàm sắp xếp mảng phân số giảm dần
void sapXepGiamDan(PhanSo ps[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)ps[i].tu / ps[i].mau < (float)ps[j].tu / ps[j].mau) {
                hoanDoiPhanSo(&ps[i], &ps[j]);
            }
        }
    }
}

int main() {
    int n;
    PhanSo ps[50];

    // Nhập số lượng phân số
    printf("Nhap so luong phan so (n <= 50): ");
    scanf("%d", &n);

    // Nhập danh sách phân số
    nhapDanhSachPhanSo(ps, n);

    // Xuất danh sách phân số
    printf("Danh sach phan so: ");
    xuatDanhSachPhanSo(ps, n);

    // Tìm phân số lớn nhất
    PhanSo max = timPhanSoLonNhat(ps, n);
    printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

    // Tìm phân số nhỏ nhất
    PhanSo min = timPhanSoNhoNhat(ps, n);
    printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);

    // Tính tổng các phân số
    PhanSo tong = tinhTongPhanSo(ps, n);
    printf("Tong cac phan so: %d/%d\n", tong.tu, tong.mau);

    // Tính tích các phân số
    PhanSo tich = tinhTichPhanSo(ps, n);
    printf("Tich cac phan so: %d/%d\n", tich.tu, tich.mau);

    // Xuất nghịch đảo giá trị các phân số
    printf("Nghich dao gia tri cac phan so: ");
    xuatNghichDaoPhanSo(ps, n);

    // Sắp xếp tăng dần
    sapXepTangDan(ps, n);
    printf("Mang phan so sau khi sap xep tang dan: ");
    xuatDanhSachPhanSo(ps, n);

    // Sắp xếp giảm dần
    sapXepGiamDan(ps, n);
    printf("Mang phan so sau khi sap xep giam dan: ");
    xuatDanhSachPhanSo(ps, n);

    return 0;
}
