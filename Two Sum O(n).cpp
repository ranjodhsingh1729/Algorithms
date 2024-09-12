#include <bits/stdc++.h>
using namespace std;




int main() {
    // TWO SUM
    int x;
    cin >> x;
    int n;
    cin >> n;
    int arr[n];
    unordered_map <int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int i, temp;
    for (i = 0; i < n; i++) {
        freq[arr[i]]--;
        if (freq[x - arr[i]]) {
            cout << arr[i] << " : " << x - arr[i] << '\n';
            break;
        }
        freq[arr[i]]++;
    }

    if (i == n) {
        cout << "TWO SUM DOESN'T EXIST" << '\n';
    }


    return 0;
}