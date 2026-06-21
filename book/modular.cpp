

// 1. The Modular Class Template
template <typename T>
struct Modular
{
    constexpr static int modulus = T::value;
    int value;
    Modular(ll v = 0)
    {
        value = v % modulus;
        if (value < 0)
            value += modulus;
    }
    Modular(ll a, ll b) : value(0)
    {
        *this += a;
        *this /= b;
    }
    Modular &operator+=(Modular const &b)
    {
        value += b.value;
        if (value >= modulus)
            value -= modulus;
        return *this;
    }
    Modular &operator-=(Modular const &b)
    {
        value -= b.value;
        if (value < 0)
            value += modulus;
        return *this;
    }
    Modular &operator*=(Modular const &b)
    {
        value = (ll)value * b.value % modulus;
        return *this;
    }
    friend Modular m_exp(Modular a, ll e)
    {
        Modular res = 1;
        while (e)
        {
            if (e & 1)
                res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Modular inverse(Modular a)
    {
        return m_exp(a, modulus - 2);
    }
    Modular &operator/=(Modular const &b)
    {
        return *this *= inverse(b);
    }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, Modular const &a) { return os << a.value; }
    friend std::istream &operator>>(std::istream &is, Modular &a)
    {
        ll x;
        is >> x;
        a = Modular(x);
        return is;
    }
    friend bool operator==(Modular const &a, Modular const &b) { return a.value == b.value; }
    friend bool operator!=(Modular const &a, Modular const &b) { return a.value != b.value; }
};
constexpr int md = 998244353; // Or 1000000007
using Mint = Modular<std::integral_constant<int, md>>;
