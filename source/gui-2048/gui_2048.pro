QT += core gui widgets

CONFIG += c++11

# Uncomment the following line to make your code fail to compile if it uses deprecated APIs.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    core2048.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
target.path = /opt/$${TARGET}/bin
INSTALLS += target
