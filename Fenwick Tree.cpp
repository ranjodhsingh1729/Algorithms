#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


struct FenwickTree {
    int n;
    vector<int> T;

    FenwickTree(int len) {
        this->n = len;
        this->T.assign(n, 0);
    }

    ll sum(int r) {
        ll res = 0;
        while (r >= 0) {
            res += T[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }

    void add(int i, int delta) {
        while (i < n) {
            T[i] += delta;
            i = (i | (i + 1));
        }
    }
};


int main() {
    return 0;
}