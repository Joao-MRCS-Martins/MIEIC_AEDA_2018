/*
 * CinemaFinder.cpp
 */

#include "CinemaFinder.h"
#include "Cinema.h"
#include "Film.h"
#include <algorithm>

CinemaFinder::CinemaFinder() { }

CinemaFinder::~CinemaFinder() { }

void CinemaFinder::addFilm(Film *f1) {
	FilmPtr fp1;
	fp1.film = f1;
	films.insert(fp1);
}

void CinemaFinder::addCinema(const Cinema &c1)
{ cinemas.push(c1); }

tabHFilm CinemaFinder::getFilms() const
{ return films; }

priority_queue<Cinema> CinemaFinder::getCinemas() const
{ return cinemas; }


// TODO


//b1
list<string> CinemaFinder::filmsWithActor(string actorName) const {
	list<string> res;
<<<<<<< Updated upstream
	tabHFilm::const_iterator it;
	for(it = films.begin();it != films.end();it++) {
		list<string> actors = it->film->getActors();
		for(list<string>::const_iterator it2 = actors.begin();  it2 != actors.end();it2++) {
			if(*it2 == actorName)
			{	res.push_back(it->film->getTitle());
				break;
			}

		}
	}
=======

	// TODO
>>>>>>> Stashed changes

	return res;
}


//b2
void CinemaFinder::addActor(string filmTitle, string actorName) {

<<<<<<< Updated upstream
	tabHFilm::const_iterator it;
	for(it = films.begin();it != films.end();it++) {
		if(it->film->getTitle() == filmTitle) {
			Film*f1 = it->film;
			films.erase(it);
			f1->addActor(actorName);
			FilmPtr fp;
			fp.film = f1;
			films.insert(fp);
			return;
		}
	}
	Film* f1= new Film(filmTitle);
	f1->addActor(actorName);
	FilmPtr fp;
	fp.film = f1;
	films.insert(fp);
=======
	// TODO
>>>>>>> Stashed changes

}


//c1
string CinemaFinder::nearestCinema(string service1) const {
	string cName="";

<<<<<<< Updated upstream
	priority_queue<Cinema> temp = cinemas;
	while(!temp.empty()) {
		list<string> servs = temp.top().getServices();
		list<string>::const_iterator it;
		for(it = servs.begin(); it!= servs.end();it++) {
			if(*it == service1)
				return temp.top().getName();
		}
		temp.pop();
	}
=======
	// TODO
>>>>>>> Stashed changes

	return cName;
}


//c2
void CinemaFinder::addServiceToNearestCinema(string service1, unsigned maxDistance) {

<<<<<<< Updated upstream
	if(cinemas.empty())
		throw CinemaNotFound();
	if(cinemas.top().getDistance() > maxDistance)
			throw CinemaNotFound();
	Cinema temp = cinemas.top();
	cinemas.pop();
	temp.addService(service1);
	cinemas.push(temp);


=======
	// TODO
>>>>>>> Stashed changes

}
