#include <iostream>
#include <vector>
#include <string>
#include <utility> //pair
#include <unordered_map>
using namespace std;

string minWindow(string s, string t){
    if(s.length()<t.length())
        return "";
    unordered_map<char, int> T;
    for(int i=0;i<t.length();++i)
        T[t[i]]++;
    int count=0, minWindow = s.length()+1;
    int start = -1, end = -1;
    int i=0,j=0,sLen = s.length(), tLen = t.length();
    bool sig = true;//true 扩展， false收缩
    // for(auto it=T.begin();it!=T.end();++it)
    //             cout<<it->first<<' ';
    while((i<=sLen-tLen&&!sig)||(j<sLen&&sig))
    {        
        if(sig)//扩展j
        {
            while(j<sLen&&T.find(s[j])==T.end())
                j++;
            if(j==sLen)
                continue;
            T[s[j]]--;
            if(T[s[j]]>=0)//需要这个字符
                count++;
            if(count==tLen)//凑齐了
            {
                sig = false;//收缩
                if((j-i+1)<minWindow)
                {
                    start = i;
                    end = j;
                    minWindow = j-i+1;
                }
            }
            j++;
        }
        else//收缩
        {
            while(i<=sLen-tLen&&T.find(s[i])==T.end())
                i++;     
            // cout<<"i: "<<i<<" j: "<<j<<" s[i]: "<<s[i]<<" s[j]: "<<s[j]<<endl;
            if((j-i)<minWindow)
            {
                start = i;
                end = j-1;
                minWindow = j-i;
            }
            T[s[i]]++;//字典中去掉
            
            if(T[s[i]]>0)
            {
                sig = true;//停止收缩
                count--;
                i++;
            }
            else//去掉后仍然不需要该字符
            {
                // sig = false;//继续收缩
                while(i<sLen&&T.find(s[i])==T.end())
                    i++;  
                if((j-i)<minWindow)
                {
                    start = i;
                    end = j-1;
                    minWindow = j-i;
                }
                i++;
            }
        }
    }
    if(start==-1)
        return "";
    return s.substr(start, end-start+1);
}
int main(int argc, char const *argv[])
{
    string s("abc");
    string t("cba");
    string res = minWindow(s, t);
    cout<<"res: "<<res<<endl;
   
    return 0;
}
// string minWindow2(string s, string t) {//o(n²)
//     unordered_map<char, int> T;
//     for(int i=0;i<t.length();i++)
//         T[t[i]] = i;
//     vector<pair<char, int>> list;//pair first存char, second存下标
//     for(int i=0;i<(int)s.length();i++)
//     {//裁剪后的输入为list，仅包含s中有的元素
//         if(T.find(s[i])!=T.end())//t中存在当前char
//         {
//             pair<char, int> tmp(s[i], i);
//             list.push_back(tmp);
//         }
//     }
    
//     int start = -1, end = -1;
//     if(list.size()<t.length())
//         return " ";
//     if(list.size()==t.length())
//     {
//         start = list.begin()->second;
//         end = list.end()->second;
//         return s.substr(start, end-start+1);
//     }
//     unordered_map<char, int> tmpSave;
//     int minWindow=(int)s.size()+1;
    
//     for(int i = 0;i<list.size();++i)
//     {
//         tmpSave[list[i].first] = list[i].second;//存当前元素
//         //向下找剩余的
//         int j = i+1;
//         while(tmpSave.size()<T.size()&&j<(int)list.size()-1)
//         {//从i后面往后搜集齐后退出
//             if(tmpSave.find(list[j].first)==tmpSave.end())//找tmpSave中是否已有，如果没有则塞进去
//             {
//                 tmpSave[list[j].first] = list[j].second;
//                 if(tmpSave.size()==T.size())
//                 {//找齐了
//                     int dist = list[j].second - list[i].second;
//                     if(dist<minWindow)
//                     {
//                         start = list[i].second;
//                         end = list[j].second;
//                         minWindow = dist;
//                     }
//                     break;
//                 }
//             }
//             j++;
//         }
//         tmpSave.clear();
//     }

//     cout<<"start: "<<start<<" end: "<<end<<endl;
//     return s.substr(start, end-start+1);

// }