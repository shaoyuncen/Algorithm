#include <iostream>
#include <string>
using namespace std;

//brute-force
char* StrStr(const char* str, const char* target)
{
    if(!*target)
        return str;
    char* p1 = (char*) str;
    while(*p1)
    {
        char* p1Begin = p1, *p2 = (char*)target;
        while(*p1&&*p2&&*p1==*p2)
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
int strStr(string src, string target)
{
    
}
int main(int argc, char const *argv[])
{
    string source = "abcdefg";
    string target = "cde";


    return 0;
}
