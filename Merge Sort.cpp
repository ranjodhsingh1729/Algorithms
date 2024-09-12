#include <bits/stdc++.h>
using namespace std;

void __merge(int l, int p, int r, int arr[]) {
    int *L = (int *) malloc(sizeof(int) * (p-l));
    memcpy(L, &arr[l], sizeof(int) * (p-l));
    int *R = (int *) malloc(sizeof(int) * (r-p));
    memcpy(R, &arr[p], sizeof(int) * (r-p));

    int n = 0, m = 0;
    for (int i = l; i < r; i++) {
        if (n < p-l && m < r-p) {
            arr[i] = L[n] < R[m] ? L[n++] : R[m++];
        } else if (n < p-l) {
            arr[i] = L[n++];
        } else {
            arr[i] = R[m++];
        }
    }

    free(L);
    free(R);
}

// O(nlogn)
void __merge_sort(int l, int r, int arr[]) {
    if (r - l > 1) {
        int p = (l + r) / 2;
        __merge_sort(l, p, arr);
        __merge_sort(p, r, arr);
        __merge(l, p, r, arr);
    }
}


void merge_sort(int n, int arr[]) {
    __merge_sort(0, n, arr);
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(n, arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}