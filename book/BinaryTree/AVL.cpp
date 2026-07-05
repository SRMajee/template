struct Node {
    int val, ht;
    Node *l, *r;
    Node(int v) : val(v), ht(1), l(nullptr), r(nullptr) {}
};

// 1. Core Helpers (Keep these one-liners)
int ht(Node* n) { return n ? n->ht : 0; }
int bf(Node* n) { return n ? ht(n->l) - ht(n->r) : 0; }
void upd(Node* n) { if(n) n->ht = 1 + max(ht(n->l), ht(n->r)); }

// 2. Rotations (Memorize the pointer swaps)
Node* rotR(Node* y) {
    Node* x = y->l; y->l = x->r; x->r = y;
    upd(y); upd(x); return x;
}

Node* rotL(Node* x) {
    Node* y = x->r; x->r = y->l; y->l = x;
    upd(x); upd(y); return y;
}

// 3. Insert & Balance
Node* insert(Node* n, int v) {
    if (!n) return new Node(v);
    
    // Standard BST Insert
    if (v < n->val) n->l = insert(n->l, v);
    else if (v > n->val) n->r = insert(n->r, v);
    else return n; // No duplicates
    
    upd(n);
    int b = bf(n);
    
    // The 4 Balance Cases
    if (b > 1 && v < n->l->val) return rotR(n);                      // LL
    if (b < -1 && v > n->r->val) return rotL(n);                     // RR
    if (b > 1 && v > n->l->val) { n->l = rotL(n->l); return rotR(n); } // LR
    if (b < -1 && v < n->r->val) { n->r = rotR(n->r); return rotL(n); } // RL
    
    return n;
}