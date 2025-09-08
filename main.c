#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// General idea of what I want to accomplish.
// Have a key via an image. 

// take rgb -> maps to 3 characters --> handle non equivilant maping

void cipher(char* start){
}

void decipher(char* start){

}

int main(){

    char original_string[2048] = "Text to be encrypted";
    char encrypted_string[2024];

    printf("%s\n", original_string);
    FILE* file_to_read;
    file_to_read = fopen("sub_mariner.ppm", "rb");

    // Error check
    if (!file_to_read){
        perror("The file failed to open!");
        exit(1);
    }

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

     for(int i=0; i<strlen(original_string); i++) {
        int curr = fgetc(file_to_read);

        if (curr == EOF){
            fprintf(stderr, "Unexpected end of file!\n");
            return 0;
        }
        curr %= 26;
        curr += 97;
        encrypted_string[i] = curr;

    }
    fclose(file_to_read);

    printf("%s\n",original_string);
    printf("%s\n",encrypted_string);


    return 0;
}