#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50
struct student_details
{
 char name[100];
 int roll;
 char tel[50];
 char address[100];
};
typedef struct student_details Student;

struct Register
{
 Student s[N];
 int nStudents;
};
typedef struct Register SReg;

int add(SReg *psr, Student *ps)
{
 int i;
 for(i = 0; i < psr->nStudents; i++)
 {
  if(ps->roll == psr->s[i].roll)
  {
   return 0;
  }
 }
 if(psr->nStudents == N)
 {
  return -1;
 }
 psr->s[psr->nStudents] = *ps;
 psr->nStudents = psr->nStudents + 1;
 return 1;
}
 
Student get(SReg *psr, int pr)
{
 int i;
 Student s;
 for(i = 0; i < psr->nStudents; i++)
 {
  if(pr == psr->s[i].roll)
  {
   return psr->s[i];
  }
 }
 s.roll = 0;
 return s;
}

int delete(SReg *psr, int r)
{
 int i, j;
 for(i = 0; i < psr->nStudents; i++)
 {
  if(r == psr->s[i].roll)
  {
   for(j = i; j < (psr->nStudents - 1); j++)
   {
    psr->s[j] = psr->s[j+1];
   }
   psr->nStudents = psr->nStudents - 1;
   return 1;
  }
 }
 return 0;
}

int modify(SReg *psr, Student *ps)
{
 int i;
 for(i = 0; i < psr->nStudents; i++)
 {
  if(ps->roll == psr->s[i].roll)
  {
   psr->s[i] = *ps;
   return 1;
  }
 }
 return 0;
}

void sortStudents(SReg *psr)
{
 int i, j;
 Student t;
 for(i = 0; i < psr->nStudents; i++)
 {
  for(j = (i+1); j < psr->nStudents; j++)
  {
   if(strcmp(psr->s[i].name, psr->s[j].name) > 0)
   {
    t = psr->s[j];
    psr->s[j] = psr->s[i];
    psr->s[i] = t;
   }
  }
 }
}

int getCount(SReg *psr)
{
 return psr->nStudents;
}

void export(SReg *psr, char* fname)
{
 FILE *fp;
 fp = fopen(fname, "w");
 if(fp == NULL)
 {
  printf("Cannot open file %s for exporting\n", fname);
 }
 else
 {
  int i;
  for(i = 0; i < psr->nStudents; i++)
  {
   fprintf(fp,"%s\n", psr->s[i].name);
   fprintf(fp,"%d\n", psr->s[i].roll);
   fprintf(fp,"%s\n", psr->s[i].tel);
   fprintf(fp,"%s\n", psr->s[i].address);
  }
  fclose(fp);
  psr->nStudents = 0;
 }
}

void load(SReg *psr, char* fname)
{
 FILE *fp;
 fp = fopen(fname, "r");
 if(fp == NULL)
 {
  printf("Cannot open file %s for loading\n", fname);
 }
 else
 {
  while(feof(fp) == 0)
  {
   int i = psr->nStudents;
   fscanf(fp,"%s[^\n]", psr->s[i].name);
   fscanf(fp,"%d[^\n]", &psr->s[i].roll);
   fscanf(fp,"%s[^\n]", psr->s[i].tel);
   fscanf(fp,"%s[^\n]", psr->s[i].address);
   psr->nStudents++;
  }
  fclose(fp);
 }
}

int main()
{
 int p;
 SReg sr;
 Student s;
 sr.nStudents = 0;
 while(1)
 {
  printf("Student Register\n");
  printf("1. Add a student\n");
  printf("2. Get a student\n");
  printf("3. Delete a student\n");
  printf("4. Modify a student\n");
  printf("5. Sort the students\n");
  printf("6. Get the count of the students\n");
  printf("7. Export student register\n");
  printf("8. Load student register\n");
  printf("9. Exit\n");
  printf("Enter your option: ");
  scanf("%d", &p);
  switch(p)
  {
   case 1:
    {
     int rc;
     printf("Enter details of the student\n");
     printf("Name: ");
     scanf("%s", s.name);
     printf("Roll no: ");
     scanf("%d", &s.roll);
     printf("Telephone number: ");
     scanf("%s", s.tel);
     printf("Address: ");
     scanf("%s", s.address);
     rc = add(&sr, &s);
     if(rc == 0)
     {
      printf("The student already exists in the register\n");
     }
     else if(rc ==1)
     {
      printf("Student has been added to the register\n");
     }
     else
     {
      printf("Student register is full\n");
     }
    }
    break;
   case 2: 
    {
     int r;
     Student rc;
     printf("Enter the roll number of the student required: ");
     scanf("%d", &r);
     rc = get(&sr, r);
     if(rc.roll == 0)
     {
      printf("No such student exists in the register\n");
     }
     else
     {
      printf("Details of the student:\n");
      printf("%s\n", rc.name);
      printf("%d\n", &rc.roll);
      printf("%s\n", rc.tel);
      printf("%s\n", rc.address);
     }
    }
    break;
   case 3:
    {
     int r, rc;
     printf("Enter the roll number of the student to be deleted: ");
     scanf("%d", &r);
     rc = delete(&sr, r);
     if(rc == 0)
     {
      printf("No such student exists in the register\n");
     }
     else
     {
      printf("Student has been deleted\n");
     }
    }
    break;
   case 4:
    {
     int rc;
     printf("Enter the roll number of the student to be modified: ");
     scanf("%d", &s.roll);
     printf("Enter details of the student\n");
     printf("Name: ");
     scanf("%s", s.name);
     printf("Telephone number: ");
     scanf("%s", s.tel);
     printf("Address: ");
     scanf("%s", s.address);
     rc = modify(&sr, &s);
     if(rc == 0)
     {
      printf("The student does not exist in the register\n");
     }
     else
     {
      printf("Student has been modified in the register\n");
     }     
    }
    break;
   case 5:
    {
     sortStudents(&sr);
    }
    break;
   case 6:
    {
     getCount(&sr);
    }
    break;
   case 7:
    {
     char fn[50];
     printf("Enter the file name where the student register is to be exported:");
     scanf("%s", fn);
     export(&sr, fn);
    }
    break;
   case 8:
    {
     char fn[50];
     printf("Enter the file name where the student register whose students are to be loaded:");
     scanf("%s", fn);  
     load(&sr, fn);
    }
    break;
   case 9: break;
   default : printf("Invalid option\n");
     break;
  }
 }
}