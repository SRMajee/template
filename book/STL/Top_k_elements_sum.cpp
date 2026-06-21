// ---------- Top K elements Sum -----------
struct top_k_elements_sum {
    multiset<int> mt1, mt2;
    int k;
    int sum;

    explicit top_k_elements_sum(int k) : k(k) {
        mt1.clear();
        mt2.clear();
        sum = 0;
    }

    void insert(int x) {
        mt1.insert(x);
        sum += x;
        if (mt1.size() > k) {
            auto it = mt1.begin();
            mt2.insert(*it);
            sum -= *it;
            mt1.erase(it);
        }
    }

    void remove(int x) {
        if (mt1.count(x) != 0) {
            auto it = mt1.find(x);
            sum -= x;
            mt1.erase(it);
            if (!mt2.empty()) {
                auto itr = prev(mt2.end());
                int val = *itr;
                mt2.erase(itr);
                insert(val);
            }
        } else if (mt2.count(x) != 0) {
            mt2.erase(mt2.find(x));
        }
    }

    int getSum() const {
        return sum;
    }
};