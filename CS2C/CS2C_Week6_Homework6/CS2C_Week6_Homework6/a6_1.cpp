/*
Created by Connor Lynch
CS2C, Advanced Data Structures & Algorithms in C++
Created Febuary 19, 2017
Professor Dave Harden
Assignment 6.1

Description: This program demonstates the functionality of the FHhashQPwFind
 class, showing how objects can be hashed into the table using several 
 different keys of different type. The program allows for hashing of a object
 passed on one of two object attributes, leaving the supporting code as
 comments for demonstration.
 
 */

#include <vector>
#include <string>
#include <iostream>
#include "EBookEntry.h"

int Hash( const EBookEntry & item );
int Hash(const string & key);
int Hash( int key );
//int getKey( const EBookEntry & item );
string getKey( const EBookEntry & item );

#include "FHhashSC.h"
#include "FHhashQPwFind.h"
using namespace std;






int main()
{
   EBookEntryReader bookInput("catalog-short4.txt");

   if (bookInput.readError())
   {
      cout << "couldn't open " << bookInput.getFileName() << " for input.\n";
      exit(1);
   }

   //cout << "=== Testing using int keys ===" << endl;
   cout << "=== Testing using string keys ===" << endl;

   //FHhashQPwFind<EBookEntry, int> hashTable;
   FHhashQPwFind<EBookEntry, string> hashTable;

   //EBookEntry::setSortType(EBookEntry::SORT_BY_ID);
   EBookEntry::setSortType(EBookEntry::SORT_BY_CREATOR);

   cout << "File Name: " << bookInput.getFileName() << endl;
   cout << "Number of Books: " << bookInput.getNumBooks() << endl;

   //Generate 25 random indices
   srand(2);
   int NUM_RANDOM_INDICES = 25;
   int randomIndices[NUM_RANDOM_INDICES];

   for (int i = 0; i < NUM_RANDOM_INDICES; i++)
   {
      randomIndices[i] = 1 + rand() % bookInput.getNumBooks();
   }

   cout << "==The random books from bookInput ==" << endl << endl;

   for (int w = 0; w < NUM_RANDOM_INDICES; w++)
      //cout << bookInput[randomIndices[w]].getSubject() << endl << endl;
      cout << bookInput[randomIndices[w]].getCreator() << endl << endl;

   for (int x = 0; x < bookInput.getNumBooks(); x++)
      hashTable.insert(bookInput[x]);

   // attempt to find on the selected key
   cout << "== The same random books from the hash table ==" << endl << endl;

   EBookEntry book;
   for (int k = 0; k < NUM_RANDOM_INDICES; k++)
   {
      try
      {
         //book = hashTable.find( bookInput[ randomIndices[k] ].getETextNum() );
         //cout << book.getSubject() << endl;
         book = hashTable.find( bookInput[ randomIndices[k] ].getCreator() );
         cout << book.getCreator() << endl;
      }
      //catch (const typename FHhashQPwFind<EBookEntry, int>::NotFoundException& e)
      catch (const typename FHhashQPwFind<EBookEntry, string>::NotFoundException& e)
      {
         cout << "no.  ";
      }
      cout << endl;
   }

   // test known failures exceptions:
   try
   {
      //book = hashTable.find(-3);
      book = hashTable.find( "Jack Kerouac" );
   }
   //catch (const typename FHhashQPwFind<EBookEntry, int>::NotFoundException& e)
   catch (const typename FHhashQPwFind<EBookEntry, string>::NotFoundException& e)
   {
      cout << "Sorry. Book does not exist with that key " << endl;
   }

   // more failures

   try
   {
      //book = hashTable.find(0.1);
      book = hashTable.find("Bob Ross");
   }
   //catch (const typename FHhashQPwFind<EBookEntry, int>::NotFoundException& e)
   catch (const typename FHhashQPwFind<EBookEntry, string>::NotFoundException& e)
   {
      cout << "Sorry. Book does not exist with that key " << endl;
   }

   try
   {
      //book = hashTable.find(50000000);
      book = hashTable.find("David Bowie");
   }
   //catch (const typename FHhashQPwFind<EBookEntry, int>::NotFoundException& e)
   catch (const typename FHhashQPwFind<EBookEntry, string>::NotFoundException& e)
   {
      cout << "Sorry. Book does not exist with that key " << endl;
   }

   return 0;
}






//Hash function is passed item of EBookEntry object type
//returns the integer result of hashing object attribute to table index
int Hash( const EBookEntry & item )
{
   return Hash(getKey(item));
}





//Hash function for string that takes string key and returns
//the integer result of hashing the string to table index
int Hash( const string & key )
{
   unsigned int k, retVal = 0;

   for(k = 0; k < key.length( ); k++ )
      retVal = 37 * retVal + key[k];


   return retVal;
}






//Hash function for integer keys returns original key
//for direct hash method
int Hash( int key )
{
   return key;
}






//Hash function for EBookEntry objects using Creator attribute to return
//string key to be hashed
string getKey( const EBookEntry & item )
{
   return item.getCreator() ;
}







/*
//Hash function for EbookEntry objects using ETextNum attribute to return
//an integer to be hashed
int getKey( const EBookEntry & item)
{
   return item.getETextNum() ;
}
*/






/*--------------------- Ouput using Ints ----------------------

 === Testing using int keys ===
File Name: catalog-short4.txt
Number of Books: 4863
==The random books from bookInput ==

Strand, The (London, England)

(no data found)

Single women -- Fiction

Natural history -- Juvenile fiction

Apuleius -- Translations into English

Questions and answers -- Periodicals

Fantasy fiction

Fiction

Smuggling -- Juvenile fiction

Science fiction

Jews -- Fiction

English literature -- History and criticism

(no data found)

Salvation

Composers -- Biography

Congregational churches -- Missions -- Periodicals

Children's literature

Folklore -- India

Biography

PS

Automobiles -- Motors -- Carburetors

Gold mines and mining -- Fiction

Detective and mystery stories

Short stories

Constitutional history -- United States

== The same random books from the hash table ==

Strand, The (London, England)

(no data found)

Single women -- Fiction

Natural history -- Juvenile fiction

Apuleius -- Translations into English

Questions and answers -- Periodicals

Fantasy fiction

Fiction

Smuggling -- Juvenile fiction

Science fiction

Jews -- Fiction

English literature -- History and criticism

(no data found)

Salvation

Composers -- Biography

Congregational churches -- Missions -- Periodicals

Children's literature

Folklore -- India

Biography

PS

Automobiles -- Motors -- Carburetors

Gold mines and mining -- Fiction

Detective and mystery stories

Short stories

Constitutional history -- United States

Sorry. Book does not exist with that key 
Sorry. Book does not exist with that key 
Sorry. Book does not exist with that key 
Program ended with exit code: 0
-----------------------------End of Int Output------------------------------*/






/*--------------------------- Output Using Strings --------------------------
=== Testing using string keys ===
File Name: catalog-short4.txt
Number of Books: 4863
==The random books from bookInput ==

Besant, Walter, Sir, 1836-1901

Various

Yonge, Charlotte Mary, 1823-1901

Kilner, Dorothy, 1755-1836

Apuleius, Lucius, 125?-180

Various

Burroughs, Edgar Rice, 1875-1950

Stephens, Ann S. (Ann Sophia), 1810-1886

Breckenridge, Gerald, 1889-1964

Marlowe, Stephen, 1928-2008

Zangwill, Israel, 1864-1926

Quiller-Couch, Arthur Thomas, Sir, 1863-1944

Leinster, Murray, 1896-1975

Martin, T. T. (Thomas Theodore), 1862-1939

Mathews, W. S. B. (William Smythe Babcock), 1837-1912

Various

Various

Valmiki

Kingston, William Henry Giles, 1814-1880

Donnell, Annie Hamilton, 1862-

Anonymous

Cullum, Ridgwell, 1867-1943

Steele, Chester K.

Ferber, Edna, 1885-1968

Jellinek, Georg, 1851-1911

== The same random books from the hash table ==

Besant, Walter, Sir, 1836-1901

Various

Yonge, Charlotte Mary, 1823-1901

Kilner, Dorothy, 1755-1836

Apuleius, Lucius, 125?-180

Various

Burroughs, Edgar Rice, 1875-1950

Stephens, Ann S. (Ann Sophia), 1810-1886

Breckenridge, Gerald, 1889-1964

Marlowe, Stephen, 1928-2008

Zangwill, Israel, 1864-1926

Quiller-Couch, Arthur Thomas, Sir, 1863-1944

Leinster, Murray, 1896-1975

Martin, T. T. (Thomas Theodore), 1862-1939

Mathews, W. S. B. (William Smythe Babcock), 1837-1912

Various

Various

Valmiki

Kingston, William Henry Giles, 1814-1880

Donnell, Annie Hamilton, 1862-

Anonymous

Cullum, Ridgwell, 1867-1943

Steele, Chester K.

Ferber, Edna, 1885-1968

Jellinek, Georg, 1851-1911

Sorry. Book does not exist with that key 
Sorry. Book does not exist with that key 
Sorry. Book does not exist with that key 
Program ended with exit code: 0
---------------------------------End of String Output----------------------*/

