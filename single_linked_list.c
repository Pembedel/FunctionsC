/* single_linked_list.c
 * 
 * Implementation of linked list
 * Add, delete, find node
 *
 * Author: Kapil
 *
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 

/* linked list for storing value*/
struct node{
    char *value;
    struct node *next;
};

/* Function prototypes */
int find_entry(struct node **head, char *value, int length);
int add_entry(struct node** head, char* value, int length); 
int del_entry(struct node **head, char *value, int length);
void del_all_entry(struct node **head);
void error(char *msg);

#define FAILURE -1
#define SUCCESS 0

/** Functions **/

/* main function*/
int main(void) 
{ 
    char value[257];
    unsigned int input;
    unsigned int value_len;
    struct node *head=NULL;
    int status;

    do
    {
        printf("\n 1. add entry \n 2. find entry\n 3. Del Entry\n 4. exit\n Enter your choice:");
        scanf("%d",&input);

        if(input>=4|| input <1)
            break;

        printf("\nEnter the value:");
        scanf("%s",value);
        value_len = strlen(value);
        
        if (value == NULL || value_len == 0)
            error("Invalid input");
        
        switch(input)
        {
            case 1:    
                status = add_entry(&head, value, value_len);
                            
                /* Adding appropriate status message for Client*/
                if (status == FAILURE)
                {
                    printf("add FAILED");
                }
            break;
            
            case 2:
                status = find_entry(&head, value, value_len);    
                if (status == FAILURE)
                {
                    printf("find FAILED");
                }    
            break;
            
            case 3:
                status = del_entry(&head, value, value_len);        
                if (status == FAILURE)
                {
                    printf("del failed");
                }
            break;
            
            default:
            break;
        }
    }while(1);
    
    del_all_entry(&head);
} 

/* Function: error() - To print error message 
 * in parameters: 
 *   msg - message to be printed
 *
 * return:
 *   void
 */
void error(char *msg) 
{
  printf("\nERROR:%s\n",msg);
  exit(EXIT_FAILURE);
}

/* Function: find_entry() - To find the if a value exists 
 * in parameters: 
 *   head - head of the linked list
 *   value - to find
 *   length - length of the value
 *
 * return:
 *   status - status of the operation
 */
int find_entry(struct node **head, char *value, int length)
{
  struct node *temp = *head;
  int status = FAILURE;
  
  while(temp != NULL)
  {
    /* Check string length also to avoid sub-string match*/
    if(strncmp(temp->value, value, length) == 0 && strlen(temp->value) == length)
    {
       printf("\nEntry in db exists for the queried value, Found value:%s",temp->value);
       status = SUCCESS;
       break;
    }
    temp = temp->next;
  }

  return status;
}

/* 
 * Function: add_entry() - To add a value exists 
 * in parameters: 
 *   head - head of the linked list
 *   value - value to be added
 *   value_len - length of value
 *
 * return:
 *   status - status of the operation
 */

int add_entry(struct node** head, char* value, int value_len) 
{ 
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    struct node *last = *head;

    if (NULL == new_node)
        return FAILURE;

    new_node = (struct node*) malloc(sizeof(struct node));

    new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = malloc((value_len+1)*sizeof(char));
    
    strncpy(new_node->value, value, value_len);
    value[value_len] ='\0';

    new_node->next = NULL; 
  
    printf("\nset value success: added new value:%s\n", new_node->value);

    if (*head == NULL) 
    { 
       *head = new_node; 
       return SUCCESS; 
    }   
       
    while (last->next != NULL) 
        last = last->next; 
   
    last->next = new_node;
    return SUCCESS;
} 

/* 
 * Function: del_entry() - To find the if a value exists 
 * in parameters: 
 *   head - head of the linked list
 *   value -  value to be found in db
 *   length - length of the value
 *
 * return:
 *   status - status of the operation
 */

int del_entry(struct node **head, char *value, int length)
{
  struct node *temp = *head;
  struct node *prev = NULL;

  while(temp != NULL)
  {
    /* Check string length also to avoid sub-string match*/
    if(strncmp(temp->value, value, length) == 0 && strlen(temp->value) == length)
    {
        if (prev == NULL && temp->next == NULL)
        {
            /* Only one node case*/
            head = NULL;
            printf("\nDelete operation success, value removed:%s",temp->value);
            free(temp->value);
            free(temp);
            return SUCCESS;
        }
        else if(prev == NULL && temp->next != NULL)
        { 
            /*If the node is the head*/
            *head = temp->next;
            printf("\nDelete operation success, value removed:%s",temp->value);
            free(temp->value);
            free(temp);
            return SUCCESS;
        }
        else
        {
            prev->next = temp->next;
            printf("\nDelete operation success, value removed:%s",temp->value);
            free(temp->value);
            free(temp);
            return SUCCESS;
        }
    }
    prev = temp;
    temp = temp->next;
  }
  return FAILURE;
}

/* 
 * Function: del_all_entry() - Free all allocated mem to avoid memleak 
 * in parameters: 
 *   head - head of the linked list
 *
 * return:
 *   void
 */
void del_all_entry(struct node **head)
{
  struct node *temp = *head;
  struct node *prev = NULL;

  while(temp != NULL)
  {
    if (prev == NULL && temp->next == NULL)
    {
        /* Only one node case*/
        head = NULL;
        printf("\nDelete operation success, value freed:%s",temp->value);

        free(temp->value);
        free(temp);
        break;
    }
    else if(prev == NULL && temp->next != NULL)
    {
        /*If the node is the head*/
        *head = temp->next;
        printf("\nDelete operation success, value removed:%s",temp->value);
        free(temp->value);
        free(temp);
    }
    else
    {
        prev->next = temp->next;
        printf("\nDelete operation success, value freed:%s",temp->value);
        free(temp->value);
        free(temp);
    }
    prev = temp;
    temp = temp->next;
  }
}
