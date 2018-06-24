// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/6/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Global.h"
#include <QMap>
#include <assert.h>
#include <malloc.h>

// Core namespace
namespace Core {

    class RF_API MemoryPool {
    public:
        MemoryPool(unsigned long long chunkSize, unsigned long long chunkNumber);
        MemoryPool(const MemoryPool &other) = delete;
        MemoryPool(MemoryPool &&other) = delete;
        MemoryPool &operator=(const MemoryPool &other) = delete;
        MemoryPool &operator=(MemoryPool &&other) = delete;
        ~MemoryPool();

    public:
        void *get(unsigned long long length);
        int free(void *pointer);

    private:
        struct BinaryNode {
            void *mLeftNode;
            void *mRightNode;
        };
        struct Span {
            Span *mLastSpan;
            Span *mNextSpan;
            unsigned long long mSpanLenght;
            bool mIsUsed;
        }
    
    private:
        unsigned long long mChunkSize;
        unsigned long long mChunkNumber;
        void *mMemory;
        bool mIsFailed;
        QMap<unsigned long long, void *> mFreeList;
        BinaryNode mRadixTree;
        Span mSpanList;
    };

}