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

    char original_string[2048] = "the iowa gambling task fails to bandit theory";
    char encrypted_string[2024];

    printf("%s\n", original_string);
    FILE* file_to_read;
    file_to_read = fopen("sub_mariner.ppm", "rb");

    // Error check
    if (!file_to_read){
        perror("The file failed to open!");
        exit(1);
    }



    // first265 pixels
    // for(int i=0; i<256; i++) {
    //     int r = fgetc(file_to_read);
    //     int g = fgetc(file_to_read);
    //     int b = fgetc(file_to_read);
    //     printf("Pixel %d -> R:%d G:%d B:%d\n", i, r, g, b);
    // }

    // This fails because PPM comes in two main "magic number" formats
    // P3 -> ASCII text 
    // P6 -> Binary


    // Note: File beginds with a header that contians a magic number 
    // Format of the file: File type |  Width Height | maxval (maximum color calue) | colors in rgb seperated by space

    char format[3];
    int width, height, maxval;

    if (fscanf(file_to_read, "%2s", format) != 1){
        fprintf(stderr, "Failed to read PPM format\n");
        exit(1);
    }

    if (fscanf(file_to_read, "%d %d", &width, &height) != 2){
        fprintf(stderr, "Failed to read width/height\n");
        exit(1);
    }

    if (fscanf(file_to_read, "%d", &maxval) != 1){
        fprintf(stderr, "Failed to read maxval\n");
        exit(1);
    }

    // Remove extra whitespace 
    fgetc(file_to_read);

    printf("PPM format: %s, width: %d, height: %d, maxval: %d\n", format, width, height, maxval);


    // To encrypt, forward read and change each to modulo of 

    // 97-122

    // prints z
    // printf("%c\n", 122);

    // basic idea= get value from r,g,b then value % 26. 
    // add remainder to current char from original string then modulo 122
    // then add 97


    // This reads rgb all at once which forces 3 indexes at a time
    // for(int i=0; i<strlen(original_string); i++) {
    //     int r = fgetc(file_to_read);

    //     int g = fgetc(file_to_read);
    //     int b = fgetc(file_to_read);

    //     // Check if you've reached the end of the file
        
    //     if (r == EOF || g == EOF || b == EOF){
    //         fprintf(stderr, "Unexpected end of file!\n");
    //         return 0;
    //     }

    //     printf("Pixel %d -> R:%d G:%d B:%d\n", i, r, g, b);
    // }

     for(int i=0; i<strlen(original_string); i++) {
        int curr = fgetc(file_to_read);

        //printf("%c\n",original_string[0]+1);

        // Check if you've reached the end of the file
        if (curr == EOF){
            fprintf(stderr, "Unexpected end of file!\n");
            return 0;
        }

        // %26
        int forward_leap = curr % 26;
        // now encrypted
        //printf("%d\n",((int)(original_string[i] + forward_leap))%122);

        // only add 97 if its less than 97
        int hold_val = ((int)(original_string[i] + forward_leap))%122;
        if (hold_val<26) hold_val += 97;
        printf("value: %d\n",hold_val);

        original_string[i] = hold_val;


        //printf("Value: %d\n", curr);
    }
    fclose(file_to_read);

    printf("%s\n",original_string);


    return 0;
}