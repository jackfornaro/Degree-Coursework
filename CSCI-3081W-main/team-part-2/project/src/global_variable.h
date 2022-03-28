#ifndef GLOBAL_VARIABLE_H_
#define GLOBAL_VARIABLE_H_


#include "path_bfs.h"
#include "path.h"
#include "map.h"
#include "context.h"
#include <map>
#include <string>
#include "vector3.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class uses a singleton structor to create global variables can be uses across different classes
 */
class PathFollow {
public:
    /**
	* @brief The constructor is used to set up the variables in this class
	*/
  PathFollow() {
    Map map;
    Context context(new PathBFS(6));
    context.setGraph(map.getMap());
    context.setStartNode(7554302660);
    setPath(context.doPathFinding());
    pos = setPos2(map.getPos());
  }

  std::vector<long> path;
  std::vector<std::pair<long, std::vector<double>>> pos;
  int currentNode = 0;
  std::vector<double> robot_found_pos {0, 0 , 0};
  /**
  * @brief To set up the singleton instance
  */
  static PathFollow* Instance() {
    if(!pathfollow){
       pathfollow = new PathFollow();
    }
    return pathfollow;
  }
  /**
  * @brief To set up the path variable
  * @param the path vector
  */
  void setPath(std::vector<long> path) {
    for(auto& x : path) {
      this->path.push_back(x);
    }
  }
  /**
  * @brief To set up the position of the pos local variables
  * @param the pos vector
  * @return the vector with a list of coordinates and the nodes
  */
  std::vector<std::pair<long, std::vector<double>>> setPos2(std::vector<std::pair<std::string, std::vector<double>>> pos) {
    long temp1;
    std::vector<std::pair<long, std::vector<double>>> ret;
    for(auto& x : pos) {
      temp1 = stol(x.first);
      std::vector<double> temp2;
      for(auto& y: x.second) {
        temp2.push_back(y);
      }
      ret.push_back(make_pair(temp1, temp2));
    }
    return ret;
  }
  /**
  * @brief To set up the position for the pos local variable
  * @param the pos vector
  */
  void setPos(std::vector<std::pair<std::string, std::vector<double>>> pos) {
    long temp1;
    for(auto& x : pos) {
      temp1 = stol(x.first);
      std::vector<double> temp2;
      for(auto& y: x.second) {
        temp2.push_back(y);
      }
      this->pos.push_back(make_pair(temp1, temp2));
    }
  }
  /**
  * @brief To get the position for the pos local variable
  * @param the starting node
  */
  std::vector<double> getPos(int currentNode) {
    std::vector<double> ret;
    for(auto& x : this->pos) {
      if (path[currentNode] == x.first) {
        for(auto& y: x.second) {
            ret.push_back(y);
        }
      }
    }

    return ret;
  }

protected:
  static PathFollow *pathfollow;


};

PathFollow *PathFollow::pathfollow = 0;

#endif
