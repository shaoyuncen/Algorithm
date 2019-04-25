/*两个线程卖火车票的程序，多线程示例*/
#include <windows.h>
#include <iostream>

using namespace std;
DWORD WINAPI Fun1Proc(LPVOID lpParameter);//thread data
DWORD WINAPI Fun1Proc(LPVOID lpParameter);//thread data

int index = 0;
int tickets = 10;
HANDLE hMutex;
int main()
{
    HANDLE hThread1;
    HANDLE hThread2;
    //创建线程
    hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
    hThread2 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
    CloseHandle(hThread1);
    CloseHandle(hThread1);

    //创建互斥对象
    hMutex = CreateMutex(NULL, TRUE, "tickets");
    if(hMutex)
    {
        if(ERROR_ALREADY_EXISTS == GetLastError())
        {
            cout<<"only one instance can run!"<<endl;
            return 0;
        }
    }
    WaitForSingleObject(hMutex, INFINITE);
    ReleaseMutex(hMutex);
    ReleaseMutex(hMutex);

    Sleep(4000);
    return 0;
}

//线程1的入口函数
DWORD WINAPI Fun1Proc(LPVOID lpParameter)//thread data
{
    while(true)
    {
        ReleaseMutex(hMutex);
        WaitForSingleObject(hMutex, INFINITE);
        if(tickets > 0)
        {
            Sleep(1);
            cout<<"thread1 sell ticket: "<<tickets--<<endl;
        }
        else
            break;
        ReleaseMutex(hMutex);
    }
    return 0;
}
//线程2的入口函数
DWORD WINAPI Fun2Proc(LPVOID lpParameter)//thread data
{
    while(true)
    {
        ReleaseMutex(hMutex);
        WaitForSingleObject(hMutex, INFINITE);
        if(tickets > 0)
        {
            Sleep(1);
            cout<<"thread2 sell ticket: "<<tickets--<<endl;
        }
        else
            break;
        ReleaseMutex(hMutex);
    }
    return 0;
}
