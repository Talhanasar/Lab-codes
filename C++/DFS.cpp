#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void DFS(vector<list<int>>& adj, int s) {
    int V = adj.size();
    vector<bool> visited(V, false);
    stack<int> st;

    visited[s] = true;
    st.push(s);

    while (!st.empty()) {
        s = st.top();
        cout << s << " ";
        st.pop();

        for (int adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                st.push(adjacent);
            }
        }
    }
}
int main(){
    int v = 4;
    vector<list<int>> adj(v);

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);

    cout << "Following is Depth First Traversal "<< "(starting from vertex ) \n";
    DFS(adj, 2);
    
    return 0;
}