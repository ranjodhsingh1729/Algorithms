#include <bits/stdc++.h>
using namespace std;

/*
IN-PLACE IMPLEMENTATION.
Probability of ARR[i] being at i-th place is 1/n-i.
LOOP INVARIANT: Before i-th Iteration Probability of Permutation ARR[0:i] is (n-i)!/n!.
*/
void shuffle(int n, int arr[]) {
    int ti, tv;
    for (int i = 0; i < n; i++) {
        ti = i + ((double) rand()/RAND_MAX)*(n-1-i);
        tv = arr[i];
        arr[i] = arr[ti];
        arr[ti] = tv;
    }
}

void rsample(int m, int n, int arr[], int brr[]) {
    int ti;
    for (int i = 0; i < m; i++) {
        ti = i + ((double) rand()/RAND_MAX)*(n-1-i);
        brr[i] = arr[ti];
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shuffle(n, arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}