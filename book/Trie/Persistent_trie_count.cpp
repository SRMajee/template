struct PersistentTrieCount {
    static const int LOG = 31;

    struct node {
        int cnt;
        node *child[2];

        node() {
            cnt = 0;
            child[0] = child[1] = nullptr;
        }

        node(node *other) {
            if (other) {
                cnt = other->cnt;
                child[0] = other->child[0];
                child[1] = other->child[1];
            } else {
                cnt = 0;
                child[0] = child[1] = nullptr;
            }
        }
    };

    vector<node *> roots;

    PersistentTrieCount() {
        roots.push_back(new node()); // version 0
    }

    // -------- INSERT --------
    node *insert(node *prev, int x) {
        node *cur_new = new node(prev);
        node *cur_prev = prev;

        node *root = cur_new;

        for (int i = LOG; i >= 0; i--) {
            int b = (x >> i) & 1;

            node *next_prev = cur_prev ? cur_prev->child[b] : nullptr;
            node *next_new = new node(next_prev);

            cur_new->child[b] = next_new;

            cur_new = next_new;
            cur_prev = next_prev;

            cur_new->cnt++;
        }

        return root;
    }

    void add(int x) {
        roots.push_back(insert(roots.back(), x));
    }

    // -------- MAX XOR in [L, R] --------
    int maxXor(node *r, node *l, int x) {
        int ans = 0;

        for (int i = LOG; i >= 0; i--) {
            int b = (x >> i) & 1;
            int want = 1 ^ b;

            int cntR = (r && r->child[want]) ? r->child[want]->cnt : 0;
            int cntL = (l && l->child[want]) ? l->child[want]->cnt : 0;

            if (cntR - cntL > 0) {
                ans |= (1LL << i);
                r = r->child[want];
                l = l ? l->child[want] : nullptr;
            } else {
                r = r->child[b];
                l = l ? l->child[b] : nullptr;
            }
        }

        return ans;
    }

    int rangeMaxXor(int L, int R, int x) {
        return maxXor(roots[R], roots[L - 1], x);
    }

    // -------- COUNT <= K --------
    int countLessOrEqual(node *r, node *l, int x, int k) {
        int res = 0;

        for (int i = LOG; i >= 0; i--) {
            if (!r) break;

            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                int cntR = r->child[xb] ? r->child[xb]->cnt : 0;
                int cntL = l && l->child[xb] ? l->child[xb]->cnt : 0;
                res += cntR - cntL;

                r = r->child[1 ^ xb];
                l = l ? l->child[1 ^ xb] : nullptr;
            } else {
                r = r->child[xb];
                l = l ? l->child[xb] : nullptr;
            }
        }

        return res;
    }

    // -------- KTH SMALLEST --------
    int kth(node *r, node *l, int k) {
        int ans = 0;

        for (int i = LOG; i >= 0; i--) {
            int cntR = r->child[0] ? r->child[0]->cnt : 0;
            int cntL = l && l->child[0] ? l->child[0]->cnt : 0;

            int leftCount = cntR - cntL;

            if (k <= leftCount) {
                r = r->child[0];
                l = l ? l->child[0] : nullptr;
            } else {
                ans |= (1LL << i);
                k -= leftCount;
                r = r->child[1];
                l = l ? l->child[1] : nullptr;
            }
        }

        return ans;
    }
};
