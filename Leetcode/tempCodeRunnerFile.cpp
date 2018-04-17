int start = 0, end = s.size() - 1;
    while(start < end)
    {
        if(s[start] != '(' || s[start] != '{' || s[start] != '[')
            start++;
        else if (s[end] != '(' || s[end] != '{' || s[end] != '[')
            end--;
        else
        {
            if (tolower(s[start++]) != tolower(s[end--]))
                return false;
        }
    }
    return true;