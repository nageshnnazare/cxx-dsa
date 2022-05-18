#include <iostream>
#include <vector>
#include <queue>

std::vector < int > bfsOfGraph(int V, std::vector < int > adj[]) {
    std::vector < int > bfs;
    std::vector < int > vis(V, 0);
    std::queue < int > q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return bfs;
}

void addEdge(std::vector < int > adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(int argc, char const* argv[]) {
    std::vector < int > adj[5];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);

    std::vector < int > ans = bfsOfGraph(5, adj);
    {
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}