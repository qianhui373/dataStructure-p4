#ifndef DENSE_VECTOR_HPP
#define DENSE_VECTOR_HPP
//
// TODO//

#include "abstract_vector.hpp"
#include <cstddef>

template<typename T>
class DenseVector: public AbstractVector<T>
{
public:
	//default constructor
	DenseVector() = default;

	//set length
	DenseVector(std::size_t length);

	//copy constructor
	DenseVector(const DenseVector<T>& rhs);

	//copy assignment
	DenseVector<T>& operator = (const DenseVector<T>& rhs);

	//move constructor
	DenseVector(DenseVector<T>&& rhs);

	// copy assignment
	DenseVector<T>& operator=(DenseVector<T> && rhs);

	//destructor
	~DenseVector();

	//return the number of items in the list
	std::size_t length() const noexcept;


	//remove all entries
	void clear();
	
	const T& operator()(std::size_t index) const;
	
	
	T& operator()(std::size_t index);




private:
	std::size_t m_capacity = 0;
	std::size_t m_size = 0;
	T* m_data = nullptr;

};

#include "dense_vector.tpp"
#endif
