#ifndef CAMERA_H_
#define CAMERA_H_

#include "image_processor_facade.h"
#include "camera_controller.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for implementing camera class
 */
class CameraClass : public ICameraObserver {
public:
    /**
	* @brief Struct for the results
	*/
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    /**
	* @brief Constructor with the given values.
	* @param cameraId the first argument
	* @param controller the second argument
	* @return It returns an object of this class.
	*/
    CameraClass(int cameraId, ICameraController* controller) ;

	/**
	* @brief Destructor.
	*/
	//~CameraClass();

    /**
	* @brief Takes a picture using the specified camera id.
	*/
    void TakePicture() ;

	/**
	* @brief Processes images asynchonously.
	* @param cameraId the first argument
	* @param xPos the second argument
	* @param yPos the third argument
	* @param zPos the fourth argument
	* @param images the fifth argument
	* @param details the sixth argument
	* @return It returns a camera result which will be passed into the ImageProcessingComplete(...) method
	*/
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const ;
    
	/**
	* @brief After the asynchronous image processing, this method will be synchronized with the update loop.
	* @param result the first argument
	*/
    void ImageProcessingComplete(ICameraResult* result) ;

private:
    ICameraController* controller;
    //CameraResult *result;
    //ImageProcessor *pImageProcessor;
    int id;
};



#endif
