/* Author: Saad Alkkhydaydi 47478969
 * Saadaedhs.alkhudaydi@students.mq.edu.au
 * Date: 22 August 2023
 */

/*
The Purpose of this code is to read binary data from a file and sort the output according to the given order specifcation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int compare(const void *a, const void *b)
{
    stage1 *firstElement = (stage1 *)a;
    stage1 *secondElement = (stage1 *)b;

    if (firstElement->calendar < secondElement->calendar)
        return 1; // cheking according to the given order and if descending  or ascending
    if (firstElement->calendar > secondElement->calendar)
        return -1;
    if (firstElement->canvas < secondElement->canvas)
        return 1;
    if (firstElement->canvas > secondElement->canvas)
        return -1;
    if (firstElement->square < secondElement->square)
        return 1;
    if (firstElement->square > secondElement->square)
        return -1;
    if (firstElement->jeans < secondElement->jeans)
        return 1;
    if (firstElement->jeans > secondElement->jeans)
        return -1;
    if (firstElement->day > secondElement->day)
        return 1;
    if (firstElement->day < secondElement->day)
        return -1;
    if (firstElement->cave > secondElement->cave)
        return 1;
    if (firstElement->cave < secondElement->cave)
        return -1;
    if (firstElement->boys < secondElement->boys)
        return 1;
    if (firstElement->boys > secondElement->boys)
        return -1;
    if (firstElement->crate < secondElement->crate)
        return 1;
    if (firstElement->crate > secondElement->crate)
        return -1;
    if (firstElement->rock < secondElement->rock)
        return 1;
    if (firstElement->rock > secondElement->rock)
        return -1;
    if (firstElement->stream < secondElement->stream)
        return 1;
    if (firstElement->stream > secondElement->stream)
        return -1;
    if (firstElement->sock < secondElement->sock)
        return 1;
    if (firstElement->sock > secondElement->sock)
        return -1;
    if (firstElement->quilt > secondElement->quilt)
        return 1;
    if (firstElement->quilt < secondElement->quilt)
        return -1;
    if (firstElement->shade < secondElement->shade)
        return 1;
    if (firstElement->shade > secondElement->shade)
        return -1;
    if (firstElement->stone > secondElement->stone)
        return 1;
    if (firstElement->stone < secondElement->stone)
        return -1;
    if (firstElement->cheese < secondElement->cheese)
        return 1;
    if (firstElement->cheese > secondElement->cheese)
        return -1;
    if (strcmp(firstElement->voice, secondElement->voice) > 0)
        return 1;
    if (strcmp(firstElement->voice, secondElement->voice) < 0)
        return -1;
    if (firstElement->expert > secondElement->expert)
        return 1;
    if (firstElement->expert < secondElement->expert)
        return -1;

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *filePointer;
    FILE *outPutFile;
    stage1 initialization;
    stage1 *structArray;
    stage1 *temp;
    int currentSize = 0;
    if (argv[1] == NULL || argv[2] == NULL)
    {
        fprintf(stderr, "No file was given");
        exit(1);
    }

    filePointer = fopen(argv[1], "rb"); // command line prompt to enter the file
    outPutFile = fopen(argv[2], "w");

    if (filePointer == NULL) // error detection for empty or non-existant files
    {
        fprintf(stderr, "The file %s is empty or does not exist\n", argv[1]);
        exit(1);
    }

    structArray = malloc(sizeof(stage1));

    while (fread(&initialization.voice, sizeof(initialization.voice), 1, filePointer) == 1 && // fread returns af value less than 1 if nothing is left to be read

           fread(&initialization.stone, sizeof(initialization.stone), 1, filePointer) == 1 &&

           fread(&initialization.expert, sizeof(initialization.expert), 1, filePointer) == 1 &&

           fread(&initialization.square, sizeof(initialization.square), 1, filePointer) == 1 &&

           fread(&initialization.shade, sizeof(initialization.shade), 1, filePointer) == 1 &&

           fread(&initialization.stream, sizeof(initialization.stream), 1, filePointer) == 1 &&

           fread(&initialization.rock, sizeof(initialization.rock), 1, filePointer) == 1 &&

           fread(&initialization.cheese, sizeof(initialization.cheese), 1, filePointer) == 1 &&

           fread(&initialization.cave, sizeof(initialization.cave), 1, filePointer) == 1 &&

           fread(&initialization.canvas, sizeof(initialization.canvas), 1, filePointer) == 1 &&

           fread(&initialization.crate, sizeof(initialization.crate), 1, filePointer) == 1 &&

           fread(&initialization.day, sizeof(initialization.day), 1, filePointer) == 1 &&

           fread(&initialization.jeans, sizeof(initialization.jeans), 1, filePointer) == 1 &&

           fread(&initialization.calendar, sizeof(initialization.calendar), 1, filePointer) == 1 &&

           fread(&initialization.quilt, sizeof(initialization.quilt), 1, filePointer) == 1 &&

           fread(&initialization.sock, sizeof(initialization.sock), 1, filePointer) == 1 &&

           fread(&initialization.boys, sizeof(initialization.boys), 1, filePointer) == 1)
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
               (unsigned char)initialization.boys);
        currentSize++;
        temp = realloc(structArray, sizeof(stage1) * currentSize);
        if (temp != NULL)
        {
            structArray = temp;
        }
        else
        {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }

        structArray[currentSize - 1] = initialization;
    }
    
    qsort(structArray, currentSize, sizeof(stage1), compare);
    for (int i = 0; i < currentSize; i++)
    {
        fwrite(&structArray[i].voice, sizeof(structArray[i].voice), 1, outPutFile);
        fwrite(&structArray[i].stone, sizeof(structArray[i].stone), 1, outPutFile);
        fwrite(&structArray[i].expert, sizeof(structArray[i].expert), 1, outPutFile);
        fwrite(&structArray[i].square, sizeof(structArray[i].square), 1, outPutFile);
        fwrite(&structArray[i].shade, sizeof(structArray[i].shade), 1, outPutFile);
        fwrite(&structArray[i].stream, sizeof(structArray[i].stream), 1, outPutFile);
        fwrite(&structArray[i].rock, sizeof(structArray[i].rock), 1, outPutFile);
        fwrite(&structArray[i].cheese, sizeof(structArray[i].cheese), 1, outPutFile);
        fwrite(&structArray[i].cave, sizeof(structArray[i].cave), 1, outPutFile);
        fwrite(&structArray[i].canvas, sizeof(structArray[i].canvas), 1, outPutFile);
        fwrite(&structArray[i].crate, sizeof(structArray[i].crate), 1, outPutFile);
        fwrite(&structArray[i].day, sizeof(structArray[i].day), 1, outPutFile);
        fwrite(&structArray[i].jeans, sizeof(structArray[i].jeans), 1, outPutFile);
        fwrite(&structArray[i].calendar, sizeof(structArray[i].calendar), 1, outPutFile);
        fwrite(&structArray[i].quilt, sizeof(structArray[i].quilt), 1, outPutFile);
        fwrite(&structArray[i].sock, sizeof(structArray[i].sock), 1, outPutFile);
        fwrite(&structArray[i].boys, sizeof(structArray[i].boys), 1, outPutFile);
    }

    if (fclose(filePointer) != 0) // closing files to not use up memory and be efficent
    {
        fprintf(stderr, "File %s did not close properlly", argv[1]);
        exit(1);
        return 1;
    }
    if (fclose(outPutFile) != 0)
    {
        fprintf(stderr, "File %s did not close properlly", argv[2]);
        exit(1);
        return 1;
    }

    free(structArray);
    

    return 0;
}
