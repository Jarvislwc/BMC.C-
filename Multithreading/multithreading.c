#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct 
{
    int a;
    int b;
    int result;
}my_data;

void *second_child(void *Arg){

    my_data *data = (my_data *)Arg;

    data->result = data->a * data->b;
    pthread_exit(NULL);

}
// 子執行緒函數
void *child(void *arg) {
   int *input = (int *) arg; // 取得資料
   int *result = malloc(sizeof(int)); // 配置記憶體
   result[0] = input[0] + input[1]; // 進行計算
   pthread_exit((void *) result); // 傳回結果
}

// 主程式
int main() {
   pthread_t t;
   void *ret; // 子執行緒傳回值
   int input[2] = {1, 2}; // 輸入的資料
   my_data data;

   data.a = 1;
   data.b = 4;

   // 建立子執行緒，傳入 input 進行計算
   // pthread_create(&t, NULL, child, (void*) input);
   pthread_create(&t,NULL,second_child,(void *) &data);

   // 等待子執行緒計算完畢
   pthread_join(t, NULL);

   // 取得計算結果
   // int *result = (int *) ret;

   // 輸出計算結果
   printf("%d + %d = %d\n", data.a, data.b, data.result);

   // 釋放記憶體

   return 0;
}