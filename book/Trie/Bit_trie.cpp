// -------- Bit Trie Implementation --------
struct node
{ 
    int cnt = 0; // how many numbers pass through
    node *child[2] = {nullptr, nullptr};
};

struct bit_trie
{
    node *root;

    bit_trie()
    {
        root = new node();
    }

    // INSERT
    void add(int x)
    {
        node *cur = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (!cur->child[bit])
                cur->child[bit] = new node();

            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    // DELETE
    void remove(int x)
    {
        node *cur = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            cur = cur->child[bit];
            cur->cnt--;
        }
    }

    // COUNT exact occurrences
    int find(int x)
    {
        node *cur = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (!cur->child[bit])
                return 0;
            cur = cur->child[bit];
        }
        return cur->cnt;
    }

    // MAX XOR
    int findMax(int x)
    {
        node *cur = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (cur->child[1 ^ bit] && cur->child[1 ^ bit]->cnt > 0)
            {
                ans |= (1LL << i);
                cur = cur->child[1 ^ bit];
            }
            else if (cur->child[bit])
            {
                cur = cur->child[bit];
            }
        }
        return ans;
    }

    // MIN XOR
    int findMin(int x)
    {
        node *cur = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (cur->child[bit] && cur->child[bit]->cnt > 0)
            {
                cur = cur->child[bit]; // XOR = 0
            }
            else if (cur->child[1 ^ bit])
            {
                ans |= (1LL << i); // XOR = 1
                cur = cur->child[1 ^ bit];
            }
        }
        return ans;
    }
};