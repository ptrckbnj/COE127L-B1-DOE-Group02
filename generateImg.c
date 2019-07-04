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





int setBoundary(int i , int min , int max){

    if( i < min) return min;

    else if( i > max ) return max;

    return i;  

}
