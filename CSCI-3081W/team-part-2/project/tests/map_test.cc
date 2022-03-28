#include "gtest/gtest.h"

#include "map.h"
#include <vector>
class MapTest : public ::testing::Test {
public:
  void SetUp( ) {
    //Context context(new PathBFS(6));
  }
protected:
};


//===================UNIT TEST FOR MAP===========================
TEST_F(MapTest, getMap) {
  Map map;
  std::vector<std::pair<std::string, std::vector<std::string>>> temp = map.getMap();
  std::vector<std::pair<std::string, std::vector<std::string>>> temp2;
  ASSERT_NE(temp, temp2) << "NULL Map";
}

TEST_F(MapTest, getPos) {
  Map map;
  std::vector<std::pair<std::string, std::vector<double>>> temp = map.getPos();
  std::vector<std::pair<std::string, std::vector<double>>> temp2;
  ASSERT_NE(temp, temp2) << "NULL Pos";
}
