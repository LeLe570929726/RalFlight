// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2018/01/05 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_MAP_H
#define RALFLIGHT_SRC_CORE_STL_MAP_H

#include "../Global/Macro.h"
#include "Iteartor.h"
#include <map>
#include <functional>
#include <memory>
#include <utility>

// Core namespace
namespace Core {

	template <class Key, class Val, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, Val>>>
	class RALFLIGHT_API_TEMPLATE Map {
	private:
		using MapIterator = Iterator<typename std::map<Key, Val, Compare, Allocator>::iterator>;
		using MapConstIterator = Iterator<typename std::map<Key, Val, Compare, Allocator>::const_iterator>;

	public:
		explicit Map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : 
			mMap(comp, alloc) {
		}
		explicit Map(const Allocator& alloc) :
			mMap(alloc) {
		}
		Map(MapIterator begin, MapIterator end, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) :
			mMap(begin.get(), end.get(), comp, alloc) {
		}
		Map(MapIterator begin, MapIterator end, const Allocator& alloc) :
			mMap(begin.get(), end, alloc) {
		}
		Map(const Map &other) :
			mMap(other.mMap) {
		}
		Map(const Map &other, const Allocator &alloc) :
			mMap(other.mMap, alloc) {
		}
		Map(Map &&other) :
			mMap(std::forward<decltype(other.mMap)>(other.mMap)) {
		}
		Map(Map &&other, const Allocator& alloc) :
			mMap(std::forward<decltype(other.mMap)>(other.mMap), alloc) {
		}
		Map &operator=(const Map &other) {
			this->mMap = other.mMap;
		}
		Map &operator=(Map &&other) {
			mMap = std::forward<decltype(other->mMap)>(other.mMap);
		}
		~Map() = default;

	public:
		bool operator==(const Map &other) {
			return *this == other;
		}
		bool operator!=(const Map &other) {
			return *this != other;
		}
		Val &operator[](const Key &key) {
			return this->mMap[key];
		}
		Val &operator[](Key &&key) {
			return this->mMap[std::forward<Key>(key)];
		}

	public:
		MapIterator begin() {
			MapIterator tempIterator(this->mMap.begin());
			return tempIterator;
		}
		MapConstIterator begin() const {
			MapConstIterator tempIterator(this->mMap.cbegin());
			return tempIterator;
		}
		MapConstIterator cbegin() const {
			MapConstIterator tempIterator(this->mMap.cbegin());
			return tempIterator;
		}
		MapIterator end() {
			MapIterator tempIterator(this->mMap.end());
			return tempIterator;
		}
		MapConstIterator end() const {
			MapConstIterator tempIterator(this->mMap.cend());
			return tempIterator;
		}
		MapConstIterator cend() const {
			MapConstIterator tempIterator(this->mMap.cend());
			return tempIterator;
		}

	public:
		bool empty() const {
			return this->mMap.empty();
		}
		int size() const {
			return static_cast<int>(this->mMap.size());
		}

	public:
		void clear() {
			this->mMap.clear();
		}
		MapIterator insert(const Key &key, const Val &value) {
			auto pair = this->mMap.insert(std::pair<const Key, Val>(key, value));
			MapIterator tempIterator(pair.first);
			return tempIterator;
		}
		MapIterator insert(MapConstIterator position, const Key &key, const Val &value) {
			auto pair = this->mMap.insert(position.get(), std::pair<const Key, Val>(key, value));
			MapIterator tempIterator(pair.first);
			return tempIterator;
		}
		void insert(MapConstIterator begin, MapConstIterator end) {
			this->mMap.insert(begin.get(), end.get());
		}
		int remove(const Key &key) {
			return static_cast<int>(this->mMap.erase(key));
		}
		MapIterator remove(MapConstIterator position) {
			MapIterator tempIterator(this->mMap.erase(position.get()));
			return tempIterator;
		}
		MapIterator remove(MapConstIterator begin, MapConstIterator end) {
			MapIterator tempIterator(this->mMap.erase(begin.get(), end.get()));
			return tempIterator;
		}

	public:
		MapIterator find(const Key &key) {
			MapIterator tempIterator(this->mMap.find(key));
			return tempIterator;
		}
		MapConstIterator find(const Key &key) const {
			MapConstIterator tempIterator(this->mMap.find(key));
			return tempIterator;
		}

	public:
		Val &at(const Key &key) {
			return this->mMap.at(key);
		}
		const Val &at(const Key &key) const {
			return this->mMap.at(key);
		}
	
	private:
		std::map<Key, Val, Compare, Allocator> mMap;
	};

}

#endif			// RALFLIGHT_SRC_CORE_STL_MAP_H