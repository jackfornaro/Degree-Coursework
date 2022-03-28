#ifndef WEB_APP_H_
#define WEB_APP_H_

//#include <map>
#include "WebServer.h"
//#include "camera_controller.h"
#include <chrono>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "simulation_facade.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A Web Application Sever that communicates with a web page through web sockets.
 */
class WebApp : public JSONSession, public ICameraController {
public:
    /**
     * @brief Default constructor to initializes server.
     * @return It returns an object of the class
     */
    WebApp();
    /**
     * @brief vertual destructor.
     */
    virtual ~WebApp();

	/**
     * @brief Creates an entity based on JSON data stored as an object.
     * @param entityData the first argument
     * @param cameraController the second argument
     */
    void CreateEntity(picojson::object& entityData, ICameraController& cameraController);
    
    /**
     * @brief Updates the simulation.  This may be called multiple times per frame.
     * @param dt the first argument
     */
    void Update(double dt);
    
    /**
     * @brief Called after all updating is done.  Entity should be returned to the UI.
     * @param returnValue the first argument
     */
    void FinishUpdate(picojson::object& returnValue);


	/**
     * @brief Receives JSON from the web server.
     * @param val the first argument
     */
    void receiveJSON(picojson::value& val);
    
    /**
     * @brief Handles specific commands from the web server.
     * @param cmd the first argument
     * @param data the second argument
     * @param returnValue the third argument
     */
    void ReceiveCommand(const std::string& cmd, picojson::object& data, picojson::object& returnValue);
    
    /**
     * @brief Handles the key up command.
     * @param key the first argument
     * @param keyCode the second argument
     */
    void KeyUp(const std::string& key, int keyCode);
    
    /**
     * @brief Handles the key down command.
     * @param key the first argument
     * @param keyCode the second argument
     */ 
    void KeyDown(const std::string& key, int keyCode);
    
    /**
     * @brief Returns whether or not a key is pressed at any time.
     * @param key the first argument
     */ 
    bool IsKeyDown(const std::string& key);
    
    /**
     * @brief Takes picture for a specific camera.
     * @param cameraId the first argument
     */ 
    void TakePicture(int cameraId);
    
    /**
     * @brief Adds camera observers to the application.
     * @param observer the first argument
     */ 
    void AddObserver(ICameraObserver& observer);
    
     /**
     * @brief Removes camera observers from the application.
     * @param observer the first argument
     */ 
    void RemoveObserver(ICameraObserver& observer);
    
    /**
     * @brief Method that handles asynchronous image processing that runs on a separate thread.
     */ 
    void ProcessImageQueue();
    

private:
    // Used for tracking time since last update
    std::chrono::time_point<std::chrono::system_clock> start;
    // Stores current state of key presses
    std::map<std::string,int> keyValue;
    // The total time the server has been running.
    double time;
    // Camera observers
    std::vector<ICameraObserver*> cameraObservers;
    // Image processing queue used for processing pictures that were taken
    std::queue<picojson::object> imageQueue;
    // Thread that handles asynchronous processing
    std::thread *imageProcessThread;
    // For synchronizing with the image queue
    std::mutex imageProcessMutex;
    // For synchronizing with the commands and update
    std::mutex updateMutex;
    // Condition variable that is used to notify thread of new images
    std::condition_variable imageProcessCond;
    // Stores whether the application is running or not.
    bool running;
    Simulation simulation;
};


#endif
