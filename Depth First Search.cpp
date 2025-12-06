#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[100];
bool visited[100];

void dfs(int node){
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]){
        if (!visited[next]) {
            dfs(next);
        }
    }
            }
int main() {
    int n, e;
    cout <<"Enter number of nodes:";
    cin>>n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout<<"Enter edges (u v):"<< endl;
    for (int i= 0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout<<"Enter starting node for DFS:";
    cin>>start;

    cout<<"DFS Traversal: ";
    dfs(start);
    return 0;
}
