inline int LC(int i) { return (i << 1); } // same as 2*i
inline int RC(int i) { return (i << 1) | 1; } // same as 2*i + 1
inline int apsum(int a, int d, int no) { return (no * (2 * a + (no - 1) * d)) / 2; }
inline int nth(int a, int d, int nn) { return a + (nn - 1) * d; }
inline ld gpterm(ld a, ld r, int n) { return a * powl(r, n - 1); }

inline ld gpsum(ld a, ld r, int n) {
    if (r == 1.0L)
        return a * n;
    return a * (powl(r, n) - 1) / (r - 1);
}

inline ii add_ii(const ii &a, const ii &b) { return MP(add(a.F, b.F), add(a.S, b.S)); }
inline ii sub_ii(const ii &a, const ii &b) { return MP(sub(a.F, b.F), sub(a.S, b.S)); }
int n, k;
int v[MAXN];
