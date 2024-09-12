#include <bits/stdc++.h>
using namespace std;

// In Place Implementation
/*
    LOOP INVARIANT: ARR[0:i] consists of elements that were
                    originaly present in ARR[0:i] but in sorted order.

*/
void insertion_sort(int n, int arr[]) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i]; // select a number
        for (j = i; j > 0 && arr[j-1] > key; j--) {
            arr[j] = arr[j-1]; // find its place
        }
        arr[j] = key; // put it there
    }
}

void insertion_sort_reverse(int n, int arr[]) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i]; // select a number
        for (j = i; j > 0 && arr[j-1] < key; j--) {
            arr[j] = arr[j-1]; // find its place
        }
        arr[j] = key; // put it there
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertion_sort_reverse(n, arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}