#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} LIST;


LIST *append( LIST *, int );
LIST *sort( LIST * ,int length);
LIST *list_switch( LIST *, LIST * );
void print_list( LIST * );
LIST *merge(LIST *first,LIST *second);
LIST *middle_f(LIST *n,int length);

int main(void)
{
    LIST *try;
    int i;

    // This is just testing code
    try = NULL;
    try = append( try, 5 );
    try = append( try, 2 );
    try = append( try, 9 );
    try = append( try, 8 );
    try = append( try, 1 );
    try = append( try, 7 );

    printf("Original list:\n");
    print_list( try );
    try = sort( try,6 );
    printf("Sorted list:\n");
    print_list( try );
    return 0;
}

void print_list( LIST *t )
{
    while( t != NULL ) {
        printf( "%d\n", t->data );
        t = t->next;
    }
}

LIST *append( LIST *start, int newdata )
{
    LIST *new, *end, *ret;

    if( (new = (LIST *)malloc(sizeof(LIST))) == NULL) {
        fprintf( stderr, "Memory Allocation error.\n" );
        // In Windows, replace following with a return statement.
        exit(1);
    }
    if( start == NULL )
        ret = new;
    else {
        ret = start;
        end = start;
        while( end->next != NULL ) end = end->next;
        end->next = new;
    }
    new->data = newdata;
    new->next = NULL;
    return ret ;
}

LIST *sort( LIST *start,int length)
{
    if(length==1)   return  start;
    LIST *middle, *half;
    middle=middle_f(start,length);
    half=middle->next;
    middle->next=NULL;
    return merge(sort(start,length/2),sort(half,length/2+length%2));
}

LIST *list_switch( LIST *l1, LIST *l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}

LIST *merge(LIST *first,LIST *second)
{
    LIST *n, *head;
    head=(LIST *)malloc(sizeof(LIST));
    n=head;	
    while(first!=NULL&&second!=NULL){
        if(first->data<=second->data){
            n->next=first;
            first=first->next;
        }
        else{
            n->next=second;
            second=second->next;
        }
        n=n->next;
    }
    if(first==NULL)
        n->next=second;
    else
        n->next=first;

    return head->next;
}

LIST *middle_f(LIST *n,int length)
{
    if(length==1)   return n;
    for(int i=0;i<length/2-1;i++){
        n=n->next;
    }
    return n;
}


