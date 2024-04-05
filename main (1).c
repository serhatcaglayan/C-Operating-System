#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 2

typedef struct folder
{
    int id ;
    char name[20];
    char path[50];
    int numberOfRead;
    int numberOfWrite;
    bool isRead ;
    bool isWriten;

}File;

typedef struct program
{
    int id ;
    char name[20];
    int readFileId[MAX] ;
    int writeFileId[MAX] ;
    int countRead;
    int countWrite;

}Program;

int menu()
{
    int selection ;

    printf("\nCreate new file (1)\n"
       "Create new program (2)\n"
       "Read file (3)\n"
       "Write to file (4)\n"
       "Release reading file (5)\n"
       "Release writing file (6)\n"
       "Close all files for the program (7)\n"
       "Display all files (8)\n"
       "Display all programs (9)\n"
       "Exit (10)\n"
       "Enter your selection: " );

       scanf("%d",&selection);


    return selection ;
}


void createFile(int *numberOfFile,File *ptr)
{

    int id ;
    char name[20];
    char path[50];
    int numberOfRead = 0;
    int numberOfWrite = 0;
    bool isRead = 0;
    bool isWriten = 0;
    bool check = 1;

    printf("Enter File Information :");
    printf("\nID : ") ; scanf("%d",&id);
     for(int i = 0 ; i <*numberOfFile;i++)
    {
        if( id == (ptr+i)->id )
        {

            printf("There is a file already with the given id!!!");
            check = 0;
            break;
        }
    }




    if(check == 1)
    {
        printf("\nName :")  ;scanf("%s",&name);
    printf("\nPath :")  ;scanf("%s",&path);

    (ptr + *numberOfFile ) ->id =id;
    strcpy((ptr + *numberOfFile )->name,name);
    strcpy((ptr + *numberOfFile )->path,path);
    (ptr + *numberOfFile )->isRead = isRead;
    (ptr + *numberOfFile )->isWriten = isWriten;
    (ptr + *numberOfFile )->numberOfRead = numberOfRead;
    (ptr + *numberOfFile )->numberOfWrite = numberOfWrite;


    (*numberOfFile)++;

    }



}
void createProgram(int*numberOfProgram,Program *ptr)
{

    int id ;
    char name[20];
    int countRead = 0;
    int countWrite = 0;

    int readFileId[MAX] ={-1,-1};
    int writeFileId[MAX] ={-1,-1};
    bool check = 1;

    printf("Enter Program Information :");
    printf("\nID : ") ; scanf("%d",&id);


     for(int i = 0 ; i <*numberOfProgram+1;i++)
    {
        if( id == (ptr+i)->id )
        {

            printf("There is a file already with the given id!!!");
            check = 0;
            break;
        }
    }


    if(check ==1)
    {

    printf("\nName :")  ;scanf("%s",&name);
        (ptr + *numberOfProgram )->id=id;
    strcpy((ptr + *numberOfProgram )->name,name);
    (ptr + *numberOfProgram )->readFileId[0] = -1;
     (ptr + *numberOfProgram )->readFileId[1] = -1;
    (ptr + *numberOfProgram )->writeFileId[0] = -1;
    (ptr + *numberOfProgram )->writeFileId[1] = -1;



    (*numberOfProgram)++;
    }



}

void readFile(Program * ptrP , File *ptrF, int NoF , int NoP)
{
  int fileID;
  int programID;
  bool check = 0 ;
  bool check2 = 0;

  int indexFile ;
  int indexProgram;


  printf("\nEnter  File ID : ") ; scanf("%d",&fileID);
  printf("\nEnter  Program ID : ") ; scanf("%d",&programID);


  for(int i = 0 ; i<NoF +1 ; i++)
  {


      if( (ptrF+i)->id  == fileID)
      {
          indexFile = i;

          check = 1;
          break;

      }

  }

  for(int i = 0 ; i<NoP +1 ; i++)
  {



      if( (ptrP+i)->id == programID )
      {

        indexProgram = i ;
          check2 = 1;
          break;

      }

  }

        if(check == 1 && check2==1 &&(ptrF+indexFile)->numberOfRead < MAX  && (ptrF+indexFile)->isWriten == 0  )
        {
          (ptrF+indexFile)->numberOfRead++;
          (ptrF+indexFile)->isRead =1;

          (ptrP+indexProgram)->readFileId[(ptrP+indexProgram)->countRead] =(ptrF+indexFile)->id;
        (ptrP+indexProgram)->countRead++;




            printf("\nFile Reading Is Successful");
        }
        else{
        printf("\n Invalid Information or Max Reading  ");
        }

}


void writeFile(Program * ptrP , File *ptrF, int NoF , int NoP)
{
  int fileID;
  int programID;
  bool check = 0 ;
  bool check2=0;

  int indexFile ;
  int indexProgram;


  printf("\nEnter  File ID : ") ; scanf("%d",&fileID);
  printf("\nEnter  Program ID : ") ; scanf("%d",&programID);


  for(int i = 0 ; i<NoF +1 ; i++)
  {


      if( (ptrF+i)->id  == fileID)
      {
          indexFile = i;

          check = 1;
          break;

      }

  }
  for(int i = 0 ; i<NoP +1 ; i++)
  {



      if( (ptrP+i)->id == programID )
      {

        indexProgram = i ;
          check2 = 1;
          break;

      }

  }



        if(check == 1 && check2 == 1 && (ptrF+indexFile)->numberOfWrite < MAX-1 )
        {
          (ptrF+indexFile)->numberOfWrite++;
          (ptrF+indexFile)->isWriten =1;

          (ptrP+indexProgram)->writeFileId[(ptrP+indexProgram)->countWrite] =(ptrF+indexFile)->id;
        (ptrP+indexProgram)->countWrite++;




            printf("\nFile Writing Is Successful");
        }
        else{
        printf("\n Invalid Information or Max Writing  ");
        }
}


void releaseReading(Program * ptrP , File *ptrF, int NoF , int NoP, int programID)
{


   int p;
   int f;
   int fileID;
   bool check = 0 ;




    for(int i = 0 ; i< NoP +1;i++)
    {
        if( (ptrP+i)->id == programID && (ptrP+i)->countRead > 0)
        {
            p = i ;
            check = 1;


            break;
        }
    }

    if(check == 1)
    {
        fileID = (ptrP+p)->readFileId[ (ptrP+p)->countRead];


    for(int i = 0 ; i< NoF ; i++)
    {
        if( (ptrF+i)->id == fileID )
        {
            f = i ;
            break;
        }
    }

    (ptrP+p)->readFileId[(ptrP+p)->countRead-1] = -1;
    (ptrP+p)->countRead--;
    (ptrF+f) ->numberOfRead--;
    if( (ptrF+f)->numberOfRead == 0 )
    {
        (ptrF+f)->isRead = 0;
    }

    }
}


void releaseWriting(Program *ptrP , File *ptrF , int NoF , int NoP, int programID)

{

   int p;
   int f;
   int fileID;
   bool check = 0 ;





    for(int i = 0 ; i< NoP +1;i++)
    {
        if( (ptrP+i)->id == programID && (ptrP+i)->countWrite > 0)
        {
            p = i ;
            check = 1;


            break;
        }
    }

    if(check == 1)
    {
        fileID = (ptrP+p)->writeFileId[ (ptrP+p)->countWrite];


    for(int i = 0 ; i< NoF ; i++)
    {
        if( (ptrF+i)->id == fileID )
        {
            f = i ;
            break;
        }
    }

    (ptrP+p)->writeFileId[(ptrP+p)->countWrite-1] = -1;
    (ptrP+p)->countWrite--;
    (ptrF+f) ->numberOfWrite--;
    if( (ptrF+f)->numberOfWrite == 0 )
    {
        (ptrF+f)->isWriten = 0;
    }





    }

}




void displayFile(File *ptr , int NoF)
{

    printf("-------------------- \n  DISPLAY FILE :");
    for(int i = 0 ; i< (NoF) ; i++)
    {
        printf("\n File ID : %d - NAME : %s - PATH : %s ",(ptr+i)->id , (ptr+i)->name , (ptr+i)->path);
        printf(" NoR : %d | NoW : %d" , (ptr+i)->numberOfRead , (ptr+i)->numberOfWrite );
        printf(" isRead : %d | isWrite : %d  " ,(ptr+i)->isRead , (ptr+i)->isWriten ) ;

    }

}
void displayProgram(Program *ptr , int NoP)

{
    printf("-------------------- \n  DISPLAY PROGRAM : ");
    for(int i = 0 ; i< (NoP) ; i++)
    {

        printf("\n-------------------- ");

        printf("\n\tProgram ID : %d - NAME : %s  ",(ptr+i)->id , (ptr+i)->name ) ;

        for(int j = 0 ; j < (ptr+i)->countRead ; j++){
            printf(" \nREAD FILE ID : %d " , (ptr+i)->readFileId[j] );
        }


        for(int j = 0 ; j < (ptr+i)->countWrite ; j++){
            printf(" \nWRITE FILE ID : %d " , (ptr+i)->writeFileId[j] );
        }

    }

}


int main()
{
   int choose ;
   int initial_memory_F = 4 ;
   int initial_memory_P = 4;
   int numberOfFile = 0;
   int numberOfProgram = 0;

   int id ;
    char name[20];
    int readFileId[MAX] ;
    int writeFileId[MAX] ;
    int countRead;
    int countWrite;
    int programID ;


    File *filePtr = (File*)calloc(initial_memory_F,sizeof(File));

    Program *programPtr = (Program*)calloc(initial_memory_P,sizeof(Program));


    do
    {
        choose = menu();

        if(choose == 1)
        {
            if(numberOfFile >= initial_memory_F)
            {
                initial_memory_F *=2;
                filePtr= (File*)realloc(filePtr, initial_memory_F * sizeof(File));
            }

            createFile(&numberOfFile,filePtr);


        }
        if(choose == 2)
        {
            if(numberOfFile >= initial_memory_P)
            {
                initial_memory_P *=2;
                programPtr = (Program*)realloc(programPtr, initial_memory_P * sizeof(Program));
            }
            createProgram(&numberOfProgram,programPtr);
        }

        if(choose == 3)
        {
            readFile(programPtr,filePtr,numberOfFile,numberOfProgram);
        }
        if(choose == 4)
        {

            writeFile(programPtr,filePtr,numberOfFile,numberOfProgram);
        }
        if(choose ==5)
        {

            printf("\nEnter Program ID to Release Reading File : ");
            scanf("%d",&programID);

             releaseReading(programPtr,filePtr,numberOfFile,numberOfProgram,programID);
        }
        if(choose == 6)
        {

             printf("\nEnter Program ID to Release Writing File : ");
             scanf("%d",&programID);

          releaseWriting(programPtr,filePtr,numberOfFile,numberOfProgram,programID);
        }
        if(choose == 7)

        {
            printf("\nEnter Program ID to Release  All File : ");
             scanf("%d",&programID);
            releaseReading(programPtr,filePtr,numberOfFile,numberOfProgram,programID);
            releaseWriting(programPtr,filePtr,numberOfFile,numberOfProgram,programID);


        }
        if(choose == 8)
        {
            displayFile(filePtr,numberOfFile);
        }
        if(choose == 9 )
        {
            displayProgram(programPtr,numberOfProgram);

        }
        if(choose == 10 )
        {
            free(programPtr);
            free(filePtr);
            break;
        }

    }while(true);

    return 0;
}

