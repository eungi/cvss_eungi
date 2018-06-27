#include "cvqtapp.h"
#include "ui_cvqtapp.h"

#include <QDebug>
#include <QFileDialog>

/*#include <vector>*/

CVQTApp::CVQTApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CVQTApp)
{
    ui->setupUi(this);
    defaultPath = QString(PRJ_PATH) + "/../images";
    //qDebug() << defaultPath;

    /*std::vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    for(int i=0;i<myVec.size();i++)
        qDebug() << "vec :" << myVec[i];*/
}

CVQTApp::~CVQTApp()
{
    delete ui;
}

void CVQTApp::on_pushButton_openimage_clicked()
{
    //qDebug() << "hello world\n";

    QString caption = "Open image";
    QString pattern = "Images (*.png *.xpm *.jpg)";

    QString fileName = QFileDialog::getOpenFileName(this, caption, defaultPath, pattern);

    image = cv::imread(fileName.toStdString());
    cv::imshow("image", image);
}

void CVQTApp::on_pushButton_writeimage_clicked()
{
    if(image.empty()) {
        qDebug() << "image is empty";
        return;
    }

    QString name = ui->lineEdit_writeimage->text();
    if(name.isEmpty()) {
        qDebug() << "save name is empty";
        return;
    }

    cv::Vec3b white(255,255,255);
    for(int y=0; y<image.rows; y++){
        for(int x=0; x<image.cols; x++) {
            /*cv::Vec3b pixel = image.at<cv::Vec3b>(y,x);
            uchar blue = pixel(0);
            uchar green = pixel(1);
            uchar red = pixel(2);
            qDebug() << "red :" << red << "\tgreen :" << green << "\tblue :" << blue;*/

            image.at<cv::Vec3b>(y,x) = white - image.at<cv::Vec3b>(y,x);
        }
    }

    cv::imshow("image", image);
    QString filename = defaultPath + "/" + name + ".jpg";
    cv::imwrite(filename.toStdString(), image);
}
