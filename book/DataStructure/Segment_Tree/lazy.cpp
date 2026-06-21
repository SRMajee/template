// ---------------- NODE + MERGE LOGIC ---------------- //
struct Node {
    int sum;
    int lazy;

    Node() {
        lazy = -1;
        sum = 0;
    }

    Node(int _val) {
        lazy = -1;
        sum = _val;
    }
};

Node merge(const Node &a, const Node &b) {
    Node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

// ---------------- SEGMENT TREE STRUCT ---------------- //
struct SegTree {
#define mid ((l + r) >> 1)
    // int n;
    // vector<Node> t;
    //  vi v;

    // void init(int n, vi &v)
    // {
    //     this->n = n;
    //     this->v = v;
    //     t.assign(4 * n + 5, Node());
    // }

    Node t[4 * MAXN];

    void build(int idx, int l, int r) {
        if (l == r) {
            t[idx] = Node(v[l]);
            return;
        }
        build(LC(idx), l, mid);
        build(RC(idx), mid + 1, r);
        t[idx] = merge(t[LC(idx)], t[RC(idx)]);
    }

    void pushDown(int idx, int l, int r, const Node *node) {
        t[idx].lazy += node->lazy;
    }

    void push(int idx, int l, int r) {
        if (t[idx].lazy != -1) {
            int tmp = t[idx].lazy;
            if (l != r) {
                int m = (l + r) >> 1;
                pushDown(LC(idx), l, m, &t[idx]);
                pushDown(RC(idx), m + 1, r, &t[idx]);
            }
            t[idx].lazy = -1;
        }
    }

    // point update
    void update1(int idx, int l, int r, int pos, int x) {
        push(idx, l, r);
        if (pos < l || pos > r)
            return;
        if (l == r) {
            t[idx] = Node(x);
            v[pos] = x;
            push(idx, l, r);
            return;
        }
        update1(LC(idx), l, mid, pos, x);
        update1(RC(idx), mid + 1, r, pos, x);
        t[idx] = merge(t[LC(idx)], t[RC(idx)]);
    }

    // range update
    void update2(int idx, int l, int r, int lq, int rq, int x) {
        push(idx, l, r);
        if (rq < l || lq > r)
            return;
        if (lq <= l && r <= rq) {
            t[idx].lazy = x;
            push(idx, l, r);
            return;
        }
        update2(LC(idx), l, mid, lq, rq, x);
        update2(RC(idx), mid + 1, r, lq, rq, x);
        t[idx] = merge(t[LC(idx)], t[RC(idx)]);
    }

    Node query(int idx, int l, int r, int lq, int rq) {
        push(idx, l, r);
        if (rq < l || lq > r)
            return Node(); // neutral element
        if (lq <= l && r <= rq)
            return t[idx];
        Node left = query(LC(idx), l, mid, lq, rq);
        Node right = query(RC(idx), mid + 1, r, lq, rq);
        return merge(left, right);
    }
#undef mid
};

SegTree seg;

void solve() {
    cin >> n >> k;
    fr(i, 1, n + 1)
    cin >>
            v[i];
    // --------------coordinate compression------------
    vi comp(v + 1, v + n + 1);
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    fr(i, 1, n + 1)
    v[i] = LB(all(comp), v[i]) - comp.begin() + 1;
    int m = SZ(comp);
    // ------------------------------------------------
    // seg.init(n,v);
    // int m=n;

    seg.build(1, 1, m);

    while (k--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            // update
            int i, x;
            cin >> i >> x;
            seg.update(1, 1, m, i, x);
        } else if (ch == 2) {
            // query
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, m, l, r).sum << endl;
        }
    }
}
