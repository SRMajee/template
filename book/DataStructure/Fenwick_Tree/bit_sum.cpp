//----------- BIT_SUM ------------
struct BIT_Sum {
    int n;
    vi tree;


    void init(int n_) {
        n = n_;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        for (; i <= n; i += i & -i)
            tree[i] += v;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += tree[i];
        return s;
    }

    int query(int l, int r) {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};
