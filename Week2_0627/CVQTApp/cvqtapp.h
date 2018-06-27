#ifndef CVQTAPP_H
#define CVQTAPP_H

#include <QMainWindow>
#include <QString>
#include <opencv2/opencv.hpp>

namespace Ui {
class CVQTApp;
}

class CVQTApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit CVQTApp(QWidget *parent = 0);
    ~CVQTApp();

private slots:
    void on_pushButton_openimage_clicked();
    void on_pushButton_writeimage_clicked();

private:
    QString defaultPath;
    Ui::CVQTApp *ui;
    cv::Mat image;      //  opencv matrix
    cv::Mat createImage(const QString& paramString);
};

#endif // CVQTAPP_H
