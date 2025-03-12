#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define max(a, b) ((a) > (b) ? (a) : (b))

void solve() {
    ll n, w;
    cin >> n >> w;
    vector<int> values(n), weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<vector<int>> dp(n+1, vector<int> (w+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - weights[i-1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
        }
    }

    cout << dp[n][w] << '\n';
}

int main() {
    ll t;
    t = 1;
    while (t--)
        solve();
    return 0;
}