// ---------- MAX HEAP ----------
template<typename T>
struct FastMaxHeap {
    vector<T> v;

    void push(T x) {
        v.push_back(x);
        push_heap(v.begin(), v.end()); // default is max-heap
    }

    void pop() {
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }

    T top() { return v.front(); }
    bool empty() { return v.empty(); }
    T size() { return (int) v.size(); }
};