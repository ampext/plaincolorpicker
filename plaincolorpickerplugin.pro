CONFIG += plugin
TEMPLATE = lib
QT += widgets designer
QMAKE_CXXFLAGS += -std=c++0x

TARGET = $$qtLibraryTarget($$TARGET)
TEMPLATE = lib

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

HEADERS = src/plaincolorpicker.h src/plaincolorpickerplugin.h
SOURCES = src/plaincolorpicker.cpp src/plaincolorpickerplugin.cpp
RESOURCES = plaincolorpicker.qrc
OTHER_FILES = plaincolorpicker.json