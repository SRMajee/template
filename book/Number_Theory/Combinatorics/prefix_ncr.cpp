vector<vector<ll>> C;
vector<vector<ll>> prefix_NCR;

void compute_prefixNCR()
{
    C.assign(NCRange, vector<ll>(NCRange, 0));
    prefix_NCR.assign(NCRange, vector<ll>(NCRange, 0));
    
    int n = NCRange - 1, k = NCRange - 1;
    for (int i = 0; i <= n; i++)
    {
        prefix_NCR[i][0] = C[i][0] = 1;
        for (int j = 1; j <= min(i, k); j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
        for (int j = 1; j <= min(i, k); j++)
        {
            prefix_NCR[i][j] = (prefix_NCR[i][j - 1] + C[i][j]) % MOD;
        }
    }
}