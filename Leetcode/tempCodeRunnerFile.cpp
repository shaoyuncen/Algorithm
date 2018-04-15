if((max - min + 1) == (int)nums.size())// min~max == length of array
    // {
    //     if(min > 1)
    //         return 1;
    //     else //min == 1
    //         return max + 1;
    // }
    // else 
    // {
    //     if(min > 1)
    //         return 1;
    //     else//the missing number is in min~max 
    //     {
    //         int missing = min + 1;
    //         for (size_t i = 0; i < nums.size();i++)
    //         {
    //             if((nums[i] - min) == 1)
    //                 missing = nums[i] + 1;
    //         }
    //         return -1;
    //     }
    // }