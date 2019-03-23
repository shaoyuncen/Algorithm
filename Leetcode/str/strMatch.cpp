

//kmp





//BF
char* strMatch(const char* str, const char* target)
{
    if(!*target)
        return str;
    char *p1 = (char*) str;
    while(*p1)
    {
        char *p1Begin = p1, *p2 = (char *)target;
        while(*p1 && *p2 && *p1 == *p2)
        {
            p1++;
            p2++;
        }
        if(!*p2)
            return p1Begin;
        p1 = p1Begin + 1;
    }
    return NULL;
}