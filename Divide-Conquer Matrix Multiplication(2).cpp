#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
} subpos;

// Only Square Matrices
void __matrix_multiply_recursive(int k, subpos a, subpos b, subpos c, int n, int *arr, int *brr, int *crr) {
    if (k == 1) {
        crr[c.x1*n+c.y1] += arr[a.x1*n+a.y1] * brr[b.x1*n+b.y1];
    } else {
        k = k/2;

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

        __matrix_multiply_recursive(k, a11, b11, c11, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a12, b21, c11, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a11, b12, c12, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a12, b22, c12, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a21, b11, c21, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a22, b21, c21, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a21, b12, c22, n, arr, brr, crr);
        __matrix_multiply_recursive(k, a22, b22, c22, n, arr, brr, crr);
    }
}

void matrix_multiply_recursive(int n, int *arr, int *brr, int *crr) {
    subpos a = {0, n, 0, n};   
    subpos b = {0, n, 0, n};   
    subpos c = {0, n, 0, n};
    __matrix_multiply_recursive(n, a, b, c, n, arr, brr, crr);
}


int main() {
    int n, temp;
    cin >> n;

    int *arr = (int *) malloc( sizeof(int *) * n*n );
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            cin >> arr[i*n+j];
        }
    }
    
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

    matrix_multiply_recursive(n, arr, brr, crr);

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