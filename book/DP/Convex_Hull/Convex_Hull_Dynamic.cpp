bool Q;

struct Line {
    mutable ll k, m, p; // slope, y-intercept, last optimal x
    bool operator<(const Line &o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
    bool isMin;


    void init(bool isMin_ = false) {
        isMin = isMin_;
        this->clear();
    }

    // Internal function: Always maintains Upper Hull logic
    void add_line(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }

    // Public function: Handles the negation for Min queries
    void add(ll k, ll m) {
        if (isMin) k = -k, m = -m;
        add_line(k, m);
    }

    const ll inf = LLONG_MAX;

    ll div(ll a, ll b) {
        // floored division
        if (b < 0) a *= -1, b *= -1;
        if (a >= 0) return a / b;
        return -((-a + b - 1) / b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return 0;
        }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }

    ll query(ll x) {
        assert(!empty());
        Q = 1;
        auto l = *lower_bound({0, 0, x});
        Q = 0;
        ll val = l.k * x + l.m;
        // Return negated value if we are in Min mode
        return isMin ? -val : val;
    }
};

// Global buffer instance
LineContainer cht;

void convexsum(LineContainer &a, LineContainer &b) {
    // 1. Reset cht logic to match the inputs
    cht.clear();
    cht.isMin = a.isMin;

    auto it1 = a.begin(), it2 = b.begin();
    while (it1 != a.end() && it2 != b.end()) {
        // IMPORTANT: Use add_line (Raw) to sum internal values directly.
        cht.add_line((it1->k) + (it2->k), (it1->m) + (it2->m));

        if ((it1->p) < (it2->p)) it1++;
        else it2++;
    }
}

void mergeall(int l, int r, vector<LineContainer> &paths) {
    if (l == r) return;
    int mid = (l + r) / 2;

    mergeall(l, mid, paths);
    mergeall(mid + 1, r, paths);

    convexsum(paths[l], paths[mid + 1]);

    // 2. Transfer from cht back to paths[l]
    // Note: cht already holds raw "upper hull" values, so we use add_line
    // to copy them without re-negating.
    for (auto it: cht) paths[l].add_line(it.k, it.m);
}
