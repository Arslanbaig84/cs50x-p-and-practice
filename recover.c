#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t Byte;
#define size 512

int main(int argc, char *argv[])
{
    //validating command line argument
    if (argc != 2)
    {
    printf("Format : ./recover Recovery_Drive\n");
    return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = NULL;

    Byte buffer[size];
    char name[8];
    int counter = 0;
    int jpg_found = 0;

    while (fread(buffer, size, 1, infile) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                fclose(outfile);
            }
            else
            {
                jpg_found = 1;
            }

            sprintf(name, "%03i.jpg", counter);
            outfile = fopen(name, "w");
            counter++;
        }

        if (jpg_found == 1)
        {
            fwrite(buffer, size, 1, outfile);
        }
    }

    if (jpg_found == 1)
    {
        fclose(outfile);
    }
    fclose(infile);
    return 0;
}