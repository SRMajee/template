// ------------- Bridges ---------------

vvi g;
vi low, tin;
vector<bool> vis;
vector<bool> is_ap;
int timer;
vector<string> bridge;

void dfs(int v, int par = -1)
{
    vis[v] = 1;
    low[v] = tin[v] = timer++;
    bool is_parent_skipped = false;
    for (auto &to : g[v])
    {
        if (to == par && !is_parent_skipped)
        {
            is_parent_skipped = true; // for multiple edges 0 - 1 again 0 - 1
            continue;
        }
        if (vis[to])
        {
            // back edge
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                bridge.PB(to_string(v) + " - " + to_string(to));
            }
        }
    }
}

void solve()
{
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
    fr(i, 1, n + 1)
    {
        if (!vis[i])
            dfs(i);
    }
    for (auto &st : bridge)
    {
        cout << st << endl;
    }
}

// Form 2 ( if wt on edge use this ) pe = parent edge
vi low, tin, vis, depth, isBridge;

int timer;
void init_()
{
    tin.clear();
    low.clear();
    vis.clear();
    depth.clear();
    isBridge.clear();

    isBridge.assign(n + 1, 0);
    tin.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    low.assign(n + 1, 0);
}
void dfs1(int node, int pe = -1)
{
    low[node] = tin[node] = timer++;
    vis[node] = 1;
    for (const auto &[v, b] : g[node])
    {
        if (v == node)
            continue;
        if (b == pe)
            continue;
        if (vis[v])
        {
            low[node] = min(low[node], tin[v]);
        }
        else
        {
            dfs1(v, b);
            low[node] = min(low[node], low[v]);
            if (low[v] > tin[node])
            {
                isBridge[b] = 1;
            }
        }
    }
}
