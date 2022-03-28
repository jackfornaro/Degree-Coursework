#ifndef SIMULATION_FACADE_H_
#define SIMULATION_FACADE_H_


#include "drone.h"
#include "EntityFactory.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for handling the simulation
 */
class Simulation {
public:
	/**
	* @brief Default constructor to initializes simulation.
	* @return It returns an object of the simulation class.
	*/
	Simulation();
	
	/**
	* @brief Destructor.
	*/
	~Simulation();
	
	/**
	* @brief Create an entity.
	* @param entityData the first argument
	* @param cameraController the second argument
	*/
	void EntityCreation(picojson::object& entityData, ICameraController& cameraController);
	
	/**
	* @brief Updates the simulation.  This may be called multiple times per frame.
	* @param dt the first argument
	* @param x the second argument
	* @param y the third argument
	* @param z the fourth argument
	* @param a the fifth argument
	*/
	void Update(double dt, double x, double y, double z, double a);
	
	/**
	* @brief Called after all updating is done.
	* @param returnValue the first argument
	*/
	void FinishUpdate(picojson::object& returnValue);
	
	friend class WebApp;
protected:
	DroneClass *MyDrone;
	EntityFactory *entityFactory;
	
};


#endif
