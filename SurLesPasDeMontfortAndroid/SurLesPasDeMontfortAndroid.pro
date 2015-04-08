TEMPLATE = app

QT += qml quick widgets sql xml positioning

SOURCES += main.cpp \
    borne.cpp \
    site.cpp \
    basededonnees.cpp \
    foncteurs.cpp \
    gps.cpp \
    fenetre.cpp \
    question.cpp

RESOURCES += qml.qrc \
    audio.qrc \
    textes.qrc \
    data.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    borne.h \
    site.h \
    basededonnees.h \
    foncteurs.h \
    gps.h \
    fenetre.h \
    config.h \
    question.h

DISTFILES += \
    TextCalvaire.txt
