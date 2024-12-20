# include <stdio.h>
# include <stdlib.h>

int *const p1; //  p1 只讀 *p1 : 變數
const int *p2; // *p2 只讀  p2 : 變數
int const *p3; // *p3 只讀  p3 : 變數 
int const * const p4; // p4 只讀 *p4 : 只讀
const int * const p5; // p5 只讀 *p5 : 只讀
  
// 被 const 修飾的東西都受到強制保護
typedef int Newint; // 幫 int 起了一個別名 叫做 Newint (可以想像成是綽號)
                    // Ex: 我本名叫 李文傑 但在公司都叫 Jarvis 

struct Node{
    int number;
    char name[20]; 
}; // 定義了一個Node結構(內含一個int 資料型態的number變數和 char陣列的Name)


typedef struct Node2
{
    int number;
    char Name[20];
}NewNode;       // 定義一個(Node2)[這邊是可以省略掉的] 結構 並且給了一個等義的別名 NewNode
                // 定義一個 結構 並且給予一個別名                

typedef struct BaseBoard
{
    int a;
    char name[20];
    int *cycle;
}BaseBoard_player; // 這邊也可以寫成


int main(void){
    BaseBoard_player Baseball;
    Baseball.a = 16;
    int fun = Baseball.a;
    if(fun > 10){
        printf("%d",Baseball.a);
    }
    return 0;
}


