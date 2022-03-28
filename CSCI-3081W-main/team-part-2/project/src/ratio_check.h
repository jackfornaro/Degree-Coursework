#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class to check if the robot is found
 */
class RatioCheck {
public:
	/**
	* @brief Default constructor.
	* @return It returns an object of this class.
	*/
	RatioCheck(){}
	
	/**
	* @brief Implementing the ratio check.
	* @param threshold the first argument
	* @return It returns a boolean to indicate whether the robot is found.
	*/
	bool ImplementRatioCheck(double threshold){
		cv::Mat blob = cv::imread("blob_image.png");
		if (blob.empty())
		{
			std::cout << "> Blob image is empty." << std::endl;
			return false;
		}
		cv::Mat edges = cv::imread("edges_image.png");
		if (edges.empty())
		{
			std::cout << "> Edges image is empty." << std::endl;
			return false;
		}

		int blobNum = 0;
		int edgesNum = 0;
		//cout << "rows: " << blob.rows << "\tcolumns: " << blob.cols << endl;
		//cout << "rows: " << edges.rows << "\tcolumns: " << edges.cols << endl;
		uchar blobValue, edgesValue;
		for (int i = 0; i < blob.rows; ++i)
		{
		    cv::Vec3b* pixel1 = blob.ptr<cv::Vec3b>(i); // point to first pixel in row
		    cv::Vec3b* pixel2 = edges.ptr<cv::Vec3b>(i);
		    for (int j = 0; j < blob.cols; ++j)
		    {
		        blobValue = pixel1[j][0];
		        edgesValue = pixel2[j][0];
		        if(blobValue > 0 && blobValue <= 255) {blobNum++;}
		        if(edgesValue > 0 && edgesValue <= 255) {edgesNum++;}
		    }
		}
		//cout << "blob: " << blobNum << endl;
		//cout << "edges: " << edgesNum << endl;
		double ans = 0;
		if(edgesNum == 0){return false;}
		else{ ans = (double)blobNum / (double)edgesNum; }
		//cout << "ans: " << ans << endl;
		if(ans > threshold) return true;
		return false;
	}

};
