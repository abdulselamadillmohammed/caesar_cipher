#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// General idea of what I want to accomplish.
// Have a key via an image. 

// take rgb -> maps to 3 characters --> handle non equivilant maping

//  s + [insert num] = 26+ therefore modulo it to loop around
//  s %= 26

// decrypt:
// looped around version - moduloed curr
// 

void cipher(char* start){
}

void decipher(char* start){

}

int main(){

    char original_string[2048] = "text to be encrypted";
    char encrypted_string[2024];
    char decrypted_string[2048];

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

        if (original_string[i] == 32){
            encrypted_string[i] = 32;
            continue;
        }

        // assume no overflow
        int current_letter = original_string[i]; // returns 0->26
        //printf("b: %d\n",current_letter);
        curr %= 26; // how much you want to add to the current letter
        current_letter += curr;
        //current_letter %= 26; // should be within range

        // if need to override
        if (current_letter > 122){
            current_letter %= 122;
            current_letter += 97;
            //printf("n: %d\n",current_letter);
        }
        else{
            //printf("o: %d\n",current_letter);
        }

        encrypted_string[i] = current_letter;

    }

    encrypted_string[strlen(original_string)] = '\0';
    printf("Original: %s\n",original_string);
    printf("Encypted: %s\n",encrypted_string);


    rewind(file_to_read);
    // re-read and discard header



    fscanf(file_to_read, "%2s", format);
    fscanf(file_to_read, "%d %d", &width, &height);
    fscanf(file_to_read, "%d", &maxval);
    fgetc(file_to_read); // eat the whitespace



    printf("--- Decrypt ---\n");

    for(int i=0; i<strlen(original_string); i++) {
        int curr = fgetc(file_to_read);

        if (curr == EOF){
            fprintf(stderr, "Unexpected end of file!\n");
            return 0;
        }

        if (encrypted_string[i] == 32){
            decrypted_string[i] = 32;
            continue;
        }


        int current_letter = encrypted_string[i];
        curr %= 26;
        //printf("%d\n", curr);
        current_letter -= curr;
        if (current_letter < 97){
            current_letter += 25;
        }


        // current_letter %= 26;
        // current_letter += 96;
        decrypted_string[i] = current_letter;

    }
    decrypted_string[strlen(original_string)] = '\0';
    printf("Decypted: %s\n",decrypted_string);
    fclose(file_to_read);
    return 0;
}