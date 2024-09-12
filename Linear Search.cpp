#include <bits/stdc++.h>

using namespace std;

/*
    LOOP INVARIANT: BEFORE EVERY ITERATION X IS NOT FOUND OR LOOP WOULD HAVE TERMINATED
*/
int linear_search(int x, int n, int arr[]) {
    for (int i = 0; i < n; i++)
        if (x == arr[i])
            return i;
    return -1;
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

    int index = linear_search(x, n, arr);

    cout << index << '\n';

    return 0;
}