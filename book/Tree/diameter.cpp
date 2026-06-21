int depth[MAXN], par[MAXN];

void dfs(int node, int p, int d) {
    par[node] = p;
    depth[node] = d;
    for (auto &v: g[node]) {
        if (v != p) {
            dfs(v, node, d + 1);
        }
    }
}

void solve() {
    cin >> n;
    fr(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    dfs(1, 0, 0);
    int id1 = max_element(depth + 1, depth + n + 1) - depth;
    dfs(id1, 0, 0);
    int diameter = *max_element(depth + 1, depth + n + 1);
    cout << diameter << endl;
}
