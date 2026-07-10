#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (const Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    for (const Edge& e : edges) {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
            cout << "Negative cycle\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "inf";
        }
        else {
            cout << dist[i];
        }
        if (i < n) cout << " ";
    }
    cout << "\n";

    return 0;
}