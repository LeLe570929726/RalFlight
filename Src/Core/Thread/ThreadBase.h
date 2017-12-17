// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2017 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/2 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_THREADBASE_H
#define RALFLIGHT_SRC_CORE_THREAD_THREADBASE_H

#include "../Global/Macro.h"
#include <tuple>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <Windows.h>
#elif defined(RALFLIGHT_SYSTEM_LINUX) || defined(RALFLIGHT_SYSTEM_MAC)
	#include <pthread.h>
#endif

// Core namespace
namespace Core {

	template <class F, class... FP>
	class RALFLIGHT_API ThreadBase {
	public:
		ThreadBase(F func, FP... para) :
			mFunc(func), mPara(std::tuple<FP...>(para...)) {
		}
		ThreadBase(const ThreadBase &other) = delete;
		ThreadBase &operator=(const ThreadBase &other) = delete;
		~ThreadBase() = default;

	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		static DWORD doRun(LPVOID para) {
			auto objPara = dynamic_cast<ThreadBase<F, FP...> *>(para);
			DoRun<std::tuple_size<decltype(objPara->mPara)>::value - 1>::run(objPara->mFunc, objPara->mPara);
			return 0;
		}
#elif defined(RALFLIGHT_SYSTEM_LINUX) || defined(RALFLIGHT_SYSTEM_MAC)
		static void *doRun(void *para) {
			auto objPara = dynamic_cast<ThreadBase<F, FP...> *>(para);
			DoRun<std::tuple_size<decltype(objPara->mPara)>::value - 1>::run(objPara->mFunc, objPara->mPara);
			return nullptr;
		}
#endif

	private:
		template <int S, class... Args>
		struct DoRun;
		template <int S, class... Args>
		struct DoRun<S, Args...> {
			static inline void run(F func, std::tuple<FP...> tupl, Args... args) {
				DoRun<S - 1, std::tuple_element<S, decltype(tupl)>::type, Args...>::run(func, tupl, std::get<S>(tupl), args...);
			}
		};
		template <int S>
		struct DoRun<S> {
			static inline void run(F func, std::tuple<FP...> tupl) {
				DoRun<S - 1, std::tuple_element<S, decltype(tupl)>::type>::run(func, tupl, std::get<S>(tupl));
			}
		};
		template <class... Args>
		struct DoRun<0, Args...> {
			static inline void run(F func, std::tuple<FP...> tupl, Args... args) {
				func(std::get<0>(tupl), args...);
			}
		};

	private:
		F mFunc;
		std::tuple<FP...> mPara;
	};

}

#endif		// RALFLIGHT_SRC_CORE_THREAD_THREADBASE_H