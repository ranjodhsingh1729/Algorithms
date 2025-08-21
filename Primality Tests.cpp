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


vector<bool> sieve(int n) {
    vector<bool> S(n+1, true);
    S[0] = false, S[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (S[i] == false)
            continue;

        for (int j = 2; i*j <= n; j++)
            S[i*j] = false;
    }
    return S;
}


bool is_prime_trial_division(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


bool is_prime_fermat(int n, int max_iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < max_iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpowmod(a, n-1, n) != 1) 
            return false;
    }

    return true;
}


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
    int n;
    cin >> n;
    vector<bool> S = sieve(n);
    for (int i = 0; i <= n; i++) {
        if (is_prime_fermat(i, 100) != S[i])
            cout << i << ' ';
    }
    cout << '\n';

    return 0;
}