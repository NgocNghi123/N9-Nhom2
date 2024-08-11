#include <stdio.h>

typedef struct {
    int tu;   
    int mau;
} PhanSo;

void nhapPhanSo(PhanSo *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tu, ps.mau);
}

int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

void toiGianPhanSo(PhanSo *ps) {
    int ucln = UCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
}

PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&kq);
    return kq;
}

PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&kq);
    return kq;
}

PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&kq);
    return kq;
}

PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    toiGianPhanSo(&kq);
    return kq;
}

int main() {
    PhanSo ps1, ps2, kq;
    printf("Nhap phan so thu nhat:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&ps2);

    printf("Phan so thu nhat: ");
    xuatPhanSo(ps1);
    printf("Phan so thu hai: ");
    xuatPhanSo(ps2);

    kq = tongPhanSo(ps1, ps2);
    printf("Tong hai phan so: ");
    xuatPhanSo(kq);

    kq = hieuPhanSo(ps1, ps2);
    printf("Hieu hai phan so: ");
    xuatPhanSo(kq);

    kq = tichPhanSo(ps1, ps2);
    printf("Tich hai phan so: ");
    xuatPhanSo(kq);

    kq = thuongPhanSo(ps1, ps2);
    printf("Thuong hai phan so: ");
    xuatPhanSo(kq);

    return 0;
}
