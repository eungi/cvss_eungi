#ifndef WEEK2_H
#define WEEK2_H

#include <QMainWindow>

namespace Ui {
class week2;
}

class week2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit week2(QWidget *parent = 0);
    ~week2();

private:
    Ui::week2 *ui;
};

#endif // WEEK2_H
