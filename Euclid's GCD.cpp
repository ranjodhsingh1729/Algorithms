#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


ll gcdrec(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcdrec(b, a % b);
    }
    // return b ? gcd (b, a % b) : a;
}

ll gcditr(ll a, ll b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


int main() {
    ll x, y;
    cin >> x >> y;
    cout << gcditr(x, y) << '\n';

    return 0;
}