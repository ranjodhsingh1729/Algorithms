#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib_itr(int n) {
    if (n < 2)
        return n;

    ll a, b, tmp;
    a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        tmp = b;
        b += a;
        a = tmp;
    }
    return b;
}

ll fib_tab(int n) {
    vector<ll> T(n+1);
    T[0] = 0, T[1] = 1;
    for (int i = 2; i <= n; i++)
        T[i] = T[i-1] + T[i-2];
    return T[n];
}

ll fib_rec(int n) {
    if (n < 2)
        return n;
    else
        return fib_rec(n-1) + fib_rec(n-2);
}

ll fib_mem(int n) {
    static vector<ll> T(n+1, -1);
    if (n < 2) {
        return n;
    } else {
        if (T[n] == -1)
            T[n] = fib_mem(n-1) + fib_mem(n-2);
        return T[n];
    }
}

void __mul(ll M[2][2], ll N[2][2]) {
    ll temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll res = 0;
            for (int k = 0; k < 2; k++) {
                res += M[i][k]*N[k][j];
            }
            temp[i][j] = res;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            N[i][j] = temp[i][j];
        }
    }
}

ll fib_mat(int n) {
    if (n == 0) return 0; 
    n -= 2; // Saving Two Operations;
    ll ans[2][2] = { 0, 1, 1, 1 };
    ll cur[2][2] = { 0, 1, 1, 1 };
    while (n > 0) {
        if (n & 1)
            __mul(cur, ans);
        __mul(cur, cur);

        n >>= 1;
    }
    return ans[1][1];
}


ll fib_gamma(int n) {
    const long double sq5 = sqrtl(5);
    const long double phi1 = (1.0 + sq5)/2.0;
    const long double phi2 = (1.0 - sq5)/2.0;

    return (ll)floorl((powl(phi1, n)-powl(phi2, n))/sq5);
}

int main() {
    int n;
    cin >> n;

    cout << "ITTERATIVE:-" << fib_itr(n) << '\n';
    cout << "TABULATION:-" << fib_tab(n) << '\n';
    cout << "RECURSION:-" << fib_rec(n) << '\n';
    cout << "MEMOIZATION:-" << fib_mem(n) << '\n';
    cout << "T_GAMMA_FUNC:-" << fib_gamma(n) << '\n';
    cout << "BINARY EXPONENTIAION:-" << fib_mat(n) << '\n';

    return 0;
}