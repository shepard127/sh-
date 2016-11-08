/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    
    // remember filenames
    float n = atof( argv[1]);
    char *infile =  argv[2];
    char *outfile = argv[3];
   
     
    FILE *inptr = fopen(infile, "r");       // open input file
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    FILE *outptr = fopen(outfile, "w");     // open output file
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
     
    
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);     // read infile's BITMAPFILEHEADER

    
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);     // read infile's BITMAPINFOHEADER

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    int switcher = 0;
    if(n > 100 || n < 0)
    {
        printf("\nEnter please positive number: > 0 && < 100\n");
    }
    else
    {
        if(n < 1)
            switcher = 1;   // smoller alhoritm 
        else
            switcher = 2;   // bigger alhoritm
    }
    
    int widthInputFile = bi.biWidth;
    int heightInputFile = bi.biHeight;

    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;                      // determine padding for scanlines
    int paddingInputFile =  (4 - (widthInputFile * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);                                   // write outfile's BITMAPFILEHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);                                   // write outfile's BITMAPINFOHEADER
    
    switch(switcher)
    {
        case 1:             // smoller
            {
                heightInputFile = abs(heightInputFile);            
                
                int pointerFileStart = ftell(inptr);
                int pointerFileEnd = 0;
                
                while(!feof(inptr))
                {
                    getc(inptr);
                    pointerFileEnd = ftell(inptr);
                }
            
                fseek(inptr, pointerFileStart, SEEK_SET);
                
                for (int i = 0; i < heightInputFile; i++)                               // iterate over infile's scanlines
                {
                        for (int j = 0; j < bi.biWidth; j++)                            // iterate over pixels in scanline
                        {
                            RGBTRIPLE triple;                                           // temporary storage
                            
                            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);                // read RGB triple from infile
                            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);              // write RGB triple to outfile
                            fseek(inptr, sizeof(RGBTRIPLE), SEEK_CUR); 
                        }
                        
                        fseek(inptr, paddingInputFile, SEEK_CUR);                       // skip over padding, if any
                        for (int k = 0; k < padding; k++)                               // then add it back (to demonstrate how)
                        {
                            fputc(0x00, outptr);
                        }
                        short int positionPointer = ftell(inptr);
                        int testPadding = (widthInputFile*3) + paddingInputFile + positionPointer;
                        if(pointerFileEnd <= testPadding)
                            break;
                        
                        fseek(inptr, testPadding, SEEK_SET);
                        
                    }
                break;
            }
        case 2:              // bigger
            {
                int duplicat_horizont = 0;
                int duplicat_vertical = 0;
                int pInPointer = ftell(inptr);
                for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
                {
                    for (int j = 0; j < bi.biWidth; j++)                                // iterate over pixels in scanline
                    {
                        RGBTRIPLE triple;                                               // temporary storage
                        
                        fread(&triple, sizeof(RGBTRIPLE), 1, inptr);                    // read RGB triple from infile
                        
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);                  // write RGB triple to outfile
                        duplicat_horizont++;
                        
                        if(duplicat_horizont < n)
                        {
                            fseek(inptr, (ftell(inptr) -3), SEEK_SET);
                        }
                        else
                            duplicat_horizont = 0;
                    }
                    fseek(inptr, paddingInputFile, SEEK_CUR);                           // skip over padding, if any
                    
                    for (int k = 0; k < padding; k++)                                   // then add it back (to demonstrate how)
                    {
                        fputc(0x00, outptr);
                    }
                    
                    duplicat_vertical++;
                    if(duplicat_vertical < n)
                    {
                        fseek(inptr, pInPointer, SEEK_SET);
                    }
                    else
                    {
                        duplicat_vertical = 0;
                        pInPointer = ftell(inptr);
                    }
                }
                break;
            }
    }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
