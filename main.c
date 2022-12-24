#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"





int main(){ 


    


    tourPointer tour = initializeHanoiTour();
    int n = 30;
    fillHanoiTour(tour , n);

    // printfCurrentState(*tour);

    clock_t start_time , end_time;
    double delta;
    printf("Starting ...\n");
    start_time = clock();
    resolveHanoiGame(tour , 1 , 3 , n);
    end_time = clock();
    delta=(double)(end_time-start_time)/(CLOCKS_PER_SEC);
    printf("time : %llf\n" , delta);

    printf("==================================================================\n");

    printfCurrentState(*tour);


    return 0;
}
