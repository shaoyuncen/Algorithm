#include "../common.h"

int uniquePaths(int m, int n) {
        if(m*n==0)  return 0;
        int arr[n][m];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0)
                    arr[i][j]=1;
                else
                    arr[i][j]=arr[i][j-1]+arr[i-1][j];
            }
        }
        return arr[n-1][m-1];
    }
int main()
{
    int m;
    int n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}