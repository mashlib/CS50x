#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single comman-line argument
    if (argc != 2)
    {

        printf("Usage: ./ recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {

        printf("FILE could not be opened\n");
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[BLOCK_SIZE];
    int jpg_found = 0;
    int jpg_count = 0;

    // allocates memory for the 3 ints and 5 chars (.jpg and \0)
    char *filename = malloc((3 * sizeof(int) + (5 * sizeof(char))));

    // Create Output FILE buffer
    FILE *img = NULL;

    // while there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {

        // Checking the first 4 bytes to see if it's a JPEG header
        // bitwise AND of buffer[3] setting anything after the first 4 bits to 0
        // since the 4th byte is always a hexadecimal between 0xe0 and 0xef
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {

            // creates a JPEG with the specifications
            sprintf(filename, "%03i.jpg", jpg_count);

            // if it's already in buffer closes it otherwise sets it to 1
            if (jpg_found == 1)
            {
                fclose(img);
            }
            else
            {
                jpg_found = 1;
            }

            // opens the file and writes the first block to it
            img = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK_SIZE, img);

            jpg_count++;
        }
        // if no header was found
        else
        {
            // already working on a JPEG?
            if (jpg_found == 1)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
        // should exit the loop if no header is found
    }

    fclose(img);
    fclose(card);
    free(filename);
}
