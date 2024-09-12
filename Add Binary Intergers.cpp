#include <bits/stdc++.h>

using namespace std;


int add_binary_intergers(int n, int arr[], int brr[], int crr[]) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        crr[i] = c ^ arr[i] ^ brr[i];
        c = (arr[i] & brr[i]) | (c & (arr[i] ^ brr[i]));
    }
    return c;
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    

    int brr[n];
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    int crr[n];
    int c = add_binary_intergers(n, arr, brr, crr);

    for (int i = 0; i < n; i++) {
        cout << crr[i] << ' ';
    }
    cout << c << '\n';

    return 0;
}