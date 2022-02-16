#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

// TODO
#include "abstract_vector.hpp"
#include <cstddef>


template<typename T>
class SparseVector: public AbstractVector<T>
{
public:
	//default constructor
	SparseVector();

	//copy constructor
	SparseVector(const SparseVector<T>& x);

	// move constructor
	SparseVector(SparseVector<T>&& x);

	//set length
	SparseVector(std::size_t length);

	//destructor
	~SparseVector();

	//copy assignment
	SparseVector& operator=(const SparseVector<T>& x);

	//move assignment
	SparseVector& operator=(SparseVector<T>&& x);


	//return the number of items
	std::size_t length() const noexcept;
	//
	
	//bool remove(std::size_t position);
	void clear();


	// return a constant reference to the value at the given index
	// uses 1-based indexing
	// throws std::invalid_argument for invalid index 
	const T& operator()(std::size_t index) const;

	// return a reference to the value at the given index
	// uses 1-based indexing
	// throws std::invalid_argument for invalid index 
	T& operator()(std::size_t index);

private:
	template<typename U>
	struct Node {
		U data = T();
		Node<U>* next = nullptr;
		Node<U>* prev = nullptr;
		std::size_t pos;
	};

	typedef Node<T>* NodePtr;

	Node<T> guard;

	std::size_t size = 0;
	const T mValue = T();

	//helpers
	
};

#include "sparse_vector.tpp"
#endif
