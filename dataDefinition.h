/*
===================
===================
Disk declaration
===================
===================
*/

typedef struct Disk{
    int size;
}Disk;


typedef struct point{
    int source;
    int destination;
}point;


/*
===================
===================
piquet declaration
===================
===================
*/

typedef struct node* pointer;

typedef struct node{
    Disk value;
    pointer next;
}node;

typedef struct stack* stackPointer;
typedef struct stack{
    point value;
    stackPointer next;
}stack;



/*
==========================
==========================
tour de Hanoï declaration
==========================
==========================
*/

typedef struct HanoiTour{
    pointer piquet1;
    pointer piquet2;
    pointer piquet3;
}HanoiTour;

typedef struct HanoiTour* tourPointer;
