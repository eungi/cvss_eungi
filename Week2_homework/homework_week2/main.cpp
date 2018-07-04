#include "week2.h"
#include <QApplication>
#include <QDateTime>
#include <QDebug>

#include <iostream>
#include <string>

#define UTC_TIME_ASIA_SEOUL    (9 * 60 * 60)   // 9h

using namespace std;

class Sensor {
public :
    Sensor(const std::string _name) {
        name = _name;
        qDebug() << QString::fromUtf8(name.c_str()) << "was created!\n";
    }

    void Data_Update() {
        qDebug() << "================================\n";
        qDebug() << QString::fromUtf8(name.c_str()) << "update\n";
        time_stamp = QDateTime::currentDateTimeUtc();
        time_stamp = time_stamp.addSecs( UTC_TIME_ASIA_SEOUL );\
        qDebug() << time_stamp << "\n";
        qDebug() << "================================\n";
    }

private :
    std::string name;
    QDateTime time_stamp;
};

class Camera : public Sensor {
public :
    Camera() : Sensor("Camera") {}
};

class LiDAR : public Sensor {
public :
    LiDAR() : Sensor("LiDAR") {}
};

int main()
{
    Camera left_camera;
    left_camera.Data_Update();

    Camera right_camera;
    right_camera.Data_Update();
    left_camera.Data_Update();

    LiDAR lidar1;
    lidar1.Data_Update();
    left_camera.Data_Update();

    return 0;
}
