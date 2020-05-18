#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;

    // Find the average of blue, green, red values for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.00);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Limits sepia values to 255
int limit(int sepia)
{
    if (sepia > 255)
    {
        sepia = 255;
    }
    return sepia;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;
    float originalBlue, originalGreen, originalRed;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;
            originalRed = image[i][j].rgbtRed;

            // Formula for sepia values
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Substitute capped sepia values into original image
            image[i][j].rgbtBlue = limit(sepiaBlue);
            image[i][j].rgbtGreen = limit(sepiaGreen);
            image[i][j].rgbtRed = limit(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            half[0] = image[i][j].rgbtBlue;
            half[1] = image[i][j].rgbtGreen;
            half[2] = image[i][j].rgbtRed;

            // Reflect half part of image
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            // Reflect first half part of image into second half part location
            image[i][width - j - 1].rgbtBlue = half[0];
            image[i][width - j - 1].rgbtGreen = half[1];
            image[i][width - j - 1].rgbtRed = half[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avg[height][width];;
    float sBlue, sGreen, sRed;
    int count;

    // Find the average of values of 8 adjacent pixels surrounding current pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            sBlue = 0.00;
            sGreen = 0.00;
            sRed = 0.00;
            count = 0;

            for (int h = -1; h < 2; h++)
            {
                // Check if outside width of image
                if (j + h < 0 || j + h > width - 1)
                {
                    continue;
                }

                // Check if outside height of image
                for (int k = -1; k < 2; k++)
                {
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }

                    sBlue += image[i + k][j + h].rgbtBlue;
                    sGreen += image[i + k][j + h].rgbtGreen;
                    sRed += image[i + k][j + h].rgbtRed;
                    count++;
                }
            }

            avg[i][j].rgbtBlue = round(sBlue / count);
            avg[i][j].rgbtGreen = round(sGreen / count);
            avg[i][j].rgbtRed = round(sRed / count);
        }
    }

    // Substitute "blurred" values into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = avg[i][j].rgbtBlue;
            image[i][j].rgbtGreen = avg[i][j].rgbtGreen;
            image[i][j].rgbtRed = avg[i][j].rgbtRed;
        }
    }
}
