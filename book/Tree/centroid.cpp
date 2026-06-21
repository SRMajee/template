int par[MAXN], subtree_sz[MAXN];

void dfs(int node,int p) {
    par[node] = p;
    subtree_sz[node] = 1;
    for (auto &v: g[node]) {
        if (v != p) {
            dfs(v, node);
            subtree_sz[node] += subtree_sz[v];
        }
    }
}


void solve() {
    cin >> n;
    fr(i, 1, n) {
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    dfs(1, 0); // create subtree

    // find all centroid
    // 1 - 2 - 3 - 4 - 5 - 6
    vi centroids;

    fr(u, 1, n+1) {
        int max_part = 0;
        for (auto &v: g[u]) {
            if (v == par[u]) {
                // size of the rest of the tree if we remove u
                max_part = max(max_part, n - subtree_sz[u]);
            } else {
                max_part = max(max_part, subtree_sz[v]);
            }
        }
        if (max_part <= n / 2)
            centroids.PB(u);
    }

    cout << centroids.size() << endl;
    for (auto &c: centroids)
        cout << c << " ";
    cout << endl;
}