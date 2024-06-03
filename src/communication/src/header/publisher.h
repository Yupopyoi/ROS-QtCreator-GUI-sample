#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <QtWidgets/QApplication>

class Publisher : public rclcpp::Node
{
    public:
    explicit Publisher(const std::string &topic_name);

    private:
        std::shared_ptr<std_msgs::msg::String> message_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publish_;
        rclcpp::TimerBase::SharedPtr timer_;
    };

#endif // PUBLISHER_H
