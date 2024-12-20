#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// stdlib.h define malloc 
// void *malloc(size_t size); 用來配置指定大小的記憶體空間，傳回 *新空間第一個位元組的記憶體位址* 
// void *calloc(size_t nmemb, size_t size);
// void free(void *ptr);
// void *realloc(void *ptr, size_t size)
typedef struct LNode
{
    int data;
    struct LNode *rightNode;
    
}LNode;

void memo(int arrLen,int arrLen1,int arrLen2){
    // 透過 calloc 所取得的記憶體空間，其值會被自動初始化為 0 或 NULL

    int dynArr;
    // 未初始化的一維陣列
    dynArr = malloc( arrLen * sizeof(int) );

    // 已初始化的一維陣列
    dynArr = calloc( arrLen, sizeof(int) );

    // 未初始化的二維陣列
    dynArr = malloc( arrLen1 * arrLen2 * sizeof(int) );

    // 已初始化的二維陣列
    dynArr = calloc( arrLen1 * arrLen2, sizeof(int) );
    }

int main()
{
    /*
    int n;
    int *pI;
    int space = 10;

    // pI = int * 分配函數(有幾個數字 * int 的size)
    // pI = malloc(space*sizeof(int)); // 123456789

    // pI = calloc(space ,sizeof(int)); // 000000000
    // 初始化記憶體
    memset(pI,0,space*sizeof(int));

    if(pI == NULL) // if fail to allocate
    {
        printf("Couldn't allocate memory\n");
        return 1;   // exit
    }

    for(int i = 0;i< space;i++){
        // pI[i] = i;
        printf("%d",pI[i]);
    }
    // Releasing the memory allocated by malloc
    */

    int NewNumber = 10;
    int numindex;
    LNode *head = NULL;
    LNode *current = NULL;
    LNode *prev = NULL;
    
    printf("sizeof(LNode *) = %d Byte\n",sizeof(LNode *));
    printf("sizeof(LNode) = %d Byte\n",sizeof(LNode));
    while(1){

        if(NewNumber==-1){
            break;
        }
        current = (LNode *)malloc(sizeof(LNode));
        
        current->rightNode = NULL;
        current->data = NewNumber;

        if(head == NULL){
            head = current;
        }
        else{
            prev -> rightNode =current;
        }

        prev = current;
        numindex = 0;
        free(prev);
    }
    while(current != NULL){
        printf("LinkedList NO = %d,data = %d,MM = %i\n",++numindex,current->data,current);
        current = current->rightNode;
    }

    return 0;
}
