#include "path_dfs.h"


PathDFS::PathDFS(long V): V(V) {
  std::vector<long> temp0 {0};
  adj.push_back(std::make_pair(0, temp0));
}

void PathDFS::setGraph(std::vector<std::pair<long, std::vector<long>>> map) {
  adj.erase(adj.begin()+1, adj.end());
  //visited.erase(visited.begin(), visited.end());
  for(auto& x : map) {
    adj.push_back(make_pair(x.first, x.second));
  }
}

std::vector<long> PathDFS::pathFind(long s) {
  visited.push_back(s);
  int index = 0;
  for (int i = 1; i < adj.size(); i++) {
    if (s == adj[i].first) {
      index = i;
    }
  }

  for (int i = 0; i < (adj[index].second).size(); i++) {
    if (std::find(visited.begin(), visited.end(), (adj[index].second)[i]) == visited.end()) {
      ret.push_back((adj[index].second)[i]);
      visited.push_back((adj[index].second)[i]);
      pathFind((adj[index].second)[i]);
     }
  }
  return ret;
}
