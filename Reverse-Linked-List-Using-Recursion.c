#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* l1 = NULL; 

struct ListNode* add_node(struct ListNode* head,int val)
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!temp)
    {
        printf("Error allocating memory\n");
    }
    temp->val = val;
    temp->next = NULL;

    if(head == NULL)//if list is empty
    {
        head = temp;
        return head;
    }
    else
    {
        //iterate to the last node of the list
        struct ListNode* current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        return head;
    }

}

void reverse(struct ListNode* head)
{
    struct ListNode *p = head;
   
    //exit condition
    if(p->next == NULL)
    {
        l1 = p;
        return;
    }
    reverse(p->next);
    struct ListNode *q = p->next;
    q->next = p;
    p->next = NULL;
    
}

void print(struct ListNode* head)
{
    printf("\n");
    struct ListNode* temp = head;
    while(temp != NULL)
    {
        printf(" %d",temp->val);
        temp = temp->next;
    }
    printf("\n");
    
    return;
}


int main()
{
    //struct ListNode* l1 = NULL;
    //struct ListNode* l2 = NULL;
    //struct ListNode* result = NULL;
    
    l1 = add_node(l1,1);
    l1 = add_node(l1,2);
    l1 = add_node(l1,3);
    l1 = add_node(l1,4);
    l1 = add_node(l1,5);
    l1 = add_node(l1,6);
    l1 = add_node(l1,7);
    
    
    printf("Input:");
    print(l1);
    
    reverse(l1);
    
    printf("Result:");
    print(l1);
    
    
	
    
}