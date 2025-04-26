#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


struct DSU {
    int n;
    vector<int> P, R;

    DSU(int n) {
        this->n = n;
        for (int i = 0; i < n; i++)
            P.push_back(i), R.push_back(0);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (R[a] >= R[b]) {
                P[b] = a;
                R[a]++;
            } else {
                P[a] = b;
                R[b]++;
            }
        }
    }

    int find_set(int a) {
        if (P[a] == a)
            return a;
        else
            return P[a] = find_set(P[a]);
    }
};


int main() {
    return 0;
}