#include <stdio.h>
#include <stdlib.h>
int array_access(int a[], int i) {
    return a[i];
}

void array_deletion(int a[], int i, int *n){
    for(int j=i; j<n-1; j++)
    {
        a[j]=a[j+1];
    }
    (*n)--;
}

void array_insertion(int a[], int i, int *n, int x){
    for(int j=n-1; j>i; j--)
    {
        a[j+1]=a[j];
    }
    a[i]=x;
    (*n)++;
}

//Lists

struct SNode {
    int val;
    struct SNode *next;
};

struct SSLL{
    struct SNode * head;
};
typedef struct SSLL *SLL;

struct DNode {
    int val;
    struct DNode *next;
    struct DNode *prev;
};

struct SDLL{
    struct DNode *head;
    struct DNode *tail;
};

typedef struct SDLL *DLL;

struct CNode{
    int val;
    struct CNode *next;
    struct CNode *prev;
};

struct SCLL{
    struct CNode *d_ancre;
};

typedef struct SCLL *CLL;

// Stacks 

struct SStack{
    int tab[1000];
    int n;
};

typedef struct SStack* Stack;

Stack new_Stack(){
    Stack s = malloc(sizeof(struct SStack));
    s->n=0;
    return s;  
}

void stack_push(Stack s, int val){
    s->tab[s->n] = val;
    s->n++;
}

int stack_top(Stack s){
    return s->tab[s->n-1];
}

int stack_pop(Stack s){
    int x = s->tab[s->n-1];
    s->n--;
    return x;
}

int stack_peek(Stack s){
    return s->tab[s->n-1];
}

// Queue

struct SQueue{
    int Q[1000];
    int n;
};

typedef struct SQueue * Queue;

Queue new_Queue(){
    Queue q = malloc(sizeof(struct SQueue));
    q->n=0;
    return q;
}

void enqueue(Queue q, int x)
{
    q->Q[q->n]=x;
    q->n++;
}

int dequeue(Queue q){
    int x= q->Q[0];
    for(int i=0;i<q->n-1;i++)
    {
        q->Q[i]=q->Q[i+1];
    }
    q->n--;
    return x;
}

int peek(Queue q){
    return q->Q[0];
}

//Hash

unsigned int hash(const char *key, int size) {
    unsigned int sum = 0;
    int i = 0;
    while (key[i] != '\0') {
        sum += key[i];
        i++;
    }
    return sum % size;
}