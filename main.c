#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// General idea of what I want to accomplish.
// Have a key via an image. 

// Map each pixel to some sort of number then take some maniutated number until you get an 
// iteration ... This is flawed. Eventually it decomposes to 26 numbers where 1=A, B=2 ... Z=26. 
// Hash map with linear probing is too much work.

// First step, get image... turn to PPM cause reading pixels from .png or other formats can be problamatic
// Used an online image converter to get my file into .ppm format


void cipher(char* start){
}

void decipher(char* start){

}

int main(){

    char original_string[2048] = "The Iowa gambling task fails to bandit theory";
    printf("%s\n", original_string);

    FILE * out;
    out = fopen("color_test.ppm", "wb");
    fprintf(out, "P6 256 256 255\n");
    for(int r=0; r<256; r++) {
        for(int b=0; b<256; b++) {
        fputc(r, out);
        fputc(0, out);
        fputc(b, out);
        }
    }
    fclose(out);



    return 0;
}