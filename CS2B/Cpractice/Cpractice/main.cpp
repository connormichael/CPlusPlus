#include <string>
#include <iostream>
#include <sstream>
#include <cctype>


#include <iostream>
using namespace std;

int main()
{
   char buffer[300]; // big buffer
   char name[10];

   cout << "Please enter your name: " << flush;
   cin.getline(buffer, sizeof(buffer)-1, '\n'); // leave lots of room

   strncpy(name, buffer, sizeof(name)-1);   // but we can't use it all
   name[sizeof(name)-1] = '\0';     // strncpy won't add NULL if one
                                    // wasn't in the copy range

   cout << "\nHello " << name << endl;

   return 0;
}

/* ------------------- output -------------------

 Please enter your name: John Jacob Jingleheimer Smith

 Hello John Jaco

 ------------------------------------------------- */
