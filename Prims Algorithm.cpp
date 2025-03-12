#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    int a, b, w;
    vector<set<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].insert({w, b});
        adj[b].insert({w, a});
    }

    vector<int> key(n+1, INF);
    vector<int> parent(n+1, -1);
    vector<bool> vis(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int node = pq.top().second; pq.pop();
        vis[node] = true;
        for (auto &i: adj[node]) {
            if (!vis[i.second] && i.first < key[i.second]) {
                pq.push({i.first, i.second});
                key[i.second] = i.first;
                parent[i.second] = node;
            }
        }
    }

    cout << "MST:" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << parent[i] << ' ' << key[i] << '\n';
    }

    return 0;
}