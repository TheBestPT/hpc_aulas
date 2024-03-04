#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

unsigned char get_gray_level(int r, int c, int nCols, int nRows, unsigned char *data){
    int idxgray = r * nCols + c;
    return data[idxgray];
}

unsigned char rgb2gray(unsigned char r, unsigned char g, unsigned char b){
    /*
    const double pr = 0.3; //weigth red
    const double pg = 0.59; // green 
    const double pb = 0.11; // blue
    */
   const double pr = 0.2; //weigth red
    const double pg = 0.4; // green 
    const double pb = 0.2; // blue
    return (double) r * pr + 
                    (double) g * pg +
                    (double) b * pb;

}

int main(int argc, char *argv[]){
    printf("%s\n", "Leitura de imagens");
    
    const char* filename = "lando_helmet2.jpeg";
    int nCols, nRows, nChannels;
    unsigned char *data = stbi_load(filename, &nCols, &nRows, &nChannels, 0);

    unsigned char *grayData = (unsigned char*) malloc(sizeof(unsigned char) * nCols * nRows);
    unsigned char *grayEdge = (unsigned char*) malloc(sizeof(unsigned char) * nCols * nRows);

    for (int c = 0; c < nCols; c++)
    {
        for (int r = 0; r < nRows; r++)
        {
            int idx = (r * nCols + c) * nChannels;
            unsigned char red = data[idx];
            unsigned char green = data[idx + 1];
            unsigned char blue = data[idx + 2];

            int idxgray = r * nCols + c;
            grayData[idxgray] = rgb2gray(red, green, blue);
        }
        
    }

    //  Detetação de contornos na linha
    for (int c = 1; c < nCols - 1; c++)
    {
        for (int r = 1; r < nRows - 1; r++)
        {
            //Horizontal edges
            unsigned char atual = get_gray_level(r, c, nCols, nRows, grayData);
            unsigned char anterior = get_gray_level(r, c-1, nCols, nRows, grayData);
            unsigned char diff = abs(atual - anterior);
            int idxgray = r * nCols + c;
            if (diff > 20)
            {
                grayEdge[idxgray] = 0xff;
            }
            
            //Vertical edges
            unsigned char atual_ver = get_gray_level(r, c, nCols, nRows, grayData);
            unsigned char anterior_ver = get_gray_level(r-1, c, nCols, nRows, grayData);
            unsigned char diff_ver = abs(atual_ver - anterior_ver);
            if (diff_ver > 20)
            {
                grayEdge[idxgray] = 0xff;
            }
        }
    }
    
    
    stbi_write_jpg("grayImage.jpg", nCols, nRows, 1, grayData, 90);
    stbi_write_jpg("grayEdge.jpg", nCols, nRows, 1, grayEdge, 90);

    printf("nCols = %d nRows = %d nChannels = %d\n", nCols, nRows, nChannels);

    
    int col_quadrado = 800; // class value: 2000
    int row_quadrado = 400; // class value: 1000
    int lado_col = 1000;
    int lado_rows = 500;

    // Copy image
    stbi_write_jpg("copyImage.jpg", nCols, nRows, nChannels, data, 90);

    for (int c = col_quadrado; c < col_quadrado+lado_col; c++)
    {
        for (int r = row_quadrado; r < row_quadrado+lado_rows; r++)
        {
            int idx = (r * nCols + c) * nChannels;
            data[idx] = (unsigned char) 0xFF;
            data[idx + 1] = (unsigned char) 0x00;
            data[idx + 2] = (unsigned char) 0x00;
        }
        
    }

    // Image with retangle
    stbi_write_jpg("retangle.jpg", nCols, nRows, nChannels, data, 90);
    free(grayData);
    return EXIT_SUCCESS;
}