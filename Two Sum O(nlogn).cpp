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


int main() {
    // TWO SUM
    int x;
    cin >> x;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i, temp;
    for (i = 0; i < n; i++) {
        temp = binary_search((x - arr[i]), n, arr);
        if (temp >= 0 && temp != i) {
            cout << i << ':' << arr[i] << ' ' << temp << ':' << arr[temp] << '\n';
            break;
        }
    }

    if (i == n) {
        cout << "TWO SUM DOESN'T EXIST" << '\n';
    }


    return 0;
}