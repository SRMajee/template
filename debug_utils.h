//
// Created by User on 10/16/2025.
//

#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#ifndef ONLINE_JUDGE
    #define DEBUG_MODE 1
#else
    #define DEBUG_MODE 0
#endif

#if DEBUG_MODE
    #include <bits/stdc++.h>
    using namespace std;

    // -------------------- BASIC MACROS --------------------
    #define debarr(a,n) cerr<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<"\n";
    #define debmat(mat,row,col) cerr<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<"\n";}
    #define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
    #define LINE cerr << "LINE: " << __LINE__ << "\n";
    #define HERE cerr << "HERE\n";
    #define dbg_time(msg) cerr << "[" << msg << "] time: " << clock()*1.0/CLOCKS_PER_SEC << "s\n";

    // -------------------- PRINT OPERATORS --------------------
    template <class S, class T> ostream& operator<<(ostream& os, const pair<S, T>& p) {
        return os << "(" << p.first << ", " << p.second << ")";
    }

    template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
        os << "[ "; for (auto &x : v) os << x << " "; return os << "]";
    }

    template <class T> ostream& operator<<(ostream& os, const set<T>& v) {
        os << "[ "; for (auto &x : v) os << x << " "; return os << "]";
    }

    template <class T> ostream& operator<<(ostream& os, const multiset<T>& v) {
        os << "[ "; for (auto &x : v) os << x << " "; return os << "]";
    }

    template <class S, class T> ostream& operator<<(ostream& os, const map<S, T>& v) {
        os << "[ "; for (auto &x : v) os << "(" << x.first << ", " << x.second << ") "; return os << "]";
    }

    template <class T> ostream& operator<<(ostream& os, const unordered_set<T>& v) {
        os << "[ "; for (auto &x : v) os << x << " "; return os << "]";
    }

    template <class S, class T> ostream& operator<<(ostream& os, const unordered_map<S, T>& v) {
        os << "[ "; for (auto &x : v) os << "(" << x.first << ", " << x.second << ") "; return os << "]";
    }

    // -------------------- DEBUG PRINT FUNCTIONS --------------------
    template <class T> void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }

    template <class T, class... S> void dbs(string str, T t, S... s) {
        int idx = str.find(',');
        cerr << str.substr(0, idx) << " : " << t << ",";
        dbs(str.substr(idx + 1), s...);
    }

    template <class T> void prc(T a, T b) {
        cerr << "[";
        for (T i = a; i != b; ++i) {
            if (i != a) cerr << ", ";
            cerr << *i;
        }
        cerr << "]\n";
    }

    // -------------------- TRACE STACK (For Recursive Functions) --------------------
    struct TraceHelper {
        static inline vector<string> callstack = {};

        static void enter(const string &fn) {
            callstack.push_back(fn);
            cerr << "→ Enter: " << fn << "\n";
        }

        static void exit() {
            if (!callstack.empty()) {
                cerr << "← Exit: " << callstack.back() << "\n";
                callstack.pop_back();
            }
        }

        static void printStack() {
            cerr << "Current Call Stack:\n";
            for (auto it = callstack.rbegin(); it != callstack.rend(); ++it)
                cerr << "   ↳ " << *it << "\n";
        }
    };

    #define TRACE(name) TraceHelper __trace_instance(name)
    struct TraceHelperInstance {
        TraceHelperInstance(const string &fn) { TraceHelper::enter(fn); }
        ~TraceHelperInstance() { TraceHelper::exit(); }
    };

#else
    // -------------------- EMPTY DEFINITIONS (Online Judge Safe) --------------------
    #define debarr(a,n)
    #define debmat(mat,row,col)
    #define pr(...)
    #define LINE
    #define HERE
    #define dbg_time(msg)
    #define dbs(...)
    #define prc(a,b)
    #define TRACE(name)
    struct TraceHelperInstance {};
#endif

#endif // DEBUG_UTILS_H
