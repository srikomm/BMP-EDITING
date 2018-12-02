#include "qdbmp.h"


UINT max(UINT r, UINT g, UINT b){
	if ((r >= g) && (r >= b))	return r;
	else if ((g >= r) && (g >= b))	return g;
	return b;
}


UINT min(UINT r, UINT g, UINT b){
	if ((r <= g) && (r <= b))	return r;
	else if ((g <= r) && (g <= b))	return g;
	return b;
}


void negative(BMP* input, BMP* output, UINT width, UINT height){
	UCHAR r, g, b;
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


void grayscale_luma(BMP* input, BMP* output, UINT width, UINT height){
	UCHAR r, g, b, grey;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			grey = r*0.2126 + g*0.7152 + b*0.0722;
			BMP_SetPixelRGB(output, x, y, grey, grey, grey);
		}
	}
	return;
}


void grayscale_desaturation(BMP* input, BMP* output, UINT width, UINT height){
	UCHAR r, g, b, grey;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			grey = (max(r, g, b) + min(r, g, b)) / 2;
			BMP_SetPixelRGB(output, x, y, grey, grey, grey);
		}
	}
	return;
}


void grayscale_decomposition(BMP* input, BMP* output, UINT width, UINT height, UINT maxOrMin){
	UCHAR r, g, b, grey;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			if (maxOrMin == 1) grey = max(r, g, b);
			else if (maxOrMin == 1) grey = min(r, g, b);
			else return;
			BMP_SetPixelRGB(output, x, y, grey, grey, grey);
		}
	}
	return;
}


void grayscale_scc(BMP* input, BMP* output, UINT width, UINT height, UINT color){
	UCHAR r, g, b, grey;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			if (color == 0)grey = r;
			else if (color == 1)grey = g;
			else if (color == 2)grey = b;
			else return;
			BMP_SetPixelRGB(output, x, y, grey, grey, grey);
		}
	}
	return;
}


void grayscale_custom_shades_of_grey(BMP* input, BMP* output, UINT width, UINT height, UINT noOfShades){
	if (noOfShades < 2 || noOfShades >256)	return;
	UCHAR r, g, b, grey, ConversionFactor, AverageValue;
	for (UINT x = 0; x < width; ++x){
		for (UINT y = 0; y < height; ++y){
			BMP_GetPixelRGB(input, x, y, &r, &g, &b);
			ConversionFactor = 255 / (noOfShades - 1);
			AverageValue = (r + g + b) / 3;
			grey = (UINT)((AverageValue / ConversionFactor) + 0.5) * ConversionFactor;
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

	input = BMP_ReadFile("Inputs//fish.bmp");
	BMP_CHECK_ERROR(stderr, -1);

	width = BMP_GetWidth(input);
	height = BMP_GetHeight(input);
	depth = BMP_GetDepth(input);

	output = BMP_Create(width, height, depth);

	grayscale_custom_shades_of_grey(input, output, width, height, 256);

	BMP_WriteFile(output, "Grayscale//fish_256_shades_of_grey.bmp");
	BMP_CHECK_ERROR(stderr, -2);

	BMP_Free(input);
	BMP_Free(output);
	return;
}