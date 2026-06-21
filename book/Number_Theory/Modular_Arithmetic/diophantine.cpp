// Requires extgcd to be defined
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) 
{
    g = extgcd(abs(a), abs(b), x0, y0);
    if (c % g != 0) 
    {
        return false; // No solution exists
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}