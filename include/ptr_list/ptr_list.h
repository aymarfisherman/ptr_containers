#pragma once 

#include <list>

namespace ptr_containers {
	template<template<typename> typename shared_ptr_type_, typename type_>
	class ptr_list : public std::list<shared_ptr_type_<type_> > {
	public:
		typedef typename shared_ptr_type_<type_> type_shared_ptr;

		ptr_list() {}

		type_shared_ptr get(type_* value) const {
			for (auto iter = this->begin(); iter != this->end(); ++iter) {
				if (iter->get() == value) {
					return *iter;
				}
			}
			return TypeSharedPtr();
		}
		
		void add(const type_shared_ptr& value) {
			this->push_back(value);
		}

		void remove(type_* value) {
			for (auto iter = this->begin(); iter != this->end();) {
				if (iter->get() == value) {
					iter = this->erase(iter);
				}else {
					++iter;
				}
			}
		}

		void remove(const type_shared_ptr& value) {
			this->remove(value.get());
		}

		bool contains(const type_shared_ptr& value) const {
			return this->contains(value.get());
		}

		bool contains(type_* value) const {
			for (auto& stored : *this) {
				if (stored.get() == value) {
					return true;
				}
			}
			return false;
		}

		virtual ~ptr_list() {}
	};
}