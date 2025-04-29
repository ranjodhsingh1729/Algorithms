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


ll binpow(int a, int b) {
    ll ans = 1, curi = a, curp = 1;
    for (int i = 0; curp <= b; i++) {
        if ((curp & b))
            ans *= curi;
        curp <<= 1;
        curi *= curi;
    }
    return ans;
}


int main() {
    int a, b;
    a = 0, b = 0;
    while (a != 0 || b != -1) {
        cin >> a >> b;
        cout << binpow(a, b) << '\n';
    }
    return 0;
}