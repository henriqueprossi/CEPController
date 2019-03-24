QT -= gui
QT += network xml sql
CONFIG += c++11 console
CONFIG -= app_bundle
DEFINES += QT_DEPRECATED_WARNINGS

unix {
    INCLUDEPATH += /usr/lib
    debug {
        LIBS += -L/usr/lib -lCPPWebFrameworkd
    }
    release {
        LIBS += -L/usr/lib -lCPPWebFramework
    }
}

macx {
    INCLUDEPATH += /usr/local/lib
    debug {
        LIBS += -L/usr/local/lib -lCPPWebFrameworkd
    }
    release {
        LIBS += -L/usr/local/lib -lCPPWebFramework
    }
}

win32 {
    INCLUDEPATH += C:/
    debug {
        LIBS += -LC:/cwf -lCPPWebFrameworkd
    }
    release {
        LIBS += -LC:/cwf -lCPPWebFramework
    }
}

SOURCES += main.cpp

DISTFILES += \
    server/config/ssl/cert.pem \
    server/config/ssl/key.pem \
    server/config/cppwebserverpages/resources/images/logo.png \
    server/config/cppwebserverpages/resources/images/favicon.ico \
    server/config/cppwebserverpages/resources/css/cppweb.css \
    server/config/cppwebserverpages/403.view \
    server/config/cppwebserverpages/404.view \
    server/config/cppwebserverpages/index.view \
    server/config/CPPWeb.ini \
    server/config/log/CPPWebServer.log \
    server/pages/hello.html \
    server/pages/cliente.view \
    server/pages/erro.html \
    server/pages/clienteedit.view \
    server/config/ssl/cert.pem \
    server/config/ssl/key.pem \
    server/config/cppwebserverpages/resources/images/logo.png \
    server/config/cppwebserverpages/resources/images/favicon.ico \
    server/config/cppwebserverpages/resources/css/cppweb.css \
    server/config/cppwebserverpages/403.view \
    server/config/cppwebserverpages/404.view \
    server/config/cppwebserverpages/index.view \
    server/config/CPPWeb.ini \
    server/config/log/CPPWebServer.log

HEADERS +=
