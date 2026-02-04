#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>

void deleteEndNode(Node **head)
{

   /*
   ÇOKKK ÖNEMLİİİİİ!!!!!

   C dilince -> operatörü * operatöründen yüksek önceliğe sahip o yüzden (*heap)-> yazmak gerekiyor
   aksi taktirde *(heap->) şeklinde algılanır.
   */
    if(*head==NULL) return;//liste boş ise

    if((*head)->next==NULL)
    {
        free(*head);
        (*head)->next=NULL;
        return;
    }

    Node *temp = *head;

    //Son düğümden bir önceki düğümü bulduk.
    while (temp->next->next != NULL)
    {
        temp =temp->next; 

    }
    free(temp->next);// Son düğümü sil
    temp->next=NULL;//Son düğümü boşa çıkarttık.
    return;


}
void addEnd(Node** head,int value)
{
    Node *newNode = malloc(sizeof(Node));
    
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

}

void printNode(Node * head)
{
    while (head!=NULL)
    {
        printf("\n%d",head->data);
        head = head->next;

    }

}


void insertAfter(Node**head, int after, int value)
{
    int flag=0;
    
    Node* newnode = malloc(sizeof(Node)); 
    newnode->next=NULL;
    newnode->data= value;
    if(*head==NULL) 
    {
        return;
    }

    for(Node *temp = *head;temp!=NULL;temp=temp->next)
    {
        
        if (temp->data==after)
        {
            Node *temp2 = temp->next;
            temp->next=newnode;
            newnode->next=temp2;
        
            return;
        }
        
        
    }
    printf("Sonrasina eklemek istediginiz deger listede bulunamadi!");
    
    

}

void deleteAfter(Node**head, int after)
{
    if(*head==NULL) 
    {
        return;
    }

    for(Node *temp = *head; temp->next!=NULL;temp=temp->next)
    {

        if(temp->data== after)
        {
            Node *temp2 =temp->next;
            temp->next = temp->next->next;
            free(temp2);
            temp2->next=NULL; 
            return;
        }
    }
    printf("Sonrasindekini silmek istediginiz eleman bulunamadi!!");
    return;
}

void deleteHead(Node**head)
{
    if(*head==NULL)
    {
        return;
    }
    Node * temp = *head;
    temp=temp->next;
    (*head)->data=temp->data;
    (*head)->next = temp->next;
    
    free(temp);
    (temp)->next=NULL;

}