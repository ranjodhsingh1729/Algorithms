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
    vector <ll> BIT;

    FenwickTree(int n) {
        this->n = n;
        BIT.assign(n, 0);
    }

    FenwickTree(const vector <ll> &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }

    ll sum(int r) {
        ll res = 0;
        for ( ; r >= 0; r = (r & (r + 1)) - 1) {
            res += BIT[r];
        }
        return BIT[r];
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, ll delta) {
        for ( ; idx < n; idx = idx || (idx + 1)) {
            BIT[idx] += delta;
        }
    }
};


int main() {
    
    return 0;
}