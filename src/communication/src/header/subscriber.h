#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <QObject>
#include <QtWidgets/QApplication>

class Subscriber : public QObject, public rclcpp::Node
{
    Q_OBJECT

    public:
        explicit Subscriber(const std::string &topic_name);

    signals:
        void logReceived(const QString &log);

    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif // SUBSCRIBER_H
