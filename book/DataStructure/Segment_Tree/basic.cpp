// ---------------- NODE + MERGE LOGIC ---------------- //
struct Node
{
    int sum;

    Node() { sum = 0; }
    Node(int _val) { sum = _val; }
};

Node merge(const Node &a, const Node &b)
{
    Node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

// ---------------- SEGMENT TREE STRUCT ---------------- //
struct SegTree
{
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

    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            t[idx] = Node(v[l]);
            return;
        }
        build(LC(idx), l, mid);
        build(RC(idx), mid + 1, r);
        t[idx] = merge(t[LC(idx)], t[RC(idx)]);
    }

    void update(int idx, int l, int r, int pos, int x)
    {
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            t[idx] = Node(x);
            v[pos] = x;
            return;
        }
        update(LC(idx), l, mid, pos, x);
        update(RC(idx), mid + 1, r, pos, x);
        t[idx] = merge(t[LC(idx)], t[RC(idx)]);
    }

    Node query(int idx, int l, int r, int lq, int rq)
    {
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

void solve()
{
    cin >> n >> k;
    fr(i, 1, n + 1)
            cin >>
        v[i];
    // --------------coordinate compression------------
    vi comp(v + 1, v + n + 1);
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    auto get_rank = [&](int x)
    {
        return lower_bound(all(comp), x) - comp.begin() + 1;
    };
    fr(i, 1, n + 1)
        v[i] = get_rank(v[i]);
    int m = SZ(comp);
    // ------------------------------------------------
    // seg.init(n,v);
    // int m=n;

    seg.build(1, 1, m);

    while (k--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            // update
            int i, x;
            cin >> i >> x;
            seg.update(1, 1, m, i, x);
        }
        else if (ch == 2)
        {
            // query
            int l, r;
            cin >> l >> r;
            cout << seg.query(1, 1, m, l, r).sum << endl;
        }
    }
}
