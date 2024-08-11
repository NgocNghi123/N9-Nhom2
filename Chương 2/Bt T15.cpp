#include <stdio.h>

void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int demChanLe(int a[], int n, int& chan, int& le) {
    chan = 0;
    le = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            chan++;
        }
        else {
            le++;
        }
    }
}

int timKiemTuyếnTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Trả về vị trí tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Giả sử mảng đã được sắp xếp tăng dần
int timKiemNhiPhan(int a[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] > x)
            return timKiemNhiPhan(a, left, mid - 1, x);

        return timKiemNhiPhan(a, mid + 1, right, x);
    }

    return -1;
}

int demSoLanXuatHien(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, x;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];

    nhapMang(a, n);
    printf("Mang vua nhap: ");
    xuatMang(a, n);

    int max = timMax(a, n);
    printf("Gia tri lon nhat: %d\n", max);

    int min = timMin(a, n);
    printf("Gia tri nho nhat: %d\n", min);

    int chan, le;
    demChanLe(a, n, chan, le);
    printf("So phan tu chan: %d\n", chan);
    printf("So phan tu le: %d\n", le);

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int viTri = timKiemTuyếnTinh(a, n, x);
    if (viTri != -1) {
        printf("Tim thay %d tai vi tri %d (tim kiem tuyen tinh)\n", x, viTri);
    }
    else {
        printf("%d khong co trong mang\n", x);
    }

    // Sắp xếp mảng để thực hiện tìm kiếm nhị phân (nếu cần)
    // ...

    viTri = timKiemNhiPhan(a, 0, n - 1, x);
    if (viTri != -1) {
        printf("Tim thay %d tai vi tri %d (tim kiem nhi phan)\n", x, viTri);
    }
    else {
        printf("%d khong co trong mang\n", x);
    }

    int count = demSoLanXuatHien(a, n, x);
    printf("%d xuat hien %d lan trong mang\n", x, count);

    return 0;
}
