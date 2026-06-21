// --------- Rolling Hash ---------
struct hasher {
    int n, k, p;
    string s;
    vector<int> powk, base, rev;

    void init(const string &_s, int _k, int _p) {
        s = _s;
        k = _k;
        p = _p;
        n = s.size();

        powk.assign(n + 1, 1);
        base.assign(n + 1, 0);
        rev.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int num = s[i] - 'a' + 1;
            base[i + 1] = (1LL * base[i] * k + num) % p;
            powk[i + 1] = (1LL * powk[i] * k) % p;
        }

        for (int i = n - 1; i >= 0; i--) {
            int num = s[i] - 'a' + 1;
            rev[i] = (1LL * rev[i + 1] * k + num) % p;
        }
    }

    // forward hash [l, r]
    int getFhash(int l, int r) const {
        if (l > r)
            return 0;
        int res = base[r + 1] - 1LL * base[l] * powk[r - l + 1] % p;
        return (res + p) % p;
    }


    // reverse hash [l, r]
    int getRhash(int l, int r) const {
        if (l > r)
            return 0;
        int res = rev[l] - 1LL * rev[r + 1] * powk[r - l + 1] % p;
        return (res + p) % p;
    }
};
