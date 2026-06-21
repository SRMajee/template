vi gen_n_fib_no(int n)
{
    vi v;
    v.PB(0);
    v.PB(1);
    int a = 0, b = 1;
    while (true)
    {
        int c = a + b;
        if (c >= n) break;
        v.PB(c);
        a = b;
        b = c;
    }
    return v;
}