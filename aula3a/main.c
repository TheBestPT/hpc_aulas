#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

int main(int argc, char *argv[]){
    printf("%s\n", "Leitura de imagens");
    const char* filename = "lando_helmet.jpg";
    int nCols, nRows, nChannels;
    unsigned char *data = stbi_load(filename, &nCols, &nRows, &nChannels, 0);

    printf("nCols = %d nRows = %d nChannels = %d\n", nCols, nRows, nChannels);


    stbi_write_jpg("test.jpg", nCols, nRows, nChannels, data, 90);
    return EXIT_SUCCESS;
}