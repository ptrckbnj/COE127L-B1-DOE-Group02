 logs << "Blur w/ OpenMP, double, 8 kernels\n";
    std::cout << "Gaussian Blur with OpenMp - double 8 kernels"
        << std::endl;
    for (int i = 0; i < 10; i++) {
        image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
        startTime = omp_get_wtime();
        gaussianImage = GaussianBlur_omp_2(image, 8);
        duration = omp_get_wtime() - startTime;
        logs << duration << "\n";
        std::cout << "FINISHED. Blurring with OpenMP, double, 8 kernels " << duration << " seconds." << std::endl;
        if (i == 9)
            cv::imwrite("gaussian_openMP_double_8.png", gaussianImage);
    }

    
    logs.close();
