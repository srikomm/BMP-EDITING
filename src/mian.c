#include "qdbmp.h"

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

	// Use the required function here.
	
	BMP_WriteFile(output, "Negative//swirl_neg.bmp");
	BMP_CHECK_ERROR(stderr, -2);

	BMP_Free(input);
	BMP_Free(output);
	return;
}