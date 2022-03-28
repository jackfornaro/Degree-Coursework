#include "gtest/gtest.h"

#include "context.h"
#include <vector>
class ContextTest : public ::testing::Test {
public:
  void SetUp( ) {
    //Context context(new PathBFS(6));
  }
protected:
};


//===================Integration Test for BFS============================
TEST_F(ContextTest, SetGraphForBFS) {
  Context context(new PathBFS(6));
  std::pair<std::string, std::vector<std::string>> temp1 ("1", {"2", "3"});
  std::vector<std::pair<std::string, std::vector<std::string>>> input_map {temp1};
  context.setGraph(input_map);
  std::pair<long, std::vector<long>> temp2 (1, {2, 3});
  std::vector<std::pair<long, std::vector<long>>> expected_output {temp2};
  EXPECT_EQ(context.getMap(), expected_output) << "BFS Map Variable Doesn't Match";
}

TEST_F(ContextTest, SetStartNodeForBFS) {
  Context context(new PathBFS(6));
  long temp = 61;
  context.setStartNode(temp);
  long expected_output = 61;
  EXPECT_EQ(context.getStartNode(), expected_output) << "BFS Start Node Doesn't Match";
}

TEST_F(ContextTest, setPosForBFS) {
  Context context(new PathBFS(6));
  std::pair<std::string, std::vector<double>> temp1 ("1", {2.0, 3.0});
  std::vector<std::pair<std::string, std::vector<double>>> input_map {temp1};
  context.setPos(input_map);
  std::pair<long, std::vector<double>> temp2 (1, {2.0, 3.0});
  std::vector<std::pair<long, std::vector<double>>> expected_output {temp2};
  EXPECT_EQ(context.getPos(), expected_output) << "BFS Pos Variable Doesn't Match";
}


//===================Integration Test for DFS============================

TEST_F(ContextTest, SetGraphForDFS) {
  Context context(new PathDFS(6));
  std::pair<std::string, std::vector<std::string>> temp1 ("1", {"2", "3"});
  std::vector<std::pair<std::string, std::vector<std::string>>> input_map {temp1};
  context.setGraph(input_map);
  std::pair<long, std::vector<long>> temp2 (1, {2, 3});
  std::vector<std::pair<long, std::vector<long>>> expected_output {temp2};
  EXPECT_EQ(context.getMap(), expected_output) << "BFS Map Variable Doesn't Match";
}

TEST_F(ContextTest, SetStartNodeForDFS) {
  Context context(new PathDFS(6));
  long temp = 61;
  context.setStartNode(temp);
  long expected_output = 61;
  EXPECT_EQ(context.getStartNode(), expected_output) << "BFS Start Node Doesn't Match";
}

TEST_F(ContextTest, setPosForDFS) {
  Context context(new PathDFS(6));
  std::pair<std::string, std::vector<double>> temp1 ("1", {2.0, 3.0});
  std::vector<std::pair<std::string, std::vector<double>>> input_map {temp1};
  context.setPos(input_map);
  std::pair<long, std::vector<double>> temp2 (1, {2.0, 3.0});
  std::vector<std::pair<long, std::vector<double>>> expected_output {temp2};
  EXPECT_EQ(context.getPos(), expected_output) << "BFS Pos Variable Doesn't Match";
}
