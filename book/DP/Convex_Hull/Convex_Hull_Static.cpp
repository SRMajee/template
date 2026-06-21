struct CHT {
    vector<pair<ll, ll> > hull; // Stores {m, c}
    vector<int> id; // Stores the index (optional, but part of your struct)
    int cur = 0;
    bool isMin;

    void init(bool isMin_ = false) {
        isMin = isMin_;
        hull.clear();
        id.clear();
        cur = 0;
    }

    // Geometry check for Convex Hull
    bool useless(const pair<ll, ll> &left, const pair<ll, ll> &middle, const pair<ll, ll> &right) {
        // Cross product to check intersection order
        // (c2 - c1) * (m2 - m3) >= (c3 - c2) * (m1 - m2)
        // Note: Logic works for both min/max because signs are handled in insert/query
        return
                (__int128) (middle.second - left.second) * (middle.first - right.first) >=
                (__int128) (right.second - middle.second) * (left.first - middle.first);
    }

    void insert(int idx, ll m, ll c) {
        // If Min query, flip signs to convert to Max query logic
        if (isMin) m = -m, c = -c;

        if (hull.empty()) {
            hull.push_back({m, c});
            id.push_back(idx);
        } else {
            // Handle parallel lines (same slope)
            if (hull.back().first == m) {
                // Keep the one with better intercept
                if (hull.back().second >= c) return;
                hull.pop_back();
                id.pop_back();
            }
            // Maintain Convexity
            while (hull.size() >= 2 && useless(hull[hull.size() - 2], hull.back(), {m, c})) {
                hull.pop_back();
                id.pop_back();
            }
            hull.push_back({m, c});
            id.push_back(idx);
        }
    }

    /*
     * best.first: The numeric value you add to your current DP[i] calculation.
     * best.second: The index j where the previous group ended (useful for backtracking).
     */
    pair<ll, int> query(ll x) {
        if (hull.empty()) return {0, -1};

        // Pointer optimization (Valid because x is monotonic increasing)
        if (cur >= hull.size()) cur = hull.size() - 1;
        while (cur + 1 < hull.size()) {
            ll val1 = hull[cur].first * x + hull[cur].second;
            ll val2 = hull[cur + 1].first * x + hull[cur + 1].second;
            if (val2 >= val1) cur++;
            else break;
        }

        ll ret = hull[cur].first * x + hull[cur].second;
        int idx = id[cur];

        // Flip result back if we are in Min mode
        return {isMin ? -ret : ret, idx};
    }
};
