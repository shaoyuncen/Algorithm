#include <stdio.h>
#include <arpa/inet.h>
//under *nix, test big/small machine.
int main()
{
    unsigned long host_addr = 0x12345678;
    printf("address: %#lx \n", host_addr);
    unsigned long net_addr = htonl(host_addr);
    printf("address: %#lx \n", net_addr);

    return 0;
}