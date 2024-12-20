/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2]
where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
加起來要等於target的值
回傳不要回傳nums[i] 要回傳第i個位址
*/
 
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    for(int i = 0;i < numbersSize;i++){
        for(int k = 1 ; k < numbersSize;k++){
            if(numbers[i] + numbers[k]== target)
            {
                returnSize[i] = i + 1;
                returnSize[k] = k + 1;
        }
    }
    for(int i = 0; i<2;i++){
        printf("%d\n",returnSize[i]);
    }
    return returnSize;
    }
    // Solution 2 : Dive and Divide 
    /*
    *returnSize = 2;
    int *result = (int *)malloc(2*sizeof(int));
    int left = 0; right = numberSize -1 ;

    while(1){
        // correct
        if(number[left] + number[right] = target){
            result[0] = left + 1;
            result[1] = right - 1;
            return result;
        }
        else if (number[left] + number[right] > target){ //target 比較小，縮小尾巴
            right --;
        }
        else if (number[left] + number[right] < target){ //target 比較大，加大數值
            left ++;
        }
    }
    */
}

int main(){
    int a[] = {2,7,11,13};
    int target = 9;
    int *number = a;
    int new_arr[]={0};
    int *returnsize = new_arr;
    twoSum(number, 4,target,returnsize);
}
