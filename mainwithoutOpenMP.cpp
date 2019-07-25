logs << "Blur\n";
    std::cout <<"Gaussian Blur Without OpenMp"
        << std::endl;
    for (int i = 0; i < 10; i++) {
        image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
        startTime = omp_get_wtime();
        gaussianImage = GaussianBlur(image);
        duration = omp_get_wtime() - startTime;
        logs << duration << "\n";
        std::cout << "FINISHED. Blurring without OpenMP took " << duration << " seconds." << std::endl;
        if (i == 9)
            cv::imwrite("gaussian_normal.png", gaussianImage);
    }
    
    logs.close();
    return  0;
