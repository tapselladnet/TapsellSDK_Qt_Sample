#ifndef TAPSELL_H
#define TAPSELL_H

#ifdef Q_OS_ANDROID
#include "tapsellAndroid.h"
#endif

#ifdef Q_OS_IOS
#include "tapsellios.h"
#endif

#endif // TAPSELL_H
