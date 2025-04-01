//developing a linked list

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    //SELF REFERENCE STRUCTURE FOR A NODE IN A LINKE LIST
    int data;
    struct node *next;
};

struct node *HEADER; //MAKE THE HEADER POINTER OF THE LINKED LIST
struct node *TAIL; //TAIL
struct node *BEFORE_TAIL; //ONE BEFORE THE TAIL

void TRAVERSE();

void ADD_NODE();

void PRINT_NODES();

int main(void) {
    //ASK THE USER TO SEND THE NUMBER OF INPUT DATA
    int NUMBER_OF_INPUT_DATA = 0; //INITIALIZE THE VARIABLES
    printf("ENTER THE NUMBER OF INPUT DATA:  ");
    scanf("%d", &NUMBER_OF_INPUT_DATA);
    //
    printf("\n"); //NEW LINE
    //REQUEST THE DATA UNTIL ALL OF THEM ARE GATHERED AND STORE THEM IN THE LINKED LIST
    int VALUE = 0; //STORE THE VALUES GIVEN BY THE USER
    for (int i = 0; i < NUMBER_OF_INPUT_DATA; i++) {
        //ASK THE VALUE
        printf("ENTER THE VALUE: ");
        scanf("%d", &VALUE);
        //
        if (i == 0) {
            //FIRST VALUE IS ASSIGNED TO THE LINKED LIST IN THIS PART
            HEADER = (struct node *) malloc(sizeof(struct node));
            TAIL = HEADER; //MAKE THE TAIL HAS THE SAME ADDRESS AS HEADER
            HEADER->data = VALUE;
        } else {
            //REST ARE ASSIGNED TO THE LINK LIST IN THIS PART
            BEFORE_TAIL = (struct node *) malloc(sizeof(struct node));
            //MAKE ANOTHER NODE AND IT IS POINTED BY THE BEFORE_TAIL
            BEFORE_TAIL->data = VALUE; //ASSIGN THE VALUE TO THE NODE USING THE BEFORE_TAIL
            TAIL->next = BEFORE_TAIL;
            //THE NEXT_VARIABLE OF THE NODE POINTED BY THE TAIL SHOULD GET THE ADDRESS OF THE BEFORE_TAIL
            TAIL = BEFORE_TAIL; //TAIL SHOULD POINT THE NEW NODE
            BEFORE_TAIL = NULL; //REMOVE THE TAIL POINTER, MAKE IT A NULL POINTER
        }
    }
    //END COLLECTING DATA AND PRINT THE VALUES
    PRINT_NODES();

    //ASK FROM THE USER
    char USER_INPUT[20];
    while (1) {
        printf("\n\nTO UPDATE A VALUE, ENTER 'UPDATE'\n");
        printf("TO ADD A NEW NODE ENTER 'ADD'\n");
        printf("TO EXIT ENTER 'EXIT'\n");
        scanf("%s", USER_INPUT);
        if (strcmp(USER_INPUT, "EXIT") == 0) { break; } //FINISH THE PROGRAMME

        if (strcmp(USER_INPUT, "UPDATE") == 0) {
            TRAVERSE();
        } else if (strcmp(USER_INPUT, "ADD") == 0) {
            ADD_NODE();
        } else {
            printf("\nWRONG INPUT!!\n");
        }
    }
}

void TRAVERSE() {
    int DUMMY = 1, VALUE = 0, VALUE_NEW = 0;
    //MAKE DUMMY VARIABLE AND INITIALIZE IT INTO 1 TO COUNT THE POSITION OF THE SPECIFIC NODE
    uint8_t BREAK = 0;
    //GET THE DATA VALUE THAT THE USER NEEDS TO FIND AND STORE IT IN THE VARIABLE 'VALUE'
    printf("\nENTER THE VALUE THAT YOU NEED TO UPDATE: ");
    scanf("%d", &VALUE);
    printf("\nENTER THE NEW VALUE: ");
    scanf("%d", &VALUE_NEW);
    //
    BEFORE_TAIL = HEADER; //MAKE THE ADDRESS OF THE BEFORE_TAIL EQUAL TO THE ADDRESS OF THE HEADER
    while (BEFORE_TAIL->data != VALUE /*CHECK THE DATA POINTED BY THE BEFORE TAIL IS NOT EQUAL TO THE VALUE */) {
        if (BEFORE_TAIL != TAIL /*BEFORE_TAIL IS NOT EQUAL TO TAIL*/) {
            BEFORE_TAIL = BEFORE_TAIL->next; //POINT THE BEFORE_TAIL TO THE NEXT NODE
            DUMMY++; //INCREMENT THE DUMMY VARIABLE
        } else {
            printf("\nVALUE IS NOT AVAILABLE IN THE LINKED LIST.");
            //PRINT AS THE VALUE IS NOT AVAILABLE IN THE LINKED LIST
            BREAK = 1; //ACKNOWLEDGE THAT THE WHILE LOOP HAS EXIT WITH A BREAK
            break;
        }
    }
    if (BREAK == 0) {
        //IF THE WHILE LOOP HAS EXIT WITHOUT A BREAK
        BEFORE_TAIL->data = VALUE_NEW;
        PRINT_NODES(); //CALL THE FUNCTION TO PRINT VALUES
    }

    BEFORE_TAIL = NULL; //MAKE THE BEFORE TAIL NULL
}

void ADD_NODE() {
    int VALUE = 0, POSITION = 0; //INITIALIZE THE VARIABLES 'POSITION' AND 'VALUE'
    struct node *ADDER = malloc(sizeof(struct node)); //MAKE A NEW POINTER VARIABLE AS ADDER
    //TAKE THE VALUE OF THE NODE AND THE POSITION OF THE NODE FROM THE USER AND STORE THEM IN VARIABLES
    printf("ENTER THE VALUE OF THE NODE: ");
    scanf("%d", &VALUE);
    printf("ENTER THE POSITION OF THE NODE: ");
    scanf("%d", &POSITION);
    //
    //ASSIGN THE VALUE INTO TEH NODE
    ADDER->data = VALUE;
    //
    BEFORE_TAIL = HEADER; //MAKE THE BEFORE_TAIL EQUAL TO THE HEADER

    for (int i = 1; i < POSITION - 1; i++) {
        BEFORE_TAIL = BEFORE_TAIL->next; //MAKE BEFORE TAIL POINT TO THE NEXT NODE
    }

    if (POSITION == 1 /*POSITION IS 1*/) {
        ADDER->next = HEADER; //ASSIGN THE NEXT_VARIABLE OF THE NODE POINTED BY THE ADDER TO HEADER
        HEADER = ADDER; //ASSIGN TRACK TO ADDER
    } else if (BEFORE_TAIL == TAIL /*BEFORE TAIL IS EQUAL TO THE TAIL*/) {
        ADDER->next = NULL; //ASSIGN THE NEXT_VARIABLE OF THE NODE POINTED BY THE ADDER TO NULL
        BEFORE_TAIL->next = ADDER;
        //ASSIGN THE ADDER ADDRESS TO THE NEXT_VARIABLE OF THE NODE POINTED BY THE BEFORE_TAIL
        TAIL = ADDER; //ASSIGN ADDER TO TAIL
    } else {
        ADDER->next = BEFORE_TAIL->next;
        //ASSIGN NEXT_VARIABLE OF THE NODE POINTED BY THE BEFORE TAIL TO THE NEXT_VARIABLE OF THE NODE POINTED BY THE ADDER
        BEFORE_TAIL->next = ADDER;
        //ASSIGN THE ADDER ADDRESS TO THE NEXT_VARIABLE OF THE NODE POINTED BY THE BEFORE_TAIL
    }


    ADDER = NULL;
    BEFORE_TAIL = NULL; //MAKE THE ADDER AND BEFORE TAIL NULL

    PRINT_NODES(); //PRINT ALL THE VALUES INCLUDING THE NEWLY ADDED NODE
}

void PRINT_NODES() {
    printf("\n\nTHE LINKED LIST IS: ");
    BEFORE_TAIL = HEADER; //MAKE BEFORE TAIL EQUAL TO HEADER
    while (BEFORE_TAIL != TAIL /*BEFORE TAIL IS NOT EQUAL TO TAIL*/) {
        printf("%d, ", BEFORE_TAIL->data); //PRINT THE VALUE IN THE MONITOR
        BEFORE_TAIL = BEFORE_TAIL->next; //POINT TO THE NEXT NODE
    }
    printf("%d", BEFORE_TAIL->data); //PRINT THE VALUE, THIS IS USED THE PRINT THE LAST NODE
}
