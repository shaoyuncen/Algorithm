int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int sum;
    int i;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    for(i=0;i<n-1;i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}