struct DSU
{
    vector<int> rank;
    vector<int> par;
    int set_size; // # of cc
    DSU(int n)
    {
        rank.assign(n + 1, 1);
        par.assign(n + 1, 0);
        fr(i, 0, n + 1) par[i] = i;
        set_size = n;
    }

    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;

        // Union by rank (size)
        if (rank[x] < rank[y])
            swap(x, y);
        // x = parent, y = child

        par[y] = x;
        rank[x] += rank[y];
        set_size--;
        return true;
    }

    int size() { return set_size; }
};
