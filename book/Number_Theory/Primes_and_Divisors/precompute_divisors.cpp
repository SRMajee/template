vector<vi> divisors;


void pre_divisors(int x=MAXN)
{
    divisors.assign(x + 9, vi());
    fr(i, 1, x - 9)
    {
        for (int j = i; j < x - 9; j += i)
        {
            divisors[j].PB(i);
        }
    }
}
}