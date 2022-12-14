#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80

typedef struct student_fixed {
  int id;
  char name[MAX_LINE];
} student_fixed;

typedef struct student_dynamic {
  int id;
  char *name;
} student_dynamic;

student_fixed student1;
student_dynamic *student2;

int main() {
  int cur_ID = 1234;
  char name[MAX_LINE];
  printf("What is your name? ");
  //scanf("%s",name);
  fgets(name,MAX_LINE,stdin);
  name[strlen(name)-1] = '\0';
  printf("Hello %s!\t(%ld)\n",name,strlen(name));

  student1.id = cur_ID;
  strcpy(student1.name,name);

  student2 = malloc(sizeof(student_dynamic));
  student2->id = cur_ID;
  student2->name = calloc(strlen(name),sizeof(char));
  strcpy(student2->name,name);

  return 0;
}
