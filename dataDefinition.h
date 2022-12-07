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


typedef struct callParams{
    int source;
    int destination;
    int disksNumber;  
}callParams;

typedef struct call* callPointer;
typedef struct call {
    callParams params;
    callPointer next;
}call;
