#include "drone.h"
#include "global_variable.h"



void DroneClass::Update(double dt) {
    //std::cout<<"hello_world2"<<std::endl;
       setMovement();
       for (int i = 0; i < 3; i++) {
           pos[i] += speed*dir[i]*dt;
       }

       // Take a picture every 5 seconds with front camera
       time += dt;
       if (time-lastPictureTime > 5.0) {
           cameras[0]->TakePicture();
           lastPictureTime = time;
       }
}

void DroneClass::setMovement() {
      int currentTo = PathFollow::Instance()->currentNode;
      std::vector<double> xyz = PathFollow::Instance()->getPos(currentTo);
      if( (pos[0] < (xyz[0]+5)) && (pos[0] > (xyz[0]-5)) &&
          (pos[1] < (xyz[1]+5)) && (pos[1] > (xyz[1]-5)) &&
          (pos[2] < (xyz[2]+5)) && (pos[2] > (xyz[2]-5)) ) {
            PathFollow::Instance()->currentNode = PathFollow::Instance()->currentNode + 1;
          }
      dir[0] = xyz[0] - pos[0];
      dir[1] = xyz[1] - pos[1];
      dir[2] = xyz[2] - pos[2];
}

void DroneClass::SetJoystick(double x, double y, double z, double a) {
        dir[0] = x; dir[1] = y; dir[2] = z;
}
