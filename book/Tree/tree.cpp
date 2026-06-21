vi depth[MAXN];
int inTime[MAXN], outTime[MAXN];
int par[MAXN][21];
int timer;
int node_depth[MAXN];

// -----------Par,Depth per node,In Time,Out Time------------
void dfs(int node, int p, int d = 0)
{
    par[node][0] = p;
    node_depth[node] = d;
    timer++;
    inTime[node] = timer;
    depth[d].PB(inTime[node]);
    fr(i, 1, 20)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (const auto &v : g[node])
    {
        if (v != p)
        {
            dfs(v, node, d + 1);
        }
    }
    outTime[node] = timer;
}
// -------- isAncestor ---------
inline bool isAncestor(int x, int y)
{
    if (x == 0)
        return true;
    return (inTime[x] <= inTime[y] && outTime[x] >= outTime[y]);
}
// -------- LCA --------
int lca(int u, int v)
{
    if (isAncestor(u, v))
        return u;
    if (isAncestor(v, u))
        return v;
    for (int i = 19; i >= 0; --i)
    {
        if (!isAncestor(par[u][i], v))
        {
            u = par[u][i];
        }
    }
    return par[u][0];
}
inline int dis(int x, int y)
{
    return node_depth[x] + node_depth[y] - 2 * node_depth[lca(x, y)] + 1;
}
int lca(int a, int b)
{
    if (node_depth[a] < node_depth[b])
        swap(a, b);

    frn(i, 20, 0)
    {
        if (((node_depth[a] - node_depth[b]) >> i) & 1)
        {
            a = par[a][i];
        }
    }
    if (a == b)
        return a;
    frn(i, 21, 0)
    {
        if (par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

// --------Get par--------
inline int getPar(int X, int b)
{
    int child = b;
    frn(i, 20, 0)
    {
        if ((X >> i) & 1)
        {
            child = par[child][i];
        }
    }
    return child;
}
