// Returns gcd(a, b) and updates x and y such that a*x + b*y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) 
{
    if (b == 0) 
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}