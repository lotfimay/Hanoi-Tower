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

// typedef struct stack* stackPointer;
// typedef struct stack{
//     point value;
//     stackPointer next;
// }stack;



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

typedef struct point* pointPointer;
typedef struct point {
    int source;
    int destination;
    int disksNumber;
    pointPointer next;
}point;
