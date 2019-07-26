//July 26, 2019
v::Mat GaussianBlur_omp_2(cv::Mat image, int num_procs) {
    cv::Mat returnImage = image;


    double sigma = 1;
    int W = 5;
    double kernel[W][W];
    double mean = W/2;
    double sum = 0.0; 
    for (int x = 0; x < W; ++x)
        for (int y = 0; y < W; ++y) {
            kernel[x][y] = exp( -0.5 * (pow((x-mean)/sigma, 2.0) + pow((y-mean)/sigma,2.0)) )
                / (2 * M_PI * sigma * sigma);

            sum += kernel[x][y];
        }
    for (int x = 0; x < W; ++x)
        for (int y = 0; y < W; ++y)
            kernel[x][y] /= sum;

    omp_set_num_threads(num_procs);

    int i, j;
    int radius = W;
    double val1 = 0, val2 = 0, val3 = 0;
#pragma omp parallel for shared(image) private(i) 
    for (i = 0; i < image.cols; i++) {
#pragma omp parallel for shared(image) private(j,val1,val2,val3) 
        for (j = 0; j < image.rows; j++) {
            int iy;
            int ix;
