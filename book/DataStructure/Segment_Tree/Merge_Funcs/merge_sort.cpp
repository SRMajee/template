struct Node
{
    vi vals;

    Node() { vals.clear(); }
    Node(int _val) { vals.PB(_val); }
};

Node merge(const Node &a, const Node &b)
{
    Node ans;
    ans.vals.reserve(SZ(a.vals) + SZ(b.vals));
    merge(all(a.vals), all(b.vals), back_inserter(ans.vals));
    return ans;
}