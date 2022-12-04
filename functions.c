#include <stdlib.h>
#include "utils.c"
#include "functions.h"






int step = 1;


int getDiskSize(Disk disk){
    return disk.size;
}

tourPointer initializeHanoiTour(){
    tourPointer tour = (tourPointer)malloc(sizeof(HanoiTour));
    tour->piquet1 = NULL;
    tour->piquet2 = NULL;
    tour->piquet3 = NULL;
    return tour; 
}

void fillHanoiTour(tourPointer tour,int disksNumber){
     int i;
     for(i = disksNumber ; i >= 1 ; i--){
        Disk disk;
        disk.size = i;
        insertPiquet(tour , 1 ,disk);
     }
}

void printfCurrentState(HanoiTour tour){

    printf("Piquet 1:\n");
    displayList(tour.piquet1);

    printf("Piquet 2:\n");
    displayList(tour.piquet2);

    printf("Piquet 3:\n");
    displayList(tour.piquet3);

}

void insertPiquet(tourPointer tour,int piquetNumber,Disk value){
     pointer* piquet = getPiquet(tour,piquetNumber);
     push(piquet , value);
}

void popPiquet(tourPointer tour , int source ,int destination){
     if(source == destination){
        printf("Error in moving \n");
        return;
     }
     pointer* sourcePiquet = getPiquet(tour , source);
     pointer* destinationPiquet = getPiquet(tour , destination);
     Disk value = pop(sourcePiquet);
     push(destinationPiquet , value);
}



int getDiskNumber(tourPointer tour , int piquetNumber){
    pointer* piquet = getPiquet(tour , piquetNumber);
    return listSize(*piquet);
}


void resolveHanoiGame(tourPointer tour , int source , int destination,int disksToBeMoved){

     if(disksToBeMoved > 1){
        resolveHanoiGame(tour , source , getTheTemporaryPiquetNumber(source , destination) , disksToBeMoved - 1);
        // resolveHanoiGame(tour , source , destination , 1);
        popPiquet(tour , source , destination);
        printf("step %d  : Disk has been moved from %s to %s\n" ,step ,  getPiquetTitle(source) , getPiquetTitle(destination));
        step++;
        resolveHanoiGame(tour , getTheTemporaryPiquetNumber(source , destination) , destination ,disksToBeMoved - 1);
     }else{
        popPiquet(tour , source , destination);
        printf("step %d  : Disk has been moved from %s to %s\n" ,step ,  getPiquetTitle(source) , getPiquetTitle(destination));
        step++;
     }
}


void resolveHanoiGameIteratif(tourPointer tour , int source , int destination , int disksToBeMoved){

    while(disksToBeMoved){
           
    }  
}

pointer* getPiquet(tourPointer tour , int piquetNumber){
    pointer* piquet = NULL;
    if(piquetNumber == 1){
        piquet = &(tour->piquet1);
    }else if (piquetNumber == 2){
        piquet = &(tour->piquet2);
    }else if(piquetNumber == 3){
        piquet =  &(tour->piquet3);
    }
    return piquet;
}

