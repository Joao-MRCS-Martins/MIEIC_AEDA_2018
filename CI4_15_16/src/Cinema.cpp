/*
 * Cinema.cpp
 */
#include "Cinema.h"

Cinema::Cinema(string nm, unsigned d, unsigned nr): name(nm), distance(d),
		numberOfRooms(nr),timetable(FilmTime(0,NULL, 0))
{}

Cinema::Cinema(string nm, unsigned d, unsigned nr, list<string> ls): name(nm), distance(d),
		numberOfRooms(nr),services(ls), timetable(FilmTime(0,NULL,0))
{}

Cinema::~Cinema() { }

string Cinema::getName() const
{ return name; }

unsigned Cinema::getDistance() const
{ return distance; }

list<string> Cinema::getServices() const
{ return services; }

BST<FilmTime> Cinema::getTimetable() const
{ return timetable; }

void Cinema::addService(string service1)
{ services.push_back(service1); }

void Cinema::addFilmTime(const FilmTime &ft1)
{ timetable.insert(ft1); }


// TODO

bool Cinema::operator<(const Cinema & cr) const
{
	if(this->getDistance() == cr.getDistance())
		return this->getServices().size() < this->getServices().size();
	return this->getDistance() > cr.getDistance();
}


//a1
Film *Cinema::filmAtHour(unsigned &h1) const {
	BSTItrIn<FilmTime> it(this->timetable);
	FilmTime prev(0,NULL,0);
	while(!it.isAtEnd()) {
		FilmTime ft = it.retrieve();
		if(ft.getHour() == h1)
		{
			return ft.getFilm();
		}

		if(ft.getHour() > h1) {
			break;
		}
		prev = ft;
		it.advance();
	}
	if(prev.getFilm()!= NULL)
		h1 = prev.getHour();
	return prev.getFilm();
}


//a2
bool Cinema::modifyHour(unsigned h1, unsigned room1, unsigned h2) {
	BSTItrIn<FilmTime> it(this->timetable);
	while(!it.isAtEnd()) {
		if(it.retrieve().getHour() == h2 && it.retrieve().getRoomID() && it.retrieve().getFilm() != NULL)
			return false;
		it.advance();
	}
	it = this->timetable;
	while(!it.isAtEnd()) {
		if(it.retrieve().getHour() == h1 && it.retrieve().getRoomID() == room1) {
			FilmTime temp = it.retrieve();
			timetable.remove(temp);
			temp.setHour(h2);
			timetable.insert(temp);
			return true;
		}
		it.advance();
	}
	return false;
}


//a3
unsigned Cinema::addFilm(Film *f1, unsigned h1) {
	unsigned roomToUse = 1;
	BSTItrIn<FilmTime> it(this->timetable);
	while(!it.isAtEnd()) {
		if(it.retrieve().getHour() == h1)
			roomToUse++;
		it.advance();
	}
	if(roomToUse > this->numberOfRooms)
		return 0;
	FilmTime ft(h1,f1,roomToUse);
	timetable.insert(ft);
	return roomToUse;
}






