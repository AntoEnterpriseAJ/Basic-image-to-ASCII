#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image\stb_image_write.h"

void handleParamters(char** argv, int argc, char** imageName, char** outputFileName)
{
	*imageName = NULL, *outputFileName = NULL;
	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			if (i + 1 < argc)
			{
				*imageName = argv[i + 1];
				i++;
			}
			else
			{
				printf("Missing image name.\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(argv[i], "-o") == 0)
		{
			if (i + 1 < argc)
			{
				*outputFileName = argv[i + 1];
				++i;
			}
			else
			{
				printf("Missing output file name.\n");
				exit(EXIT_FAILURE);
			}

		}
	}
	if (*imageName == NULL || *outputFileName == NULL)
	{
		printf("Missing arguments.\nExample: ImageToASCII.exe -i imageName2.jpg -o out.txt");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char** argv)
{
	char* imageName, * outputFileName;
	handleParamters(argv, argc, &imageName, &outputFileName);
	int width, height, channels;
	char* image = stbi_load(imageName, &width, &height, &channels, 0);
	if (image == NULL)
	{
		printf("Error loading the image.");
		return 1;
	}
	char shades[] = { "   .\'\\`^\",:;Il!i><~+_-][}{1)(|\\/tfjrxnvczXYJCQ0OZmwpdbkhao*#MW8%%" };
	int shadesSize = 66;

	size_t imageSize = width * height * channels;
	FILE* output = fopen(outputFileName, "w");
	if (output == NULL)
	{
		printf("Error opening the output file.");
		return 3;
	}
	for (char* pixel = image; pixel < image + imageSize; pixel += channels)
	{
		char R = *pixel;
		char G = *(pixel + 1);
		char B = *(pixel + 2);
		if (channels == 4)
		{
			char A = *(pixel + 3);
		}

		int average = (R + G + B) / 3;
		int shadesIndex = (int)(shadesSize * (average / 255.0));
		fprintf(output, "%c", shades[shadesIndex]);
		if ((pixel - image + channels) % (width * channels) == 0)
		{
			fprintf(output, "\n");
		}
	}

	stbi_image_free(image);
	return 0;
}
