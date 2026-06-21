inline int floordiv(int p, int q)
{
    if (q < 0) p = -p, q = -q;
    return (p >= 0 ? p / q : -((-p + q - 1) / q));
}

inline int ceildiv(int p, int q) { return -floordiv(-p, q); }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

pll get_red_frac(ll a, ll b)
{
    if (a == 0 && b == 0) return MP(0, 0);
    if (a == 0) return MP(0, 1);
    if (b == 0) return MP(1, 0);
    int neg = 1;
    if (a < 0)
    {
        a *= -1;
        neg *= -1;
    }
    if (b < 0)
    {
        b *= -1;
        neg *= -1;
    }
    ll g = __gcd(a, b);
    return MP(neg * a / g, b / g);
}