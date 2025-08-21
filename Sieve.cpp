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

int main() {
    int n;
    cin >> n;

    vector<bool> S = sieve(n);

    for (int i = 0; i <= n; i++)
        if (S[i])
            cout << i << ' ';
    cout << endl;

    return 0;
}