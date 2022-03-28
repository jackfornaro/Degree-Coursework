#ifndef BLOB_DETECT_H_
#define BLOB_DETECT_H_

#include <iostream>
#include "opencv2/opencv.hpp"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class to do blob detection
 */
class BlobDetection {
public:

	/**
	* @brief Default constructor.
	* @return It returns an object of this class.
	*/
	BlobDetection(){}

	/**
	* @brief To do the cannyEdgeDetection.
	* @param filename the first argument
	*/
	void ImplementBlobDetection(const char* filename){
		cv::Mat image = cv::imread(filename);
		if (image.empty())
		{
			std::cout << "> This image is empty." << std::endl;
			return;
		}
		cv::Mat output;
		cv::inRange(image, cv::Scalar(10, 80, 161), cv::Scalar(64, 183, 255), output);
		cv::imwrite("blob_image.png", output); 
	}

};


#endif
