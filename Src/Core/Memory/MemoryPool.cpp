// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/6/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "MemoryPool.h"

// Core namespace
namespace Core {

    MemoryPool::MemoryPool(unsigned long long chunkSize, unsigned long long chunkNumber) :
        mChunkSize(chunkSize), mChunkNumber(chunkNumber), mMemory(nullptr), mIsFailed(false) {
        assert(this->mChunkSize >= 16);
        assert(this->mChunkNumber > = 1);
        // Get memory
        this->mMemory = malloc((this->mChunkSize * this->mChunkNumber);
        if(this->mMemory == nullptr) {
            this->mIsFailed = true;
        }
        // Create freelist
        unsigned long long *tmpPtr = static_cast<unsigned long long *>(this->mMemory);
        *tmpPtr = 0x00000000;
        this->mFreeList.insert(this->mChunkNumber, this->mMemory);
    }

    MemoryPool::~MemoryPool() {
        if(this->mIsFailed != true) {
            free(this->mMemory);
        }
    }

    void *MemoryPool::get(unsigned long long length) {
        
    }

    int MemoryPool::free(void *pointer) {

    }

}