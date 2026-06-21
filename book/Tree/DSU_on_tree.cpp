

int sz[MAXN], col[MAXN], cnt[MAXN];
int st[MAXN], ft[MAXN], ver[MAXN];
int timer = 0;

// 1. Precalculate sizes AND build the flattened tree (Euler tour)
void getsz(int v, int p) {
    sz[v] = 1;
    st[v] = timer;
    ver[timer] = v;
    timer++;

    for (int u: g[v]) {
        if (u != p) {
            getsz(u, v);
            sz[v] += sz[u];
        }
    }
    ft[v] = timer;
}

// 2. The core DSU on Tree logic (Method 4)
void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;

    // Find the heavy child
    for (int u: g[v]) {
        if (u != p && sz[u] > mx) {
            mx = sz[u];
            bigChild = u;
        }
    }

    // Process light children and clear their data
    for (int u: g[v]) {
        if (u != p && u != bigChild) {
            dfs(u, v, 0);
        }
    }

    // Process heavy child and keep its data
    if (bigChild != -1) {
        dfs(bigChild, v, 1);
    }

    // Add light children's data using the flattened array
    for (int u: g[v]) {
        if (u != p && u != bigChild) {
            for (int i = st[u]; i < ft[u]; i++) {
                cnt[col[ver[i]]]++;
            }
        }
    }

    // Add the current node itself
    cnt[col[v]]++;

    // ---> ANSWER QUERIES FOR NODE 'v' HERE <---

    // Clear the whole subtree instantly using the flat array if keep == 0
    if (keep == 0) {
        for (int i = st[v]; i < ft[v]; i++) {
            cnt[col[ver[i]]]--;
        }
    }
}
