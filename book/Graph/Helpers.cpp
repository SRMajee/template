int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};
bool isValid(int x, int y)
{
    return (x < n && y < m && x >= 0 && y >= 0 && v[x][y] != '#');
}
vii neighbors(int a, int b)
{
    vii ans;
    fr(i, 0, 4)
    {
        int x = a + dx[i];
        int y = b + dy[i];
        if (isValid(x, y))
        {
            ans.EB(x, y);
        }
    }
    return ans;
}