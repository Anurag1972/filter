#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
             float blue =image[i][j].rgbtBlue;
             float red =image[i][j].rgbtRed;
             float green =image[i][j].rgbtGreen;
             float averagergb= (red+blue+green)/3;
             image[i][j].rgbtRed= round(averagergb);
             image[i][j].rgbtGreen=round(averagergb);
             image[i][j].rgbtBlue=round(averagergb);
        }
    }

    return ;
}
int cap (value)
{
    return value>255?255:value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
             float originalBlue =image[i][j].rgbtBlue;
             float originalRed =image[i][j].rgbtRed;
             float originalGreen =image[i][j].rgbtGreen;

           float  sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
           float  sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            image[i][j].rgbtRed=cap(round(sepiaRed));
            image[i][j].rgbtBlue=cap(round(sepiaBlue));
            image[i][j].rgbtGreen=cap(round(sepiaGreen));


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflectedImage[height][width];

    // Create reflected image array
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            reflectedImage[i][j] = image[i][width - 1 - j];
        }
    }

    // Copy reflected image array to normal image array
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = reflectedImage[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
