struct PersistentTrieTime {
    static const int LOG = 31;

    struct node {
        int time;
        node *child[2];

        node() {
            time = -1;
            child[0] = child[1] = nullptr;
        }

        node *clone() {
            node *cur = new node();
            cur->time = time;
            cur->child[0] = child[0];
            cur->child[1] = child[1];
            return cur;
        }

        bool exists(int l) {
            return this && time >= l;
        }
    };

    vector<node *> version;
    node *last;

    PersistentTrieTime(int n = 2e5) {
        version.resize(n + 5);
        last = new node();
        version[0] = last;
    }

    // -------- INSERT --------
    void insert(int x, int idx) {
        node *v = last->clone();
        version[idx] = v;

        for (int i = LOG; i >= 0; i--) {
            int b = (x >> i) & 1;

            if (!v->child[b])
                v->child[b] = new node();
            else
                v->child[b] = v->child[b]->clone();

            v = v->child[b];
            v->time = idx;
        }

        last = version[idx];
    }

    // -------- MAX XOR --------
    int maxXor(node *root, int x, int l) {
        node *v = root;
        int ans = 0;

        for (int i = LOG; i >= 0; i--) {
            int b = (x >> i) & 1;

            if (v->child[1 ^ b] && v->child[1 ^ b]->exists(l)) {
                ans |= (1LL << i);
                v = v->child[1 ^ b];
            } else {
                v = v->child[b];
            }
        }

        return ans;
    }

    int rangeMaxXor(int l, int r, int x) {
        return maxXor(version[r], x, l);
    }

    // -------- MIN XOR --------
    int minXor(node *root, int x, int l) {
        node *v = root;
        int ans = 0;

        for (int i = LOG; i >= 0; i--) {
            int b = (x >> i) & 1;

            if (v->child[b] && v->child[b]->exists(l)) {
                v = v->child[b];
            } else {
                ans |= (1LL << i);
                v = v->child[1 ^ b];
            }
        }

        return ans;
    }
};
