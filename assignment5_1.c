#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[20];
    unsigned int roll;
    unsigned int marks;
    struct student *next;
} student;

student *addSNodeSorted(student *head, char name[20], unsigned int roll, unsigned int marks){
    student *temp = (student *)malloc(sizeof(student));
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->roll = roll;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return head;
    }
    if (marks < head->marks){
        temp->next = head;
        head = temp;
        return head;
    }else{
        student *ptr = head;
        while (ptr->next != NULL && ptr->next->marks < marks)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}

int isPresentSNode(student *head, char name[], unsigned int roll, unsigned int marks){
    int i = 1;
    student *ptr = head;
    while (ptr != NULL){
        if (strcmp(name, ptr->name) == 0 && ptr->roll == roll && ptr->marks == marks)
            return i;
        ptr = ptr->next;
        i++;
    }
    return 0;
}

student *deleteSNodeS(student *head, unsigned int roll){
    if (head == NULL)
        return 0;
    if (head->roll == roll){
        student *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    student *ptr;
    ptr = head;
    while (ptr->next != NULL){
        if (ptr->next->roll == roll){
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

int main()
{
    student *head = NULL;
    int input = 1;
    while (input){
        printf("\n1. ADD STUDENT INFORMATION.\n");
        printf("2. SEARCH FOR STUDENT.\n");
        printf("3. DELETE A STUDENT RECORD.\n");
        printf("4. PRINT ENTIRE LIST.\n ");
        printf("ENTER YOUR CHOICE(0 FOR EXIT):");
        scanf("%d", &input);
        switch (input){
        case 1:
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
                char name1[20];
                unsigned int roll;
                unsigned int marks;
                printf("Enter the name of the student: ");
                scanf("%s", name1);
                printf("Enter the roll of the student: ");
                scanf("%d", &roll);
                printf("Enter the marks of the student: ");
                scanf("%d", &marks);
                int position = isPresentSNode(head, name1, roll, marks);
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
        case 0:
        {
            printf("OPERATIONS TERMINATED.\n");
            break;
        }
        default:
        {
            printf("Enter a valid input.\n");
        }
        }
    }
}