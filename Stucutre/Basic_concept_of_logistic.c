#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Swift 255 

// 寫一個函數，接受三個整數，使用邏輯 AND 運算符判斷這三個數字是否全部為正數，並返回結果。
int calculate_and(int a,int b,int c)
{
    return (a > 0 ) && (b > 0) && (c > 0);
}
//寫一個函數，接受一個字符，使用邏輯 OR 運算符判斷該字符是否為母音（a, e, i, o, u），並返回結果。
int mother(char string)
{
    return (string == 'a') || (string == 'e') || (string == 'i') || (string == 'o') || (string == 'u');
} // 傻B阿 怎麼會用賦值運算


//寫一個函數，接受一個整數，使用邏輯 AND 運算符判斷該數字是否為偶數且是正數，並返回結果。
bool Calculate_Positeve_And_Even(int number)
{
    return (number > 0 && number /2 == 0);
}

// 寫一個函數，接受兩個整數，使用邏輯運算判斷並返回較大的數字。
int Calculate_Greater(int number,int number2)
{
    if(number & number2 > 0)
    {
        return number;
    }
    return number2;
}

// 寫一個函數，接受一個布爾變數，使用邏輯 NOT 運算符反轉其值並返回結果。
int Use_Not_change(bool change)
{
    return !change;
}
int main()
{
    int AND_1 = 7;
    int AND_2 = 10;
    int AND_3 = -3;
    char string = 'c';
    bool change = true;
    /*{
    if(calculate_and(AND_1,AND_2,AND_3))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    }
    if(mother(string))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    if(Calculate_Positeve_And_Even(AND_1))
    {
        printf("True");
    }
    else{
        printf("False");
    }
    
    if(Calculate_Greater(AND_1,AND_2))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    */
    if(Use_Not_change(change))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;

}