    logs << "Blur w/ OpenMP, simple, 8 kernels\n";
    std::cout << "Gaussian Blur With OpenMp - Simple 8 Kernels" 
        << std::endl;
    for (int i = 0; i < 10; i++) {
        image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
        startTime = omp_get_wtime();
        gaussianImage = GaussianBlur_omp(image, 8);
        duration = omp_get_wtime() - startTime;
        logs << duration << "\n";
        std::cout << "FINISHED. Blurring with OpenMP, simple, 8 kernels" << duration << " seconds." << std::endl;
        if (i == 9)
            cv::imwrite("gaussian_openMP_8.png", gaussianImage);
    }

