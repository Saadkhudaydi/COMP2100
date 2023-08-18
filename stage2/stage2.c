/* Author: Saad Alkkhydaydi 47478969
 * Saadaedhs.alkhudaydi@students.mq.edu.au
 * Date: 19 August 2023
 */

/*
The Purpose of this code is to read binary data from a file and print the output according to the given struct specifcation  
*/

#include <stdio.h>


typedef struct Stage1
{
    char voice[10];           // char is used for strings
    unsigned short int stone; // short int is 2 bytes = 16 bits
    char expert;              // char is one byte = 8 bits
    int square;               // int is 4 bytes = 32 bits
    int shade;                // int is 4 bytes = 32 bits
    unsigned char stream;     // unsigned char is one byte
    long int rock;            // long is 8 bytes
    int cheese;               // int is 4 bytes
    short int cave;           // short int is 2 bytes
    short int canvas;         // short int is 2 bytes
    double crate;             // double is 8 bytes = 64 bits
    float day;                // float is 4 bytes
    unsigned short int jeans; // short int is  2 bytes
    unsigned int calendar;    // int is 4 bytes
    unsigned int quilt;       // int is 4 bytes
    double sock;              // double is 8 btyes
    char boys;                // char is one byte.
} stage1;

int main(int argc, char *argv[])
{
    signed char TRUE = 1;
    FILE *filePointer;
    

    stage1 initialization;

    filePointer = fopen(argv[1], "rb"); // command line prompt to enter the file
    
    if (argv[1]==NULL) // error check if no file was entered
    {
        fprintf(stderr,"No file was given");
        exit(1);
        return 1;
    }
 
    
    if (filePointer == NULL) // error detection for empty or non-existant files 
    {
        fprintf(stderr,"The file %s is emtpy or dose not exist\n",argv[1]);
	   exit(1);
        return 1;
    }

    
    printf("voice, stone, expert, square, shade, stream, rock, cheese, cave, canvas, crate, day, jeans, calendar, quilt, sock, boys\n");
    while (
        fread(&initialization.voice, sizeof(initialization.voice), 1, filePointer) == 1 && // fread returns af value less than 1 if nothing is left to be read

        fread(&initialization.stone, sizeof(initialization.stone), 1, filePointer) == 1 &&

        fread(&initialization.expert, sizeof(initialization.expert), 1, filePointer) == 1 && 

        fread(&initialization.square, sizeof(initialization.square), 1, filePointer) == 1 &&

        fread(&initialization.shade, sizeof(initialization.shade), 1, filePointer) == 1 &&

        fread(&initialization.stream, sizeof(initialization.stream), 1, filePointer) == 1 &&

        fread(&initialization.rock, sizeof(initialization.rock), 1, filePointer) == 1 &&

        fread(&initialization.cheese, sizeof(initialization.cheese), 1, filePointer) == 1 &&

        fread(&initialization.cave, sizeof(initialization.cave), 1, filePointer) == 1 &&

        fread(&initialization.canvas, sizeof(initialization.canvas), 1, filePointer) == 1 && 

        fread(&initialization.crate, sizeof(initialization.crate), 1, filePointer)  == 1 &&

        fread(&initialization.day, sizeof(initialization.day), 1, filePointer) == 1 && 

        fread(&initialization.jeans, sizeof(initialization.jeans), 1, filePointer)  == 1 &&

        fread(&initialization.calendar, sizeof(initialization.calendar), 1, filePointer) == 1 &&

        fread(&initialization.quilt, sizeof(initialization.quilt), 1, filePointer) == 1 &&

        fread(&initialization.sock, sizeof(initialization.sock), 1, filePointer) == 1 &&

        fread(&initialization.boys, sizeof(initialization.boys), 1, filePointer) == 1
    )
    {
          
        
        printf("%s, %d, %c, %d, %d, %d, %lld, %d, %d, %d, %lf, %f, %hu, %u, %u, %lf, %x\n",
               initialization.voice,
               initialization.stone,
               initialization.expert,
               initialization.square,
               initialization.shade,
               initialization.stream,
               initialization.rock,
               initialization.cheese,
               initialization.cave,
               initialization.canvas,
               initialization.crate,
               initialization.day,
               initialization.jeans,
               initialization.calendar,
               initialization.quilt,
               initialization.sock,
       (unsigned char) initialization.boys);  // used unsinged char to get the desired result specified in output.txt files 
               
            
              
    }
   if(fclose(filePointer)!= 0)  // closing files to not use up memory and be efficent 
	{
		fprintf(stderr,"File %s did not close properlly",argv[1]);
        exit(1);
		return 1;
	}	
    return 0;
}
