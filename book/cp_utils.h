//
// Created by User on 11/6/2025.
//

#ifndef CP_UTILS_H
#define CP_UTILS_H

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// =================== BASIC TYPE ALIASES ===================
#define ll long long
#define int long long
#define ld long double
#define endl '\n'

// =================== MACROS ===================
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
#define uset unordered_set
#define umap unordered_map
#define MEM(a, v) memset(a, v, sizeof(a))

// =================== TYPE SHORTCUTS ===================
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
using ii = pair<int,int>;
using pll = pair<ll,ll>;
using vii = vector<ii>;
using vll = vector<pll>;
using vvii = vector<vii>;
using vvll = vector<vll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i128 = __int128_t;
using ui128 = __uint128_t;

// =================== TEMPLATE ARRAYS ===================
template<typename T, size_t N>
using arr_ = array<T, N>;

template<typename T, size_t N, size_t M>
using arr2_ = array<array<T, M>, N>;

template<typename T, size_t N, size_t M, size_t P>
using arr3_ = array<array<array<T, P>, M>, N>;

// =================== PRIORITY QUEUES ===================
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template<class T>
using max_heap = priority_queue<T>;

// =================== PBDS STRUCTURES ===================
// Ordered Set
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered Multiset
template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered Map
template<class K, class V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// Hash Table (fast alternative to unordered_map)
template<class K, class V>
using hash_map = __gnu_pbds::gp_hash_table<K, V>;

template<class K>
using hash_set = __gnu_pbds::gp_hash_table<K, null_type>;

// Size of container
template <typename T> int SZ(const T& x) { return static_cast<int>(x.size()); }

// =================== CONSTANTS ===================
const ll INFL = 1e18;
const ll INF = 1e9;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 100;
const int NCRange = 1001;
const ld EPS = 1e-7;
const int PRIME_1 = 1000000021;
const int PRIME_2 = 1000000009;
const int PRIME_3 = 999999929;

#endif // CP_UTILS_H
