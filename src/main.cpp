
#include "snorenotify.h"

#include <QtGui/QApplication>

#if HAVE_KDE
#include "core/version.h"
#include <KAboutData>
#include <KCmdLineArgs>
#include <KUniqueApplication>
#endif

int main ( int argc, char *argv[] )
{

#if HAVE_KDE
    KAboutData about("SnoreNotify",0,ki18n("SnoreNotify"),Snore::Version::version().toLatin1(),
                     ki18n("A notification deamon."),KAboutData::License_GPL_V2, ki18n("Copyright (c) 2010-2013 Patrick von Reth <vonreth@kde.org>"));
    KCmdLineArgs::init(argc, argv, &about);
    KUniqueApplication app;
#else
    QApplication app ( argc, argv );
#endif

    SnoreNotify sn;
    return app.exec();
}

