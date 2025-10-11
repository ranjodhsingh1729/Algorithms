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


int main() {
    int n;
    vector<int> basis, dp;


    // Each Element Can Be Used More Than Once
    // Two Combination is Different if frequence of even one element is different
    // I.E: Each Combination is a multiset.
    for (auto &i: basis) {
        for (int j = i; j <= n; j++) {
            dp[j] = mod(dp[j] + dp[j-i], 1e9+7);
        }
    }

    
    // Each Element Can Be Used At Most Once
    // Two Combination is Different if their elements are different
    // I.E: Each Combination is a set.
    for (auto &i: basis) {
        for (int j = n; j >= i; j--) {
            dp[j] = mod(dp[j] + dp[j-i], 1e9+7);
        }
    }


    return 0;
}