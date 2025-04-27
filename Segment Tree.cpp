#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


#define parent(n) ((n+1)/2)-1
#define left(n) (2*(n+1))-1
#define right(n) (2*(n+1)+1)-1
struct SegmentTree {
    int n;
    vector<int> T;

    SegmentTree(int n) {
        this->n = n;
        this->T.assign(4*n, 0);
    }

    void build(int node, int tl, int tr, vector<int> &arr) {
        if (tl == tr) {
            T[node] = arr[tl];
        } else {
            int mid = tl+(tr-tl)/2;
            build(left(node), tl, mid, arr);
            build(right(node), mid+1, tr, arr);
            T[node] = T[left(node)] + T[right(node)];
        }
    }

    void update(int node, int tl, int tr, int idx, int val) {
        if (tl == tr) {
            T[node] = val;
        } else {
            int mid = tl+(tr-tl)/2;
            if (idx <= mid) {
                update(left(node), tl, mid, idx, val);
            } else {
                update(right(node), mid+1, tr, idx, val);
            }
            T[node] = T[left(node)] + T[right(node)];
        }
    }

    ll sum(int node, int tl, int tr, int ql, int qr) {
        if (ql == tl && qr == tr) {
            return T[node];
        }
        
        int mid = tl+(tr-tl)/2;
        if (qr <= mid) {
            return sum(left(node), tl, mid, tl, qr);
        } else if (ql > mid) {
            return sum(right(node), mid+1, tr, ql, tr);
        } else {
            return sum(left(node), tl, mid, tl, qr) + sum(right(node), mid+1, tr, ql, tr);
        }
    }
};




int main() {
    return 0;
}