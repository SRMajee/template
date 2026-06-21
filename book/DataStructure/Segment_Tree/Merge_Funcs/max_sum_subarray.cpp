//  Max Sum Subarray
struct Node {
    int max_sum, l_sum, r_sum, tot;

    Node(bool empty = false) {
        if (empty) {
            tot = 0;
            max_sum = l_sum = r_sum = -INFL;
        } else {
            tot = max_sum = l_sum = r_sum = -INFL;
        }
    }

    Node(int val) {
        tot = val;
        max_sum = l_sum = r_sum = max(-INFL, val);
    }
};

Node merge(const Node &a, const Node &b) {
    Node ans;
    ans.max_sum = max({a.max_sum, b.max_sum, a.r_sum + b.l_sum});
    ans.l_sum = max(a.l_sum, a.tot + b.l_sum);
    ans.r_sum = max(b.r_sum, b.tot + a.r_sum);
    ans.tot = a.tot + b.tot;
    return ans;
}


// cnt
Node merge(const Node &a, const Node &b) {
    if (a.sum.F > b.sum.F) return a;
    else if (a.sum.F < b.sum.F) return b;
    return Node(MP(a.sum.F, add(a.sum.S, b.sum.S)));
}
