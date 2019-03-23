
void *memmove(void *dest, const void *src, size_t n)
{
    char *p1 = dest;
    const char *p2 = src;
    if(p2 < p1){ //内存重叠，src在dest左边则从右往左赋值
        p2 += n;
        p1 += n;
        while(n-- != 0)
            *--p1 = *--p2;
    }
    else{
        while(n-- != 0)
            *p1++ = *p2++;
    }
    return p1;
}