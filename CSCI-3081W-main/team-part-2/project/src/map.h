#ifndef MAP_H_
#define MAP_H_

#include "picojson.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class uses to extract the provided nodes.json and edges.json to set up the map
 */
class Map {
  std::vector<std::pair<std::string, std::vector<double>>> pos;
  std::vector<std::pair<std::string, std::vector<std::string>>> map;
public:
  /**
  * @brief To constructor of the class to initialize the local variables
  */
  Map(){
    std::ifstream nodes("edges.json");
    std::stringstream buf;
    buf << nodes.rdbuf();
    std::string json = buf.str();
    picojson::value v;
    std::string err = picojson::parse(v, json);
    if (!err.empty()) {
        std::cerr << err << std::endl;
    } else {
        printf("picojson parsed\n");
    }
    if (v.is<picojson::array>()) {
        picojson::array arr = v.get<picojson::array>();
        int prefix = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].is<picojson::object>()) {
                picojson::object o = arr[i].get<picojson::object>();
                for (picojson::object::const_iterator it = o.begin(); it != o.end(); it++) {
                    prefix++;
                    std::string node = it->first;
                    std::vector<std::string> neighbor;
                    std::string temp;
                    picojson::array arr = it->second.get<picojson::array>();
                    for(int i=0; i<arr.size(); i++){
                      temp = arr[i].serialize();
                      temp = temp.substr(1, temp.size() - 2);
                      neighbor.push_back(temp);
                    }
                    map.push_back(std::make_pair(node, neighbor));
                }
            } else {
                printf("array value is not a picojson::object\n");
            }
        }
    } else {
        printf("value is not an array\n");
    }
    //===========================
    std::ifstream nodes2("nodes.json");
    std::stringstream buf2;
    buf2 << nodes2.rdbuf();
    std::string json2 = buf2.str();
    picojson::value v2;
    std::string err2 = picojson::parse(v2, json2);
    if (!err2.empty()) {
        std::cerr << err2 << std::endl;
    } else {
        printf("picojson parsed\n");
    }

    if (v2.is<picojson::array>()) {
        picojson::array arr2 = v2.get<picojson::array>();
        int prefix = 0;
        for (int i = 0; i < arr2.size(); i++) {
            if (arr2[i].is<picojson::object>()) {
                picojson::object o2 = arr2[i].get<picojson::object>();
                for (picojson::object::const_iterator it2 = o2.begin(); it2 != o2.end(); it2++) {
                    prefix++;
                    std::string node2 = it2->first;
                    picojson::object temp = it2->second.get<picojson::object>();
                    picojson::object temp2 = temp.find("position")->second.get<picojson::object>();
                    double x = temp2.find("x")->second.get<double>();
                    double y = temp2.find("y")->second.get<double>();
                    double z = temp2.find("z")->second.get<double>();
                    //std::cout<<"temp: "<< node2 <<std::endl;
                    std::vector<double> xyz;
                    xyz.push_back(x);
                    xyz.push_back(y);
                    xyz.push_back(z);

                    //std::cout<< node2 << " :" << xyz[0] << " " << xyz[1] << " " << xyz[2] << std::endl;
                    pos.push_back(std::make_pair(node2, xyz));
                }
            } else {
                printf("array value is not a picojson::object\n");
            }
        }
    } else {
        printf("value is not an array\n");
    }


  }
  /**
  * @brief To get the map variable
  * @return the map variable
  */
  std::vector<std::pair<std::string, std::vector<std::string>>> getMap() {
    return this->map;
  }
  /**
  * @brief To get the pos variable
  * @return the pos variable
  */
  std::vector<std::pair<std::string, std::vector<double>>> getPos() {
    return this->pos;
  }

};
#endif
