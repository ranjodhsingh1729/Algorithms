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

ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll z = gcd_ext(b, a % b, x, y);
        y = x - y * (a / b);
        x = (x - y) / (a / b);
        return z;
    }
}


ll gcd_ext_itr(ll a, ll b, ll &x, ll &y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b, q;
    while (b1) {
        q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}


int main() {
    ll a, b, x, y;
    cin >> a >> b;
    cout << gcd_ext_itr(a, b, x, y) << ' ';
    cout << x << ' ' <<  y << '\n';
    return 0;
}