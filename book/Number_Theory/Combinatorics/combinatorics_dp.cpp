vvi nCr;

void precompute_nCr(int x)
{
    nCr.assign(x + 2, vi(x + 2, 0));
    for (int i = 0; i <= x; ++i)
    {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
        }
    }
}