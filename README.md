# COE127L-B1-DOE-Group02

### The aim for this project is to implement a conversion of an image to gaussian blur using multi-threading. 

Gaussian blur is the result of blurring an image by a Gaussian function. It is a widely used effect in graphics software, typically to reduce image noise and reduce detail. 

The Design of Experiment is about comparing the execution time of using the Gaussian blur on images using multithreading and serial process having bitmap resolution of a picture. Bitmaps are defined as a regular rectangular mesh of cells called pixels, each pixel containing a color value. They are characterized by only two parameters, the number of pixels and the information content (color depth) per pixel. There are other attributes that are applied to bitmaps but they are derivations of these two fundamental parameters.  BMP stands for Bitmap and because they are uncompressed, are larger in size when compared to JPG images. BMPs are typically stored as 32 bits per pixel. 

![2](https://user-images.githubusercontent.com/50915438/61888342-ed3f8000-af35-11e9-8bec-664f3d8c27ad.jpg)


## Objectives 

To create a Gaussian blur program that uses serial processing on a images
To create a Gaussian blur program that uses multithreading on image
To prove that multithreading process is faster than serial process. 
To be able to know the theories for multi-threading and matplotlib python. 


## OpenMP
Parallel code with OpenMP marks, through a special directive, sections to be executed in parallel. The part of the code marked to run in parallel will cause threads to form. The main tread is the master thread. The slave threads all run in parallel and run the same code. Each thread executes the parallelized section of the code independently. When a thread finishes, it joins the master. When all threads finished, the master continues with code following the parallel section. The idea of Gaussian smoothing is to use this 2-D distribution as a point-spread function, and this is achieved by convolution. Since the image is stored as a collection of discrete pixel we need to produce a discrete approximation to the Gaussian function before we can perform the convolution. In theory, the Gaussian distribution is non-zero everywhere, which would require an infinitely large convolution kernel, but in practice it is effectively zero more than about three standard deviations from the mean, and so we can truncate the kernel at this point.

![1](https://user-images.githubusercontent.com/50915438/61888340-eca6e980-af35-11e9-91bc-8f87a0a8808f.png)

![3](https://user-images.githubusercontent.com/50915438/61888464-1bbd5b00-af36-11e9-8941-ddb9c752b7c4.png)
