#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int popo_1;
    int popo_2;
}popopo;

int findmaxandsign(popopo *j){
    printf("%d\n",j->popo_1);
    printf("%d\n",j->popo_2);
    int i = 0;
    while (i < 10)
    {
        if(j->popo_1 > j->popo_2){
            j->popo_2 = j->popo_1 + 20;
        }
        else {
            j->popo_1 = j->popo_2 + 20;
        }
        i++;
    }
    return 0; //不用回傳結構體，可以直接回傳0就好，結構體的變數已經修正完成了
}

int main(){
    popopo j;
    j.popo_1 = 10;
    j.popo_2 = 20;
    findmaxandsign(&j);

    printf("%d\n",j.popo_1);
    printf("%d\n",j.popo_2);
    return 0;
}

