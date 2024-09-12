#include <bits/stdc++.h>
using namespace std;

int __combine(int l, int p, int r, int arr[]) {
    int a = 0, b = 0, n = p-l, m = r-p;

    int x = 0;
    for (int i = l; i < r; i++) {
        if (a < n && b < m) {
            if (arr[p+b] < arr[l+a]) {
                x += n-a;
                b++;
            } else {
                a++;
            }
        } else {
            break;
        }
    }

    return x;
}

// O(nlogn)
int __count_inversions(int l, int r, int arr[]) {
    if (r - l > 1) {
        int p = (l + r) / 2;
        return __count_inversions(l, p, arr) + __count_inversions(p, r, arr) + __combine(l, p, r, arr);
    }
    return 0;
}


int count_inversions(int n, int arr[]) {
    return __count_inversions(0, n, arr);
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int y = count_inversions(n, arr);

    cout << y << '\n';

    return 0;
}