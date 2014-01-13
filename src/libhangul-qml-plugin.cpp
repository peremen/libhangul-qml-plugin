#include "libhangul-qml-plugin.h"
#include "hangulic.h"

#include <qqml.h>

void LibhangulQmlPlugin::registerTypes(const char *uri)
{
    // @uri name.peremen.libhangul
    qmlRegisterType<HangulIC>(uri, 1, 0, "HangulInputContext");
}


