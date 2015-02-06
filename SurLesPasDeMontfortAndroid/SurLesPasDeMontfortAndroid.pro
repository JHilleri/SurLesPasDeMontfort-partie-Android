TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    ressourcemultimedia.cpp \
    borne.cpp \
    site.cpp \
    basededonnees.cpp \
    fenetresite.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ressourcemultimedia.h \
    borne.h \
    site.h \
    basededonnees.h \
    fenetresite.h
