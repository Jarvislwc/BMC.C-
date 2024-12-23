#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value; // list value
    struct node *next; // point to next
}Node;

// Create a node
void create_node(Node **start,int value)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> value = value;
    new_node -> next = NULL;
    if(*start == NULL)
    {
        *start = new_node;
    } 
    else 
    {
        Node *current;
        current = *start;
        while(current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = new_node;
        printf("Add a new node\n");
    }
}
// print list
void print_list(Node *head)
{
    Node *current;
    current = head; 
    if (current == NULL)
    {
        printf("There is no LL here.");
    }
    else
    {
        while (current != NULL)
        {
            printf("%d,",current->value);
            current = current->next;
        }
        printf("\n");
    }
}
// free list
void free_list(Node *head)
{
    Node *current,*previous;
    current = head;
    // previous = current;
    while (current != NULL)
        {
            previous = current;
            current = current->next;
            printf("Free node\n");
            free(previous); 
        }
}

// 插入一個節點
void insert_node_(Node **node,int insert_after_value,int value)
{
    
    Node *current = *node; //新插入節點的前一個前點
    while (current!=NULL)
    {
        if(insert_after_value == current -> value){ // 找到要新插入的點了
            Node *new_node = (Node*)malloc(sizeof(Node));
            new_node ->value = value;
            new_node ->next = NULL; //先讓新增的節點指向NULL.
            if (current->next ==NULL) // if current next point is null. 
            {
                current -> next = new_node;
                printf("Insert a new node\n");
                break;
            }
            else
            {
                new_node->next = current->next; // 將原本cur的下一個節點 assign給new node
                current -> next = new_node; // cur的下一個改為新節點
            }
            
        }
        current = current->next;
        if (current == NULL)
        {
            printf("There is no match value\n");
        }
        
    }
}
int main()
{
    int a = 5;
    Node *head = NULL;
    create_node(&head,5);
    create_node(&head,10);
    insert_node_(&head,10,41);
    create_node(&head,15);
    

    print_list(head);
    free_list(head);
    // create_new_node(int a);
    
    return 0;
}
