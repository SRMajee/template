// ---------- Monotone Deque -----------
struct monotone_deque
{
    deque<int> q;

    void insert(int x)
    {
        while (!q.empty() && q.back() > x)
        {
            q.PPF();
        }
        q.PB(x);
    }

    void erase(int x)
    {
        if (q.front() == x)
            q.PPF();
    }

    int getMin() const
    {
        return q.front();
    }
};