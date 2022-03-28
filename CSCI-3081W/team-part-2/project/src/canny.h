#ifndef CANNY_H_
#define CANNY_H_

#include <iostream>
#include "opencv2/opencv.hpp"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class to do the opencv built-in canny edges detection.
 */
class CvCannyEdgeDetect {
public:

	/**
	* @brief Default constructor.
	* @return It returns an object of this class.
	*/
	CvCannyEdgeDetect(){}
	
	/**
	* @brief To do the cannyEdgeDetection.
	*/
	void CannyEdgeDetect(){
		cv::Mat imgOriginal;        // input image
		cv::Mat imgGrayscale;       // grayscale of input image
		cv::Mat imgBlurred;         // intermediate blured image
		cv::Mat imgCanny;           // Canny edge image


		imgOriginal = cv::imread("blob_image.png");            // open image

		if (imgOriginal.empty()) {                                    // if unable to open image
		    std::cout << "error: image not read from file\n\n";        // show error message on command line
		    return;                                                // and exit program
		}

		cv::cvtColor(imgOriginal, imgGrayscale, cv::COLOR_BGR2GRAY);        // convert to grayscale

		cv::GaussianBlur(imgGrayscale,            // input image
		    imgBlurred,                            // output image
		    cv::Size(5, 5),                        // smoothing window width and height in pixels
		    1.5);                                // sigma value, determines how much the image will be blurred

		cv::Canny(imgBlurred,            // input image
		    imgCanny,                    // output image
		    100,                        // low threshold
		    200);                        // high threshold

		cv::imwrite("edges_image.png", imgCanny);

	}

};

#endif
