// -------- String Trie Implementation --------
struct node
{
    int cnt_end, cnt_prefix;
    node *child[26];

    node()
    {
        cnt_end = cnt_prefix = 0;
        fr(i, 0, 26)
            child[i] = nullptr;
    }
};

struct string_trie
{
    node *root;

    string_trie()
    {
        root = new node();
    }

    void add(string &x)
    {
        node *cur = root;
        for (const auto &ch : x)
        {
            cur->cnt_prefix++;
            int i = ch - 'a';
            if (cur->child[i] == nullptr)
            {
                cur->child[i] = new node();
            }
            cur = cur->child[i];
        }
        cur->cnt_end++;
    }

    int find(string &x)
    {
        node *cur = root;
        for (const auto &ch : x)
        {
            int i = ch - 'a';
            if (cur->child[i] == nullptr && cur->child[i]->cnt_prefix > 0)
            {
                return 0;
            }
            cur = cur->child[i];
        }
        return cur->cnt_prefix + cur->cnt_end;
    }
};
