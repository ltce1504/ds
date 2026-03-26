#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max], F=-1, R=-1;

// Insert
void insert() {
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &num);
    if(F==0 && R==max-1)
        printf("\nOverload");
    else {
        if(F==-1 && R==-1)
            F=R=0;
        else {
            if(R==max-1 && F!=0)
                R=0;
            else
                R++;
        }
        queue[R]=num;
    }
}

// Delete
void delete() {
    int val;
    if(F==-1)
        printf("\n Underflow");
    else {
        val = queue[F];
        printf("\n Element deleted");
        if (F==R)
            F=R=-1;
        else {
            if(F==max-1)
                F=0;
            else
                F++;
        }
    }
}

// Display
void display() {
    printf("\nQueue: ");
    if(F==-1 && R==-1)
        printf("\n Queue is empty..");
    else {
        if(F<R) {
            for(int i=F; i<=R; i++)
                printf("%d \n", queue[i]);
        }
        else {
            for(int i=F; i<max; i++)
                printf("%d \n", queue[i]);
            for(int i=0; i<=R; i++)
                printf("%d \n", queue[i]);
        }
    }
}

// Main function
void main() {
    int choice;
    while(1) {
        printf("\n Circular Queue Operations \n1. Insert \n2. Delete \n3. Dsiplay \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("\nExiting, Goodbye!");
                    return;
            default: printf("\nInvalid choice");
        }
    }
}
