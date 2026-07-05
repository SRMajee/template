struct Fenwick
{
    int n;
    vl bit;

    Fenwick(int n = 0) { init(n); }

    void init(int n_)
    {
        n = n_;
        bit.assign(n + 1, 0);
    }

    // Build from 1-indexed array a[1..n] in O(n)
    void build(const vl &a)
    {
        // a.size() should be n+1 with a[0] dummy
        init((int)a.size() - 1);
        for (int i = 1; i <= n; i++)
            bit[i] = a[i];
        for (int i = 1; i <= n; i++)
        {
            int j = i + (i & -i);
            if (j <= n)
                bit[j] += bit[i];
        }
    }

    // add x at index i
    inline void add(int i, ll x)
    {
        for (; i <= n; i += i & -i)
            bit[i] += x;
    }

    // prefix query [1..i]
    inline ll query(int i) const
    {
        ll r = 0;
        for (; i > 0; i -= i & -i)
            r += bit[i];
        return r;
    }

    // range query [l..r]
    inline ll query(int l, int r) const
    {
        if (r < l)
            return 0;
        return query(r) - query(l - 1);
    }

    // smallest idx such that prefix query >= target
    // if target <= 0 returns 1; if target > total, returns n+1 (clamp outside)
    // Returns the 0-indexed k-th smallest element (k=0 for 1st element)
    int find_by_order(int k)
    {
        int idx = 0;
        // __lg(N) is a GCC built-in that returns floor(log2(N))
        for (int i = 1 << __lg(n); i > 0; i >>= 1)
        {
            if (idx + i <= n && bit[idx + i] <= k)
            {
                k -= bit[idx + i];
                idx += i;
            }
        }
        return idx + 1;
    }
};
