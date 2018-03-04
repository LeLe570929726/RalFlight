// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/12/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_RUNNABLE_H
#define RALFLIGHT_SRC_CORE_THREAD_RUNNABLE_H

#include "../Global/Macro.h"
#include "RunnableBase.h"
#include <tuple>
#include <utility>
#include <functional>

// Core namespace
namespace Core {

	template <class F, class... FP>
	class RALFLIGHT_API_TEMPLATE Runnable : public RunnableBase {
	public:
		Runnable(F &&func, FP&&... para) :
			mFunc(std::forward<F>(func)), mPara(std::forward<FP>(para)...) {
		}
		Runnable(const Runnable &other) = delete;
		Runnable(Runnable &&other) :
			mFunc(std::forward<F>(other.mFunc)), mPara(std::forward<FP>(other.mPara)...) {
		}
		Runnable &operator=(const Runnable &other) = delete;
		virtual ~Runnable() = default;

	public:
		virtual void run() override {
			this->doRun(std::make_index_sequence<std::tuple_size<std::tuple<FP...>>::value>());
		}
		template <size_t... I>
		void doRun(std::index_sequence<I...> index) {
			std::invoke(std::move(this->mFunc), std::move(std::get<I>(this->mPara))...);
		}

	private:
		F mFunc;
		std::tuple<FP...> mPara;
	};

}

#endif			// RALFLIGHT_SRC_CORE_THREAD_RUNNABLE_H