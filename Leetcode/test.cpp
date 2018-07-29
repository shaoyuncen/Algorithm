#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    for(int num : nums)
        cout<<num<<endl;
    return 0;
}
