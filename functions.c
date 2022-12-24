#include <stdlib.h>
#include "utils.c"
#include "functions.h"






// int steps = 1;


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
        Disk* disk = (Disk*)malloc(sizeof(Disk));
        disk->size = i;
        insertPiquet(tour , 1 ,*disk);
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
        int tmpPiquet = getTheTemporaryPiquetNumber(source , destination);
        resolveHanoiGame(tour , source , tmpPiquet , disksToBeMoved - 1);
        resolveHanoiGame(tour , source , destination , 1);
        resolveHanoiGame(tour , tmpPiquet , destination ,disksToBeMoved - 1);
     }else{
        popPiquet(tour , source , destination);
      //   printf("step %d  : move a Disk from %s to %s\n" ,steps ,  getPiquetTitle(source) , getPiquetTitle(destination));
      //   steps++;
     }
}


void resolveHanoiGameIteratif(tourPointer tour , int source , int destination , int disksToBeMoved){

     int localSteps = 1;
     callPointer stack = initStack();

     callParams params = newParams(getTheTemporaryPiquetNumber(source , destination) , destination , disksToBeMoved - 1);
     pushCall(&stack , params);

     params = newParams(source , destination , 1);
     pushCall(&stack , params);

     params = newParams(source,getTheTemporaryPiquetNumber(source , destination) , disksToBeMoved - 1 );
     pushCall(&stack , params);

     while(!isEmptyStack(stack)){
        callPointer call = popCall(&stack);
        if(call->params.disksNumber > 1){
           
           params = newParams(getTheTemporaryPiquetNumber(call->params.source , call->params.destination) , call->params.destination , call->params.disksNumber - 1);
           pushCall(&stack , params);

           params = newParams(call->params.source , call->params.destination , 1);
           pushCall(&stack , params);

           params = newParams(call->params.source , getTheTemporaryPiquetNumber(call->params.source , call->params.destination) , call->params.disksNumber - 1);
           pushCall(&stack , params);
        }else{
          popPiquet(tour , call->params.source , call->params.destination);
         //  printf("step %d  : move a Disk from  %s to %s\n" ,localSteps ,  getPiquetTitle(call->params.source) , getPiquetTitle(call->params.destination));
          localSteps++;
        }
     }
}



