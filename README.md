# BMP EDITING

This repo focuses on editing BMP images at pixel level using C. For ease of use I used <a href="http://qdbmp.sourceforge.net/">QDBMP</a> library. And for Grayscale techniques I followed <a href="https://github.com/tannerhelland">Tanner Helland</a>'s <a href="http://www.tannerhelland.com/3643/grayscale-image-algorithm-vb6/">article</a>.

<b>Original Image</b>

![fish.bmp](src/Inputs/fish.bmp?raw=true "Fish.bmp")

<b>Negative</b>
To get negative of an image, we just invert each color in each pixel of the image.

![fish_neg.bmp](src/Outputs/fish_neg.bmp?raw=true "Fish Negative.bmp")
