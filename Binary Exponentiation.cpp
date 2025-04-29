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



ll binpowrec(int a, int b) {
    if (b == 0)
        return 1;
    
    ll tmp = binpowrec(a, b/2);
    if (b&1) {
        return tmp * tmp * a;
    } else {
        return tmp * tmp;
    }
}


ll binpowitr(int a, int b) {
    ll ans = 1, cur = a;
    while (b > 0) {
        if (b & 1)
            ans *= cur;
        cur *= cur;

        b >>= 1;
    }
    return ans;
}


ll binpowmod(ll a, ll b, ll m) {
    ll ans = 1, cur = a % m;
    while (b > 0) {
        if (b & 1)
            ans = (ans * cur) % m;
        cur = (cur * cur) % m;

        b >>= 1;
    }
    return ans;
}


ll mulop_mod(ll a, ll b, ll m) {
    a = a < m ? a : (a % m);
    b = b < m ? b : (b % m);
    ll ans = 0, cur = b;
    while (a > 0) {
        if (a & 1)
            ans = (ans + cur) % m;
        cur = (cur + cur) % m;

        a >>= 1;
    }
    return ans;
}



int main() {
    ll a, b;
    a = 0, b = 0;
    while (a != 0 || b != -1) {
        cin >> a >> b;
        cout << mulop_mod(a, b, 1e7+9) << '\n';
    }
    return 0;
}