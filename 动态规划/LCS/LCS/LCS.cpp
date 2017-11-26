// ����¼LCS.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int row;//��
	int col;//��
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
		}//����ÿ�е�����
		b = new char*[row];
		for (int temp = 0; temp < row; temp++)
		{
			b[temp] = new char[col];
		}//����ÿ�е�����
		for (int i = 0; i < row; i++)
		{//��ʼ��c,b����
			for (int j = 0; j < col; j++)
			{
				if (i == 0 || j == 0)
				{
					c[i][j] = 0;
					b[i][j] = '0';
				}
				else
				{
					if (A[j - 1] == B[i - 1])//ע����Ϊ�����һ��һ��0����������i,j�ֱ��1
					{//����i�����У������ȶ�����j�����Ա����Ⱥ��űȵĻ�����A[j-1]������A[i-1]
						c[i][j] = c[i - 1][j - 1] + 1;
						b[i][j] = '\\';
					}
					else if (A[j - 1] != B[i - 1])
						if (c[i][j - 1] <= c[i - 1][j])//���С���ϱ�
						{
							c[i][j] = c[i - 1][j];
							b[i][j] = '|';
						}
						else//��ߴ����ϱ�
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
					temp = j;//������һ��'\'��j��λ��
					j = -1;//������һ��
				}
			}
			j = temp - 1;//���ϴε�j��λ����ǰ��
		}
		string StrTemp(tempStr.rbegin(), tempStr.rend());
		Lcs.push_back(StrTemp);
	}

	void print()
	{
		LengthOfLCS();
		searchLCS();
		cout << "����cΪ��\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << c[i][j] << ' ';
			}
			cout << '\n';
		}//��ӡ��ά����c
		cout << "����bΪ��\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}//��ӡ��ά����b
		int count = Lcs.size();
		for (int i = 0; i < count; i++)
		{
			cout << "�������Ϊ��" << Lcs[i] << endl;
		}
	}
	~LCS()
	{
		for (int i = 0; i < row; i++)
		{
			delete[]c[i];
		}
		delete[]c; //�ͷ�����Ŀռ�
		c = NULL;
		for (int i = 0; i < row; i++)
		{
			delete[]b[i];
		}
		delete[]b; //�ͷ�����Ŀռ�
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

