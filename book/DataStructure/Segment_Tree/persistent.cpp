// 1. MERGE FUNCTION: Change this based on the problem (sum, min, max, etc.)
inline i32 merge_nodes(i32 left, i32 right)
{
    return left + right; // Default: Sum
}

// 2. NODE DEFINITION: Strictly i32 to prevent memory bloat with #define int long long
struct Node
{
    i32 val; // Stores count, sum, min, max, etc.
    i32 lc;  // Index of the left child
    i32 rc;  // Index of the right child

    Node() : val(0), lc(0), rc(0) {}
};

// 3. TREE STRUCTURE
struct PersistentSegTree
{
    vector<Node> t;

    // expected_updates: N * log(N). 300,000 updates * 20 ≈ 6,000,000 nodes.
    // Dynamic reserve prevents vector reallocation freezes.
    PersistentSegTree(i32 expected_updates = 300005)
    {
        t.reserve(expected_updates * 22);
        t.PB(Node()); // t[0] is the dummy/null node
    }

    // Creates a new version of the tree with 'pos' updated
    // Returns the root index of the new version
    i32 update(i32 prev_idx, i32 l, i32 r, i32 pos, i32 val)
    {
        i32 idx = t.size();
        t.PB(Node());

        if (prev_idx != 0)
            t[idx] = t[prev_idx]; // Copy previous state

        if (l == r)
        {
            // APPLY UPDATE LOGIC HERE (e.g., += for sum/count, = for replacement, max() for LIS)
            t[idx].val += val;
            return idx;
        }

        i32 mid = l + (r - l) / 2;
        if (pos <= mid)
            t[idx].lc = update(prev_idx ? t[prev_idx].lc : 0, l, mid, pos, val);
        else
            t[idx].rc = update(prev_idx ? t[prev_idx].rc : 0, mid + 1, r, pos, val);

        t[idx].val = merge_nodes(t[t[idx].lc].val, t[t[idx].rc].val);
        return idx;
    }

    // Range query on a specific version of the tree
    i32 query_range(i32 idx, i32 l, i32 r, i32 lq, i32 rq)
    {
        if (idx == 0 || rq < l || lq > r)
            return 0; // Return neutral element for your merge
        if (lq <= l && r <= rq)
            return t[idx].val;

        i32 mid = l + (r - l) / 2;
        i32 left_res = query_range(t[idx].lc, l, mid, lq, rq);
        i32 right_res = query_range(t[idx].rc, mid + 1, r, lq, rq);

        return merge_nodes(left_res, right_res);
    }

    // Example: Find K-th smallest element using prefix subtraction on versions (root_r - root_l)
    i32 query_kth(i32 root_l, i32 root_r, i32 l, i32 r, i32 k)
    {
        if (l == r)
            return l;

        i32 left_count = t[t[root_r].lc].val - t[t[root_l].lc].val;
        i32 mid = l + (r - l) / 2;

        if (left_count >= k)
            return query_kth(t[root_l].lc, t[root_r].lc, l, mid, k);
        else
            return query_kth(t[root_l].rc, t[root_r].rc, mid + 1, r, k - left_count);
    }
};

// =========================================================================

void solve()
{
    // 1. Read input
    int n, q;
    cin >> n >> q;

    // 2. Coordinate Compression
    vi a(n), comp;
    fr(i, 0, n) {
        cin >> a[i];
        comp.PB(a[i]);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    int K = comp.size();
    auto get_rank = [&](int x) { return LB(all(comp), x) - comp.begin() + 1; };
    

    // 3. Initialize PST and Roots Array
    PersistentSegTree pst(n + q); // Estimate total updates
    vector<i32> roots(n + 1, 0);
    // Build initial tree versions
    fr(i, 1, n + 1) {
        roots[i] = pst.update(roots[i - 1], 1, K, get_rank(a[i - 1]), 1);
    }
    // 4. Process Queries
    while(q--) {
       // Answer using roots array...
    }
    
}