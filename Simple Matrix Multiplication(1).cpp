#include <bits/stdc++.h>
using namespace std;

#define MAXLEN 100


void multiply_matrices(int a, int b, int c, int arr[][MAXLEN], int brr[][MAXLEN], int crr[][MAXLEN]) {
    for (int i = 0; i < a; i++) {
        for (int k = 0; k < c; k++) {
            for (int j = 0; j < b; j++) {
                crr[i][k] += arr[i][j] * brr[j][k];
            }
        }
    }
}


int main() {
    int a, b;
    cin >> a;
    cin >> b;
    int arr[MAXLEN][MAXLEN];
    for (int i = 0; i < a; i++) {
        for (int j = 0 ; j < b; j++) {
            cin >> arr[i][j];
        }
    }
    
    int c, d;
    cin >> c;
    cin >> d;
    int brr[MAXLEN][MAXLEN];
    for (int i = 0; i < c; i++) {
        for (int j = 0 ; j < d; j++) {
            cin >> brr[i][j];
        }
    }

    int crr[MAXLEN][MAXLEN];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < d; j++) {
            crr[i][j] = 0;
        }
    }
    

    if (b == c) {
        multiply_matrices(a, c, d, arr, brr, crr);
    } else {
        cout << "B != C" << '\n';
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < d; j++) {
            cout << crr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}