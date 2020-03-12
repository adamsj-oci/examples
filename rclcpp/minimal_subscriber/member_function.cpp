// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>
#include <chrono>
#include <fstream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
std::fstream myfile;
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {                    
     myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", enter minimal_subscriber"
                            << "\n";
                     myfile.close();
                                          myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", enter create_subscription"
                            << "\n";
                     myfile.close();
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
                           myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", exit create_subscription"
                            << "\n";
                     myfile.close();
                          myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", exit minimal_subscriber"
                            << "\n";
                     myfile.close();
  }

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
         myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", enter topic_callback"
                            << "\n";
                     myfile.close();
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
         myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", exit topic_callback"
                            << "\n";
                     myfile.close();
  }
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
       myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", enter init"
                            << "\n";
                     myfile.close();
  rclcpp::init(argc, argv);
       myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", exit init"
                            << "\n";
                     myfile.close();
                          myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", enter spin"
                            << "\n";
                     myfile.close();
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
       myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", exit spin"
                            << "\n";
                     myfile.close();
                          myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", enter shutdown"
                            << "\n";
                     myfile.close();
  rclcpp::shutdown();
       myfile.open("sub_call_order.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                     myfile << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << ", exit shutdown"
                            << "\n";
                     myfile.close();
  return 0;
}
