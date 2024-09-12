#include <bits/stdc++.h>
using namespace std;

int horners_eval(int x, int n, int arr[]) {
    int p = 0;
    for (int i = n; i > 0; i--) {
        p = arr[i-1] + x*p;
    }
    return p;
}


int main() {


    return 0;
}