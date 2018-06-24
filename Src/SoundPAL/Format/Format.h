// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/5/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Global.h"
#include "../../Core/Math/Scalar.h"
#include <QByteArray>

// SoundPAL namespace
namespace SoundPAL {

    class RF_API Format {
    public:
        Format(const QByteArray &byteArr) = 0;
        virtual ~Format() = 0;

    public:
        virtual Core::int32 getBufferSize() = 0;
    };

}