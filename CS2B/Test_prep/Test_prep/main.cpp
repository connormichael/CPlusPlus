//
//  main.cpp
//  Test_prep
//
//  Created by Connor Lynch on 12/11/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

class B {

private:
   int j = 5;
public:

   void f();
   // other members
};

void B::f()
{
   cout << "base" << endl;
}

class D: public B {
public:
   // other members
   void f();
   // other members
};

void D::f()
{
   cout << "child" << j <<  endl;
}


void g( B& b) {
   // other code
   b.f();
   // other code
};

void recursive(int i);

void recursive( int i ) {
   using namespace std;
   if (i < 8) {
      cout << i << " ";
      recursive(i);
   }
}


int main()
{


}

