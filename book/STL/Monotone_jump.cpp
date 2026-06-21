// ------- NGE,NSE,PGE,PSE --------
template<typename T>
struct MonotoneJump {
    vector<int> nse, nge, pse, pge;

    MonotoneJump(const vector<T> &arr) {
        int n = (int) arr.size();

        // defaults: next -> n (no next), prev -> -1 (no prev)
        nse.assign(n, n);
        nge.assign(n, n);
        pse.assign(n, -1);
        pge.assign(n, -1);

        // Next Smaller / Next Greater (iterate right-to-left using jumps)
        for (int i = n - 1; i >= 0; --i) {
            // NSE: find first j > i with arr[j] < arr[i]
            int j = i + 1;
            while (j < n && arr[j] >= arr[i]) j = nse[j]; // jump to next candidate (or n)
            if (j < n) nse[i] = j;

            // NGE: find first j > i with arr[j] > arr[i]
            j = i + 1;
            while (j < n && arr[j] <= arr[i]) j = nge[j];
            if (j < n) nge[i] = j;
        }

        // Prev Smaller / Prev Greater (iterate left-to-right using jumps)
        for (int i = 0; i < n; ++i) {
            // PSE: find first j < i with arr[j] < arr[i]
            int j = i - 1;
            while (j >= 0 && arr[j] >= arr[i]) j = pse[j]; // jump to previous candidate (or -1)
            if (j >= 0) pse[i] = j;

            // PGE: find first j < i with arr[j] > arr[i]
            j = i - 1;
            while (j >= 0 && arr[j] <= arr[i]) j = pge[j];
            if (j >= 0) pge[i] = j;
        }
    }
};