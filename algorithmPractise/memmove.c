//内存重叠处理
//临时变量太多或没安全释放
//没有测试内存越界
//指针操作不熟悉
void* memmove(void* dest, const void* src, size_t n)
{
    char* p1 = dest;
    const char* p2 = src;
    if(p2 < p1)
    {//内存重叠则逆序拷贝
        p2 += n;
        p1 += n;
        while(n--!=0)
            *--p1 = *--p2;
    }
    else
    {
        while(n--!= 0)
            *p1++ = *p2++;
    }
    return p1;
}
