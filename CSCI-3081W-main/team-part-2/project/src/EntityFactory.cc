#include "EntityFactory.h"

//EntityFactory::~EntityFactory(){
//	delete camera;
//}

void EntityFactory::CreateEntity(picojson::object& entityData, ICameraController& cameraController, DroneClass* MyDrone){
	if (entityData["name"].get<std::string>() == "drone") {
		    MyDrone->id = entityData["entityId"].get<double>();
		    MyDrone->speed = entityData["speed"].get<double>();

		    // Get the position as an array
		    picojson::array position = entityData["position"].get<picojson::array>();
		    MyDrone->pos[0] = position[0].get<double>();
		    MyDrone->pos[1] = position[1].get<double>();
		    MyDrone->pos[2] = position[1].get<double>();

		    // Get the direction as an array
		    picojson::array dir = entityData["direction"].get<picojson::array>();
		    MyDrone->dir[0] = dir[0].get<double>();
		    MyDrone->dir[1] = dir[1].get<double>();
		    MyDrone->dir[2] = dir[1].get<double>();

		    // Create cameras for the entity.
		    picojson::array cameras = entityData["cameras"].get<picojson::array>();
		    for (int i = 0; i < cameras.size(); i++) {
		        camera = new CameraClass(cameras[i].get<double>(), &cameraController);
		        MyDrone->cameras.push_back(camera);
		    }
    }

}
