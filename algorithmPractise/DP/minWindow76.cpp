#include <iostream>
#include <vector>
#include <string>
#include <utility> //pair
#include <unordered_map>
using namespace std;
string minWindow(string s, string t) 
{
    unordered_map<char, int> T;
    for(int i=0;i<t.length();i++)
        T[t[i]] = i;
    vector<pair<char, int>> list;//pair first存char, second存下标
    for(int i=0;i<(int)s.length();i++)
    {//裁剪后的输入为list，仅包含s中有的元素
        if(T.find(s[i])!=T.end())//t中存在当前char
        {
            pair<char, int> tmp(s[i], i);
            list.push_back(tmp);
        }
    }
    
    int start = -1, end = -1;
    if(list.size()<t.length())
        return " ";
    if(list.size()==t.length())
    {
        start = list.begin()->second;
        end = list.end()->second;
        return s.substr(start, end-start+1);
    }
    unordered_map<char, int> tmpSave;
    int minWindow=(int)s.size()+1;
    
    for(int i = 0;i<list.size();++i)
    {
        tmpSave[list[i].first] = list[i].second;//存当前元素
        //向下找剩余的
        int j = i+1;
        while(tmpSave.size()<T.size()&&j<(int)list.size()-1)
        {//从i后面往后搜集齐后退出
            if(tmpSave.find(list[j].first)==tmpSave.end())//找tmpSave中是否已有，如果没有则塞进去
            {
                tmpSave[list[j].first] = list[j].second;
                if(tmpSave.size()==T.size())
                {//找齐了
                    int dist = list[j].second - list[i].second;
                    if(dist<minWindow)
                    {
                        start = list[i].second;
                        end = list[j].second;
                        minWindow = dist;
                    }
                    break;
                }
            }
            j++;
        }
        tmpSave.clear();
    }

    cout<<"start: "<<start<<" end: "<<end<<endl;
    return s.substr(start, end-start+1);

}
int main(int argc, char const *argv[])
{
    string s("caccasabasiuoiuxcvabb");
    string t("ab");
    string res = minWindow(s, t);
    cout<<"res: "<<res<<endl;
    return 0;
}
