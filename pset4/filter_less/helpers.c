/*---------------------------------
Task 2 of 4

Brief
- Write a program that applies filters to BMPs
- Implement function in helpers.c file
- Complete grayscale function
    - Taken in an image
    - Turn into black-and-white version
- Complete sepia function
    - Take in an image
    - Turn it into a sepia version
- Complete reflect function
    - Taken an image
    - Reflect image horizontally
- Complete blur function
    - Take an image
    - Return a box-blurred version of the image

Expected output

    ./filter -r image.bmp reflected.bmp
    
Distribution code
- None on this page
- images (dir)
- bmp.h
- filter.c
- helpers.h
- Makefile

Key concept:
- Memory management
-----------------------------------*/


#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double average = (int)round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed, originalGreen, originalBlue;
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            double sepiaRed = (int)round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            double sepiaGreen = (int)round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            double sepiaBlue = (int)round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = width / 2; j < n; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy image array to avoid multiply blurs layers
    RGBTRIPLE copy[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            copy[a][b] = image[a][b];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Variables to sum all the colour values
            double red = 0;
            double green = 0;
            double blue = 0;

            //Keep track of number of pixels
            double pixel = 0.0;

            // Check left
            if (i - 1 >= 0)
            {
                red += copy[i - 1][j].rgbtRed;
                green += copy[i - 1][j].rgbtGreen;
                blue += copy[i - 1][j].rgbtBlue;
                pixel++;

            }

            // Check above
            if (j - 1 >= 0)
            {
                red += copy[i][j - 1].rgbtRed;
                green += copy[i][j - 1].rgbtGreen;
                blue += copy[i][j - 1].rgbtBlue;
                pixel++;
            }

            // Check below
            if (i + 1 < height)
            {
                red += copy[i + 1][j].rgbtRed;
                green += copy[i + 1][j].rgbtGreen;
                blue += copy[i + 1][j].rgbtBlue;
                pixel++;
            }

            // Check right
            if (j + 1 < width)
            {
                red += copy[i][j + 1].rgbtRed;
                green += copy[i][j + 1].rgbtGreen;
                blue += copy[i][j + 1].rgbtBlue;
                pixel++;
            }

            // Check top left
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += copy[i - 1][j - 1].rgbtRed;
                green += copy[i - 1][j - 1].rgbtGreen;
                blue += copy[i - 1][j - 1].rgbtBlue;
                pixel++;
            }

            // Check top right
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += copy[i - 1][j + 1].rgbtRed;
                green += copy[i - 1][j + 1].rgbtGreen;
                blue += copy[i - 1][j + 1].rgbtBlue;
                pixel++;
            }

            // Check bottom left
            if (i + 1 < height && j - 1 >= 0)
            {
                red += copy[i + 1][j - 1].rgbtRed;
                green += copy[i + 1][j - 1].rgbtGreen;
                blue += copy[i + 1][j - 1].rgbtBlue;
                pixel++;
            }

            //Check bottom right
            if (i + 1 < height && j + 1 < width)
            {
                red += copy[i + 1][j + 1].rgbtRed;
                green += copy[i + 1][j + 1].rgbtGreen;
                blue += copy[i + 1][j + 1].rgbtBlue;
                pixel++;
            }

            // Add current
            red += copy[i][j].rgbtRed;
            green += copy[i][j].rgbtGreen;
            blue += copy[i][j].rgbtBlue;
            pixel++;

            // Find averages and store in original image
            double average_r = round(red / pixel);
            double average_g = round(green / pixel);
            double average_b = round(blue / pixel);

            image[i][j].rgbtRed = average_r;
            image[i][j].rgbtGreen = average_g;
            image[i][j].rgbtBlue = average_b;
        }
    }
    return;
}