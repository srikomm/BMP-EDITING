#include "qdbmp.h"

void negative(BMP* input, BMP* output, UINT width, UINT height){
	UCHAR r, g, b, grey;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			BMP_SetPixelRGB(output, x, y, 255 - r, 255 - g, 255 - b);
		}
	}
	return;
}


void grayscale_avg(BMP* input, BMP* output, UINT width, UINT height){
	UCHAR r, g, b, grey;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			grey = (r + g + b) / 3;
			BMP_SetPixelRGB(output, x, y, grey, grey, grey);
		}
	}
	return;
}


void main(){
	BMP *input, *output;
	UCHAR r, g, b, grey;
	UINT width, height;
	UINT x, y;
	USHORT depth;

	input = BMP_ReadFile("Inputs//swirl.bmp");
	BMP_CHECK_ERROR(stderr, -1);

	width = BMP_GetWidth(input);
	height = BMP_GetHeight(input);
	depth = BMP_GetDepth(input);

	output = BMP_Create(width, height, depth);

	negative(input, output, width, height);

	BMP_WriteFile(output, "Negative//swirl_neg.bmp");
	BMP_CHECK_ERROR(stderr, -2);

	BMP_Free(input);
	BMP_Free(output);
	return;
}