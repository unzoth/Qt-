QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    departmentedit.cpp \
    departmentview.cpp \
    doctoredit.cpp \
    doctorview.cpp \
    idatabase.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    patientedit.cpp \
    patientview.cpp \
    recordedit.cpp \
    recordview.cpp \
    welcomeview.cpp

HEADERS += \
    departmentedit.h \
    departmentview.h \
    doctoredit.h \
    doctorview.h \
    idatabase.h \
    loginview.h \
    masterview.h \
    patientedit.h \
    patientview.h \
    recordedit.h \
    recordview.h \
    welcomeview.h

FORMS += \
    departmentedit.ui \
    departmentview.ui \
    doctoredit.ui \
    doctorview.ui \
    loginview.ui \
    masterview.ui \
    patientedit.ui \
    patientview.ui \
    recordedit.ui \
    recordview.ui \
    welcomeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
