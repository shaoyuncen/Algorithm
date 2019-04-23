#include <iostream>
#include <list>
#include <queue>
using namespace std;

/*首先用邻接表存图
用一个数组存入度情况，数组下标为节点号
用一个队列保存入度为0的节点
然后拓扑排序：
首先将入度为0的入队
当队不为空时：
    取队首节点（取出节点删掉边）
    计数器+1
    并将该节点指向的节点的入度均减一
    减完后为0的入队
（此时队为空）
若计数器大于节点数则不是无环图
    返回false(排序失败)
否则
    返回true(排序成功)
 */
class Graph{
public:
    explicit Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    bool topological_sort();

  private:
    Graph(); //禁止默认构造
    const int v;            //顶点个数
    list<int> *adj;   //邻接表(双向链表)
    queue<int> q;     //入度为0的顶点的队列
    int *indegree;    //记录每个顶点的入度
};
/*class definition*/
Graph::Graph(int V):v(V)
{
    adj = new list<int>[V];
    indegree = new int[V];//入度初始化为0
    for (int i = 0; i < V;++i)
    {
        indegree[i] = 0;
    }
}
Graph::~Graph()
{
    delete[] adj;
    delete[] indegree;
}
void Graph::addEdge(int ver, int ver2)
{
    adj[ver].push_back(ver2);
    ++indegree[ver2];
}
bool Graph::topological_sort()
{
    for (int i = 0; i < this->v;++i)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int count = 0;//记录已输出的顶点数
    while(!q.empty())
    {
        int ver = q.front();//队列中取出一个顶点
        q.pop();

        cout << ver << " ";
        ++count;
        //将所有ver指向的顶点的入度减1，并将入度为0的入队
        list<int>::iterator beg = adj[ver].begin();
        for( ; beg!=adj[ver].end(); ++beg)
            if(!(--indegree[*beg]))
                q.push(*beg);   // 若入度为0，则入栈
    }
    if(count < this->v)
        return false;
    else
        return true;
}
int main()
{
    Graph g(6);   // 创建图
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topological_sort();
    return 0;
}
