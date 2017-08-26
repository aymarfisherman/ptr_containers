#pragma once

#include <unordered_map>

namespace ptr_containers {
	template<typename key_type_, typename type_>
	class raw_ptr_unordered_map : public std::unordered_map<key_type_, type_*> {
	public:
		raw_ptr_unordered_map() {}

		type_* get(type_* value) const {
			for (auto iter = this->begin(); iter != this->end(); ++iter) {
				auto& stored = iter->second;
				if (stored == value) {
					return stored;
				}
			}
			return nullptr;
		}

		type_* get(key_type_& key) const {
			auto entry = this->find(key);
			if (entry == this->end()) {
				return nullptr;
			}
			return entry->second;
		}

		void remove(const key_type_& key) {
			this->erase(key);
		}

		void remove(type_* value) {
			for (auto iter = this->begin(); iter != this->end();) {
				auto& stored = iter->second;
				if (stored == value) {
					iter = this->erase(iter);
				} else {
					++iter;
				}
			}
		}
		
		bool contains(const key_type_& key) const {
			auto entry = this->find(key);
			if (entry == this->end()) {
				return false;
			}
			return true;
		}

		bool contains(type_* value) const {
			for (auto& entry : *this) {
				if (entry.second == value) {
					return true;
				}
			}
			return false;
		}

		virtual ~raw_ptr_unordered_map() {}
	};
}