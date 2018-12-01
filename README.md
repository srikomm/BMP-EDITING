# BMP EDITING

This repo focuses on editing BMP images at pixel level using C. For ease of use I used <a href="http://qdbmp.sourceforge.net/">QDBMP</a> library. And for Grayscale techniques I followed <a href="https://github.com/tannerhelland">Tanner Helland</a>'s <a href="http://www.tannerhelland.com/3643/grayscale-image-algorithm-vb6/">article</a>.

<b>Original Image</b>

![fish.bmp](src/Inputs/fish.bmp?raw=true "Fish.bmp")

<a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L18"><b>Negative</b></a><br>To get negative of an image, we just invert each color in each pixel of the image.</br>

![fish_neg.bmp](src/Outputs/fish_neg.bmp?raw=true "Fish Negative.bmp")
