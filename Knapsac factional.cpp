#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int,int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pre(r, l) for (ll i = (r); i >= ll((l)); i--)
#define fro(l, r) for (ll i = (l); i <= ll((r)); i++)


void solve() {
    ll n;
    cin >> n;
    ll w;
    cin >> w;
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> items[i].second;
    }
    sort(items.begin(), items.end(), [](auto &a, auto &b){
        return double(a.second)/a.first > double(b.second)/b.first;
    });

    ll cur_p = 0, cur_w = 0;
    for (int i = 0; i < n; i++) {
        if (cur_w + items[i].first <= w) {
            cur_w += items[i].first;
            cur_p += items[i].second;
        } else {
            cur_p += double(w-cur_w)/items[i].first * items[i].second;
            break;
        }
    }

    cout << cur_p << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}