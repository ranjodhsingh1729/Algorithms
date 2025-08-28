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
    vector<int> P, S;

    DSU(int n) : n(n) {
        for (int i = 0; i < n; i++) {
            P.push_back(i);
            S.push_back(1);
        }
    }

    int find_set(int v) {
        if (v == P[v])
            return v;
        return P[v] = find_set(P[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (S[b] < S[a]) 
                swap(a, b);
            P[b] = a;
            S[a] += S[b];
        }
    }
};


// struct DSU {
//     int n;
//     vector<int> P, R;

//     DSU(int n) {
//         this->n = n;
//         for (int i = 0; i < n; i++)
//             P.push_back(i), R.push_back(0);
//     }

//     int find_set(int a) {
//         if (P[a] == a)
//             return a;
//         else
//             return P[a] = find_set(P[a]);
//     }

//     void union_set(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if (a != b) {
//             if (R[a] < R[b])
//                 swap(a, b);
//             P[b] = a;
//             if (R[a] == R[b])
//                 R[a]++;
//         }
//     }
// };


// int main() {
//     return 0;
// }