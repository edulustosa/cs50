// Recovers JPEG images from a .raw file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in a block
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open input file
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    int num = -1;
    FILE *img = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, f))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Found a new JPEG header
            if (img != NULL)
            {
                fclose(img); // Close the previous image file
            }

            num++;
            char filename[8];
            sprintf(filename, "%03i.jpg", num);
            img = fopen(filename, "wb");
            if (img == NULL)
            {
                printf("Could not open file.\n");
                return 1;
            }
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img); // Write data to the image file
        }
    }

    // Close the last image file
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the input file
    fclose(f);

    return 0;
}
