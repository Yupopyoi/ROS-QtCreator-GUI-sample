#include "mainwindow.h"

#include "publisher.h"
#include "subscriber.h"

#include <QtWidgets/QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    setvbuf(stdout, nullptr, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);

    std::shared_ptr<Publisher> publisher = nullptr;
    std::shared_ptr<Subscriber> subscriber = nullptr;
    std::shared_ptr<rclcpp::executors::MultiThreadedExecutor> executor = nullptr;

    executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();

    publisher = std::make_shared<Publisher>("chatter");

    subscriber = std::make_shared<Subscriber>("chatter");

    executor->add_node(publisher);
    executor->add_node(subscriber);

    std::thread executor_thread([executor](){executor->spin();});

    QApplication a(argc, argv);

    mainwindow mainWindow;
    mainWindow.show();

    QObject::connect(subscriber.get(), &Subscriber::logReceived, &mainWindow, &mainwindow::DisplaySubscription);

    return a.exec();
}
