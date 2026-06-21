struct Node {
    int sum;

    Node() {
    }

    Node(int x) {
    }
};

Node merge(const Node &a, const Node &b) {
    Node ans;
    return ans;
}

// ---------------- FENWICK TREE ---------------- //
struct FenwickTree {
    int n;
    vector<Node> tree;

    void init(int _n) {
        n = _n;
        tree.assign(n + 1, Node());
    }

    void update(int i, Node val) {
        for (; i <= n; i += i & -i) {
            tree[i] = merge(tree[i], val);
        }
    }

    Node query(int i) {
        Node res;
        for (; i > 0; i -= i & -i) {
            res = merge(res, tree[i]);
        }
        return res;
    }
};
