# BMP EDITING

This repo focuses on editing BMP images at pixel level using C. For ease of use I used <a href="http://qdbmp.sourceforge.net/">QDBMP</a> library. And for Grayscale techniques I followed <a href="https://github.com/tannerhelland">Tanner Helland</a>'s <a href="http://www.tannerhelland.com/3643/grayscale-image-algorithm-vb6/">article</a>.

<b>Original Image</b>

![fish.bmp](src/Inputs/fish.bmp?raw=true "Fish.bmp")

<a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L18"><h1>Negative</h1></a><br>To get negative of an image, we just invert each color in each pixel of the image.</br>
![fish_neg.bmp](src/Outputs/fish_neg.bmp?raw=true "Fish Negative.bmp")

<h1>Greyscale</h1>
While converting a colored image to greyscale, a grey value is calculated from RGB values of the pixel and all the 3 RGB values are updated to the same grey value. This grey value depends upon the algorithm used.
<h2>
<a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L29">Average Method</a></h2>
In this method grey value is simply the average of all 3 RGB values of a pixel.

![fish_avg.bmp](src/Outputs/fish_avg.bmp?raw=true "Fish Average.bmp")
<a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L42">Correcting for the human eye (Luma Method)</a></h2>
This method uses an algorithm specified by the original ITU-R recommendation (BT.709, specifically) to calculate the grey value.

![fish_luma.bmp](src/Outputs/fish_luma.bmp?raw=true "Fish Luma.bmp")
