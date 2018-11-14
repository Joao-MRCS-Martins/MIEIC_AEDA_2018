/*
 * PostOffice.cpp
 */

#include "PostOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}

vector<Mail *> PostOffice::removePostman(string name)
{
	Postman p1;
	vector<Mail*> emptyvec;
	for(size_t i=0;i<postmen.size();i++)
	{
		if(postmen[i].getName()==name)
		{
			p1= postmen[i];
			postmen.erase(postmen.begin() + i);
			return p1.getMail();
		}
	}
	return emptyvec;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance)
{
	unsigned int bal=0;
	vector<Mail*> sendtoPO;
	for (size_t i=0; i<mailToSend.size();i++)
	{
		bal += mailToSend[i]->getPrice();
		if(mailToSend[i]->getZipCode() >= firstZipCode && mailToSend[i]->getZipCode() <= lastZipCode)
			addMailToDeliver(mailToSend[i]);
		else
			sendtoPO.push_back(mailToSend[i]);
	}
	balance = bal;
	mailToSend.clear();
	return sendtoPO;
}
Postman PostOffice::addMailToPostman(Mail *m, string name)
{

	for(size_t i =0; i< postmen.size();i++)
	{
		if(postmen[i].getName()== name)
		{
			postmen[i].addMail(m);
			return postmen[i];
		}
	}
	throw NoPostmanException(name);
}
