#include <iostream>
using namespace std;
int strStr(string haystack, string needle)
{
    if (needle.empty())
        return 0;
    int i, j = 0;
    for (i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[j]) //找与needle中第一个字母相等的地方（i）
            j++;//相等就j++
        else
        {
            i -= j;
            j = 0;
        }//不等就让i后退，比较了几格退几格，并且把j置零
        if (j == needle.size()) //当匹配完成后
            return i - j + 1; // j是比较了的格数，那么i+1 -j则是一开始的位置
    }
    return -1;
}
// int strStr(string haystack, string needle) {
//     if(needle.empty()) return 0;
//     int j = 0,size_h = haystack.size(), size_n = needle.size();
//     if(size_h < size_n) return -1;
//     for(int i = 0; i < size_h; i++)
//     {
//         if(haystack[i] == needle[0])
//         {
//             int temp_i = i;
//             while(needle[j] != '\0' && temp_i <size_h)
//             {
//                 if(needle[j] != haystack[temp_i])
//                     break;
//                 j++;
//                 temp_i++;
//             }
//             if(j == size_n)
//                 return i;
//             else
//             {
//                 j = 0;
//                 continue;
//             }
//         }
//     }

//     return -1;
// }

int main()
{
    string s1 = "mississippi";
    string s2 = "issip";
    
    cout << strStr(s1, s2) << endl;
    return 0;
}