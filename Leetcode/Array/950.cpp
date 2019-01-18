#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


void print(deque<int> A)
{
    for(auto num : A)
    {
        cout << num << ' ';
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> numbers = {4,5,1,3,2,6};
    sort(numbers.rbegin(), numbers.rend());
    deque<int> d;
    d.push_back(numbers[0]);
    print(d);
    for (int i = 1; i < numbers.size(); i++) {
        d.push_front(d.back());
        d.pop_back();
        d.push_front(numbers[i]);
        print(d);
    }
   
    
        
    

    return 0;    
}
