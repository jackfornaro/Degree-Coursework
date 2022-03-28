#include "simulation_facade.h"


Simulation::Simulation(){
	MyDrone = new DroneClass();
	entityFactory = new EntityFactory();
}

Simulation::~Simulation(){
	delete MyDrone;
	delete entityFactory;
}

void Simulation::EntityCreation(picojson::object& entityData, ICameraController& cameraController){

		picojson::value val(entityData);
		std::cout << val.serialize() << std::endl;

    	entityFactory->CreateEntity(entityData, cameraController, MyDrone);
}
	
void Simulation::Update(double dt, double x, double y, double z, double a){
		// Updates the simulation.  This may be called multiple times per frame.

		MyDrone->SetJoystick(x, y, z, a);
	
		MyDrone->Update(dt);
}

void Simulation::FinishUpdate(picojson::object& returnValue){
		// Called after all updating is done.
		//std::cout<<"hello_world3"<<std::endl;
		// Below is an example of how to send the position and direction to the UI.  
		// In general you will want to loop through entities that have changed to update
		// their position and direction:
		picojson::object entity;
		entity["entityId"] = picojson::value((double)0);
		
		// Save the position as an array
		picojson::array pos;
		pos.push_back(picojson::value(MyDrone->pos[0] * 1.4 / 20));
    	pos.push_back(picojson::value(MyDrone->pos[1] * 1.4 / 150));
    	pos.push_back(picojson::value(MyDrone->pos[2] * 1.4 / 20));
    	//pos.push_back(picojson::value(MyDrone->pos[0]));
    	//pos.push_back(picojson::value(MyDrone->pos[1]));
    	//pos.push_back(picojson::value(MyDrone->pos[2]));
		entity["pos"] = picojson::value(pos);

		// Save the direction as an array
		picojson::array dir;
		dir.push_back(picojson::value(MyDrone->dir[0]));
		dir.push_back(picojson::value(MyDrone->dir[1]));
		dir.push_back(picojson::value(MyDrone->dir[2]));
		entity["dir"] = picojson::value(dir);

		// Send the compile picojson data to the UI in the returnValue variable
		returnValue["entity"+std::to_string(MyDrone->id)] = picojson::value(entity);
}



