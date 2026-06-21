// ---------- QUEUE (vector + index) ----------
template<typename T>
struct FastQueue {
    vector<T> v;
    T head = 0; // index for front

    void push(T x) { v.push_back(x); }
    void pop() { head++; } // O(1) amortized
    T front() { return v[head]; }
    bool empty() { return head >= (int) v.size(); }
    T size() { return (T) v.size() - head; }
};