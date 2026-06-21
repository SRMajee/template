struct BIT {
    int32_t n;
    vector<int32_t> tree;

    BIT(int32_t n) : n(n), tree(n + 1, 0) {
    }

    void update(int32_t i, int32_t val) {
        for (; i <= n; i += i & -i) tree[i] = max(tree[i], val);
    }

    int32_t query(int32_t i) {
        int32_t res = 0;
        for (; i > 0; i -= i & -i) res = max(res, tree[i]);
        return res;
    }
};
