#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> adj(n+1);

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    set <pair <ll, ll>> q;
    vector <bool> visited(n+1, false);
    vector <pair <ll, ll>> dist(n+1, {INF, INF});

    dist[1] = {0, 1};
    q.insert({0, 1});

    ll curi, curv, nxti, nxtv, prvi, cost;
    while (!q.empty()) {
        curv = q.begin()->first;
        curi = q.begin()->second;
        
        for (auto x: adj[curi]) {
            nxtv = x.first;
            nxti = x.second;


            cost = dist[nxti].first;
            if (curv+nxtv < cost) {
                dist[nxti] = { curv+nxtv , curi };
            }
            cost = dist[nxti].first;


            if (!visited[nxti]) {
                q.insert( { cost , nxti } );
            }
        }

        visited[curi] = true;
        q.erase(q.begin());

    }


    int tmp;
    int k = 0, path[MAXLEN];

    tmp = n;
    while (tmp != 1) {
        path[k++] = tmp;
        cost = dist[tmp].first;

        if (cost != INF) {
            tmp = dist[tmp].second;
        } else {
            cout << -1 << '\n';
            return 0;
        }
    }


    cout << 1 << ' ';
    for (int i = k-1; i > 0; i--) {
        cout << path[i] << ' ';
    }
    cout << n << '\n';

    return 0;
}