// ---------- MIN HEAP ----------
template<typename T>
struct FastMinHeap {
    vector<T> v;

    void push(T x) {
        v.push_back(x);
        push_heap(v.begin(), v.end(), greater<T>()); // use greater<>
    }

    void pop() {
        pop_heap(v.begin(), v.end(), greater<T>());
        v.pop_back();
    }

    T top() { return v.front(); }
    bool empty() { return v.empty(); }
    T size() { return (int) v.size(); }
};
