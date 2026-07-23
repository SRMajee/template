// ---------------- NODE LOGIC ---------------- //
struct Node {
    ll sum = 0;
    ll lazy = 0;
    int lc = 0; // Index of the left child in the vector
    int rc = 0; // Index of the right child in the vector
};

// ---------------- SEGMENT TREE STRUCT ---------------- //
struct SegTree {
    vector<Node> t;

    SegTree() {
        t.push_back(Node()); // 0-th index acts as a dummy/null node
        t.push_back(Node()); // 1-st index is the root
    }

    // Dynamically creates children if they don't exist yet
    void extend(int idx) {
        if (!t[idx].lc) {
            t[idx].lc = t.size();
            t.push_back(Node());
        }
        if (!t[idx].rc) {
            t[idx].rc = t.size();
            t.push_back(Node());
        }
    }

    void push(int idx, ll l, ll r) {
        if (t[idx].lazy != 0) {
            t[idx].sum += t[idx].lazy * (r - l + 1);
            if (l != r) {
                extend(idx);
                t[t[idx].lc].lazy += t[idx].lazy;
                t[t[idx].rc].lazy += t[idx].lazy;
            }
            t[idx].lazy = 0;
        }
    }

    void update(int idx, ll l, ll r, ll lq, ll rq, ll x) {
        if (!idx) return; // Failsafe
        
        push(idx, l, r);
        if (rq < l || lq > r) return;
        
        if (lq <= l && r <= rq) {
            t[idx].lazy += x;
            push(idx, l, r);
            return;
        }
        
        extend(idx);
        ll mid = l + (r - l) / 2;
        update(t[idx].lc, l, mid, lq, rq, x);
        update(t[idx].rc, mid + 1, r, lq, rq, x);
        
        t[idx].sum = t[t[idx].lc].sum + t[t[idx].rc].sum;
    }

    ll query(int idx, ll l, ll r, ll lq, ll rq) {
        if (!idx) return 0; // If node was never created, its sum is 0
        
        push(idx, l, r);
        if (rq < l || lq > r) return 0;
        if (lq <= l && r <= rq) return t[idx].sum;
        
        ll mid = l + (r - l) / 2;
        return query(t[idx].lc, l, mid, lq, rq) + query(t[idx].rc, mid + 1, r, lq, rq);
    }
};