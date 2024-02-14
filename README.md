# ImageToASCII Converter 🎨

## Overview

This is a simple C program for converting images to ASCII art. The program takes an input image, processes it, and generates a corresponding ASCII art representation. It supports various image formats and allows you to specify the input image and output ASCII file through command-line parameters.

## Features

- Converts images to ASCII art
- Command-line interface for easy use
- Supports multiple image formats

## Usage

### Prerequisites

Make sure you have the necessary libraries installed. The program uses the [stb_image](https://github.com/nothings/stb) library for image loading and [stb_image_write](https://github.com/nothings/stb) for image writing.

### Compile 🛠️

```bash
gcc ImageToASCII.c stb_image/stb_image.c stb_image/stb_image_write.c -o ImageToASCII
```

### Run ▶️

```bash
./ImageToASCII -i input_image.jpg -o output_ascii.txt
```

Replace `input_image.jpg` with the path to your image file and `output_ascii.txt` with the desired name for the ASCII art file.

## How It Works 🤔

The program processes the input image by loading it using the stb_image library. It then iterates through each pixel in the image, calculates the average intensity (brightness) of the pixel, maps this intensity to a corresponding ASCII character from a predefined set of shades, and writes the ASCII character to the output file. The result is an ASCII art representation of the input image.

## Notes 📝

This program was created for study purposes. Feel free to explore and modify the code for your own learning and experimentation.

## License 📄

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
