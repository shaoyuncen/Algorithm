//Newton method 求根
float squareRoot(float n)
{
    float x = n;
    float y = 1;
    float e = 0.000001;
    while(x-y>e)
    {
        x = (x+y)/2;
        y = n / x;
    }
    return x;
}