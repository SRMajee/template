// ---------- Range Add, Point Query ----------
struct RangeAddPointQuery {
    Fenwick F; // holds difference array
    RangeAddPointQuery(int n = 0) { init(n); }

    void init(int n) {
        F.init(n);
    }

    // add x to [l..r]
    void add(int l, int r, ll x) {
        if (l > r) return;
        F.add(l, x);
        if (r + 1 <= F.n)
            F.add(r + 1, -x);
    }

    // value at index i
    ll get(int i) const { return F.query(i); }
};
