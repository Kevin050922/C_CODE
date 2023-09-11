
//两数之和
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int n = numsSize;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                *returnSize = 2;
                int* ans = (int*)malloc(sizeof(int) * 2);
                ans[0] = i; ans[1] = j;
                return ans;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

//malloc函数，申请空间，用于返回多个整型



//回文数
#include<stdio.h>
bool isPalindrome(int x)
{
    int i = 0;
    int m[100];
    if (x > 0 && x < 10)
        return true;
    else if (x < 0)
        return false;
    else if (x > 10)
    {
        while (x > 0)
            m[i] = x % 10;
        x = x / 10;
        i++;
    }
    int j = 0;
    for (j = 0; j <= i / 2; j++)
    {
        if (m[j] = m[i - j])
            continue;
        return false;
    }
    return true;
}