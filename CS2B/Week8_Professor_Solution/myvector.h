// file myvector.h

#include <cstdlib>

template <class T>
class MyVector {
public:
   class NegativeSize{};

   typedef std::size_t size_type;
   typedef T value_type;
   MyVector(size_type inSize = 0, const value_type& inValue = value_type());
   size_type size() const;
   size_type capacity() const;
   value_type at(size_type i) const;
   void push_back(const value_type& insertMe);
private:
   value_type* items;
   size_type mSize;
   size_type mCapacity;
};

#include "myvector.cpp"