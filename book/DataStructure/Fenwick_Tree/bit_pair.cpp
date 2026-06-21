// Bit Pair
struct BIT_Pair {
    int n;
    vii tree;

    void init(int n_) {
        n = n_;
        tree.assign(n + 1, MP(0, 0));
    }

    void update(int i, ii v) {
        for (; i <= n; i += i & -i)
            if (v.F > tree[i].F)
                tree[i] = v;
    }

    ii query(int i) {
        ii s = MP(0, 0);
        for (; i > 0; i -= i & -i)
            if (s.F < tree[i].F)
                s = tree[i];
        return s;
    }

    ii query(int l, int r) {
        if (l > r)
            return 0;
        return sub_ii(query(r), query(l - 1));
    }
};
