#include<iostream>
#include <regex>
#include <string>
using namespace std;
void trim(std::string& str) {
	if (str.empty())
		return;
	int i = 0, j = 0;
	while (j < str.length()) {
		if (str[j] == ' ')
			j++;
		else
		{
			str[i] = str[j];
			i++; j++;
		}
	}
	str = str.substr(0, i);
}
int main(int argc, char const *argv[])
{
    string sql = "     SELECT * From User";
    int len = sql.length();
	int i = 0;
	while (sql[i] == ' ')
		i++;
	if (i + 5 < len)
	{
		transform(sql.begin(), sql.begin()+i+6, sql.begin(), ::tolower);
        cout<<sql.substr(i, 6)<<endl;
	}
    return 0;
}
