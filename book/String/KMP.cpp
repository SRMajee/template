// -------- KMP --------
vector<int> kmp(string &s) {
    int n = s.size();
    int i = 0, j = -1;
    vector<int> kmp(n + 1, 0);
    kmp[0] = -1;
    while (i < n) {
        while (j != -1 && s[i] != s[j])
            j = kmp[j];
        j++;
        i++;
        kmp[i] = j;
    }
    return kmp;
}
