#-------------------------------------------------
#
# Project created by QtCreator 2012-12-28T14:25:47
#
#-------------------------------------------------

TARGET = Charms
TEMPLATE = lib

DEFINES += CHARMS_LIBRARY

SOURCES += chartplane.cpp \
    chart.cpp \
    chartlegend.cpp

HEADERS += chartplane.h\
        Charms_global.h \
    chart.h \
    chartlegend.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
