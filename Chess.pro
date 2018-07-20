TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    chessboard.cpp \
    chessfunctions.cpp

HEADERS += \
    chessboard.h \
    chessfunctions.h \
    movetemplate.h
