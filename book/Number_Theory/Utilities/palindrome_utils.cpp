template <typename T>
bool is_palindrome(const T &container)
{
    int n = container.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (container[i] != container[n - i - 1]) return false;
    }
    return true;
}

template <typename Container>
bool canFormPalindrome(const Container &cont)
{
    hash_map<typename Container::value_type, int> freq;
    for (auto &el : cont) ++freq[el];
    int oddCount = 0;
    for (auto &[val, count] : freq)
    {
        if (count % 2 != 0) oddCount++;
    }
    return oddCount <= 1;
}