// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/6/24 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Global.h"
#include <QQueue>
#include <QReadWriteLock>

// Core namespace
namespace Core {

    template <class T>
    class RF_API_TEMPLATE SafeQueue {
    public:
        SafeQueue() = default;
        SafeQueue(const SafeQueue &other) = delete;
        SafeQueue(SafeQueue &&other) = delete;
        SafeQueue &operator=(const SafeQueue &other) = delete;
        SafeQueue &operator=(SafeQueue &&other) = delete;
        ~SafeQueue() = default;

    public:
        void push(const T &value) {
            this->mRWLock.lockForWrite();
            this->mQueue.enqueue(value);
            this->mRWLock.unlock();
        }
        T pop() {
            this->mRWLock.lockForWrite();
            auto tmpObj = this->mQueue.dequeue();
            this->mRWLock.unlock();
            return tmpObj;
        }
        T &front() {
            this->mRWLock.lockForRead();
            auto tmpObj = this->mQueue.head();
            this->mRWLock.unlock();
            return tmpObj;
        }
        const T &front() const {
            this->mRWLock.lockForRead();
            auto tmpObj = this->mQueue.head();
            this->mRWLock.unlock();
            return tmpObj;
        }
        T &back() {
            this->mRWLock.lockForRead();
            auto tmpObj = this->mQueue.back();
            this->mRWLock.unlock();
            return tmpObj;
        }
        const T &back() const {
            this->mRWLock.lockForRead();
            auto tmpObj = this->mQueue.back();
            this->mRWLock.unlock();
            return tmpObj;
        }
        bool isEmpty() const {
            this->mRWLock.lockForRead();
            bool result = this->mQueue.empty();
            this->mRWLock.unlock();
            return result;
        }
        uint32 size() const {
            this->mRWLock.lockForRead();
            uint32 result = this->mQueue.size();
            this->mRWLock.unlock();
            return result;
        }

    private:
        QQueue<T> mQueue;
        QReadWriteLock mRWLock;
    };

}