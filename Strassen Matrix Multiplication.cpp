#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
} subpos;

void __matrix_combination(int f1, int f2, int k, int l, int m, int n, subpos a, subpos b, subpos c, int *arr, int *brr, int *crr) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (f1) {
                crr[c.x1*n+c.y1+i*n+j] += f2 ? arr[a.x1*l+a.y1+i*l+j]-brr[b.x1*m+b.y1+i*m+j] : arr[a.x1*l+a.y1+i*l+j]+brr[b.x1*m+b.y1+i*m+j];
            } else {
                crr[c.x1*n+c.y1+i*n+j] = f2 ? arr[a.x1*l+a.y1+i*l+j]-brr[b.x1*m+b.y1+i*m+j] : arr[a.x1*l+a.y1+i*l+j]+brr[b.x1*m+b.y1+i*m+j];
            }
        }
    }
}

// Only Square Matrices
void __matrix_multiply_strassen(int k, int l, int m, int n, subpos a, subpos b, subpos c, int *arr, int *brr, int *crr) {
    if (k == 1) {
        crr[c.x1*n+c.y1] += arr[a.x1*l+a.y1] * brr[b.x1*m+b.y1];
    } else {
        k = k/2;
        subpos ful = {0, k, 0, k};

        subpos a11 = {a.x1, (a.x1+a.x2)/2, a.y1, (a.y1+a.y2)/2};
        subpos a12 = {(a.x1+a.x2)/2, a.x2, a.y1, (a.y1+a.y2)/2};
        subpos a21 = {a.x1, (a.x1+a.x2)/2, (a.y1+a.y2)/2, a.y2};
        subpos a22 = {(a.x1+a.x2)/2, a.x2, (a.y1+a.y2)/2, a.y2};
        subpos b11 = {b.x1, (b.x1+b.x2)/2, b.y1, (b.y1+b.y2)/2};
        subpos b12 = {(b.x1+b.x2)/2, b.x2, b.y1, (b.y1+b.y2)/2};
        subpos b21 = {b.x1, (b.x1+b.x2)/2, (b.y1+b.y2)/2, b.y2};
        subpos b22 = {(b.x1+b.x2)/2, b.x2, (b.y1+b.y2)/2, b.y2};
        subpos c11 = {c.x1, (c.x1+c.x2)/2, c.y1, (c.y1+c.y2)/2};
        subpos c12 = {(c.x1+c.x2)/2, c.x2, c.y1, (c.y1+c.y2)/2};
        subpos c21 = {c.x1, (c.x1+c.x2)/2, (c.y1+c.y2)/2, c.y2};
        subpos c22 = {(c.x1+c.x2)/2, c.x2, (c.y1+c.y2)/2, c.y2};

        int *s01 = (int *) malloc( sizeof(int) * k*k );
        int *s02 = (int *) malloc( sizeof(int) * k*k );
        int *s03 = (int *) malloc( sizeof(int) * k*k );
        int *s04 = (int *) malloc( sizeof(int) * k*k );
        int *s05 = (int *) malloc( sizeof(int) * k*k );
        int *s06 = (int *) malloc( sizeof(int) * k*k );
        int *s07 = (int *) malloc( sizeof(int) * k*k );
        int *s08 = (int *) malloc( sizeof(int) * k*k );
        int *s09 = (int *) malloc( sizeof(int) * k*k );
        int *s10 = (int *) malloc( sizeof(int) * k*k );

        int *p01 = (int *) malloc( sizeof(int) * k*k );
        int *p02 = (int *) malloc( sizeof(int) * k*k );
        int *p03 = (int *) malloc( sizeof(int) * k*k );
        int *p04 = (int *) malloc( sizeof(int) * k*k );
        int *p05 = (int *) malloc( sizeof(int) * k*k );
        int *p06 = (int *) malloc( sizeof(int) * k*k );
        int *p07 = (int *) malloc( sizeof(int) * k*k );

        __matrix_combination(0, 0, k, l, l, k, a11, a22, ful, arr, arr, s01);
        __matrix_combination(0, 0, k, m, m, k, b11, b22, ful, brr, brr, s02);
        __matrix_combination(0, 0, k, l, l, k, a21, a22, ful, arr, arr, s03);
        __matrix_combination(0, 1, k, m, m, k, b12, b22, ful, brr, brr, s04);
        __matrix_combination(0, 1, k, m, m, k, b21, b11, ful, brr, brr, s05);
        __matrix_combination(0, 0, k, l, l, k, a11, a12, ful, arr, arr, s06);
        __matrix_combination(0, 1, k, l, l, k, a21, a11, ful, arr, arr, s07);
        __matrix_combination(0, 0, k, m, m, k, b11, b12, ful, brr, brr, s08);
        __matrix_combination(0, 1, k, l, l, k, a12, a22, ful, arr, arr, s09);
        __matrix_combination(0, 0, k, m, m, k, b21, b22, ful, brr, brr, s10);

        __matrix_multiply_strassen(k, k, k, k, ful, ful, ful, s01, s02, p01);
        __matrix_multiply_strassen(k, k, m, k, ful, b11, ful, s03, brr, p02);
        __matrix_multiply_strassen(k, l, k, k, a11, ful, ful, arr, s04, p03);
        __matrix_multiply_strassen(k, l, k, k, a22, ful, ful, arr, s05, p04);
        __matrix_multiply_strassen(k, k, m, k, ful, b22, ful, s06, brr, p05);
        __matrix_multiply_strassen(k, k, k, k, ful, ful, ful, s07, s08, p06);
        __matrix_multiply_strassen(k, k, k, k, ful, ful, ful, s09, s10, p07);

        __matrix_combination(1, 0, k, k, k, n, ful, ful, c11, p01, p04, crr);
        __matrix_combination(1, 1, k, k, k, n, ful, ful, c11, p07, p05, crr);
        __matrix_combination(1, 0, k, k, k, n, ful, ful, c12, p03, p05, crr);
        __matrix_combination(1, 0, k, k, k, n, ful, ful, c21, p02, p04, crr);
        __matrix_combination(1, 0, k, k, k, n, ful, ful, c22, p01, p03, crr);
        __matrix_combination(1, 1, k, k, k, n, ful, ful, c22, p06, p02, crr);


        free(s01);
        free(s02);
        free(s03);
        free(s04);
        free(s05);
        free(s06);
        free(s07);
        free(s08);
        free(s09);
        free(s10);
        free(p01);
        free(p02);
        free(p03);
        free(p04);
        free(p05);
        free(p06);
        free(p07);
    }
}

void matrix_multiply_strassen(int n, int *arr, int *brr, int *crr) {
    subpos a = {0, n, 0, n};
    subpos b = {0, n, 0, n};
    subpos c = {0, n, 0, n};
    __matrix_multiply_strassen(n, n, n, n, a, b, c, arr, brr, crr);
}


int main() {
    int n, temp;
    cout << "N: ";
    cin >> n;

    cout << "A:- " << '\n';
    int *arr = (int *) malloc( sizeof(int *) * n*n );
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            cin >> arr[i*n+j];
        }
    }

    cout << "B:- " << '\n';    
    int *brr = (int *) malloc( sizeof(int *) * n*n );
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            cin >> brr[i*n+j];
        }
    }

    int *crr = (int *) malloc( sizeof(int *) * n*n );
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            crr[i*n+j] = 0;
        }
    }

    matrix_multiply_strassen(n, arr, brr, crr);


    cout << "C:- " << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << crr[i*n+j] << ' ';
        }
        cout << '\n';
    }

    free(arr);
    free(brr);
    free(crr);

    return 0;
}