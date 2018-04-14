#include <iostream>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
        result = (result << 1) + (n >> i & 1);//n>>i&1的意思是只保留末位的二进制数1 / 0
    return result;
}
int main()
{
    uint32_t n = 43261596; // 00000010100101000001111010011100
    uint32_t number = reverseBits(n); //00111001011110000010100101000000  964176192
    cout << number << endl;

    return 0;
}