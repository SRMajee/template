using Matrix = vector<vector<ll>>;

Matrix mat_mul(Matrix const& a, Matrix const& b) 
{
    int n = a.size();
    int m = b[0].size();
    int p = b.size();
    Matrix res(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            for (int k = 0; k < p; k++) 
            {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix mat_pow(Matrix a, ll p) 
{
    int n = a.size();
    Matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1; // Identity matrix
    
    while (p > 0) 
    {
        if (p & 1) res = mat_mul(res, a);
        a = mat_mul(a, a);
        p >>= 1;
    }
    return res;
}