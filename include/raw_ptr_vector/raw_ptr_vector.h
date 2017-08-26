#pragma once

#include <vector>

namespace ptr_containers {
	template<typename type_>
	class raw_ptr_vector : public std::vector<type_*> {
	public:
		raw_ptr_vector() {}

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

		virtual ~raw_ptr_vector() {}
	};
}