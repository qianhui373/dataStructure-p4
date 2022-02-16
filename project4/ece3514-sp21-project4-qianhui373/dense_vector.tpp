#include "dense_vector.hpp"
#include "abstract_vector.hpp"
// TODO
//


template<typename T>
DenseVector<T>::~DenseVector() {
	delete[] m_data;
}

template <typename T>
DenseVector<T>::DenseVector(std::size_t length) {
    m_size = m_capacity = length;
    m_data = new T[m_capacity];
    for (std::size_t i = 0; i < m_size; i++) {
        m_data[i] = T();
    }
}

template<typename T>
DenseVector<T>::DenseVector(const DenseVector<T>& rhs) {
    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;

    m_data = new T[m_capacity];
    for (std::size_t i = 0; i <= m_size; ++i) {
        m_data[i] = rhs.m_data[i];
    }

    /*for (std::size_t i = m_size; i < m_capacity; ++i) {
        m_data[i] = T();
    }*/
}



template<typename T>
DenseVector<T>::DenseVector(DenseVector<T>&& rhs) {
    std::swap(m_capacity, rhs.m_capacity);
    std::swap(m_size, rhs.m_size);
    std::swap(m_data, rhs.m_data);
}




template <typename T>
DenseVector<T> & DenseVector<T>::operator=(const DenseVector<T>& rhs){  
  //TODO
  if(m_capacity < rhs.m_size){
    m_capacity = rhs.m_capacity;
    delete [] m_data;
    m_data = new T[m_capacity];

  }

  for (std::size_t i = 0; i < rhs.m_size; ++i) {
    m_data[i] = rhs.m_data[i];
  }

  m_size = rhs.m_size;

  return *this;


}

template <typename T>
DenseVector<T> & DenseVector<T>::operator=(DenseVector<T>&& rhs){  
  //TODO

  delete [] m_data;
  m_data = nullptr;
  m_capacity = 0;
  m_size = 0;

  std::swap(m_capacity, rhs.m_capacity);
  std::swap(m_size, rhs.m_size);
  std::swap(m_data, rhs.m_data);
  return *this;
}


/////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
std::size_t DenseVector<T>::length() const noexcept {
    return m_size;
}



template <typename T>
void DenseVector<T>::clear() {

    m_size = 0;
}

//
///////////////////////////////////////////
template <typename T>
const T& DenseVector<T>::operator()(std::size_t index) const{
    if(index == 0 || index >= m_size + 1){
    throw std::invalid_argument("invalide position in ListArray::getEntry");
  }

  return m_data[index-1];
}


template <typename T>
T& DenseVector<T>::operator()(std::size_t index){
    if(index == 0 || index >= m_size + 1){
    throw std::invalid_argument("invalide position in ListArray::getEntry");
  }

  return m_data[index-1];
}