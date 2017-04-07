
#include <iostream>
#include "myvector.h"
using namespace std;

void print(MyVector& printMe);

int main() {
   MyVector v;
   MyVector::size_type currentSize;

   for (int i = 0; i < 20; i++) {
      v.push_back(i);

      currentSize = v.size();
      cout << "size: " << currentSize << " capacity: " << v.capacity() << endl;
   }

   print(v);
}




void print(MyVector& printMe) {
   for (int i = 0; i < printMe.size(); i++) {
      cout << printMe.at(i) << " ";
   }
   cout << endl;
}