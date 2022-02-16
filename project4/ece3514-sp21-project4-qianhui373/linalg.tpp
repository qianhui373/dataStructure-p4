#include "linalg.hpp"
#include "abstract_vector.hpp"
// TODO
#include <algorithm>
#include <stdexcept>
#include "math.h"
#include <cstddef>
#include <utility>
#include <stdexcept>

template<typename T>
T dot(const AbstractVector<T>& x, const AbstractVector<T>& y) {
	std::size_t lengtha = x.length();
	std::size_t lengthb = y.length();
	T dott = T();
	if (lengtha != lengthb) {
		throw std::invalid_argument("length(x) != length(y)");
		
	}
	else {
		
		for (int i = 1; i <= lengtha; i++) {
			dott += x(i) * y(i);
		}
	}
	return dott;
		
}

template<typename T>
T norm1(const AbstractVector<T>& x) {
	std::size_t lengtha = x.length();
	T suma = T();
	for (int i = 1; i <= lengtha; i++) {
		
			suma += abs(x(i));
		
	}
	return suma;
}



// compute the 2-norm (square root of the sum of elements squared) of a vector
template<typename T>
double norm2(const AbstractVector<T>& x) {
	std::size_t lengtha = x.length();
	T sumb = T();
	for (int i = 1; i <= lengtha; i++) {
		sumb += pow(x(i), 2);
		
	}
	sumb = sqrt(sumb);
	return sumb;
}
