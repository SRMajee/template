
// -------------- MST ---------------
void MST()
{
    cin >> n >> k;
    vector<tuple<int, int, int>> edges;
    fr(i, 0, k)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.EB(w, a, b);
    }
    sort(all(edges));
    DSU ds(n);
    int ans = 0;
    for (auto &[w, x, y] : edges)
    {
        if (ds.find(x) != ds.find(y))
        {
            ans += w;
            ds.merge(x, y);
        }
    }
    cout << ans << endl;
}