void cycleSort(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        while (v[i] > 0 && v[i] <= n && v[v[i] - 1] != v[i]) {
            swap(v[i], v[v[i] - 1]);
        }
    }
}
