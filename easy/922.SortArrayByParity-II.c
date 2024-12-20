/*
Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

如果i是基數的話,i的值也要是基數
反之 i 是偶數的話 , i 的值也要是偶數

*/
#include <stdio.h>
#include <stdlib.h>


int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    /*
    *returnSize = numsSize;
    int *returnSize = (int *)malloc(numsSize * sizeof(int))
    int j = 1; // 交換用
    for(int i = 0;i <numsSize;i++){
        if(i % 2 == 0){ // i 是偶數
            if (nums[i] % 2 != 0) // nums[i]不是偶數, 如果偶數,是在正確的位置上
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
             
        }
        else{ // i是基數
            if(nums[i] % 2 == 0){ // i 是偶數，不是在正確的位置上
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        if(j != numsSize-1){
            j++;
        }

    }
    for(int j = 0; j< numsSize;j++){
        printf("%d",nums[j]);
    }
    return nums;
    */
    *returnSize = numsSize;
    int *arr = (int *)malloc(numsSize * sizeof(int));
    int k = 1;
    int j = 0; // 交換用
    for(int i = 0;i <numsSize;i++){ 
        if(nums[i]%2==0){
            arr[j]=nums[i];
            j+=2;
        }
        else{
            arr[k]=nums[i];
            k+=2;
        }
    
    }
    return arr;
}

int main(){
    int a[] = {3,4,5,2};
    int *nums = a;
    int *returnSize = a;
    sortArrayByParityII(nums,4,returnSize);

    return 0;
}