// ---------- Running Mean Median Mode -----------
struct running_mmm {
    multiset<int> lo, hi; // lo = upper half, hi = lower half
    map<int,int> freq; // number -> frequency
    map<int, set<int> > bucket; // frequency -> set of numbers
    ll sum, sumsq; // kept modulo MOD
    int n;

    running_mmm() : sum(0), sumsq(0), n(0) {
    }

    void rebalance() {
        // ensure lo has the median (or extra element if odd)
        if (lo.size() > hi.size() + 1) {
            // move smallest from lo -> hi
            auto it = lo.begin();
            hi.insert(*it);
            lo.erase(it);
        } else if (lo.size() < hi.size()) {
            // move largest from hi -> lo
            auto it = prev(hi.end());
            lo.insert(*it);
            hi.erase(it);
        }
    }

    void insert(int x) {
        // pick side based on smallest element in lo (lo = upper half)
        if (lo.empty() || x >= *lo.begin()) {
            lo.insert(x);
        } else {
            hi.insert(x);
        }
        n++;
        sum = add(sum, x);
        sumsq = add(sumsq, mul(x, x));
        rebalance();

        // mode update
        int old = freq[x];
        if (old > 0) {
            bucket[old].erase(x);
            if (bucket[old].empty()) bucket.erase(old);
        }
        freq[x]++;
        bucket[freq[x]].insert(x);
    }

    void erase(int x) {
        if (freq[x] == 0) return; // not present (though problem guarantees presence)

        // erase from whichever multiset contains it
        auto itlo = lo.find(x);
        if (itlo != lo.end()) lo.erase(itlo);
        else {
            auto ithi = hi.find(x);
            if (ithi != hi.end()) hi.erase(ithi);
            // else: shouldn't happen if freq>0
        }

        n--;
        sum = sub(sum, x);
        sumsq = sub(sumsq, mul(x, x));
        rebalance();

        // mode update
        int old = freq[x];
        bucket[old].erase(x);
        if (bucket[old].empty()) bucket.erase(old);
        freq[x]--;
        if (freq[x] > 0) bucket[freq[x]].insert(x);
        else freq.erase(x);
    }

    int getMean() {
        return n == 0 ? -1 : mul(sum, inv(n));
    }

    int getMode() {
        if (n == 0) return -1;
        auto it = prev(bucket.end()); // max frequency
        return *it->second.begin(); // smallest number among those with max freq
    }

    int getMedian() {
        if (n == 0) return -1;
        if (n & 1) {
            // odd -> smallest element of lo (lo has the extra element)
            return *lo.begin() % MOD;
        } else {
            // even -> average of largest of hi and smallest of lo
            ll a = *prev(hi.end()); // largest of lower half
            ll b = *lo.begin(); // smallest of upper half
            a %= MOD;
            if (a < 0) a += MOD;
            b %= MOD;
            if (b < 0) b += MOD;
            add(a, b); // a = (a + b) % MOD
            return mul(a, inv(2));
        }
    }
};