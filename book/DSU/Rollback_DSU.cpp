struct DSU_Rollback
{
    vi parent;
    vi sz;
    stack<ii> history; // Stores {child_node, parent_original_size}
    multiset<int> st;
    int components;

    DSU_Rollback(int n)
    {
        parent.resize(n);
        iota(all(parent), 0);
        sz.assign(n, 1);
        components = n;
        fr(i, 0, n) st.insert(1);
    }

    int find(int x)
    {
        while (x != parent[x])
            x = parent[x];
        return x;
    }

    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        st.erase(st.find(sz[u]));
        st.erase(st.find(sz[v]));
        parent[u] = v;
        sz[v] += sz[u];
        st.insert(sz[v]);
        components--;
        return true;
    }

    bool mergeWithRollback(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        st.erase(st.find(sz[u]));
        st.erase(st.find(sz[v]));
        history.push({u, sz[v]});
        parent[u] = v;
        sz[v] += sz[u];
        st.insert(sz[v]);
        components--;
        return true;
    }

    int getSnapshot() { return history.size(); }

    void rollback(int snapshot)
    {
        while ((int)history.size() > snapshot)
        {
            ii top = history.top();
            history.pop();
            int child = top.first;
            int old_par_sz = top.second;
            int par = parent[child];
            st.erase(st.find(sz[par]));
            sz[par] = old_par_sz;
            parent[child] = child;
            st.insert(sz[par]);
            st.insert(sz[child]);
            components++;
        }
    }

    int getMax()
    {
        if (st.empty())
            return 0;
        return *st.rbegin();
    }
};
