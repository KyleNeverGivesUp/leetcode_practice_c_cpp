#include <stdio.h>
#include <string.h>

// struct Student{
//     char name[50];
//     int id;
//     float gpa;
// };

typedef struct{
    char name[50];
    int id;
    float gpa;
} Student;

typedef struct {
    char name[50];
    int id;
    float gpa;
} Teacher ;

int main(){
    Student s1;
    s1.id = 101;
    s1.gpa = 3.8;
    strcpy(s1.name, "Kyle");
    printf("ID is %d\n", s1.id);

    // Teacher t1 = {"Xinyi", 102, 3.9};
    // printf("Teacher ID is %s\n", t1.name);
    
    Student *p = &s1;
    printf("ID is %d\n", p->id);

    return 0; 
}