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

void moveBetweenTwoTowers(tourPointer tour , int tower1 ,int tower2){
   

   pointer* tower1Stack  = NULL;
   pointer* tower2Stack  = NULL;


   tower1Stack = getPiquet(tour , tower1);
   tower2Stack = getPiquet(tour , tower2);

   if(tower1Stack || tower2Stack){

    if(!*tower1Stack){
       popPiquet(tour , tower2 , tower1);
      //  printf("Move a disk from %d to %d\n" , tower2 , tower1);
    }
    else if(!*tower2Stack){
      popPiquet(tour , tower1 , tower2);
      // printf("Move a disk from %d to %d\n" , tower1 , tower2);
    }
   else if(getDiskSize(peek(*tower1Stack)) > getDiskSize(peek(*tower2Stack))){
    
       popPiquet(tour , tower2 , tower1);
      //  printf("Move a disk from %d to %d\n" , tower2 , tower1);
   }else {

      popPiquet(tour , tower1 , tower2);
      // printf("Move a disk from %d to %d\n" , tower1 , tower2);
   }

   }



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
   //   long long int localSteps = 1ll;
     callPointer stack = initStack();
     int tempPiquet = getTheTemporaryPiquetNumber(source , destination);
   
     pushCall(&stack , newParams(tempPiquet , destination , disksToBeMoved - 1));
     pushCall(&stack , newParams(source , destination , 1));
     pushCall(&stack , newParams(source,tempPiquet , disksToBeMoved - 1 ));

     while(!isEmptyStack(stack)){
         callParams currentCall = popCall(&stack);
         
        if(currentCall.disksNumber > 1){
           tempPiquet = getTheTemporaryPiquetNumber(currentCall.source , currentCall.destination);

           pushCall(&stack , newParams(tempPiquet , currentCall.destination , currentCall.disksNumber - 1));
           pushCall(&stack , newParams(currentCall.source , currentCall.destination , 1));
           pushCall(&stack , newParams(currentCall.source , tempPiquet , currentCall.disksNumber - 1));

        }else{
          popPiquet(tour , currentCall.source , currentCall.destination);
        }
     }
}


void resolveHanoiGameIteratif2(tourPointer tour , int source , int destination , int disksToBeMoved){
   
   int tempPiquet = getTheTemporaryPiquetNumber(source , destination);

   long long int i , total_num_of_moves;
  
    //If number of disks is even, then interchange 
    //destination pole and auxiliary pole 
    if (disksToBeMoved % 2 == 0) 
    { 
        int temp = destination; 
        destination = tempPiquet; 
        tempPiquet = temp; 
    } 
    total_num_of_moves = pow(2, disksToBeMoved) - 1; 
  

  
    for (i = 1ll; i <= total_num_of_moves; i++) 
    { 
        if (i % 3 == 1) 
        {
         //  popPiquet(tour, source, destination); 
          moveBetweenTwoTowers(tour , source , destination);
         //  printf("Move a disk from %d to %d\n" , source , destination);
        }
        
  
        else if (i % 3 == 2) {
         //  popPiquet(tour, source, tempPiquet);
          moveBetweenTwoTowers(tour , source , tempPiquet); 
         //  printf("Move a disk from %d to %d\n" , source , tempPiquet);
        }
  
        else if (i % 3 == 0) {
         //  popPiquet(tour, tempPiquet, destination);
           moveBetweenTwoTowers(tour , tempPiquet , destination); 
         //  printf("Move a disk from %d to %d\n" ,tempPiquet , destination);
        }
    } 
}



