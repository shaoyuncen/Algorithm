
//《程序员自我修养》P307
void *malloc(size_t nbytes)
{
    void* ret = mmap(0, nbytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    if(ret == MAP_FAILED)
        return 0;
    return ret;
}