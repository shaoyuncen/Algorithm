
void merge_sort(int array[], int helper[], int left, int right)
{
    if(left >= right)
        return;
    
    int mid = (left+right)/2;
    merge_sort(array, helper, left, mid);
    merge_sort(array, helper, mid+1, right);

    //merge two parts
    int helperLeft = left;
    int helperRight = mid+1;
    int curr = left;
    for(int i = left; i <= right; ++i)
        helper[i] = array[i];
    
    while(helperLeft <= mid && helperRight <= right)
    {
        if(helper[helperLeft] <= helper[helperRight])
            array[curr++] = helper[helperLeft++];
        else
            array[curr++] = helper[helperRight++];
    }

    while(helperLeft <= mid)
        array[curr++] = helper[helperLeft++];
}