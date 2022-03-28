#include <iostream>
#include <cmath>
#include "vector3.h"
#include "opencv2/opencv.hpp"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class to find robot's location
 */
class FindRobot {
public:

	/**
	* @brief Default constructor.
	* @return It returns an object of this class.
	*/
	FindRobot(){}
	
	/**
	* @brief Finding the robot's location.
	* @param cameraX the first argument
	* @param cameraY the second argument
	* @param cameraZ the third argument
	* @return It returns a 3D vector to indicate robot's lacation.
	*/
	Vector3 ImplementFindRobotLocation(double cameraX, double cameraY, double cameraZ){
		cv::Mat edges = cv::imread("edges_image.png");
		cv::Mat depth = cv::imread("depth.jpg");
		
		Vector3 dirVec;
		Vector3 direction;
		Vector3 robotPos;
		Vector3 cameraPosition(cameraX, cameraY, cameraZ);
		double edgeValue, distance;
		
		for (int i = 0; i < edges.rows; ++i)
		{
		    cv::Vec3b* pixel1 = edges.ptr<cv::Vec3b>(i); // point to first pixel in row
		    cv::Vec3b* pixel2 = depth.ptr<cv::Vec3b>(i);
		    for (int j = 0; j < edges.cols; ++j)
		    {
		      	edgeValue = pixel1[j][0];
		      	if(edgeValue == 255){
		      		dirVec.x = pixel2[j][2];
		      		dirVec.y = pixel2[j][1];
		      		dirVec.z = pixel2[j][0];
		      		
		      		dirVec = dirVec / 255.0;
		      		
		      		dirVec = dirVec - Vector3(0.5, 0.5, 0.5);
		      		dirVec = dirVec * 2.0;
		      		
		      		double magDirVec = sqrt(dirVec.x*dirVec.x + dirVec.y*dirVec.y + dirVec.z*dirVec.z);
		      		distance = ((1.0 - magDirVec) * 50.0);
		      		direction = (dirVec / magDirVec);
		      		
		      		robotPos = cameraPosition + (direction * distance);
		      	}
		    }
		}
		return robotPos;
	}
};
