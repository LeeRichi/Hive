
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>
#include <utility>

#pragma once

template <typename T>
class Array {
	private:
		T* _array;
		unsigned int _size;
	public:
		Array() : _array(nullptr), _size(0) {}
		Array(unsigned int n) : _size(n) {
			if (n > 0) {
				_array = new T[n];
			} else {
				_array = nullptr;
			}
		}
		Array(const Array& other) : _size(other._size) {
			if (other._array) {
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i) {
					_array[i] = other._array[i];
				}
			} else {
				_array = nullptr;
			}
		}
		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _array;
				_size = other._size;
				if (other._array) {
					_array = new T[_size];
					for (unsigned int i = 0; i < _size; ++i) {
						_array[i] = other._array[i];
					}
				} else {
					_array = nullptr;
				}
			}
			return *this;
		}
		~Array() {
			delete[] _array;
		}
		T& operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			return _array[index];
		}
		const T& operator[](unsigned int index) const {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			return _array[index];
		}
		unsigned int size() const {
			return _size;
		}
};


