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

#include "../Global/Token.h"
#include "../../Core/Math/Scalar.h"
#include "../../Core/String/String.h"

// SoundPAL namespace
namespace SoundPAL {

    class RF_API Format {
    public:
        Format(const Core::String &byteArr) {
            Core::String tmp = byteArr;
            tmp.contains("23333");
        }
        virtual ~Format() = 0;

    public:
        virtual Core::int32 getBufferSize() = 0;
    };

}