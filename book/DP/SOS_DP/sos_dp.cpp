const ll MLOG = 20;
const ll MAXN = (1 << MLOG);
// finding subsets
void forward1(ll dp[])
{
    fr(bit, 0, MLOG)
        fr(i, 0, MAXN) if (!((i >> bit) & 1)) { dp[i] += dp[i ^ (1 << bit)]; }
}

// removing subsets
void backward1(ll dp[])
{
    fr(bit, 0, MLOG)
        frn(i, MAXN - 1, 0) if (!((i >> bit) & 1)) { dp[i] -= dp[i ^ (1 << bit)]; }
}

// finding supersets
void forward2(ll dp[])
{
    fr(bit, 0, MLOG)
        fr(i, 0, MAXN) if (!((i >> bit) & 1)){dp[i] += dp[i ^ (1 << bit)];}
}

// removing supersets

void backward2(ll dp[])
{
    fr(bit, 0, MLOG)
        frn(i, MAXN - 1, 0) if (!((i >> bit) & 1)){dp[i] -= dp[i ^ (1 << bit)]; }
}
