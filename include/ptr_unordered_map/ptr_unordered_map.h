#pragma once

#include <unordered_map>

namespace ptr_containers {
	template<template<typename> typename shared_ptr_type_, typename key_type_, typename type_>
	class ptr_unordered_map : public std::unordered_map<key_type_, shared_ptr_type_<type_> > {
	public:
		typedef typename shared_ptr_type_<type_> type_shared_ptr;

		ptr_unordered_map() {}

		type_shared_ptr get(type_* value) const {
			for (auto iter = this->begin(); iter != this->end(); ++iter) {
				auto stored = iter->second;
				if (stored.get() == value) {
					return stored;
				}
			}
			return type_shared_ptr();
		}

		type_* get(const key_type_& key) const {
			auto entry = this->find(key);
			if (entry == this->end()) {
				return nullptr;
			}
			return entry->second.get();
		}

		void remove(const key_type_& key) {
			this->erase(key);
		}

		void remove(type_* value) {
			for (auto iter = this->begin(); iter != this->end();) {
				auto stored = iter->second;
				if (stored.get() == value) {
					iter = this->erase(iter);
				} else {
					++iter;
				}
			}
		}

		void remove(const type_shared_ptr& value) {
			this->remove(value.get());
		}

		bool contains(const key_type_& key) const {
			auto entry = this->find(key);
			if (entry == this->end()) {
				return false;
			}
			return true;
		}

		bool contains(type_* value) const {
			for (auto entry : *this) {
				if (entry.second.get() == value) {
					return true;
				}
			}
			return false;
		}

		bool contains(const type_shared_ptr& value) const {
			return this->contains(value.get());
		}

		virtual ~ptr_unordered_map() {}
	};
}