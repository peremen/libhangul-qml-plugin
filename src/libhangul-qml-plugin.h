#ifndef LIBHANGUL_QML_PLUGIN_H
#define LIBHANGUL_QML_PLUGIN_H

#include <QQmlExtensionPlugin>

class LibhangulQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // LIBHANGUL_QML_PLUGIN_H

