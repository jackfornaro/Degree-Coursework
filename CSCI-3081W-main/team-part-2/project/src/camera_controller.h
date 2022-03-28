#ifndef ICAMERA_CONTROLLER_H_
#define ICAMERA_CONTROLLER_H_

#include <vector>
#include "picojson.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The result returned from the image processing
 */
class ICameraResult {
public:
    /**
	* @brief Virtual Destructor.
	*/
    virtual ~ICameraResult() {}
};


/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/
/**
 * @brief A raw camera image stored in jpg format (data) and length is an int
 */
struct RawCameraImage {
    const unsigned char* data;
    int length;
};


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A Camera Observer monitors results from all cameras.  It will process the pictures returned asynchronously and act on results.
 */
class ICameraObserver {
public:
    /**
	* @brief Virtual Destructor.
	*/
    virtual ~ICameraObserver() {}
    
    /**
	* @brief Processes images asynchronously after a picture has been taken.  This method will pass in the camera position and the raw images stored in jpg format.
	* @param cameraId the first argument
	* @param xPos the second argument
	* @param yPos the third argument
	* @param zPos the fourth argument
	* @param images the fifth argument
	* @param details the sixth argument
	* @return It returns a camera result which will be passed into the ImageProcessingComplete(...) method
	*/
    virtual ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const = 0;
    
    /**
	* @brief After the asynchronous image processing is done, this method is called to synchronize the results with the simulation update loop.
	* @param result the first argument
	*/
    virtual void ImageProcessingComplete(ICameraResult* result) = 0;
};

/// The Camera Controller class controls and allows for monitoring of all cameras.
class ICameraController {
public:
    /**
	* @brief Virtual Destructor.
	*/
    virtual ~ICameraController() {}
    
    /**
	* @brief To take a picture with a specific camera, pass in the camera id.
	* @param cameraId the first argument
	*/
    virtual void TakePicture(int cameraId) = 0;

    /**
	* @brief Adds a camera observer to monitor cameras.
	* @param observer the first argument
	*/
    virtual void AddObserver(ICameraObserver& observer) = 0;

    /**
	* @brief Removes a camera observer.
	* @param observer the first argument
	*/
    virtual void RemoveObserver(ICameraObserver& observer) = 0;
};

#endif
