#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    int size = A.size();
    if(size == 1)
        return A;
    int count = size - 1;
    for (size_t i = 0; i < count; )
    {
        int loca = i;
        if(A[loca] % 2 != 0)
        {
            int temp = A[count];
            A[count] = A[i];
            A[i] = temp;//A[i]和A[count]换位置
            count--;
            i = loca;
        }
        else
            i++;        
    }

    return A;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {3, 1, 2, 4};
    sortArrayByParity(A);
    for (size_t i = 0; i < A.size(); i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}

