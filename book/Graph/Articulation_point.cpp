// ------------- Articulation Point ------------------
int n, m;
vvi g;
vi low, tin;
vector<bool> vis;
vector<bool> is_ap;
int timer;

void dfs(int v, int par = -1) {
    vis[v] = 1;
    low[v] = tin[v] = timer++;
    int child = 0;
    for (auto &to: g[v]) {
        if (to == par)
            continue;
        if (vis[to]) {
            // back edge
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            child++;
            if (par != -1 && low[to] >= tin[v]) {
                // this condition hits for exactly child no of times if AP
                // not root
                is_ap[v] = true;
            }
        }
    }
    if (par == -1 && child > 1) {
        is_ap[v] = true;
    }
}

void solve() {
    cin >> n >> m;
    g.assign(n + 1, {});
    fr(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].PB(b);
        g[b].PB(a);
    }
    timer = 0;
    vis.assign(n + 1, false);
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    is_ap.assign(n + 1, false);
    fr(i, 1, n + 1)
    {
        if (!vis[i])
            dfs(i);
    }
    fr(i, 1, n + 1)
    {
        cout << i << " : " << is_ap[i] << endl;
    }
}
