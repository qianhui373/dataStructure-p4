#include "sparse_vector.hpp"
#include "abstract_vector.hpp"

// TODO

template<typename T>
SparseVector<T>::SparseVector() {
	guard.prev = guard.next = &guard;
}


template<typename T>
SparseVector<T>::SparseVector(std::size_t length) {
    guard.prev = guard.next = &guard;
    size = length;
}


template<typename T>
SparseVector<T>::SparseVector(const SparseVector<T>& x) {
    guard.prev = guard.next = &guard;
    size = x.size;
    NodePtr  xcurr = x.guard.next;
    NodePtr curr = &guard;
    while (xcurr != &x.guard) {
        NodePtr temp = new Node<T>;
        temp->pos = xcurr->pos;
        temp->data = xcurr->data;
        temp->prev = curr;
        temp->next = &guard;
        curr->next = temp;
        guard.prev = temp;
        xcurr = xcurr->next;
        curr = temp;

    }
}

template<typename T>
SparseVector<T>::SparseVector(SparseVector<T>&& x){
    
    std::swap(size, x.size);
    if (size > 0) {
        guard.next = x.guard.next;
        x.guard.next = &x.guard;
        guard.prev = x.guard.prev;
        x.guard.prev = &x.guard;
        guard.next->prev = &guard;
        guard.prev->next = &guard;
    }
else {
    guard.prev = guard.next = &guard;
}

}




template<typename T>
SparseVector<T>::~SparseVector(){
    clear();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
SparseVector<T>& SparseVector<T>::operator=(const SparseVector<T>& x){
    //const this = T();
    if (this != &x) {
        clear();
        size = x.size;
        NodePtr xcurr = x.guard.next;
        NodePtr curr = &guard;
        for (std::size_t i = 1; i <= x.size; ++i) {

            NodePtr temp = new Node<T>;
            temp->data = xcurr->data;
            temp->prev = curr;
            temp->next = &guard;
            temp->pos = xcurr->pos;
            curr->next = temp;
            guard.prev = temp;
            xcurr = xcurr->next;
            curr = temp;
        }
    }
    return *this;
  
 
}


template<typename T>
SparseVector<T>& SparseVector<T>::operator=(SparseVector<T>&& x) {
    clear();
  if (this != &x) {  
        
        std::swap(size, x.size);
        if(size>0){
            guard.next = x.guard.next;
            x.guard.next = &x.guard;
            guard.prev = x.guard.prev;
            x.guard.prev = &x.guard;
            guard.next->prev = &guard;
            guard.prev->next = &guard;
            
        }
        
        
  }

 return *this;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
std::size_t SparseVector<T>::length()const noexcept{

  return size;
}


template<typename T>
void SparseVector<T>::clear(){
    NodePtr curr = guard.next;
    while(curr != &guard){
        guard.next = curr->next;
        delete curr;
        
        curr = guard.next;
    }
    size = 0;
}





///////////////////////////////////////////
template <typename T>
const T& SparseVector<T>::operator()(std::size_t index) const {
   
    if (index == 0 || index > size) {
        throw std::invalid_argument("invalid position in getEntry");
    }


    NodePtr curr = guard.next;

    while(curr != &guard){
        if(curr->pos == index){
            return curr->data;
        }
        else if(curr->pos < index){
            curr = curr->next;    
        }
        else if(curr->pos >index)
            break;
}

    return mValue;

    
}


template <typename T>
T& SparseVector<T>::operator()(std::size_t index) {
    if(index == 0 || index > size){
        throw std::invalid_argument("invalid position in getEntry");   
    }

    
    NodePtr curr = guard.next;
    while(curr != &guard){
        if(curr->pos == index){
            return curr->data;
        }
        else if(curr->pos < index){
            curr = curr->next;
        }
        else if(curr->pos > index){
            break;
        }

    }
    
    NodePtr temp = new Node<T>;
    temp->pos = index;
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev->next = temp;
    curr->prev = temp;
    
    
    return temp->data;

  
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
