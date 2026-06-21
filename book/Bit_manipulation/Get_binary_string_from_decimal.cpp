// Get binary string from decimal
string get_bit_string(ll n) {
    string s;
    for (int i = 63; i >= 0; --i)
        s.push_back((n & (1LL << i)) ? '1' : '0');
    return s;
}