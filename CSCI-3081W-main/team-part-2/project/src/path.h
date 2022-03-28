#ifndef PATH_H_
#define PATH_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <unordered_map>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for using DFS to find the search path
 */

class Path {
public:
  /**
   * @brief The class destructor
   */
  ~Path() {}
  /**
   * @brief The virtual function find path
   * @param The Starting node
   * @return A list of nodes to follow
   */
  virtual std::vector<long> pathFind(long s) = 0;
  /**
   * @brief The virtual to set up the map and store it in local variable
   * @param A map with neighbors
   */
  virtual void setGraph(std::vector<std::pair<long, std::vector<long>>> map) = 0;
};

#endif
