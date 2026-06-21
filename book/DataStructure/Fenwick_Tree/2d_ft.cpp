// 2D Fenwick Tree
struct FenwickTree {
    int N;
    unordered_map<int, ll> bit; // Sparse array using map

    // Default constructor is sufficient for sparse map
    FenwickTree(int n = 1e9) : N(n) {
    }

    void addat(int idx, ll val) {
        // Standard Fenwick update loop
        for (; idx <= N; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    ll getsum(int idx) {
        ll sum = 0;
        // Standard Fenwick query loop
        for (; idx > 0; idx -= idx & -idx) {
            if (bit.count(idx)) sum += bit[idx];
        }
        return sum;
    }
};

struct Fenwick2D {
    int N; // Limit for X coordinate
    int M; // Limit for Y coordinate (added for inner tree limit)
    unordered_map<int, FenwickTree> fen;

    // Modified constructor to take N (and optional M)
    Fenwick2D(int n, int m = 1e9) {
        N = n;
        M = m;
    }

    // Prefix sum query: Sum from (1, 1) to (x, y)
    ll getsum(int x, int y) {
        ll sum = 0;
        while (x > 0) {
            // Access inner Fenwick for this x-node
            if (fen.count(x)) {
                sum += fen[x].getsum(y);
            }
            x -= (x & -x);
        }
        return sum;
    }

    // Point update: Add v to (x, y)
    void addat(int x, int y, ll v) {
        while (x <= N) {
            // fen[x] creates a new FenwickTree if it doesn't exist
            if (fen.find(x) == fen.end()) {
                fen[x] = FenwickTree(M);
            }
            fen[x].addat(y, v);
            x += (x & -x);
        }
    }

    // Helper: Range Query using Inclusion-Exclusion
    ll query(int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return 0;
        return getsum(x2, y2)
               - getsum(x1 - 1, y2)
               - getsum(x2, y1 - 1)
               + getsum(x1 - 1, y1 - 1);
    }
};
