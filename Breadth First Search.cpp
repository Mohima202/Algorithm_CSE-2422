#include<bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, int n){
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int next : adj[node]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
               }
    cout << endl;
}
int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    BFS(start, adj, n);
    return 0;
}
