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
#include "Format.h"
#include <QByteArray>

// SoundPAL namespace
namespace SoundPAL {

    class RF_API FormatWav : public Format {
    public:
        FormatWav(const QByteArray &byteArr);
        virtual ~FormatWav();

    public:
        virtual Core::int32 getBufferSize() override;

    private:
        void parse(const QByteArray &byteArr);

    private:
        struct RIFFChunk {
            Core::int32 ChunkSize;
            Core::int32 Format;
        };
        struct FMTChunk {
            Core::int32 ChunkSize;
            Core::int16 AudioFormat;
            Core::int16 NumChannels;
            Core::int32 SimpleRate;
            Core::int32 ByteRate;
            Core::int16 BlockAlign;
            Core::int16 BitsPerSamplt;
        };
        struct DataChunk {
            Core::int32 ChunkSize;
            void *PointorOfData;
        };
        enum Token {
            RIFF = 0x46464952,       // FFIR
            fmt = 0x20746D66,        // tmf
            data = 0x61746164        // data
        };
    };

}