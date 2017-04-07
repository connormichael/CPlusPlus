//
//  main.cpp
//  Basis for String Homework
//
//  Created by Connor Lynch on 1/17/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
   // declare some string references (variables)
   string thxMom, thxAgent, thxFox;
   string outputString;

   // for fun, create the String object directly in the declaration
   string acceptanceSpeech = "I'd like to thank ";

   // create the rest of the  string objects to use
   // in your speech.
   thxMom = "my Mother, Ethel, and wife Kitty.";
   thxFox = "everyone at Fox and FBC.";
   thxAgent = "my agent and everyone at Paradigm.";

   // stand up at the podium and get settled ...
   // for this use String Literals directly in the
   // output statements.
   cout << "I didn't really expect to win ...\n\n";
   cout << "I don't even have a speech prepared!\n\n";
   cout <<  "Anyway ...\n\n";

   // now finally start to thank people.
   outputString = "First of all " + acceptanceSpeech + thxFox + "\n";
   cout << outputString;

   outputString = "Next, " + acceptanceSpeech + thxAgent +  "\n";
   cout << outputString;

   outputString = "But mostly, " + acceptanceSpeech + thxMom +  "\n\n";
   cout << outputString;

   return (0);
}