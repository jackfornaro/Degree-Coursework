#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "WebServer.h"
#include "camera_controller.h"
#include <string>
#include "drone.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for handling entity creation.
 */
class EntityFactory {
public:
	/**
	* @brief Destructor to free the memory.
	*/
	//~EntityFactory();

	/**
	* @brief Copy constructor.
	* @param entityData the first argument
	* @param cameraController the second argument
	* @param MyDrone the third argument
	* @return It returns an object of a 3D vector with the given values.
	*/
  	void CreateEntity(picojson::object& entityData, ICameraController& cameraController, DroneClass* MyDrone);

protected:
	CameraClass* camera;
  
};



#endif
