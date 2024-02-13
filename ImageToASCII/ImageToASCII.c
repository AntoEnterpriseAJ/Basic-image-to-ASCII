#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image\stb_image_write.h"

int main(int argc, char** argv)
{
	int width, height, channels;
	char* image = stbi_load("imageName", &width, &height, &channels, 0);

	return 0;
}