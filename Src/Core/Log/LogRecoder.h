// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/6/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Global.h"
#include <QThread>

// Core namespace
namespace Core {

    class RF_API LogRecorder : private QThread {
    public:
        
    
    protected:
        virtual void run() override {

        }
    }

}