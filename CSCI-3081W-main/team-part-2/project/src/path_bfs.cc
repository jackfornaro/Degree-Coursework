#include "path_bfs.h"

PathBFS::PathBFS(long V): V(V){
  //Dummy node
  std::vector<long> temp0 {0};
  adj.push_back(std::make_pair(0, temp0));
}

void PathBFS::setGraph(std::vector<std::pair<long, std::vector<long>>> map) {
  adj.erase(adj.begin()+1, adj.end());
  for(auto& x : map) {
    adj.push_back(make_pair(x.first, x.second));
  }
}

std::vector<long> PathBFS::pathFind(long s) {
  std::vector<long> visit;
  std::vector<long> queue;
  std::vector<long> ret;
  visit.push_back(s);
  queue.push_back(s);

  bool found;
  int index;
  for (int i = 1; i < adj.size(); i++) {
    if (s == adj[i].first) {
      found = true;
      index = i;
    }
  }

  if (!found) {
    std::cout<< "Node don't exist for BFS" <<std::endl;
    return ret;
  }

  while (!queue.empty()) {
    s = queue.front();
    ret.push_back(s);
    queue.erase(queue.begin());
    for (int i = 1; i < adj.size(); i++) {
      if (s == adj[i].first) index = i;
    }
    for (int i = 0; i < (adj[index].second).size(); i++) {
      if (std::find(visit.begin(), visit.end(), (adj[index].second)[i]) == visit.end()) {
        visit.push_back((adj[index].second)[i]);
        queue.push_back((adj[index].second)[i]);
       }
    }
  }

  return ret;
}
