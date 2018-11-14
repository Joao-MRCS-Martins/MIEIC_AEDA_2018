/*
 * Postman.cpp
 */
#include "Postman.h"
#include <iostream>
unsigned int id_ =1;
Postman::Postman(): id(0) {}

Postman::Postman(string name)
{
	id = id_;
	id_++;
	this->name = name;
}

void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}

bool Postman::operator <(const Postman &p1) const
{
	vector<string> zipcodes_1;
	vector<string> zipcodes_2;
	for(size_t i = 0; i < this->getMail().size();i++ )
	{
		bool unique=true;
		for(size_t j =0; j < zipcodes_1.size();j++)
		{

			if(this->getMail()[i]->getZipCode() == zipcodes_1[j])
				unique = false;
		}
		if(unique)
			zipcodes_1.push_back(this->getMail()[i]->getZipCode());
	}
	for(size_t i = 0; i < p1.getMail().size();i++ )
		{
			bool unique=true;
			for(size_t j =0; j < zipcodes_2.size();j++)
			{

				if(p1.getMail()[i]->getZipCode() == zipcodes_2[j])
					unique = false;
			}
			if(unique)
				zipcodes_2.push_back(p1.getMail()[i]->getZipCode());
		}
	return zipcodes_1.size() < zipcodes_2.size();
}
