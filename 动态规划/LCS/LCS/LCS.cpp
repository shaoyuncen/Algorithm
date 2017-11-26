// 备忘录LCS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <string>
using namespace std;
class LCS {
private:
	char **b = NULL;
	int **c = NULL;
	int row;//行
	int col;//列
	string A;
	string B;
	vector<string> Lcs;
public:
	LCS(string A, string B)
	{
		this->A = A;
		this->B = B;
		col = A.length() + 1;
		row = B.length() + 1;
	}
	void LCS::LengthOfLCS()
	{//set array c->record lengthOfLCS, array b->search specific LCS
		c = new int*[row];
		for (int temp = 0; temp < row; temp++) {
			c[temp] = new int[col];
		}//申请每行的数组
		b = new char*[row];
		for (int temp = 0; temp < row; temp++)
		{
			b[temp] = new char[col];
		}//申请每行的数组
		for (int i = 0; i < row; i++)
		{//初始化c,b数组
			for (int j = 0; j < col; j++)
			{
				if (i == 0 || j == 0)
				{
					c[i][j] = 0;
					b[i][j] = '0';
				}
				else
				{
					if (A[j - 1] == B[i - 1])//注意因为添加了一排一列0，所以这里i,j分别减1
					{//并且i代表行，这里先动的是j，所以保持先横排比的话，是A[j-1]而不是A[i-1]
						c[i][j] = c[i - 1][j - 1] + 1;
						b[i][j] = '\\';
					}
					else if (A[j - 1] != B[i - 1])
						if (c[i][j - 1] <= c[i - 1][j])//左边小于上边
						{
							c[i][j] = c[i - 1][j];
							b[i][j] = '|';
						}
						else//左边大于上边
						{
							c[i][j] = c[i][j - 1];
							b[i][j] = '<';
						}
					else
					{
						cout << "Class LCS: LengthOfLCS Error" << endl;
						return;
					}
				}
			}
		}

	}
	void LCS::searchLCS()
	{
		LengthOfLCS();
		int temp = 0;
		string tempStr;
		for (int i = row - 1, j = col - 1; i >= 0; i--)
		{
			for (; j >= 0; j--)
			{
				if (b[i][j] == '\\')
				{
					tempStr += A[j - 1];
					temp = j;//保存上一个'\'中j的位置
					j = -1;//进入上一行
				}
			}
			j = temp - 1;//从上次的j的位置往前搜
		}
		string StrTemp(tempStr.rbegin(), tempStr.rend());
		Lcs.push_back(StrTemp);
	}

	void print()
	{
		LengthOfLCS();
		searchLCS();
		cout << "数组c为：\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << c[i][j] << ' ';
			}
			cout << '\n';
		}//打印二维数组c
		cout << "数组b为：\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}//打印二维数组b
		int count = Lcs.size();
		for (int i = 0; i < count; i++)
		{
			cout << "最长子序列为：" << Lcs[i] << endl;
		}
	}
	~LCS()
	{
		for (int i = 0; i < row; i++)
		{
			delete[]c[i];
		}
		delete[]c; //释放申请的空间
		c = NULL;
		for (int i = 0; i < row; i++)
		{
			delete[]b[i];
		}
		delete[]b; //释放申请的空间
		b = NULL;
	}
};

int main()
{
	string A = "BCDACB";
	string B = "ABADCB";
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	LCS lcs(A, B);

	lcs.print();


}

