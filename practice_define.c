#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SZE 100
#define NUM_SCORES 5


struct node{
    int data;
    struct node* next;
};


int main(){
    struct node* tail = NULL;
    
    struct node* head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    tail = head;
    // printf("head->data = %d\n", head->data);
    // printf("tail->next = %p\n", tail->next);

    // new node
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = 2;
    new_node->next = head;
    printf("head = %p\n", head);
    printf("&head = %p\n", &head);
    printf("new_node = %p\n", new_node);
    printf("new_node->next = %p\n", new_node->next);

    struct node* tmp = new_node;
    while (tmp != NULL){
        printf("tmp->data = %d\n", tmp->data);
        tmp = tmp->next;
    }
}

// typedef struct
// {
// char letter_grade;
// int id;
// } Student;
// void init_grades( Student ros[], int num_students )
// {
// for (int i = 0; i < num_students; i++)
// ros[i].letter_grade = 'X';
// }
// int main()
// {
// Student roster[5];
// printf("sizeof(roster) = %lu \n", sizeof(roster));
// printf("sizeof(Student) = %lu \n", sizeof(Student));
// printf("number of elements = %lu \n", sizeof(roster)/sizeof(Student));
// init_grades( roster, sizeof(roster)/sizeof(Student) );
// printf("roster[2].letter_grade = %c \n", roster[2].letter_grade);
// return 0;
// }

// void set_scores(int scores[], int val){
//     for(int i=0;i<NUM_SCORES;i++){
//         scores[i] = val;
//     }
// }

// void set_scores(int* scores, int val){
//     for(int i=0;i<NUM_SCORES;i++){
//         *scores++ = val;
//         printf("scores address = %p, value = %d\n", scores-1, *(scores-1));
//     }
// }

// int main(){
//     // int scores[NUM_SCORES];
//     int* scores=malloc(1024 * 1024 * 1024);
//     if (scores == NULL) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }
//     memset(scores, 0xAA, 1024 * 1024 * 1024);
//     unsigned char* p = (unsigned char*)scores;
//     for(int i=0;i<NUM_SCORES;i++){
//         printf("scores[%d] = %c\n", i, *(p+i));
//     }

//     for(int i=0;i<NUM_SCORES;i++){
//         printf("scores[%d] = %c\n", i, scores[1024*1024*1024-NUM_SCORES+i]);
//     }

    // printf("scores address = %p\n", scores);
    // printf("scores size = %lu\n", sizeof(scores));
    // printf("scores size = %lu\n", sizeof(*scores));
    // printf("scores size = %lu\n", sizeof(int));
    
    // set_scores(scores, 100);
    // memset

//     for(int i=0;i<NUM_SCORES;i++){
//         printf("scores[%d] = %d\n", i, scores[i]);
// }
// }



// int main(){
//     #ifdef TABLE_SZE
//     int table[TABLE_SZE];
//     #else
//     int table[10];
//     #endif
//     printf("table size= %lu\n", sizeof(table));
// }

// int main(int argc, char *argv[]) {
//     // printf("argb = %d\t%s\n", argc, argv[1]);
//     typeof(argc) x = argc;
//     printf("type of argc = %d\n", x);
// }


#include <stdio.h>
#include <math.h>
// float Pythy(float a, float b);

// int main()
// {
//     char firstName[30];
//     int num;

//     printf("Enter your first name: \n");
//     scanf("%s", firstName);
//     printf("Enter a number: \n");
//     scanf("%d", &num);

//     printf("Hello %s, your number is %d\n", firstName, num);
// }

// struct my_struct{
//     int a;
//     char b;
// };

// typedef struct {
//     int a;
//     char b;
// } student;

// typedef enum {F=0,T=1} myBool;

// int a[5];
// int main()
// {
//     myBool bool1 = 0;
//     printf("bool1 = %d\n", bool1+1);
//     a[0] = 2;
//     a[1] = 3;
//     a[2] = 7;
//     struct my_struct student1;
//     // printf("sizeof(s) = %lu\n", sizeof(s));
//     printf("sizeof(a[0]) = %lu\n", sizeof(a[0]));
//     printf("a[2] = %d\n", a[2]);
//     printf("*(a+2) = %d\n", *(a+2));
//     printf("a = %p\n", a);
//     printf("a+1 = %p\n", a+1);
//     printf("*(a+1) = %d\n", *(a+1));
// }

// int main(){
//     char a,b;
//     struct my_struct s = {1,'k'};
//     // s.a=1;
//     // s.b='y';
//     printf("s.a = %d, s.b = %c\n", s.a, s.b);
//     a = 2;
//     b = 'x';
//     printf("a = %d, b = %c\n", a, b);
//     printf("a+b=%d\n", a+b);

// }

// int main(){
    // int b, c;
    // b = 100;
    // c = 100;
    // int* d = NULL;
    // printf("*d = %p\n", d);
    // printf("b = %p\n", &b);
    // printf("sizeof(b) = %lu\n", sizeof(b));
    // printf("sizeof(&b) = %lu\n", sizeof(&b));
    // printf("c = %p\n", &c);
    // printf("%x \n",*((char*)&b+0));
    // printf("%x ",*((unsigned char*)&b+0));
    // printf("%x ",*((unsigned char*)&b+1));
    // printf("%x ",*((unsigned char*)&b+2));
    // printf("%x ",*((unsigned char*)&b+3));
    // printf("\n");
    // printf("%d ",*((unsigned char*)&b+0));
    // printf("%d ",*((unsigned char*)&b+1));
    // printf("%d ",*((unsigned char*)&b+2));
    // printf("%d ",*((unsigned char*)&b+3));
    // printf("\n");
    // printf("%d ",*((unsigned char*)&b+0) + *((unsigned char*)&b+1) + *((unsigned char*)&b+2) + *((unsigned char*)&b+3));
    // printf("\n");
    // printf("%d ",*((unsigned char*)&b+0) + *((unsigned char*)&b+1) + *((unsigned char*)&b+2) + *((unsigned char*)&b+3));
    // printf("\n");
    // printf("%d ",*((unsigned char*)&b+0) + *((unsigned char*)&b+1) + *((unsigned char*)&b+2) + *((unsigned char*)&b+3));
    // printf("\n")
// }
