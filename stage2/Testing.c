/* Author: Saad Alkkhydaydi 47478969
* Saadaedhs.alkhudaydi@students.mq.edu.au
* Date: 16 August 2023
*/

#include<stdio.h>

#pragma pack(1)


 typedef struct Stage1
{
    char voice[10];       // char is used for strings 
    unsigned short int stone;       //short int is 2 bytes = 16 bits
    char expert;                    // char is one byte = 8 bits
    int square;                       // int is 4 bytes = 32 bits
    int shade;                        // int is 4 bytes = 32 bits
    unsigned char stream;             // unsigned char is one byte
    long int rock;                    // long is 8 bytes
    int cheese;                       // int is 4 bytes
    short int cave;                   // short int is 2 bytes 
    short int canvas;                 // short int is 2 bytes 
    double crate;                     // double is 8 bytes = 64 bits
    float day;                        // float is 4 bytes 
    unsigned short int jeans;         // short int is  2 bytes
    unsigned int calendar;            // int is 4 bytes
    unsigned int quilt;               // int is 4 bytes 
    double sock;                      // double is 8 btyes
    char boys;               // char is one byte. unsigned to get dc instead of ffffdc
}stage1;




int main(int argc, char *argv[])
{
    int TRUE = 1;
  FILE *file_Pointer;
  
  stage1 initialization;
  
  

        file_Pointer = fopen("input-5.bin", "rb");
        if(file_Pointer == NULL)
        {
            printf("The file is empty");
            return 1;
        }
        
       // fread(&initialization,sizeof(initialization),1,file_Pointer);
        
        printf("voice, stone, expert, square, shade, stream, rock, cheese, cave, canvas, crate, day, jeans, calendar, quilt, sock, boys\n");
        for (int i = 0; i <= 100; i++)
        {
            fread(&initialization,sizeof(struct Stage1),1,file_Pointer);
             printf("%s, %d, %c, %d, %d, %d, %lld, %d, %d, %d, %lf, %f, %hu, %d, %d, %lf, %x\n",
                    initialization.voice,
                    initialization.stone,
                    initialization.expert,
                    initialization.square ,
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
                    initialization.boys 
                    );
                
        };
        
       
        fclose(file_Pointer);
        



    

    system("pause");
    
    return 0;
} 