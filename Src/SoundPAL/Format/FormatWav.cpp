// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/5/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "FormatWav.h"

// SoundPAL namespace
namespace SoundPAL {

    void FormatWav::parse(const QByteArray &byteArr) {
        // Chunk of wav
        RIFFChunk riff;
        FMTChunk fmt;
        DataChunk data;
        // Find chunk
        for(int i = 0; i < byteArr.length(); ++i) {
            if(i + 3 >= byteArr.length()) {
                break;
            }
            Core::int32 token = byteArr[i] | (byteArr[i + 1] << 8) | (byteArr[i + 2] << 16) | (byteArr[i + 3] << 24);
            switch(token) {
            // RIFF token
            case 0x46464952:
                riff.ChunkSize = 
            }
        }
    }

}