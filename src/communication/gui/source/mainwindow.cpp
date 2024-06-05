#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("ROS2_With_Qt");
    ui = std::make_unique<Ui::MainWindow>();
    ui->setupUi(this);

    label = ui->subscribedText;
}

void mainwindow::DisplaySubscription(const QString &log)
{
    label->setText(log);
}

/*
 *
 *     setWindowTitle("ROS2_With_Qt");
    ui = std::make_unique<Ui::mainwindow>();
    ui->setupUi(this);

    executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();

    publisher = std::make_shared<Publisher>("chatter");

    subscriber = std::make_shared<Subscriber>("chatter");

    executor->add_node(publisher);
    executor->add_node(subscriber);

    executor->spin();
*/
