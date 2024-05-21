#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student 
{
    char name[20];
    unsigned int roll;
    unsigned int marks;
    struct student *next;

} student;

student *addSNodeSorted(student *head, char name[20], unsigned int roll, unsigned int marks)
{
    student *temp = (student *)malloc(sizeof(student));
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->roll = roll;
    temp->next = NULL;

    if (head == NULL)        
    {
        head = temp;
        return head;
    }

    if (marks < head->marks)    
    {
        temp->next = head;
        head = temp;
        return head;
    }
    else           
    {
        student *ptr = head;
        while (ptr->next != NULL && ptr->next->marks < marks)
            ptr = ptr->next;

        temp->next = ptr->next;
        ptr->next = temp;
    }

    return head;
}
int isPresentSNode(student *head, unsigned int roll)
{
    int i = 1;
    student *ptr = head;
    while (ptr != NULL)
    {
        if ( ptr->roll == roll) 
            return i;

        ptr = ptr->next;  
        i++;
    }
    return 0;
}
student *deleteSNodeS(student *head, unsigned int roll)
{
    if (head == NULL) 
        return 0;

    if (head->roll == roll)
    {

        student *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    student *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->next->roll == roll)
        {
            student *temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return head;
        }
        ptr = ptr->next;
    }
    printf("No such student exits.\n");  
    return head;
}

void printLL(student *head){       
	printf("%-22s %-8s %-6s\n" , "Name", "Roll" , "Marks");
	student *ptr = head;
	while(ptr != NULL){
		printf("%-22s %-8d %-6d\n", ptr->name, ptr->roll, ptr->marks);
		ptr = ptr->next;
	}
}

student *freeSNodeSorted(student *head) 
{
    if (head == NULL)
        return NULL;

    student *temp = head;
    student *ptr = head->next;
    while (temp != NULL)
    {
        free(temp);
        temp = ptr;
        if (ptr != NULL)
            ptr = ptr->next;
    }
    return head;
}

student *reverseSNodeSorted(student *head) 
{
    if (head == NULL)   //LIST EMPTY
        return NULL;
    else if (head->next == NULL)   
        return head;

    student *ptr = head;        
    student *after = head->next->next;
    student *temp = head->next;

    ptr->next = NULL;
    while (temp != NULL)
    {
        temp->next = ptr;                
        ptr = temp;
        temp = after;
        if (after != NULL)
            after = after->next;
    }
    head = ptr;
    return head;
}

struct student *sortOnMarksSNodeSorted(struct student *start)  
{

    student *ans = NULL;
    student *temp = start;

    ans = temp;
    temp = temp->next;
    ans->next = NULL;

    while (temp != NULL)  
    {
        student *temp1 = temp;    
        temp = temp->next;
        temp1->next = NULL;

        if (temp1->marks < ans->marks) 
        {
            temp1->next = ans;
            ans = temp1;
        }
        else
        {
            student *ptr = ans;
            while (ptr->next != NULL && ptr->next->marks < temp1->marks) 
                ptr = ptr->next;

            temp1->next = ptr->next; 
            ptr->next = temp1;
        }
    }

    return ans;
}

struct student *sortOnRollSNodeSorted(struct student *start)  
{

    student *ans = NULL;
    student *temp = start;

    ans = temp;                 
    temp = temp->next;
    ans->next = NULL;

    while (temp != NULL)         
    {
        student *temp1 = temp;
        temp = temp->next;
        temp1->next = NULL;

        if (temp1->roll < ans->roll)    
        {
            temp1->next = ans;
            ans = temp1;
        }
        else                      
        {
            student *ptr = ans;
            while (ptr->next != NULL && ptr->next->roll < temp1->roll)
                ptr = ptr->next;

            temp1->next = ptr->next;
            ptr->next = temp1;
        }
    }
    return ans;
}

student *mergeSNodeSorted(student **head1, student **head2) 
{

    student *temp = NULL;
    student *merged = NULL; 

    if (*head1 == NULL || *head2 == NULL)
    {
        if (*head1 == NULL)   
            return *head2;
        else
            return *head1;
    }

    if ((*head1)->marks < (*head2)->marks)   
    {
        merged = *head1;
        *head1 = (*head1)->next;
        merged->next = NULL;
    }
    else
    {
        student *temp1 = *head2;
        merged = temp1;
        *head2 = (*head2)->next;
        merged->next = NULL;
    }
    temp = merged;

    while (*head1 != NULL && *head2 != NULL)     
    {
        if ((*head1)->marks < (*head2)->marks)
        {
            temp->next = *head1;
            temp = temp->next;
            *head1 = (*head1)->next;
            temp->next = NULL;
        }
        else
        {
            temp->next = *head2;
            temp = temp->next;
            *head2 = (*head2)->next;
            temp->next = NULL;
        }
    }

    if (*head1 != NULL)          
        temp->next = *head1;
    else if (*head2 != NULL)
        temp->next = *head2;

    *head1 = NULL;     
    *head2 = NULL;

    return merged;
}

int main()
{
    student *head = NULL;
    student *head2 = NULL;
    int input = 1;
    while (input)
    {
        printf("\n1. ADD A STUDENT INFORMATION.\n2. SEARCH FOR A STUDENT.\n3. DELETE AN ENTRY.\n4. PRINT THE TOTAL REGISTRY.\n5. FREE TOTAL REGISTRY.\n6. REVERSE THE LIST.\n7. SORT LIST ON THE BASIS OF ROLL.\n8. MERGE ANOTHER LIST WITH EXISITING ONE.\nENTER YOUR INPUT(0 FOR EXIT): ");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
            {
                char name1[20], name2[20];
                unsigned int roll;
                unsigned int marks;
                printf("Enter the name of the student: ");
                scanf("%s", name1);
                printf("Enter the roll of the student: ");
                scanf("%d", &roll);
                printf("Enter the marks of the student: ");
                scanf("%d", &marks);
                if(head!=NULL) head=sortOnMarksSNodeSorted(head);
                head = addSNodeSorted(head, name1, roll, marks);
                if (head != NULL)
                {
                    printf("Student succesfully added.\n");
                }

                break;
            }
            case 2:
            {
                if (head == NULL)      
                    printf("Empty List! Search operation not possible\n");
                else
                {
                    unsigned int roll;
                    printf("Enter the roll of the student: ");
                    scanf("%d", &roll);
                    int position = isPresentSNode(head, roll);
                    if (position == 0)
                        printf("The student is not in the registry.\n");
                    else
                        printf("The student is in position no. %d\n", position);
                }
                break;
            }
            case 3:   
            {
                if (head == NULL)
                    printf("Empty List!Deletion Not Possible\n");
                else
                {
                    unsigned int roll;
                    printf("Enter the roll of the student to delete: ");
                    scanf("%d", &roll);
                    head = deleteSNodeS(head, roll);
                    if (head)
                        printf("Operation completed.\n");
                }
                break;
            }
            case 4: 
            {
                printLL(head);
                break;
            }
            case 5:    
            {
                head = freeSNodeSorted(head);
                if (head == NULL)
                    printf("Linked List was cleared.\n");
                else
                    printf("Could not delete Linked List.\n");

                break;
            }
            case 6:
            {
                head = reverseSNodeSorted(head); 
                printLL(head);     
                if (head != NULL)
                    printf("The list was reversed.\n");
                else
                    printf("Could not reverse the linked list.\n");

                break;
            }
            case 7:
            {
                head = sortOnRollSNodeSorted(head);  
                printLL(head);
                if (head != NULL)
                    printf("Sorted on the basis of roll.\n");
                else
                    printf("Could not sort.\n");

                break;
            }
            case 8:
            {
                printf("Creating another List to merger:-\n");    
                printf("Enter number of students: ");
                unsigned short int num;
                scanf("%d", &num);
                for (int i = 0; i < num; i++)
                {
                    char name1[20];
                    unsigned int roll;
                    unsigned int marks;
                    printf("Enter the name of the student: ");
                    scanf("%s", name1);
                    printf("Enter the roll of the student: ");
                    scanf("%d", &roll);
                    printf("Enter the marks of the student: ");
                    scanf("%d", &marks);


                    head2 = addSNodeSorted(head2, name1, roll, marks); 
                    if (head2)
                    {
                        printf("Added student.\n");
                    }
                }

                head=sortOnMarksSNodeSorted(head);  
                student *merged = NULL;
                merged = mergeSNodeSorted(&head, &head2);
                printLL(merged);

                head = merged;     

                freeSNodeSorted(head2); 
                head2 = NULL;           

                printf("The list was merged in the existing list.\n");
                break;
            }
            case 0:
            {
                printf("Operations Terminated\n");
                freeSNodeSorted(head);   
                break;
            }
            default:
            {
                printf("Enter a valid input.\n");
            }
        }
    }
}