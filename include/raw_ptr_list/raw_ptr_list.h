#pragma once 

#include <list>

namespace ptr_containers {
	template<typename type_>
	class raw_ptr_list : public std::list<type_*> {
	public:
		raw_ptr_list() {}

		type_* get(type_* value) const {
			for (auto iter = this->begin(); iter != this->end(); ++iter) {
				if (*iter == value) {
					return *iter;
				}
			}
			return nullptr;
		}
		
		void add(type_* value) {
			this->push_back(value);
		}

		void remove(type_* value) {
			for (auto iter = this->begin(); iter != this->end();) {
				if (*iter == value) {
					iter = this->erase(iter);
				}else {
					++iter;
				}
			}
		}

		bool contains(type_* value) const {
			for (auto& stored : *this) {
				if (stored == value) {
					return true;
				}
			}
			return false;
		}

		virtual ~raw_ptr_list() {}
	};
}