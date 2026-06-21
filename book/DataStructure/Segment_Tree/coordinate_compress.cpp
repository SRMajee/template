/*
* TO-DO
 * 1. toggle x
 * 2. # of elements <= k
 */
struct Coordinate_compress {
    map<int,int> compVal;
    vi rev;
    int cnt;

    void add(int x) { compVal[x]; }

    void build() {
        cnt = 0;
        for (auto &[key,val]: compVal) {
            val = cnt++;
            rev.eb(key);
        }
    }

    inline int getComp(int x) { return compVal[x]; }
    inline int getRev(int x) { return rev[x]; }

    int getPrev(int x) {
        auto it = compVal.ub(x);
        --it;
        return it->S;
    }

    int getNext(int x) {
        auto it = compVal.lb(x);
        return it->S;
    }
};