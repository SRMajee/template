// --------- Double Hash ----------
struct double_hash
{
    string s;
    int n;
    hasher a, b;

    void init(const string &_s)
    {
        s = _s;
        n = s.size();
        a.init(s, 37, PRIME_1);
        b.init(s, 39, PRIME_2);
    }

    pair<int, int> getFhash(int l, int r) const
    {
        return {a.getFhash(l, r), b.getFhash(l, r)};
    }

    pair<int, int> getRhash(int l, int r) const
    {
        return {a.getRhash(l, r), b.getRhash(l, r)};
    }

    bool isPal(int l, int r) const
    {
        if (l < 0 || r >= n || l > r)
            return false;
        return getFhash(l, r) == getRhash(l, r);
    }

    // lexicographical comparison of s[i..i+len-1] and s[j..j+len-1]
    // returns:  0 equal, 1 if first smaller, -1 otherwise
    int lexOrder(int i, int j, int len) const
    {
        int lo = 0, hi = len, lcp = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (getFhash(i, i + mid - 1) == getFhash(j, j + mid - 1))
            {
                lcp = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        if (lcp == len)
            return 0;
        return (s[i + lcp] < s[j + lcp]) ? 1 : -1;
    }

    // -------- Palindrome expansion check --------
    bool palCenter(int l, int r, int k) const
    {
        return (l - k >= 0 && r + k < n &&
                getFhash(l - k, l + k) == getRhash(r - k, r + k));
    }

    // -------- Longest common prefix with another string --------
    inline bool checkPrefix(const double_hash &other,
                            int mid, int x1, int x2) const
    {
        return getFhash(x1, x1 + mid - 1) ==
               other.getFhash(x2, x2 + mid - 1);
    }

    int lcp(const double_hash &other, int x1, int x2) const
    {
        int lo = 0;
        int hi = min(n - x1, other.n - x2);
        int ans = 0;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (mid == 0 || checkPrefix(other, mid, x1, x2))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
    int findOcc(int l, int r)
    {
        int cnt = 0;
        int k = r - l + 1;
        for (int i = 0; i <= n - k; i++)
        {
            if (getFhash(i, i + k - 1) == getFhash(l, r))
                cnt++;
        }
        return cnt;
    }
};
