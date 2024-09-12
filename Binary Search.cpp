#include <bits/stdc++.h>
using namespace std;


int binary_search(int x, int n, int arr[]) {
    int l, p, h;
    l = 0, h = n;
    
    while (l < h) {
        p = (l + h) / 2;

        if (x < arr[p]) {
            h = p;
        } else if (x > arr[p]) {
            l = p + 1;
        } else {
            return p;
        }
    }

    return -1;
}


int __binary_search_recursive(int l, int h, int x, int arr[]) {
    if (l < h) {
        int p = (l + h) / 2;

        if (x < arr[p]) {
            return __binary_search_recursive(l, p, x, arr);
        } else if (x > arr[p]) {
            return __binary_search_recursive(p+1, h, x, arr);
        } else {
            return p;
        }
    } else {
        return -1;
    }
}

int binary_search_recursive(int x, int n, int arr[]) {
    return __binary_search_recursive(0, n, x, arr);
}

int main() {
    int x;
    cin >> x;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int y = binary_search_recursive(x, n, arr);

    cout << y << '\n';
    
    return 0;
}