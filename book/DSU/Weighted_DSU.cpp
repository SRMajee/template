struct WeightedDSU
{
    vi rank;
    vii par; // {parent, distance_to_parent}
    int set_size;

    // rollback info: {child, old_parent, old_dist, old_rank_of_parent}
    stack<ii> history;

    WeightedDSU(int n)
    {
        par.resize(n + 1);
        rank.assign(n + 1, 1);
        fr(i, 0, n + 1)
        {
            par[i].F = i;
            par[i].S = 0;
        }
        set_size = n;
    }

    // find root and total distance from x to root
    ii find(int x)
    {
        if (par[x].F == x)
            return par[x];
        ii y = find(par[x].F);
        return par[x] = MP(y.F, par[x].S + y.S);
    }

    // merge x and y with weight w (potential[y] = potential[x] + w)
    bool merge(int x, int y, int w)
    {
        auto [rx, dx] = find(x);
        auto [ry, dy] = find(y);
        if (rx == ry)
            return (dx - dy) == w;

        int adjusted_w = w + dy - dx; // if ry is parent

        if (rank[rx] > rank[ry])
        {
            swap(rx, ry);
            adjusted_w = -adjusted_w;
        }

        // save state before merge for rollback
        history.emplace(ry, rx);

        par[rx] = MP(ry, adjusted_w);
        rank[ry] += rank[rx];
        set_size--;
        return true;
    }

    // rollback last merge
    void rollback()
    {
        if (history.empty())
            return;

        auto [y, x] = history.top();
        history.pop();

        par[y] = {y, 0};
        rank[x] -= rank[y];
        set_size++;
    }

    // query distance difference between x and y (if connected)
    pair<bool, int> diff(int x, int y)
    {
        auto [rx, dx] = find(x);
        auto [ry, dy] = find(y);
        if (rx != ry)
            return {false, 0};
        return {true, dx - dy};
    }

    // optional checkpoint rollback support
    int checkpoint() { return history.size(); }

    void rollbackTo(int checkpoint_id)
    {
        while (history.size() > checkpoint_id)
            rollback();
    }

    int size() const { return set_size; }
};
