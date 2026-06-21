// --------- Manacher ----------
vector<int> Manachers(string &s) {
    string t;
    for (auto c: s)
        t += "#" + string(1, c);
    t = "$" + t + "#^";
    int n = t.size();
    vector<int> p(n + 2, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * c - i;
        if (r > i)
            p[i] = min(p[mirror], r - i);
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            ++p[i];
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
    }
    return p;
}
