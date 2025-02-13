#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


void fileio() {
    #ifndef ONLINE_JUDGE
    freopen(".streams/input.txt", "r", stdin);
    freopen(".streams/output.txt", "w", stdout);
    #endif
}

void solve() {
    int SIEVE[30] = { 0 };
    SIEVE[0] = 1;
    SIEVE[1] = 1;

    for (int i = 2; i <= 25; i++) {
        for (int j = 2; j*i <= 25; j++) {
            SIEVE[i*j] = 1;
        }
    }

    for (int i = 0; i < 30; i++) {
        if (!SIEVE[i])
        cout << i << ' ';
    }
    cout << '\n';

    
}


int main() {
    FIXIO;
    //fileio();

    ll t;
    // t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}