//
//  main.cpp
//  CS2B Assignment 1
//
//  Created by Connor Lynch on 4/16/16.
//  Copyright (c) 2016 connor lynch. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Movie {
private:
   string movie_name_;
   int tickets_available_;
   double ticket_price_;
   string movie[12] = {"blah"};

public:
   static const string kMovieName;
   static const int kTicketsAvailable = 0;
   static const double kTicketPrice;


public:
   Movie();
   Movie(string movie_name, int tickets_available, double ticket_price);
   ~Movie();
   void set_movie_name(string movie_name_);
   void set_tickets_available(int tickets_available_);
   void set_ticket_price(double ticket_price_);
   string get_movie_name();
   int get_tickets_available();
   double get_ticket_price();
   int PurchaseTicket();
   void Display();


};
const string Movie::kMovieName = "TRON";
const double Movie::kTicketPrice = 0.0;


class MovieTicketMaster {
private:
   string threater_name_;
   string threater_location_;
   Movie movies[1000] = {};
   Movie * p_movie_list_ = NULL;



public:
   static const string kTheaterName;
   static const string kTheaterLocation;

public:
   MovieTicketMaster();
   MovieTicketMaster(string theater_name, string theater_location);
   ~MovieTicketMaster();
   void ViewMovies();
   void SearchMovies();
   void FindMovie();
   void PurchaseTicket();
   void Init(Movie * p_movie_list, int size);
   void set_p_movie_list(Movie * p_movie_list_);
   void Run();
   string Menu();

};
const string MovieTicketMaster::kTheaterName = "Theater_Blah";
const string MovieTicketMaster::kTheaterLocation = "Location_Blah";




int main()
{
   const int g_kSize = 10;
   Movie * const movie_list = new Movie[g_kSize];
   Movie * p_movie_list = NULL;
   p_movie_list = movie_list;

   MovieTicketMaster::Menu();


/*
   const int g_kSize = 10;
   string * p_movies = NULL;
   int * p_counter = NULL;

   string movies[g_kSize] = { "The Godfather", "The Shawshank Redemption",
      "Schindler's List", "Raging Bull", "Casablanca",
      "One Flew Over the Cuckoo's Nest","Gone with the Wind", "Citizen Kane",
      "The Wizard of Oz", "Lawrence of Arabia" };

   p_movies = movies;


   for (int i=0; i < g_kSize; i++){
      *p_counter = 0;
      p_counter++;

   }
*/

}

//Here are all the methods for the MovieTicketMaster class
MovieTicketMaster::MovieTicketMaster():
threater_name_(kTheaterName), threater_location_(kTheaterLocation), p_movie_list_(NULL) {}

MovieTicketMaster::MovieTicketMaster(string theater_name, string theater_location):
threater_name_(theater_name), threater_location_(theater_location),p_movie_list_(NULL){}

MovieTicketMaster::~MovieTicketMaster()
{
   cout << "Theater <Century 20>, Location <Santa Clara> has been closed ..";
};

void MovieTicketMaster::Init(Movie * p_movie_list , int g_kSize)
{
   Movie * p_count = p_movie_list;
   for (int i = 0; i < g_kSize; i++){
      p_count->set_movie_name("SHaw");
      p_count->set_tickets_available(20);
      p_count->set_ticket_price(8.88);
      p_count++;
   }
};

void MovieTicketMaster::Run(){

}

string MovieTicketMaster::Menu()
{
   string blah = "Hellow World";
   return blah;
};



void MovieTicketMaster::set_p_movie_list(Movie * p_movie_list) {p_movie_list_ = p_movie_list;}





//Here are all the methods for the Movie Class
Movie::Movie():
movie_name_(kMovieName), tickets_available_(kTicketsAvailable),ticket_price_(kTicketPrice) {}

Movie::Movie(string movie_name, int tickets_available, double ticket_price):
movie_name_(movie_name), tickets_available_(tickets_available), ticket_price_(ticket_price) {}

//right now this is a non-opt destructor. This will have to change
Movie::~Movie(){
   cout << "Movie <”Fast and Furious 7”> object is no longer showing …";
}

void Movie::set_movie_name(string movie_name) {movie_name_ = movie_name; }

void Movie::set_tickets_available(int tickets_available) {tickets_available_ = tickets_available;}

void Movie::set_ticket_price(double ticket_price) {ticket_price_= ticket_price;}

string Movie::get_movie_name() { return movie_name_; }

int Movie::get_tickets_available() { return tickets_available_;}

double Movie::get_ticket_price() { return ticket_price_;}

int PurchaseTicket(int number_of_tickets);
void Display();














