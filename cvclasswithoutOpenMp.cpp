cv::Mat GaussianBlur(cv::Mat image) {
    cv::Mat returnImage = image;

    double sigma = 1;
    int W = 5;
    double mean = W/2;
    double kernel[W][W];
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

    int i, j;
    int radius = W;
    double val1 = 0, val2 = 0, val3 = 0;
    for (i = 0; i < image.cols; i++) {
        for (j = 0; j < image.rows; j++) {
            int iy;
            int ix;
            for (ix = -radius/2 ; ix <= radius/2; ix++) {
                for (iy = -radius/2; iy <= radius/2; iy++) {
                    int x = std::min(image.cols, std::max(0, i-ix));
                    int y = std::min(image.rows, std::max(0, j-iy));
                    val1 += (image.at<cv::Vec3b>(y, x)[0] * kernel[iy+2][ix+2]);
                    val2 += (image.at<cv::Vec3b>(y, x)[1] * kernel[iy+2][ix+2]);
                    val3 += (image.at<cv::Vec3b>(y, x)[2] * kernel[iy+2][ix+2]);
                } 
            }

            returnImage.at<cv::Vec3b>(j, i)[0] = int(val1);
            returnImage.at<cv::Vec3b>(j, i)[1] = int(val2);
            returnImage.at<cv::Vec3b>(j, i)[2] = int(val3);
            val1 = val2 = val3 = 0;
        }
    }
    return returnImage;
}
