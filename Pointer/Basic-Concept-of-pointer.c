#include <stdio.h>
#include <stdlib.h>
//交換兩個變數的值 -> 寫一個函數，利用指標來交換兩個整數變數的值。
int calculate(int *a,int size){
    int sum = 0;
    for(int i = 0; i <size ;i++){
        sum+= *(a+i); // 指向陣列的指標 所以只有只第一個頭
        // 如果是sum = sum + *a = 1 + 1 + 1 + 1 + 1
    }
    return sum;
}
//寫一個函數，使用指標來計算整數數組的所有元素的和。
void change(int *a, int *b){
    int tmp; // 交換用
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// 寫一個函數，使用指標來查找一個給定的數字在整數數組中的位置，若找到則返回位置，否則返回 -1。
int Find(int find_number,int *array,int size){
    for(int i = 0;i < size ; i++){
        if(find_number == *(array+i)){
            printf("Bingo\n");
            return 0;
        }
        else{
            printf("Not find\n");
            // return -1;
        }
    }
    return -1;
}
// 寫一個函數，用指標來計算一個字串的長度（不能使用標準庫函數 strlen）。
int calculate_length(const char *str_array){ // 這邊如果是int 會導致錯誤 長度變成22
    int length = 0;
    while (*(str_array+length) != '\0')
    {
        printf("element exist\n");
        length++;
    }

    return length;
    
}
// 反轉數組(Reverse array) use Pointer
void reverse(int *array,int size)
{
    // arr = 1,2,3,4,5
    
    // after_arr = 5,4,3,2,1
    /*{
    for(int i = size-1; i >= 0 ; i--)
        {
        printf("%d\n",*(array + i));
        }
    }*/
    
    int *start = array;
    int *end = array + size -1;
    while(*start < *end)
    {
        printf("Before : Array = %d,Size = %d\n",*start,*end);
        int tmp = *start;
        *start = *end;
        *end = tmp;
        printf("After : Array = %d,Size = %d\n",*start,*end);
        *start++;
        *end--;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}
int main(void){
    int array[5] = {1,2,3,4,5};
    const char str_array[] = "Hello,world!";
    int a = 10;
    int b = 20; 
    int find_number = 5;
    {
        // printf("Before change : a = %d , b = %d\n",a,b);
        // change(&a,&b);
        // printf("After change : a = %d , b = %d\n",a,b);
    }
    int size = sizeof(array) / sizeof(array[0]);
    {
        // int result = calculate(array,size);
        // printf("%d",result);
    }
    // int result = Find(find_number,array,size);
    // int length = calculate_length(str_array);
    reverse(array,size);
    
    // printf("%d",length);
    return 0;
}