//第n个素数，即不能被前n-1个素数整除
//Prime(n) = G(Prime(n-1),Prime(n-2),Prime(n-3)...Prime(1));
//Prime(1) = 2  
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int getNthPrime(int n)
{
    std::list<int> primes(1,2);//length:1 value:2
    int number=3;
    while(primes.size()!=n)
    {
        bool isPrime = true;
        for(auto it=primes.begin();it!=primes.end()&&(*it)*(*it)<=number;++it)
        {
            if(number % (*it) == 0)
                isPrime = false;
        }
        if(isPrime)
            primes.push_back(number);
        
        number+=2;
    }
    return *(primes.rbegin());

}
bool isPalindrome(int n)
{
    vector<int> nums;
    while(n)
    {
        nums.push_back(n%10);
        n = n/10;
    }
    for(int i=0,j=nums.size()-1;i<j;i++,j--)
        if(nums[i]!=nums[j])
            return false;
    return true;
}
list<int> primes(1,2);//sushu table
int number = 3;
bool isPrime(int N)
{   
    if(N<number)//查找素数表有没有这个数
    {
        for(auto it=primes.rbegin();it!=primes.rend();++it)
        {//从后往前找，到达比N小则停止
            if(*it<N)
                return false;
            if(*it==N)
                return true;
        }
        return false;
    }
    while(N>=number)
    {
        bool isPrime = true;
        for(auto it=primes.begin();it!=primes.end()&&(*it)*(*it)<=number;++it)
        {
            if(number%*it==0)
            {
                isPrime=false;
                break;
            }
        }    
        if(isPrime)
            primes.push_back(number);
        number+=2;
    }
    if(*primes.rbegin()==N)
        return true;
    else
        return false;   
}

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 10000000;i++)
    {
        if(isPrime(i))
            cout<<i<<endl;
    }
    
    
    return 0;
}
