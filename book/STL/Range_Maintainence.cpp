
// ---------- Range Maintanence -----------
struct range_maintanence {
    set<ii> st;

    void add(int l, int r) {
        auto it = st.lb({l, -1});
        // finding min it ranges in which l lies
        if (it != st.begin() && (--it)->second < l) ++it;

        while (it != st.end() && it->F <= r) {
            l = min(l, it->F);
            r = max(r, it->S);
            it = st.erase(it);
        }
        st.insert({l, r});
    }

    void remove(int l, int r) {
        auto it = st.lb({l, -1});
        // finding min it ranges in which l lies
        if (it != st.begin() && (--it)->second < l) ++it;

        while (it != st.end() && it->F <= r) {
            int L = it->F, R = it->S;
            it = st.erase(it);
            if (L < l) st.insert({L, l - 1});
            if (R > r) st.insert({r + 1, R});
        }
    }

    bool checkPoint(int x) {
        auto it = st.ub({x, INF});
        return it != st.begin() && (--it)->S >= x;
    }

    bool check_interval_any(int l, int r) {
        auto it = st.ub({l, INF});
        return (it != st.end() && it->F <= r) || checkPoint((l));
    }

    bool check_interval_all(int l, int r) {
        auto it = st.ub({l, INF});
        return it != st.begin() && (--it)->S >= r;
    }
};
