//Referenced code from refactoring.guru and from lecture
#include <iostream>
#include <fstream>

class Logger {
protected:
  Logger(const std::string value): value_(value) {}
  static Logger* logger_;
  std::string value_;

public:
  static Logger *GetInstance(const std::string& value) {
    if(logger_==nullptr){
      logger_ = new Logger(value);
    }
    return logger_;
  }

  void WriteToCSV(const std::string& data) {
    std::ofstream myfile;
    myfile.open("data.csv");
    myfile << data << endl;
    myfile.close();
  }

  void WriteToTerminal(const std::string& data) {
    std::cout << data << endl;
  }
};
