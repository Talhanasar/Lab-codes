#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void BFS(vector<list<int>>& adj, int s) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (int adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
}

int main() {
    int V = 4;
    vector<list<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);

    cout << "Following is Breadth First Traversal "<< "(starting from vertex 2) \n";
    BFS(adj, 3);

    return 0;
}
