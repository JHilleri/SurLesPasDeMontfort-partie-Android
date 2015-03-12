TEMPLATE = app

QT += qml quick widgets sql xml

SOURCES += main.cpp \
    borne.cpp \
    site.cpp \
    basededonnees.cpp \
    fenetresite.cpp \
    foncteurs.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    borne.h \
    site.h \
    basededonnees.h \
    fenetresite.h \
    foncteurs.h

DISTFILES += \
    TextCalvaire.txt
