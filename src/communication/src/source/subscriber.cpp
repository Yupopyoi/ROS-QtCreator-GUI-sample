#include "subscriber.h"

Subscriber::Subscriber(const std::string &topic_name) : Node("subscriber")
{
    auto callback =
        [this](const std_msgs::msg::String::SharedPtr message) -> void
    {
        RCLCPP_INFO(this->get_logger(),"%s", message->data.c_str());
        emit logReceived(QString::fromStdString(message->data));
    };

    subscription_ = create_subscription<std_msgs::msg::String>(topic_name, 10, callback);
};

