#include <iostream>
#include <vector>

void dfs(int node, std::vector<int>& vis, std::vector<int> adj[], std::vector<int>& storeDfs) {
    storeDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, storeDfs);
        }
    }
}

std::vector<int>dfsOfGraph(int V, std::vector<int> adj[]) {
    std::vector<int> storeDfs;
    std::vector<int> vis(V + 1, 0);
    for (int i = 1;i <= V;i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, storeDfs);
        }
    }
    return storeDfs;
}

void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(int argc, char const* argv[]) {
    std::vector<int> adj[6];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 2);
    addEdge(adj, 5, 1);

    std::vector<int> df = dfsOfGraph(5, adj);
    {
        for (auto it : df)
            std::cout << it << " ";
        std::cout << std::endl;
    }

    return 0;
}