// -------------- Dikjstra -------------
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;

void sssp(int sc) {
    vis.assign(n + 1, 0);
    dis.assign(n + 1, INFL);
    min_heap<ii> q;
    dis[sc] = 0;
    q.push({0, sc}); // { cost, node }
    while (!q.empty()) {
        int x = q.top().S;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto &v: g[x]) {
            if (dis[v.F] > dis[x] + v.S) {
                dis[v.F] = dis[x] + v.S;
                q.push({dis[v.F], v.F});
            }
        }
    }
}
