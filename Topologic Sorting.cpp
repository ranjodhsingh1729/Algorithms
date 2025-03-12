#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool> &visited, stack<int> &Stack, vector<vector<int>> &adj) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            dfs(i, visited, Stack, adj);
    Stack.push(v);
}

void topologicalSort(int V, vector<vector<int>> &adj) {
    stack<int> Stack;
    vector<bool> visited(V+1, false);
    for (int i = 1; i <= V; i++)
        if (!visited[i])
            dfs(i, visited, Stack, adj);

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << "TOPOLOGIC SORT:- ";
    topologicalSort(n, adj);
    cout << endl;
    
    return 0;
}
