// ---------- STACK (vector) ----------
template<typename T>
struct FastStack {
    vector<T> v;
    void push(T x) { v.push_back(x); }
    void pop() { v.pop_back(); }
    T top() { return v.back(); }
    bool empty() { return v.empty(); }
    T size() { return (int) v.size(); }
};
