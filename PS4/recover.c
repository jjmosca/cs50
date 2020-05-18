#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

// Open memory card
// Look for beginning of a JPEG (0xff 0xd8 0xff 0xe*)
// Open a new JPEG file
// Write 512 bytes until a new JPEG is found
// Stop at end of file

int main(int argc, char *argv[])
{
    // Check if user indicate file to read
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Read file
    FILE *inptr = fopen(argv[1], "r");

    // If file is non-existent, exit program
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 2;
    }

    BYTE buffer[512];
    int count = 0;
    char filename[8];
    FILE *outptr = NULL;

    while (true)
    {

        // Read each byte per 512 byte block in file and store in array called buffer
        size_t block = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        // Exit program if end of file is reached
        if (block == 0 && feof(inptr))
        {
            break;
        }

        // Check for JPEG signature in every block
        bool jpeg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // Close previous output file if new JPEG signature is found
        if (jpeg && outptr != NULL)
        {
            fclose(outptr);
            count++;
        }

        // Write to new output file if JPEG signature is found
        if (jpeg)
        {
            sprintf(filename, "%03i.jpg", count);
            outptr = fopen(filename, "w");
        }

        // Write if there is an open output file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), block, outptr);
        }
    }

    fclose(outptr); // Close last output file
    fclose(inptr); // Close input file

    return 0;
}
