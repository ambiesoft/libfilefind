TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
# CONFIG -= qt
QT -= gui

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libfilefind/release/ -llibfilefind
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libfilefind/debug/ -llibfilefind
else:unix: LIBS += -L$$OUT_PWD/../libfilefind/ -llibfilefind

INCLUDEPATH += $$PWD/../libfilefind
DEPENDPATH += $$PWD/../libfilefind

HEADERS += \
    ../libfilefind/libfilefind.h
