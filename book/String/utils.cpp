vector<string> split(const string &s, char delim = ' ')
{
    vector<string> result;
    string word;
    for (char c : s)
    {
        if (c == delim)
        {
            if (!word.empty())
            {
                result.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
        result.push_back(word);
    return result;
}