TEMPLATE = app
TARGET = player

CONFIG += qt debug

QMAKE_CXXFLAGS += -std=c++0x `pkg-config --cflags libzmq Qt5GStreamer-1.0 Qt5GStreamerUi-1.0` -Wno-unu
sed-parameter
QMAKE_LIBS += `pkg-config --libs libzmq Qt5GStreamer-1.0 Qt5GStreamerUi-1.0`

HEADERS = mediaapp.h  player.h

SOURCES = main.cpp  mediaapp.cpp  player.cpp



target.path = .
INSTALLS += target

QT += widgets
QT += webenginewidgets
