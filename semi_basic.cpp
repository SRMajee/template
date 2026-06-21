#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define ld long double
#define fr(i, a, b) for (int i = (a); i < (b); i++)
#define frn(i, a, b) for (int i = (a); i >= (b); i--)
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

template <typename T>
int SZ(const T &x) { return static_cast<int>(x.size()); }

using vi = vector<int>;
using vvi = vector<vi>;
using mii = map<int, int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vvvii = vector<vvii>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const int MAX_S = 300005;
typedef bitset<MAX_S> BS;
using vbs = vector<BS>;

const int PRIME_1 = 1000000021;
const int PRIME_2 = 1000000009;
const int PRIME_3 = 999999929;
const int PRIME_4 = 998244353;
const ll INFL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MLOG = 17;
const int MAXN = 1 << MLOG;
const ld EPS = 1e-7;

// #define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
// #define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
// #define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
// template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
// template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
// template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
// template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
// template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
inline ll add(ll a, ll b, ll m = MOD) { return (a + (b % m) + m) % m; }
inline ll sub(ll a, ll b, ll m = MOD) { return (a - (b % m) + m) % m; }
inline ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
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
    int _t = 1;
    // cin >> _t;
    while (_t--)
        solve();
    return 0;
}
