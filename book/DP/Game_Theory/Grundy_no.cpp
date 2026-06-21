int calculateMex(const set<int> &s)
{
    int mex = 0;
    for (auto &i : s)
    {
        if (i == mex)
            mex++;
        else
            break;
    }
    return mex;
}
vector<int> G;
vector<int> calculateGrundy(int n)
{
    G.assign(n + 1, 0);
    vector<int> moves = {1, 2, 3};

    for (int i = 1; i <= n; i++)
    {
        set<int> s;
        // type of move
        for (int m : moves)
        {
            if (i >= m)
                s.insert(G[i - m]);
        }
        G[i] = calculateMex(s);
    }

    return G;
}