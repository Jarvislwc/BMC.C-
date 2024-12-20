/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.

Return k.

把陣列中與val值相同的數字給刪掉
並且計算陣列中剩餘個數
*/

#include <stdio.h>
#include <stdlib.h>

int removeElement(int *nums,int numsSize ,int val);

int main(){
    int a[9] = {0,1,1,2,2,3,5,6,7};
    int *nums = a;
    int val = 3;
    printf("%d",removeElement(nums,9,val));

    return 0;
}
int removeElement(int *nums,int numsSize ,int val){
    int numberofelement = 0;
    for(int i = 0;i<numsSize;i++){
        if(nums[i] != val){
            nums[numberofelement] = nums[i];
            numberofelement++;
            
        }
        
    }
    for(int k = 0;k<numsSize;k++){
        printf("%d\n",nums[k]);
    }
    return numberofelement;
}

// 0613 / Accept