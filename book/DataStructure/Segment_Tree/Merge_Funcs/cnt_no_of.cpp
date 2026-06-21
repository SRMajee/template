struct Node {
    ii sum;
    Node() { sum = MP(0, 0); }
    Node(int val, int cnt) { sum = MP(val, 1); }
};

Node merge(const Node &a, const Node &b) {
    if (a.sum.F > b.sum.F) return a;
    else if (a.sum.F < b.sum.F) return b;
    return Node(MP(a.sum.F, add(a.sum.S, b.sum.S)));
}
