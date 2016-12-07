#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    BYTE* buffer = malloc(SIZE);
    char nameNewFile [8]; 
    FILE *newOutFile;
    int counter = 0;
    
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    
    // open input file 
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    
    if (inptr == NULL)				// a pointer to a file check
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    if (buffer == NULL)				// buffer check
    {
        printf("Error memory\n");
        return 2;
    }
    
    while (fread(buffer,sizeof(buffer), 1, inptr) == 1)			// read the block of memory, what was considered to push in the buffer
    {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1)) // if the beginning of the buffer similar to the beginning of the jpg
            {
                sprintf(nameNewFile, "%03d.jpg", counter);		// nameNewFile record in the file name that we want to create
                counter++;										
                
    
                if (newOutFile != NULL)									// if a pointer engaged newOutFile
                {
                    fclose(newOutFile);	
                    newOutFile = fopen(nameNewFile, "w");				// create file
                    fwrite(buffer, sizeof(buffer), 1, newOutFile);		// thrown into it data from the buffer
                }
                
                    else
                    {
                        newOutFile = fopen(nameNewFile, "w");			// create file
                        fwrite(buffer, sizeof(buffer), 1, newOutFile);	// thrown into it data from the buffer
                    }
            }
             
            else if(newOutFile != NULL)					
            {
                fwrite(buffer, sizeof(buffer), 1, newOutFile);		// continue record file
            }
    }
    
     fclose(inptr);			// close all file, buffer cleaning
     fclose(newOutFile);
     free(buffer);
     
     return 0;
}
