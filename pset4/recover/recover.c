#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    
    typedef uint8_t BYTE;
    
    // Check command line arguments
    if (argc == 1)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    
    // Open input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open: %s\n", argv[1]);
        return 1;
    }
    
    // Set buffer, output file and JPEG counter
    BYTE buffer[512];
    FILE *output = NULL;
    int jpg = 0;
    
    // Loop until no more input remaining
    while (fread(buffer, sizeof(buffer), 1, input))
    {
        // Check for start of JPEG
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            jpg++;
            
            // First JPEG found create, open and write to file
            if (jpg == 1)
            {
                char *filename = malloc(sizeof(BYTE) * 8);
                if (filename == NULL)
                {
                    printf("Not enough memory");
                    return 2;
                }
            
                sprintf(filename, "%03i.jpg", jpg - 1);
            
                output = fopen(filename, "w");
                if (output == NULL)
                {
                    printf("Error with output file");
                    return 3;
                }
                
                free(filename);
                
                fwrite(buffer, sizeof(buffer), 1, output);
            }
            
            // Not first close previous then create, open and write to new file
            else
            {
                fclose(output);
                
                char *filename = malloc(sizeof(BYTE) * 8);
                if (filename == NULL)
                {
                    printf("Not enough memory");
                    return 2;
                }
            
                sprintf(filename, "%03i.jpg", jpg - 1);
            
                output = fopen(filename, "w");
                if (output == NULL)
                {
                    printf("Error with output file");
                    return 3;
                }
                
                free(filename);
                
                fwrite(buffer, sizeof(buffer), 1, output);
            }
        }
        
        // Block doesn't start with JPEG header, but JPEG already found write data
        else
        {
            if (jpg > 0)
            {
                fwrite(buffer, sizeof(buffer), 1, output);
            }
        }
    }
    
    // Close all files and end
    fclose(input);
    fclose(output);
    return 0;
}