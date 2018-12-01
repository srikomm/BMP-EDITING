# BMP EDITING

This repo focuses on editing BMP images at pixel level using C. For ease of use I used <a href="http://qdbmp.sourceforge.net/">QDBMP</a> library. And for Grayscale techniques I followed <a href="https://github.com/tannerhelland">Tanner Helland</a>'s <a href="http://www.tannerhelland.com/3643/grayscale-image-algorithm-vb6/">article</a>.

<b>Original Image</b>

![fish.bmp](src/Inputs/fish.bmp?raw=true "Fish.bmp")

<a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L18"><h1>Negative</h1></a><br>To get negative of an image, we just invert each color in each pixel of the image.</br>
![fish_neg.bmp](src/Outputs/fish_neg.bmp?raw=true "Fish Negative.bmp")

<h1>Greyscale</h1>
While converting a colored image to greyscale, a grey value is calculated from RGB values of the pixel and all the 3 RGB values are updated to the same grey value. This grey value depends upon the algorithm used.
<h2><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L29">Average Method</a></h2>
In this method grey value is simply the average of all 3 RGB values of a pixel.

![fish_avg.bmp](src/Outputs/fish_avg.bmp?raw=true "Fish Average.bmp")

<h2><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L42">Correcting for the human eye (Luma Method)</a></h2>
This method uses an algorithm specified by the original ITU-R recommendation (BT.709, specifically) to calculate the grey value.

![fish_luma.bmp](src/Outputs/fish_luma.bmp?raw=true "Fish Luma.bmp")

<h2><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L55">Desaturation</a></h2>
This method takes the average of the max and min values of a pixel and assigns it as the grey value.

![fish_desaturation.bmp](src/Outputs/fish_desaturation.bmp?raw=true "Fish Desaturation.bmp")

<h2>Decomposition</h2>
There are two ways to decompose an image.
<h3><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L68">Max Decomposition</a></h3>
This uses the max value of all the 3 channels for the grey value.

![fish_decomposition_max.bmp](src/Outputs/fish_decomposition_max.bmp?raw=true "Fish Decomposition Max.bmp")
<h3><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L81">Min Decomposition</a></h3>
This uses the min value of all the 3 channels for the grey value.

![fish_decomposition_min.bmp](src/Outputs/fish_decomposition_min.bmp?raw=true "Fish Decomposition Min.bmp")

<h2>Single Color Channel</h2>
This method uses data from a single color channel.
<h3><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L94">SCC Red</a></h3>
This uses the red channel directly as gray.

![fish_scc_red.bmp](src/Outputs/fish_scc_red.bmp?raw=true "Fish SCC Red.bmp")
<h3><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L107">SCC Green</a></h3>
This uses the green channel directly as gray.

![fish_scc_green.bmp](src/Outputs/fish_scc_green.bmp?raw=true "Fish SCC Green.bmp")
<h3><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L120">SCC Blue</a></h3>
This uses the blue channel directly as gray.

![fish_scc_blue.bmp](src/Outputs/fish_scc_blue.bmp?raw=true "Fish SCC Blue.bmp")

<br></br>
For better understanding of the SCC method, I am including another example here.
<b>Original Image</b>
![rgb.bmp](src/Inputs/rgb.bmp?raw=true "RGB.bmp")
<br></br><b>SCC Red</b>
![rgb_red.bmp](src/Outputs/rgb_red.bmp?raw=true "RGB Red.bmp")
<br></br><b>SCC Green</b>
![rgb_green.bmp](src/Outputs/rgb_green.bmp?raw=true "RGB Green.bmp")
<br></br><b>SCC Blue</b>
![rgb_blue.bmp](src/Outputs/rgb_blue.bmp?raw=true "RGB Blue.bmp")

<h2><a href="https://github.com/SRIpandu1729/BMP-EDITING/blob/50ad32632ec124878991ebb7e5ee40563ed929fe/src/mian.c#L133">Custom shades of grey</a></h2>
<br></br>In this method, the greyscale image is generated based on the number of shades of grey we define.
As the number of shades of grey increases the image gets better and better.

<b>2 shades of grey</b>
![fish_2_shades_of_grey.bmp](src/Outputs/fish_2_shades_of_grey.bmp?raw=true "FISH 2 Shades of Grey.bmp")
<b>3 shades of grey</b>
![fish_3_shades_of_grey.bmp](src/Outputs/fish_3_shades_of_grey.bmp?raw=true "FISH 3 Shades of Grey.bmp")
<b>4 shades of grey</b>
![fish_4_shades_of_grey.bmp](src/Outputs/fish_4_shades_of_grey.bmp?raw=true "FISH 4 Shades of Grey.bmp")
<b>8 shades of grey</b>
![fish_8_shades_of_grey.bmp](src/Outputs/fish_8_shades_of_grey.bmp?raw=true "FISH 8 Shades of Grey.bmp")
<b>16 shades of grey</b>
![fish_16_shades_of_grey.bmp](src/Outputs/fish_16_shades_of_grey.bmp?raw=true "FISH 16 Shades of Grey.bmp")
<b>32 shades of grey</b>
![fish_32_shades_of_grey.bmp](src/Outputs/fish_32_shades_of_grey.bmp?raw=true "FISH 32 Shades of Grey.bmp")
<b>64 shades of grey</b>
![fish_64_shades_of_grey.bmp](src/Outputs/fish_64_shades_of_grey.bmp?raw=true "FISH 64 Shades of Grey.bmp")
<b>128 shades of grey</b>
![fish_128_shades_of_grey.bmp](src/Outputs/fish_128_shades_of_grey.bmp?raw=true "FISH 128 Shades of Grey.bmp")
<b>256 shades of grey</b>
![fish_256_shades_of_grey.bmp](src/Outputs/fish_256_shades_of_grey.bmp?raw=true "FISH 256 Shades of Grey.bmp")
