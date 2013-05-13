#-------------------------------------------------
#
# Project created by QtCreator 2013-04-29T10:01:17
#
#-------------------------------------------------

QT       += core gui

TARGET = CW
TEMPLATE = app


SOURCES += main.cpp\
       mainwindow.cpp \
       obviousmethod.cpp \
       notobviousmethod.cpp \
    qfunc3d.cpp

HEADERS  += mainwindow.h \
        obviousmethod.h \
        notobviousmethod.h \
    qfunc3d.h

FORMS    += mainwindow.ui \
        obviousmethod.ui \
        notobviousmethod.ui
unix {
INCLUDEPATH += /usr/include/qwt-qt4\
            /usr/include/qwtplot3d-qt4\
            /usr/include/GL
LIBS += -L/usr/lib -lqwt-qt4\
        -L/usr/lib -lqwtplot3d-qt4\
        -L/usr/lib/i386-linux-gnu -lGLU
}

win32 {
LIBS += -LD:/QTSDK/mingw/lib -lglu32
LIBS += D:/QTSDK/Qwt-5.2.3/lib/libqwt5.a
LIBS += -LD:/QTSDK/qwtplot3d-0.2.7/lib -lqwtplot3d
INCLUDEPATH += D:/QTSDK/Qwt-5.2.3/include
INCLUDEPATH += D:/QTSDK/qwtplot3d-0.2.7/include
INCLUDEPATH += D:/QTSDK/mingw/include/GL
}
