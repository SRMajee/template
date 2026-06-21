// --- Global Variables ---

int dfn[MAXN], low[MAXN], scc[MAXN];
bool in_stk[MAXN];
int timer, scc_cnt;
stack<int> stk;

// --- Initialization ---
// Call this before processing a new test case
void init_tarjan(int n)
{
    timer = 0;
    scc_cnt = 0;
    while (!stk.empty())
        stk.pop();
    for (int i = 0; i <= n; ++i)
    {
        dfn[i] = low[i] = scc[i] = 0;
        in_stk[i] = false;
        g[i].clear();
    }
}

// --- Tarjan's DFS ---
void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    stk.push(u);
    in_stk[u] = true;

    for (int v : g[u])
    {
        if (!dfn[v])
        {
            // Node v is unvisited; standard DFS step
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stk[v])
        {
            // Node v is already in the current DFS path (back-edge)
            low[u] = min(low[u], dfn[v]);
        }
    }

    // If u is the root of an SCC
    if (low[u] == dfn[u])
    {
        ++scc_cnt;
        while (true)
        {
            int v = stk.top();
            stk.pop();
            in_stk[v] = false;
            scc[v] = scc_cnt;
            if (u == v)
                break;
        }
    }
}

// --- Usage in solve() ---
/*
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i);
    }
*/