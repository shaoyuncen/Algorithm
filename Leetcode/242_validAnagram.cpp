#include <iostream>
using namespace std;
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int counts[26] = {0};
    for (int i = 0; i < (int)s.size(); i++)
    {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string s = "anagram";
    string t = "nagraa";
    if(isAnagram(s, t))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}