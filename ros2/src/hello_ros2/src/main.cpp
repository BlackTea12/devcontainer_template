#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class HelloNode : public rclcpp::Node
{
public:
    HelloNode() : Node("hello_node")
    {
        publisher_ = create_publisher<std_msgs::msg::String>("hello", 10);
        timer_ = create_wall_timer(1s, [this]() {
            std_msgs::msg::String msg;
            msg.data = "Hello, ROS 2 Template! #" + std::to_string(count_++);
            RCLCPP_INFO(get_logger(), "Publishing: '%s'", msg.data.c_str());
            publisher_->publish(msg);
        });
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_ = 0;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HelloNode>());
    rclcpp::shutdown();
    return 0;
}
