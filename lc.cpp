#define ll long long
// #define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define PF push_front
#define EB emplace_back
#define EF emplace_front
#define PPF pop_front
#define PPB pop_back
#define F first
#define S second
#define MP make_pair
#define MT make_tuple
#define MEM(a, v) memset(a, v, sizeof(a))
#define uset unordered_set
#define umap unordered_map
#define PI acosl(-1.0L)
#define fr(i, a, b) for (int i = (a); i < (b); ++i)
#define frn(i, a, b) for (int i = (a); i >= (b); --i)
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<ii>;
using vll = vector<pll>;
using vvii = vector<vii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

const ll INFL = 1e18;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 100;
const ld EPS = 1e-7;
const int PRIME_1 = 1000000021;
const int PRIME_2 = 1000000009;
const int PRIME_3 = 999999929;
const int PRIME_4 = 998244353;

inline int LC(int i) { return (i << 1); }     // same as 2*i
inline int RC(int i) { return (i << 1) | 1; } // same as 2*i + 1
template <typename T>
int SZ(const T &x) { return static_cast<int>(x.size()); }

// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
