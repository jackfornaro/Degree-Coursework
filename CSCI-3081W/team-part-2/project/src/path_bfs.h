#ifndef PATH_BFS_H_
#define PATH_BFS_H_

#include <iostream>
#include "path.h"
#include <algorithm>
#include <tuple>
#include <unordered_map>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for using BFS to find the search path
 */
class PathBFS : public Path {
  long V;//vertices
  std::vector<std::pair<long, std::vector<long>>> adj;
public:
  /**
  * @brief Contructor that initialize the vertices variable
  * @param the long number
  */
  PathBFS(long V);
  /**
  * @brief The class destructor
  */
  ~PathBFS() {}
  /**
  * @brief The function that is used to set up the adj variable
  * @param A vector of pairs, where first is the node, and second is the vector of neighbors
  */
  void setGraph(std::vector<std::pair<long, std::vector<long>>> map);
  /**
  * @brief The function that is used to find the bfs path of our map
  * @param A long num that is the starting node
  * @return A list of nodes for the drone to travel to
  */
  std::vector<long> pathFind(long s);
  /**
  * @brief The function that is used to get the V variable
  * @return The V variable
  */
  long getNode() { return V; }
  /**
  * @brief The function that is used to get the adj variable
  * @return The adj variable
  */
  std::vector<std::pair<long, std::vector<long>>> getAdj() {
    adj.erase(adj.begin(), adj.begin()+1);
    return adj;
  }
};

#endif
