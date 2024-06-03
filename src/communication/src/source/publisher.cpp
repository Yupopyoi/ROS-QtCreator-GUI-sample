#include "publisher.h"

Publisher::Publisher(const std::string &topic_name) : Node("publisher")
{
    message_ = std::make_shared<std_msgs::msg::String>();

    auto publish_Message =
        [this]() -> void
    {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::string time_str = std::ctime(&now_c);
        message_->data = time_str;

        //RCLCPP_INFO(this->get_logger(),"%s", message_->data.c_str());
        publish_->publish(*message_);
    };

    publish_ = create_publisher<std_msgs::msg::String>(topic_name, 10);
    timer_ = create_wall_timer(std::chrono::milliseconds(100), publish_Message);
}
