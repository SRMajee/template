struct MasterPersistentTrie
{
    static const int LOG = 30;

    // Flattened structure (Structure of Arrays) for cache locality and speed
    vector<array<int, 2>> child;
    vector<int> cnt;     // Used for 1D version-range queries
    vector<int> min_idx; // Used for 2D bounded queries
    vector<int> max_idx;
    vector<int> roots;

    MasterPersistentTrie()
    {
        // PRE-ALLOCATION: Crucial for avoiding TLE from millions of push_backs
        child.reserve(7000005);
        cnt.reserve(7000005);
        min_idx.reserve(7000005);
        max_idx.reserve(7000005);
        roots.reserve(300005);

        // Dummy node 0
        child.push_back({0, 0});
        cnt.push_back(0);
        min_idx.push_back(2e9);
        max_idx.push_back(-2e9);
        roots.push_back(0);
    }

    int new_node()
    {
        int u = child.size();
        child.push_back({0, 0});
        cnt.push_back(0);
        min_idx.push_back(2e9);
        max_idx.push_back(-2e9);
        return u;
    }

    // ==========================================
    // 1. INSERTION (Iterative & Flat Array)
    // ==========================================
    int insert(int prev_root, int val, int idx)
    {
        int curr = new_node();
        int root_curr = curr;
        int prev = prev_root;

        cnt[curr] = cnt[prev] + 1;
        min_idx[curr] = min(min_idx[prev], idx);
        max_idx[curr] = max(max_idx[prev], idx);
        child[curr][0] = child[prev][0];
        child[curr][1] = child[prev][1];

        for (int i = LOG; i >= 0; i--)
        {
            int b = (val >> i) & 1;

            int nxt = new_node();
            int p_child = child[prev][b];

            if (p_child)
            {
                child[nxt][0] = child[p_child][0];
                child[nxt][1] = child[p_child][1];
                cnt[nxt] = cnt[p_child];
                min_idx[nxt] = min_idx[p_child];
                max_idx[nxt] = max_idx[p_child];
            }

            cnt[nxt]++;
            min_idx[nxt] = min(min_idx[nxt], idx);
            max_idx[nxt] = max(max_idx[nxt], idx);

            child[curr][b] = nxt;
            curr = nxt;
            prev = p_child;
        }

        roots.push_back(root_curr);
        return root_curr;
    }

    // ==========================================
    // 2. 2D BOUNDED QUERIES (Recursive with Fast Path)
    // ==========================================
    int query_max_xor_2D(int root, int val, int L, int R)
    {
        return max_xor_rec(root, val, L, R, LOG);
    }

    int query_min_xor_2D(int root, int val, int L, int R)
    {
        return min_xor_rec(root, val, L, R, LOG);
    }

    // ==========================================
    // 3. 1D VERSION-RANGE QUERIES (Iterative)
    // ==========================================
    int query_kth_smallest_1D(int root_L, int root_R, int k)
    {
        int u_L = root_L, u_R = root_R;
        int ans = 0;

        for (int i = LOG; i >= 0; i--)
        {
            int count_left = cnt[child[u_R][0]] - cnt[child[u_L][0]];

            if (count_left >= k)
            {
                u_L = child[u_L][0];
                u_R = child[u_R][0];
            }
            else
            {
                ans |= (1LL << i);
                k -= count_left;
                u_L = child[u_L][1];
                u_R = child[u_R][1];
            }
        }
        return ans;
    }

    int count_less_equal_1D(int root_L, int root_R, int val)
    {
        int u_L = root_L, u_R = root_R;
        int count = 0;

        for (int i = LOG; i >= 0; i--)
        {
            if (!u_R)
                break;

            int b = (val >> i) & 1;

            if (b == 1)
            {
                count += cnt[child[u_R][0]] - cnt[child[u_L][0]];
                u_L = child[u_L][1];
                u_R = child[u_R][1];
            }
            else
            {
                u_L = child[u_L][0];
                u_R = child[u_R][0];
            }
        }
        count += cnt[u_R] - cnt[u_L];
        return count;
    }

private:
    int max_xor_rec(int node, int val, int L, int R, int bit)
    {
        if (!node || min_idx[node] > R || max_idx[node] < L)
            return -1;

        // FAST PATH OPTIMIZATION: If subtree is strictly inside [L, R]
        if (min_idx[node] >= L && max_idx[node] <= R)
        {
            int ans = 0;
            int curr = node;
            for (int i = bit; i >= 0; i--)
            {
                int b = (val >> i) & 1;
                if (child[curr][1 ^ b])
                {
                    ans |= (1LL << i);
                    curr = child[curr][1 ^ b];
                }
                else
                {
                    curr = child[curr][b];
                }
            }
            return ans;
        }

        if (bit < 0)
            return 0;

        int b = (val >> bit) & 1;
        int best = -1;

        if (child[node][1 ^ b])
        {
            best = max_xor_rec(child[node][1 ^ b], val, L, R, bit - 1);
            if (best != -1)
                return best | (1LL << bit);
        }

        if (best == -1 && child[node][b])
        {
            best = max_xor_rec(child[node][b], val, L, R, bit - 1);
        }

        return best;
    }

    int min_xor_rec(int node, int val, int L, int R, int bit)
    {
        if (!node || min_idx[node] > R || max_idx[node] < L)
            return -1;

        // FAST PATH OPTIMIZATION
        if (min_idx[node] >= L && max_idx[node] <= R)
        {
            int ans = 0;
            int curr = node;
            for (int i = bit; i >= 0; i--)
            {
                int b = (val >> i) & 1;
                if (child[curr][b])
                {
                    curr = child[curr][b];
                }
                else
                {
                    ans |= (1LL << i);
                    curr = child[curr][1 ^ b];
                }
            }
            return ans;
        }

        if (bit < 0)
            return 0;

        int b = (val >> bit) & 1;
        int best = -1;

        if (child[node][b])
        {
            best = min_xor_rec(child[node][b], val, L, R, bit - 1);
            if (best != -1)
                return best;
        }

        if (best == -1 && child[node][1 ^ b])
        {
            best = min_xor_rec(child[node][1 ^ b], val, L, R, bit - 1);
            if (best != -1)
                return best | (1LL << bit);
        }

        return best;
    }
};