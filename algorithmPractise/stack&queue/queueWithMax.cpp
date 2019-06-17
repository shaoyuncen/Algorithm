//queue with max
#include <iostream>
#include <queue>
class queueWithMax{
public:    
    queueWithMax();
    void push(int value);
    void pop();
    int getMax();
private:
    std::queue<int> que;
    std::queue<int> maxQue;
};
void queueWithMax::push(int value)
{
    if(maxQue.empty()||maxQue.front()>=value)
    {
        maxQue.push(value);
    }
    else
    {
        maxQue.pop();   
        maxQue.push(value);
    }
    que.push(value);
}
void queueWithMax::pop()
{
    int value = que.front();
    que.pop();
    if(value == maxQue.front())
        maxQue.pop();
}
int queueWithMax::getMax()
{
    return maxQue.front();
}
