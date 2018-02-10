#ifndef TAPSELL_H
#define TAPSELL_H

#ifdef Q_OS_ANDROID
#include "tapsellAndroid.h"
#endif

#ifdef Q_OS_IOS
#include "tapsellios.h"
#endif

#include "tapsellIos.h"

#endif // TAPSELL_H
