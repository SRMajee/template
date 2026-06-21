#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
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
#define uset unordered_set
#define umap unordered_map
#define MEM(a, v) memset(a, v, sizeof(a))
#define PI acosl(-1.0L)
#define endl '\n'
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define fr3(i, a, b) for (int i = (a); i < (b); ++i)
#define fr4(i, a, b, s) for (int i = (a); i < (b); i += (s))
#define fr(...) GET_MACRO(__VA_ARGS__, fr4, fr3)(__VA_ARGS__)
#define frn3(i, a, b) for (int i = (a); i >= (b); --i)
#define frn4(i, a, b, s) for (int i = (a); i >= (b); i -= (s))
#define frn(...) GET_MACRO(__VA_ARGS__, frn4, frn3)(__VA_ARGS__)
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
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
using vvll = vector<vll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
const int MAX_S = 300005;
typedef bitset<MAX_S> BS;
using vbs = vector<BS>;
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i128 = __int128_t;
using ui128 = __uint128_t;
ostream &operator<<(ostream &os, i128 n)
{
    if (n < 0)
    {
        os << '-';
        n = -n;
    }
    if (n > 9)
        os << (n / 10);
    return os << (char)(n % 10 + '0');
}
template <typename T, size_t N>
using arr_ = array<T, N>;
template <typename T, size_t N, size_t M>
using arr2_ = array<array<T, M>, N>;
template <typename T, size_t N, size_t M, size_t P>
using arr3_ = array<array<array<T, P>, M>, N>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;
// ORDERED SET (supports order statistics)
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered multiset (allow duplicates)
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ORDERED MAP (like map but with order statistics)
template <class K, class V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// HASH TABLES (fast, like unordered_map/unordered_set but safer)
template <class K, class V>
using hash_map = __gnu_pbds::gp_hash_table<K, V>;
template <class K>
using hash_set = __gnu_pbds::gp_hash_table<K, null_type>;

template <typename T>
int SZ(const T &x) { return static_cast<int>(x.size()); }

const int PRIME_1 = 1000000021;
const int PRIME_2 = 1000000009;
const int PRIME_3 = 1000000007;
const int PRIME_4 = 999999929;
const int PRIME_5 = 998244353;
const ll INFL = 1e18;
const ll INF = 1e9;
const int MOD = PRIME_2;
const int MLOG = 17;
const int MAXN = 1 << MLOG;
const int NCRange = 1001;
const ld EPS = 1e-7;
static int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
const int P = 16;

// // --------------- Debuggers --------------------
// #define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
// #define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
// #define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
// // 1. Container Overloads MUST come first
// template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
// template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T> ostream& operator <<(ostream& os, const deque<T>& p) { os << "[ "; for (auto& it : p) os << it << " "; return os << "]"; }
// template <class T> ostream& operator <<(ostream& os, const list<T>& p) { os << "[ "; for (auto& it : p) os << it << " "; return os << "]"; }
// // Adapters
// template <class T> ostream& operator <<(ostream& os, queue<T> q) { os << "[ "; while (!q.empty()) { os << q.front() << " "; q.pop(); } return os << "]"; }
// template <class T> ostream& operator <<(ostream& os, stack<T> s) { os << "[ "; while (!s.empty()) { os << s.top() << " "; s.pop(); } return os << "](top)"; }
// template <class T, class Container, class Compare> ostream& operator <<(ostream& os, priority_queue<T, Container, Compare> pq) { os << "[ "; while (!pq.empty()) { os << pq.top() << " "; pq.pop(); } return os << "]"; }
// // PBDS
// template <class T, class cmp> ostream& operator <<(ostream& os, const tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>& p) { os << "[ "; for (auto& it : p) os << it << " "; return os << "]"; }
// template <class K, class V, class cmp> ostream& operator <<(ostream& os, const tree<K, V, cmp, rb_tree_tag, tree_order_statistics_node_update>& p) { os << "[ "; for (auto& it : p) os << it << " "; return os << "]"; }
// // 2. Debug Functions come AFTER overloads so they can use them
// template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
// template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
// template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

// --------- Fast I/O ---------
inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
// ------------------ Seg tree helpers ----------------
inline int LC(int i) { return (i << 1); }     // same as 2*i
inline int RC(int i) { return (i << 1) | 1; } // same as 2*i + 1
inline int apsum(int a, int d, int no) { return (no * (2 * a + (no - 1) * d)) / 2; }
inline int nth(int a, int d, int nn) { return a + (nn - 1) * d; }
inline ld gpterm(ld a, ld r, int n) { return a * powl(r, n - 1); }
inline ld gpsum(ld a, ld r, int n)
{
    if (r == 1.0L)
        return a * n;
    return a * (powl(r, n) - 1) / (r - 1);
}
ll binpow(ll a, ll e, ll m = MOD)
{
    int res = 1;
    a %= m;
    while (e)
    {
        if (e & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return res;
}
ll inv(ll a, ll m = MOD) { return binpow(a, m - 2, m); }
// ------------------- Mod add,sub,mul,div helper-----------------
inline ll add(ll a, ll b, ll m = MOD)
{
    a += b;
    return a >= m ? a - m : a;
}
inline ll sub(ll a, ll b, ll m = MOD)
{
    a -= b;
    return a < 0 ? a + m : a;
}
inline ll mul(ll a, ll b, ll m = MOD) { return (a * b) % m; }
inline ll _div(ll a, ll b, ll m = MOD) { return (a * inv(b, m)) % m; }
inline ii add_ii(const ii &a, const ii &b) { return MP(add(a.F, b.F), add(a.S, b.S)); }
inline ii sub_ii(const ii &a, const ii &b) { return MP(sub(a.F, b.F), sub(a.S, b.S)); }

// ---------- Random between a and b -----------
inline int get_random(int a, int b) { return a + rand() % (b - a + 1); }
// ---------- Random no gen -------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

using state = tuple<int, int, int>;
using vS = vector<state>;
// --------- Solve ---------
int n, m, k, q, l, r;
vi v;
string s;

void solve()
{
    cin >> n >> k;
    v.clear();
    v.assign(n, 0);
    fr(i, 0, n)
    {
        cin >> v[i];
    }
}

signed main()
{
    fastio();
    // pre_divisors();
    // sieve();
    // linear_sieve(MAXN);
    // pre_ncr();
    // compute_prefixNCR(n,k);
    // gen_n_fib_no();
    int _t = 1;
    // cin >> _t;
    while (_t--)
        solve();
}
