#include "camera.h"
//#include "global_variable.h"


CameraClass::CameraClass(int cameraId, ICameraController* controller) : id(id), controller(controller) {
	controller->AddObserver(*this);
	//result = new CameraResult();
	//pImageProcessor = new ImageProcessor();
}

//CameraClass::~CameraClass(){
	//delete controller;
	//delete result;
	//delete pImageProcessor;
//}

void CameraClass::TakePicture() {
    controller->TakePicture(id);
}

ICameraResult* CameraClass::ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
        if (cameraId == id || cameraId < 0) {
            // These will output the image to files.  Ultimately this is just for debugging:
            std::ofstream colorFile ("color.jpg", std::ios::out | std::ios::binary);
            colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
            std::ofstream depthFile ("depth.jpg", std::ios::out | std::ios::binary);
            depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);

            // Use the following to convert color and depth images to RGBA image from memory (inside your image class / perhaps with a new constructor):
            // int width, height, components;
            // unsigned char* buffer = stbi_load_from_memory((const unsigned char*)images[0].data, images[0].length(), &width, &height, &components, 4);
            // components = 4;

            // Generate the result of image processing.  This could include images using the Result class.
            CameraResult *result = new CameraResult();
            result->found = true;
            result->pos[0] = xPos;
            result->pos[1] = yPos;
            result->pos[2] = zPos;
            
            // Image Processing Facade
            ImageProcessor *pImageProcessor = new ImageProcessor();
            pImageProcessor->DoDetection();
            Vector3 robotPos;
            if(pImageProcessor->DoRatioCheck()){
            	robotPos = pImageProcessor->DoRobotLocationFinding(result->pos[0], result->pos[1], result->pos[2]);
            	//PathFollow::Instance()->robot_found_pos[0] = (robotPos.x);
              	//PathFollow::Instance()->robot_found_pos[1] = (robotPos.y);
             	//PathFollow::Instance()->robot_found_pos[2] = (robotPos.z);
            	std::cout << "robot position: " << robotPos.x << " " << robotPos.y << " " << robotPos.z << std::endl;
            }
            	
            
            
            return result;
        }
        else {
            return NULL;
        }
}

void CameraClass::ImageProcessingComplete(ICameraResult* result) {
        CameraResult& res = *static_cast<CameraResult*>(result);
        if (res.found) {
            std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[2] << std::endl;
        }
        delete result;
}

