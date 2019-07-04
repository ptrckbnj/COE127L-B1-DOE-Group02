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
    /*if( in->bitpix != 24){
        free(in);
        printf("Need 24 bit bmp file!");
        exit(1);
    } */
    char* data = (char*) malloc (in->arraywidth);
    fseek(file, in->data, SEEK_SET);
    fread(data, in->arraywidth, 1, file);
    fclose(file);
    return data;
}
