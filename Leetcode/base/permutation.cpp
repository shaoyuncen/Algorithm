//排列模板
//abc全排列 abc acb......
#include<vector>
#include <stdio.h>
#include <algorithm>

void permutation(char* pStr, char* pBegin)
{
    assert(pStr && pBegin);

    if(*pBegin == '\0')
        printf("%s\n", pStr);
    else{
        for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            swap(*pBegin, *pCh);
            permutation(pStr, pBegin + 1);
            swap(*pBegin, *pCh);
        }
    }
}
