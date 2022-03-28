#ifndef DRONE_H_
#define DRONE_H_


#include "camera.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for handling Drone
 */
class DroneClass {
public:
    int id; double pos[3]; double dir[3]; double speed;
    

    /**
	* @brief Default constructor.
	* @return It returns an object of this class.
	*/
    DroneClass(){
        pos[0] = 0; pos[1] = 0; pos[2] = 0;
        
        dir[0] = 0; dir[1] = 0; dir[2] = 0;
        speed = 1;
    }
    
    /**
	* @brief Constructor with the given values.
	* @param x the first argument
	* @param y the sescond argument
	* @param z the third argument
	* @param s the fourth argument
	* @return It returns an object of this class.
	*/
    DroneClass(double x, double y, double z, double s){
        pos[0] = x; pos[1] = y; pos[2] = z;
        
        dir[0] = 0; dir[1] = 0; dir[2] = 0;
        speed = s;
    }
    
    /**
	* @brief To get the position.
	* @param index the first argument
	* @return It returns the value of the given index.
	*/
    double GetPosition(int index){
	    return pos[index];
  	}


    
    /**
	* @brief It updates drone's movement
	* @param dt the first argument
	*/
    void Update(double dt);
    
    /**
	* @brief It sets the next direction to move to for the drone.
	*/
    void setMovement();
    
    /**
	* @brief It updates drone's movement
	* @param x the first argument
	* @param y the second argument
	* @param z the third argument
	*/
    void SetJoystick(double x, double y, double z, double a);

    std::vector<CameraClass*> cameras;
    float lastPictureTime = 0.0;
    float time = 0.0;
	
} ;






#endif
