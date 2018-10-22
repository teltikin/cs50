
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{

    // Assigns size to variable
    float size = atof(argv[1]);

    // Assigns filenames to variables.
    char *infile = argv[2];
    char *outfile = argv[3];

    // Opens files and checks that they exist.
    FILE *inptr = fopen(infile, "r");
    if (inptr != NULL)
        FILE *inptr = fopen(infile, "r");
    else
        return 1;
    FILE *outptr = fopen(outfile, "w");
    if (outptr != NULL)
        FILE *outptr = fopen(outfile, "w");    
    else
        return 2;

    // Reads BITMAPFILEHEADER and BITMAPINFOHEADER of the in file.
    BITMAPFILEHEADER bmfh;
    fread(&bmfh, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPINFOHEADER bmih;
    fread(&bmih, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Makes new dimensions.
    int wid1 = bmih.biWidth;
    int high1 = bmih.biHeight;
    int wid2 = floor(wid1 * n);
    int high2 = floor(high1 * n);

    // Padding
    int padIn = (4 - (wid1 * sizeof(RGBTRIPLE)) % 4) % 4;
    int padOut = (4 - (wid2 * sizeof(RGBTRIPLE)) % 4) % 4;

    // Change headers
    bmih.biHeight = high2;
    bmih.biWidth = wid2;
    bmih.biSizeImage = ((sizeof(RGBTRIPLE) * wid2) + padOut) * abs(high2);
    bmfh.bfSize = bmih.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    fwrite(&bmfh, sizeof(BITMAPFILEHEADER), 1, outptr);    fwrite(&bmih, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Ratios
    double wRatio = (double) wid1 / (double) wid2;
    double hRatio = (double) high1 / (double) high2;
    RGBTRIPLE scanline[wid1 * sizeof(RGBTRIPLE)];
    int cachedScanline = -1;

    for (int i = 0, biHeight = abs(high2); i < biHeight; i++)
    {
        int row = i * hRatio;
        if (cachedScanline != row)
        {
            fseek(inptr, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (((sizeof(RGBTRIPLE) * wid1) + padIn) * row), SEEK_SET);
            fread(scanline, sizeof(RGBTRIPLE), wid1, inptr);
            cachedScanline = row;
        }
        for (int j = 0; j < wid2; j++)
        {
            int column = j * wRatio;
            fwrite(&scanline[column], sizeof(RGBTRIPLE), 1, outptr);
        }
        for (int j = 0; j < padOut; j++)
        {
            fputc(0x00, outptr);
        }
    }
    
    fclose(inptr);

    fclose(outptr);

    return 0;
}
