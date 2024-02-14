#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image\stb_image_write.h"

int main(int argc, char** argv)
{
	int width, height, channels;
	char* image = stbi_load("imageName2.jpg", &width, &height, &channels, 0);
	if (image == NULL)
	{
		perror("Error loading the image");
		return 1;
	}
	char shades[] = { "   .\'\\`^\",:;Il!i><~+_-][}{1)(|\\/tfjrxnvczXYJCQ0OZmwpdbkhao*#MW8%%" };
	int shadesSize = 66;

	size_t imageSize = width * height * channels;
	char outputFileName[] = {"out.txt"};
	FILE* output = fopen(outputFileName, "w");
	if (output == NULL)
	{
		perror("Error opening the output file");
		return 3;
	}
	for (char* pixel = image; pixel < image + imageSize; pixel += channels)
	{
		char R = *pixel;
		char G = *(pixel + 1);
		char B = *(pixel + 2);
		if (channels == 4)
		{
			char A = (*pixel + 3);
		}

		int average = (R + G + B) / 3;
		int shadesIndex = average % shadesSize;
		putchar(shades[shadesIndex]);
		fprintf(output, "%c", shades[shadesIndex]);
		if ((pixel - image + channels) % (width * channels) == 0)
		{
			printf("\n");
			fprintf(output, "\n");
		}
	}

	free(image);
	free(shades);
	stbi_image_free(image);
	return 0;
}