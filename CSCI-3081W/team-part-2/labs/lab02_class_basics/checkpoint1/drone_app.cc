#include "drone_app.h"

namespace csci3081 {

void DroneApp::receiveJSON(picojson::value& val) {
    picojson::object data = val.get<picojson::object>();
    std::string cmd = data["command"].get<std::string>();
    picojson::object returnValue;
    returnValue["id"] = data["id"];
    ReceiveCommand(cmd, data, returnValue);
    picojson::value retVal(returnValue);
    sendJSON(retVal);
}

void DroneApp::ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue) {
    if (cmd == "update") {
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        double delta = diff.count() - time;
        time += delta;

        double simSpeed = data["simSpeed"].get<double>();
        delta *= simSpeed;

        if (delta > 0.1) {
            for (float f = 0.0; f < delta; f+=0.01) {
                Update(0.01, returnValue);
            }
        }
        else {
            Update(delta, returnValue);
        }
    }
    else if (cmd == "keyup") {
        KeyUp(data["key"].get<std::string>(), data["keyCode"].get<double>());
    }
    else if (cmd == "keydown") {
        KeyDown(data["key"].get<std::string>(), data["keyCode"].get<double>());
    }
    else {
        std::cout << "Unknown command: " << cmd << " - " << picojson::value(data).serialize() << std::endl;
    }
}

void DroneApp::Update(double dt, picojson::object& returnValue) {
    drone.SetJoystick(
        IsKeyDown("ArrowRight") ? 1 : (IsKeyDown("ArrowLeft") ? -1 : 0),
        IsKeyDown("ArrowUp") ? 1 : (IsKeyDown("ArrowDown") ? -1 : 0),
        IsKeyDown("w") ? 1 : (IsKeyDown("s") ? -1 : 0),
        IsKeyDown("a") ? 1 : (IsKeyDown("d") ? -1 : 0)
    );
    drone.Update(dt);
    picojson::array pos;
    pos.push_back(picojson::value(drone.GetPosition(0)));
    pos.push_back(picojson::value(drone.GetPosition(1)));
    pos.push_back(picojson::value(drone.GetPosition(2)));
    returnValue["pos"] = picojson::value(pos);
    picojson::array propSpeed;
    propSpeed.push_back(picojson::value(drone.GetPropellerSpeed(0)));
    propSpeed.push_back(picojson::value(drone.GetPropellerSpeed(1)));
    propSpeed.push_back(picojson::value(drone.GetPropellerSpeed(2)));
    propSpeed.push_back(picojson::value(drone.GetPropellerSpeed(3)));
    returnValue["propSpeed"] = picojson::value(propSpeed);
}

void DroneApp::KeyUp(const std::string& key, int keyCode) {
    keyValue[key] = 0;
}

void DroneApp::KeyDown(const std::string& key, int keyCode) {
    keyValue[key] = 1;
}

bool DroneApp::IsKeyDown(const std::string& key) {
    std::map<std::string,int>::iterator it = keyValue.find(key);
    if (it != keyValue.end()) {
        return it->second;
    } 

    return false;
}

}
