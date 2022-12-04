void resolveHanoiGame(tourPointer tour , int source , int destination,int disksToBeMoved);
int getDiskNumber(tourPointer tour , int piquetNumber);
void popPiquet(tourPointer tour , int source ,int destination);

/*
insert a disk in the tower
*/
void insertPiquet(tourPointer tour,int piquetNumber,Disk value);
void printfCurrentState(HanoiTour tour);
void fillHanoiTour(tourPointer tour,int disksNumber);
pointer* getPiquet(tourPointer tour , int piquetNumber);
