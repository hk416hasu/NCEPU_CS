#include <iostream>
#include <string>
#include "json.hpp"

int main() {
  // 定义变量
  std::string message = "Success";
  std::string uID = "1000001";
  std::string username = "李燃";
  std::string authority_num = "";

  // 构造 JSON 对象
  nlohmann::json output = {
    {"message", message},
    {"uID", uID},
    {"username", username},
    {"authority_num", authority_num}
  };

  // 输出 JSON 对象
  std::cout << output << std::endl;
  return 0;
}

