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
    
    if (inptr == NULL)				// проверка указателя на файл
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    if (buffer == NULL)				// проверка буфера
    {
        printf("Error memory\n");
        return 2;
    }
    
    while (fread(buffer,sizeof(buffer), 1, inptr) == 1)			// считываем блок памяти, то что считали пихаем в буфер
    {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1)) // если начало буфера похоже на начало jpg
            {
                sprintf(nameNewFile, "%03d.jpg", counter);		// записываем в nameNewFile название файла который мы хотим создать
                counter++;										
                
    
                if (newOutFile != NULL)									// если указатель newOutFile задействован
                {
                    fclose(newOutFile);	
                    newOutFile = fopen(nameNewFile, "w");				// создали файл
                    fwrite(buffer, sizeof(buffer), 1, newOutFile);		// закинули в него данные из буфера
                }
                
                    else
                    {
                        newOutFile = fopen(nameNewFile, "w");			// создали файл
                        fwrite(buffer, sizeof(buffer), 1, newOutFile);	// закинули в него данные из буфера
                    }
            }
             
            else if(newOutFile != NULL)					
            {
                fwrite(buffer, sizeof(buffer), 1, newOutFile);		// продолжаем записывать файл
            }
    }
    
     fclose(inptr);			// закрыли все файлы, очистили буфер
     fclose(newOutFile);
     free(buffer);
     
     return 0;
}