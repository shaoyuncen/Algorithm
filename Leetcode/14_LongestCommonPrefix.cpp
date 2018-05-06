#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        string output("");
        int count = 0;
        int i = 0;
        while(!strs.empty())
        {
            char ch = strs[0][count];
            for(; i < (int)strs.size(); i++)
            {
                if(strs[i].size() <= count)
                    return output;
                if(strs[i][count] != ch)
                    break;
            }
            if(i == strs.size())
            {
                i = 0;
                output += strs[i][count];
                count++;
            }
            else
                break;
        }
        return output;
    }

int main()
{
    string s1 = "flower";
    string s2 = "flow";
    string s3 = "flight";
    vector<string> strs;
    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}