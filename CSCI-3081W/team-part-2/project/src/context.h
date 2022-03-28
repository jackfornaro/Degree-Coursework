#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <vector>
#include "path.h"
#include "path_bfs.h"
#include "path_dfs.h"
#include <string>
#include <typeinfo>
//https://www.sourcecodeexamples.net/2020/09/c-strategy-pattern-example.html
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The context class use strategy pattern for drone movement
 */
class Context {
  Path *path;
  long s_node;
  std::vector<std::pair<long, std::vector<long>>> map;
  std::vector<std::pair<long, std::vector<double>>> pos;
public:
  /**
  * @brief Constructor for the context class to initialize the path object
  * @param A path object
  * @return It returns an object of this class.
  */
  Context(Path* const path) : path(path) {}

  /**
  * @brief Destructor for the Context class
  */
  ~Context() { delete this -> path; }

  /**
  * @brief To reset the path of the finding object
  * @param A path object
  */
  void setPathFind(Path *path) {
    delete this->path;
    this->path = path;
  }

  /**
  * @brief To get the start node
  * @return It returns the start node
  */
  int getStartNode() {
    return s_node;
  }

  /**
  * @brief To set the start node
  * @param A strat node
  */
  void setStartNode(long s_node) {
    this->s_node = s_node;
  }

  /**
  * @brief To call the path finding algorithm in path class to generate a path
  * @return It returns a list of nodes to travel to
  */
  std::vector<long> doPathFinding() const {
    std::vector<long> result = this->path->pathFind(s_node);
    return result;
  }

  /**
  * @brief To set up the graph for the local map variable
  * @param It takes in a vector of pair, where first is the node and second is its neighbors
  */
  void setGraph(std::vector<std::pair<std::string, std::vector<std::string>>> map) {
    long temp1;
    for(auto& x : map) {
      std::vector<long> temp2;
      temp1 = stol(x.first);
      for(auto& y: x.second) {
        temp2.push_back(stol(y));
      }
      this->map.push_back(make_pair(temp1, temp2));
    }
    this->path->setGraph(this->map);
    //this->path->printTest();
  }

  /**
  * @brief To set up the graph for the local pos variable
  * @param It takes in a vector of pair, where first is the node and second is its coordinates
  */
  void setPos(std::vector<std::pair<std::string, std::vector<double>>> xyz) {
    long temp1;
    for(auto& x : xyz) {
      std::vector<double> temp2;
      temp1 = stol(x.first);
      for(auto& y: x.second) {
        temp2.push_back(y);
      }
      this->pos.push_back(make_pair(temp1, temp2));
    }

  }

  /**
  * @brief To get the coordinates of a node
  * @param A node
  * @return The x, y, z coordinates of the node in a vector<double>
  */
  std::vector<double> getPosOfNode(long node) {
    std::vector<double> temp;
    for(auto& x : pos) {
      if (x.first == node) {
        std::vector<double> temp;
        for(auto& y: x.second) {
          temp.push_back(y);
        }

      }
    }
    return temp;
  }

  /**
  * @brief To get the vector map
  * @return The list of node and its neighbors in a vector of pairs
  */
  std::vector<std::pair<long, std::vector<long>>> getMap() {
    return this->map;
  }

  /**
  * @brief To get the vector pos
  * @return The list of node and its coordinates in a vector of pairs
  */
  std::vector<std::pair<long, std::vector<double>>> getPos() {
    return this->pos;
  }

};

#endif
