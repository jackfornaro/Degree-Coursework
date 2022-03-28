#ifndef IMAGE_PROCESSOR_FACADE_H_
#define IMAGE_PROCESSOR_FACADE_H_

#include "blob_detect.h"
#include "canny.h"
#include "ratio_check.h"
#include "depth_location.h"
#include "vector3.h"



/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class as a facade to implement Image Processing
 */
class ImageProcessor {
protected:
	BlobDetection *blob;
	CvCannyEdgeDetect *canny;
	RatioCheck *ratio;
	FindRobot *findrobot;

public:

	/**
	* @brief Default constructor to initialize member variables.
	* @return It returns an object of the vector class.
	*/
	ImageProcessor() {
		blob = new BlobDetection();
		canny = new CvCannyEdgeDetect();
		ratio = new RatioCheck();
	}

	/**
	* @brief Destructor to free the memory.
	*/
	~ImageProcessor(){
		delete blob;
		delete canny;
		delete ratio;
	}

	/**
	* @brief To do the blob detection and canny edges detection with the given image.
	*/
	void DoDetection(){
		blob->ImplementBlobDetection("color.jpg");
		canny->CannyEdgeDetect();
	}
	
	/**
	* @brief To do the ratio check to see if the robot is found.
	* @return It returns a boolean indicating if the robot is found.
	*/
	bool DoRatioCheck(){
		return ratio->ImplementRatioCheck(1.2);
	}

	/**
	* @brief To find the location of the robot.
	* @param corX the first argument
	* @param corY the second argument
	* @param corZ the third argument 
	* @return It returns a 3D vector of the robot's location.
	*/
	Vector3 DoRobotLocationFinding(double xCor, double yCor, double zCor){
		return findrobot->ImplementFindRobotLocation(xCor, yCor, zCor);
	}
};




#endif
