# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <stdint.h>
# include <time.h>
# include <math.h>
# include <sys/time.h>

# define IMAGESIZE 54

# pragma pack(push, 2)          
    typedef struct {
        char sign;
        int size;
        int notused;
        int data;
        int headwidth;
        int width;
        int height;
        short numofplanes;
        short bitpix;
        int method;
        int arraywidth;
        int horizresol;
        int vertresol;
        int colnum;
        int basecolnum;
    } img;
# pragma pop

char* openImg(int inputFileNumber, img* bmp);
void generateImg(char* imgdata, img* bmp);
int setBoundary(int i , int min , int max);

int main(int argc, char *argv[]) {
    int radius = atoi(argv[1]);
    unsigned char* imgdata;
    img* bmp = (img*) malloc (IMAGESIZE);
    int inputFileNumber = atoi(argv[2]);   
    imgdata = openImg(inputFileNumber, bmp);

    int width = bmp->width;
    int height = bmp->height;


    unsigned char* red;
    unsigned char* green;
    unsigned char* blue;
    red = (unsigned char*) malloc (width*height);
    green = (unsigned char*) malloc(width*height);
    blue = (unsigned char*) malloc(width*height);
    int i, j;
    int pos = 0;
    
    int rgb_width =  width * 3 ;
    if ((width * 3  % 4) != 0) {
       rgb_width += (4 - (width * 3 % 4));  
    }
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width * 3; j += 3, pos++){
            red[pos] = imgdata[i * rgb_width + j];
            green[pos] = imgdata[i * rgb_width + j + 1];
            blue[pos] = imgdata[i * rgb_width + j + 2];  
        }
    }

    struct timeval start_time, stop_time, elapsed_time; 
 

    double row;
    double col;
    double redSum = 0;
    double greenSum = 0;
    double blueSum = 0;
    double weightSum = 0;
}

char* openImg(int inputFileNumber, img* in) {
    char inPutFileNameBuffer[32];
    sprintf(inPutFileNameBuffer, "%d.bmp",inputFileNumber);

    FILE* file;
    if (!(file = fopen(inPutFileNameBuffer, "rb"))) {
        printf("File not found!");
        free(in);
        exit(1);
    }
    fread(in, 54, 1, file);
    if( in->bitpix != 24){
        free(in);
        printf("Need 24 bit bmp file!");
        exit(1);
    }
    char* data = (char*) malloc (in->arraywidth);
    fseek(file, in->data, SEEK_SET);
    fread(data, in->arraywidth, 1, file);
    fclose(file);
    return data;
}

void generateImg(char* imgdata , img* out) {
    FILE* file;
    time_t now;
    time(&now);
    char fileNameBuffer[32];
    sprintf(fileNameBuffer, "%s.bmp",ctime(&now));
    file = fopen(fileNameBuffer, "wb");
    fwrite(out, IMAGESIZE, 1, file);
    fseek(file, out->data, SEEK_SET);
    fwrite(imgdata, out->arraywidth, 1, file);
    fclose(file);
}


