int n, m, k, q;
string l, r;
int dp[10010][2][2][105];
int rec(int level, int tlo, int thi, int sum) {
    if (level == n) {
        return (sum == 0);
    }
    int &t = dp[level][tlo][thi][sum];
    if (t != -1)
        return t;
    int ans = 0;
    int lo = (tlo == 1) ? (l[level] - '0') : 0;
    int hi = (thi == 1) ? (r[level] - '0') : 9;
    fr(i, lo, hi + 1) {
        int ntlo = tlo && (i == l[level] - '0');
        int nthi = thi && (i == r[level] - '0');
        ans = add(ans, rec(level + 1, ntlo, nthi, (sum + i) % m));
    }
    return t = ans;
}

void solve() {
    cin >> r >> m;
    string t = "1";
    int cnt = SZ(r) - SZ(t);
    l = string(cnt, '0') + t;
    MEM(dp, -1);
    n = SZ(r);
    int ans = rec(0, 1, 1, 0);
    cout << ans << endl;
}
