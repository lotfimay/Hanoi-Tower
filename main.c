#include <stdio.h>
#include <stdlib.h>
#include "functions.c"




int main(){ 


    


    tourPointer tour = initializeHanoiTour();
    int n = 3;
    fillHanoiTour(tour , n);

    printfCurrentState(*tour);

  
    resolveHanoiGame(tour , 1 , 3 , n);

    printf("==================================================================\n");

    printfCurrentState(*tour);


    return 0;
}
