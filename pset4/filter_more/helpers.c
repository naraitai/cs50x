/*---------------------------------
Task 3 of 4

Brief
- Write a program that applies filters to BMPs
- Implement functions in helpers.c file
- Complete grayscale function
    - Taken in an image
    - Turn into black-and-white version
- Complete reflect function
    - Taken an image
    - Reflect image horizontally
- Complete blur function
    - Take an image
    - Return a box-blurred version of the image
- Complete edges function
    - Taken an image
    - Highlight the edges between objects
    - Use the Sobel operator

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
            double average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy image array
    RGBTRIPLE copy[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            copy[a][b] = image[a][b];
        }
    }

    // Loop through every pixel of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Track pixels and rgb values
            double pixels = 0.0;
            int red = 0;
            int green = 0;
            int blue = 0;

            // For each pixel loop 9 times to check surrounding pixels
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Only accept pixel positions that fall in the image
                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1)
                    {
                        red += copy[i + k][j + l].rgbtRed;
                        green += copy[i + k][j + l].rgbtGreen;
                        blue += copy[i + k][j + l].rgbtBlue;
                        pixels++;
                    }
                }
            }

            // Average rgb values
            double average_r = round(red / pixels);
            double average_g = round(green / pixels);
            double average_b = round(blue / pixels);

            // Blur pixel
            image[i][j].rgbtRed = average_r;
            image[i][j].rgbtGreen = average_g;
            image[i][j].rgbtBlue = average_b;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Make copy of image
    RGBTRIPLE copy[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            copy[a][b] = image[a][b];
        }
    }

    // 2D array of Gx matrix
    int GxKernel[3][3];
    GxKernel[0][0] = -1;
    GxKernel[0][1] = 0;
    GxKernel[0][2] = 1;
    GxKernel[1][0] = -2;
    GxKernel[1][1] = 0;
    GxKernel[1][2] = 2;
    GxKernel[2][0] = -1;
    GxKernel[2][1] = 0;
    GxKernel[2][2] = 1;

    // 2D array of Gy matrix
    int GyKernel[3][3];
    GyKernel[0][0] = -1;
    GyKernel[0][1] = -2;
    GyKernel[0][2] = -1;
    GyKernel[1][0] = 0;
    GyKernel[1][1] = 0;
    GyKernel[1][2] = 0;
    GyKernel[2][0] = 1;
    GyKernel[2][1] = 2;
    GyKernel[2][2] = 1;

    // Loop through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Set Gx and Gy counter to 0
            int GxRed = 0, GxGreen = 0, GxBlue = 0;
            int GyRed = 0, GyGreen = 0, GyBlue = 0;

            // Loop 9 times to calculate Gx and Gy for all pixels current pixel touches
            for (int k = 0, m = -1; m < 2; k++, m++)
            {
                for (int l = 0, n = -1; n < 2 ; l++, n++)
                {
                    // Only accept pixel position that fall within image
                    if (i + m >= 0 && j + n >= 0 && i + m <= height - 1 && j + n <= width - 1)
                    {
                        GxRed += GxKernel[k][l] * copy[i + m][j + n].rgbtRed;
                        GxGreen += GxKernel[k][l] * copy[i + m][j + n].rgbtGreen;
                        GxBlue += GxKernel[k][l] * copy[i + m][j + n].rgbtBlue;

                        GyRed += GyKernel[k][l] * copy[i + m][j + n].rgbtRed;
                        GyGreen += GyKernel[k][l] * copy[i + m][j + n].rgbtGreen;
                        GyBlue += GyKernel[k][l] * copy[i + m][j + n].rgbtBlue;
                    }
                }
            }

            // Declare array and hold totaled Gx and Gy values
            int squares[3];
            squares[0] = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));
            squares[1] = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            squares[2] = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));

            // Loop through values. Set anything over 255 to 255
            for (int q = 0; q < 3; q++)
            {
                if (squares[q] > 255)
                {
                    squares[q] = 255;
                }
            }

            // Give current pixel new value
            image[i][j].rgbtRed = squares[0];
            image[i][j].rgbtGreen = squares[1];
            image[i][j].rgbtBlue = squares[2];
        }
    }
    return;
}
