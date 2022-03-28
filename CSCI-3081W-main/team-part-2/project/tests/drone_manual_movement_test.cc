#include "gtest/gtest.h"
#include "drone.h"

class DroneMovementTest : public ::testing::Test {
public:
    void SetUp(){


    }

protected:


};

TEST_F(DroneMovementTest, GetInitialPositionWithoutArgument){
  	DroneClass drone;
    EXPECT_EQ(drone.GetPosition(0), 0) << "X-Coordinate";
    EXPECT_EQ(drone.GetPosition(1), 0) << "Y-Coordinate";
    EXPECT_EQ(drone.GetPosition(2), 0) << "Z-Coordinate";
}


TEST_F(DroneMovementTest, GetInitialPositionWithArgument){
	DroneClass drone1(6,0,5,1);
    EXPECT_EQ(drone1.GetPosition(0), 6) << "X-Coordinate";
    EXPECT_EQ(drone1.GetPosition(1), 0) << "Y-Coordinate";
    EXPECT_EQ(drone1.GetPosition(2), 5) << "Z-Coordinate";
}

TEST_F(DroneMovementTest, SetJoystick){
	DroneClass drone1(6,0,5,1);
    drone1.SetJoystick(1,0,0,0);
    EXPECT_TRUE(drone1.dir[0] == 1);
    EXPECT_TRUE(drone1.dir[1] == 0);
    EXPECT_TRUE(drone1.dir[2] == 0);
}

TEST_F(DroneMovementTest, Update){
	DroneClass drone2(6,0,5,1);
    drone2.SetJoystick(1,1,0,0);
    
    double expect1 = 0;
    double expect2 = 2;
    double expect3 = 6;
    
    drone2.Update(0.01);
    int temp1 = drone2.GetPosition(0);
    int temp2 = drone2.GetPosition(1);
    int temp3 = drone2.GetPosition(2);
    
    EXPECT_EQ(temp1, expect1) << "X-Coordinate";
    EXPECT_EQ(temp2, expect2) << "Y-Coordinate";
    EXPECT_EQ(temp3, expect3) << "Z-Coordinate";
   
}


