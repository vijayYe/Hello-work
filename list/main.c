#include "list.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include <sys/types.h>
#include <string.h>

#define MAX_STRING_LENGTH 64

typedef struct student {
  char first_name[MAX_STRING_LENGTH];
  char last_name[MAX_STRING_LENGTH];
  unsigned int age;
  struct list node_student;
} student_t;

typedef struct{
  char first_name[MAX_STRING_LENGTH];
  unsigned int type; 
  unsigned int age;
  struct list node_teacher;
} teacher_t;

struct list class;



student_t *make_student(const char *fn, const char *ln, unsigned int a) {
  student_t *stu = NULL;

  if ((stu = calloc(1, sizeof(struct student))) == NULL) {
    return NULL; /* Failed to allocate memory. */
  }
  if (strlen(fn) > (MAX_STRING_LENGTH - 1)) {
    return NULL; /* First name too long. */
  }
  if (strlen(ln) > (MAX_STRING_LENGTH - 1)) {
    return NULL; /* Last name too long. */
  }

  strcpy(stu->first_name, fn);
  strcpy(stu->last_name, ln);
  stu->age = a;
  return stu;
}

void del_student(student_t * stu){
	free(stu);
}

int main(int argc, char* argv[]){
	list_init(&class);

	student_t *stu = NULL;

	/* Create students. */
	if ((stu = make_student("Pierre", "Dupont", 16)) == NULL) {
	  fprintf(stderr, "Failed to create Pierre.\n");
	  return -1;
	}
	list_insert(&class, &stu->node_student);


	if ((stu = make_student("Hugot", "Badeaux", 18)) == NULL) {
	  fprintf(stderr, "Failed to create Hugot.\n");
	  return -1;
	}
	list_insert(&class, &stu->node_student);


	if ((stu = make_student("Celine", "Brousseau", 17)) == NULL) {
	  fprintf(stderr, "Failed to create Celine.\n");
	  return -1;
	}
	list_insert(&class, &stu->node_student);

	student_t *stu_n = NULL;
#if 1
	/* Print all students in class. */
	printf("All the students in class.\n");
	dl_list_for_each_safe(stu, stu_n, &class, student_t, node_student) {
	  printf("First name: %s, next:%s\n", stu->first_name, stu_n->first_name);
	  printf("Last name: %s, next:%s\n", stu->last_name, stu_n->last_name);
	  printf("Age: %u, next: %u\n\n", stu->age, stu_n->age);
	}
#endif

	
	dl_list_for_each_safe(stu, stu_n, &class, student_t, node_student) {
		printf("First name: %s, next:%s\n", stu->first_name, stu_n->first_name);
		 printf("Last name: %s, next:%s\n", stu->last_name, stu_n->last_name);
		  printf("Age: %u, next: %u\n\n", stu->age, stu_n->age);
		if(stu->age == 18){
			list_remove(&stu->node_student);
			del_student(stu);
		}
	}

#if 1
		/* Print all students in class. */
		printf("All the students in class.\n");
		dl_list_for_each(stu, &class, student_t, node_student) {
		  printf("First name: %s\n", stu->first_name);
		  printf("Last name: %s\n", stu->last_name);
		  printf("Age: %u\n\n", stu->age);
		}
#endif

	return 0;
}


