#include "gtest/gtest.h"

#include "path_bfs.h"
#include <vector>
class PathBFSTest : public ::testing::Test {
public:
  void SetUp( ) {
    //Context context(new PathBFS(6));
  }
protected:
};

//===================UNIT TEST FOR BFS===========================
TEST_F(PathBFSTest, getMap) {
  PathBFS path(6);
  long expected_output = 6;
  EXPECT_EQ(path.getNode(), expected_output) << "BFS Map Variable Doesn't Match";
}

TEST_F(PathBFSTest, getAdj) {
  PathBFS path(6);
  std::pair<long, std::vector<long>> temp (1, {2, 3});
  std::vector<std::pair<long, std::vector<long>>> input_map {temp};
  path.setGraph(input_map);

  std::pair<long, std::vector<long>> temp2 (1, {2, 3});
  std::vector<std::pair<long, std::vector<long>>> expected_output { temp2 };

  std::vector<std::pair<long, std::vector<long>>> input = path.getAdj();

  EXPECT_EQ(input, expected_output) << "BFS Adj Variable Doesn't Match";
}
