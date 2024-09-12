#include <bits/stdc++.h>
using namespace std;


void bubble_sort(int n, int arr[]) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i+1; j--) {
            if (arr[j-1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubble_sort(n, arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
 

    return 0;
}