#include <iostream>
#include <set>
#include <vector>
#define max(a, b) a>b?a:b
using namespace std;
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != (int)s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }//dicuss里面的解决方案
// int lengthOfLongestSubstring(string s)
// {
//     int size = s.size();
//     int count = 0;
//     string str;
//     for (int i = 0; i < size; i++)
//     {
//         str.push_back(s[i]);
//         set<int> sets(str.begin(), str.end());
//         if (sets.size() != str.size())
//         {
//             string temp(str.begin() + 1, str.end());
//             str = temp;
//         }
//         count = max((int)str.size(), count);
//     }
//     return count;
// } //我的解决方案
int main()
{
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl;

    return 0;
}
