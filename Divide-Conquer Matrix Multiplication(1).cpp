#include <bits/stdc++.h>
using namespace std;


// Only Square Matrices
void __matrix_multiply_recursive(int n, int *arr, int *brr, int *crr) {
    if (n == 1) {
        crr[0] += arr[0] * brr[0];
    } else {
        if (n & 1) {
            n++;
            arr = (int *) realloc(arr, sizeof(int) * n*n );
            brr = (int *) realloc(brr, sizeof(int) * n*n );
            crr = (int *) realloc(crr, sizeof(int) * n*n );

            int temp;
            for (int i = n-1; i > 0; i--) {
                for (int j = 0; j < n-1; j++) {
                    temp = arr[(i-1)*(n-1)+j];
                    arr[(i-1)*(n-1)+j] = arr[i*n+j];
                    arr[i*n+j] = temp;
                    
                    temp = brr[(i-1)*(n-1)+j];
                    brr[(i-1)*(n-1)+j] = brr[i*n+j];
                    brr[i*n+j] = temp;

                    temp = crr[(i-1)*(n-1)+j];
                    crr[(i-1)*(n-1)+j] = crr[i*n+j];
                    crr[i*n+j] = temp;
                }
            }

        }

        int k = n/2;
        int *a11 = (int *) malloc( sizeof(int) * k*k );
        int *a12 = (int *) malloc( sizeof(int) * k*k );
        int *a21 = (int *) malloc( sizeof(int) * k*k );
        int *a22 = (int *) malloc( sizeof(int) * k*k );
        int *b11 = (int *) malloc( sizeof(int) * k*k );
        int *b12 = (int *) malloc( sizeof(int) * k*k );
        int *b21 = (int *) malloc( sizeof(int) * k*k );
        int *b22 = (int *) malloc( sizeof(int) * k*k );
        int *c11 = (int *) malloc( sizeof(int) * k*k );
        int *c12 = (int *) malloc( sizeof(int) * k*k );
        int *c21 = (int *) malloc( sizeof(int) * k*k );
        int *c22 = (int *) malloc( sizeof(int) * k*k );

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                a11[i*k+j] = arr[i*n+j];
                a12[i*k+j] = arr[i*n+k+j];
                a21[i*k+j] = arr[(k+i)*n+j];
                a22[i*k+j] = arr[(k+i)*n+k+j];
                b11[i*k+j] = brr[i*n+j];
                b12[i*k+j] = brr[i*n+k+j];
                b21[i*k+j] = brr[(k+i)*n+j];
                b22[i*k+j] = brr[(k+i)*n+k+j];
                c11[i*k+j] = crr[i*n+j];
                c12[i*k+j] = crr[i*n+k+j];
                c21[i*k+j] = crr[(k+i)*n+j];
                c22[i*k+j] = crr[(k+i)*n+k+j];
            }
        }

        __matrix_multiply_recursive(k, a11, b11, c11);
        __matrix_multiply_recursive(k, a12, b21, c11);
        __matrix_multiply_recursive(k, a11, b12, c12);
        __matrix_multiply_recursive(k, a12, b22, c12);
        __matrix_multiply_recursive(k, a21, b11, c21);
        __matrix_multiply_recursive(k, a22, b21, c21);
        __matrix_multiply_recursive(k, a21, b12, c22);
        __matrix_multiply_recursive(k, a22, b22, c22);


        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                crr[i*n+j] = c11[i*k+j];
                crr[i*n+k+j] = c12[i*k+j];
                crr[(k+i)*n+j] = c21[i*k+j];
                crr[(k+i)*n+k+j] = c22[i*k+j];
            }
        }

        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        free(c11);
        free(c12);
        free(c21);
        free(c22);
    }
}

void matrix_multiply_recursive(int n, int *arr, int *brr, int *crr) {
    __matrix_multiply_recursive(n, arr, brr, crr);
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

    int f = n & 1 ? 1 : 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << crr[(i+f)*(n+f)+j] << ' ';
        }
        cout << '\n';
    }

    free(arr);
    free(brr);
    free(crr);

    return 0;
}