#include <bits/stdc++.h>
using namespace std;

// In Place Implementation
/*
    LOOP INVARIANT: BEFORE EACH ITERATION ARR[0:I-1] IS SORTED;
*/
void selection_sort(int n, int arr[]) {
    int i, j, min_ind, min_val;
    for (i = 0; i < n-1; i++) {
        min_ind = i;
        min_val = arr[i];
        for (j = i+1; j < n; j++) {
            if (arr[j] < min_val) {
                min_ind = j;
                min_val = arr[j];
            }
        }
        arr[min_ind] = arr[i];
        arr[i] = min_val;
    }

}



int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selection_sort(n, arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}