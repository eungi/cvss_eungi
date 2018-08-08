#-------------------------------------------------
#
# Project created by QtCreator 2018-08-07T09:37:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt2DViewer
TEMPLATE = app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += ProjectPath=\\\"$$PWD\\\"

INCLUDEPATH += $$PWD

# set library path that was built by your hand
LIBRARY_ROOT=/home/eungi/mylib/deploy
# when use "#include", compiler searches INCLUDEPATH
INCLUDEPATH += $$LIBRARY_ROOT/opencv-3.4.1/include
# add library path to find *.so
LIBS += -L$$LIBRARY_ROOT/opencv-3.4.1/lib

# import opencv manually
LIBS += -lopencv_core   \
    -lopencv_imgproc    \
    -lopencv_highgui    \
    -lopencv_imgcodecs

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Modules/glvertexmanager.cpp \
    Modules/glwidget.cpp

HEADERS += \
        mainwindow.h \
    Modules/glvertexmanager.h \
    Modules/glwidget.h \
    Modules/pose6dof.h \
    Modules/project_common.h \
    Modules/car.h \
    Modules/pose6dofqt.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    Modules/fragment.frag \
    Modules/vertex.vert
