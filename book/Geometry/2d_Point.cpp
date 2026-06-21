struct Point {
    ll x, y;
    int id;
};

bool is_upper(const Point &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

ll cross_product(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

bool cmp(const Point &a, const Point &b) {
    bool up_a = is_upper(a);
    bool up_b = is_upper(b);
    if (up_a != up_b) return up_a;
    return cross_product(a, b) > 0;
}

bool same_dir(const Point &a, const Point &b) { return is_upper(a) == is_upper(b) && cross_product(a, b) == 0; }
