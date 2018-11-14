/*
 * PostOffice.h
 */

#ifndef SRC_POSTOFFICE_H_
#define SRC_POSTOFFICE_H_

#include "Mail.h"
#include "Postman.h"
#include <vector>


class PostOffice {
	vector<Mail *> mailToSend;
	vector<Mail *> mailToDeliver;
	vector<Postman> postmen;
	string firstZipCode, lastZipCode;
public:
	PostOffice();
	PostOffice(string firstZCode, string lastZCode);
	void addMailToSend(Mail *m);
	void addMailToDeliver(Mail *m);
	void addPostman(const Postman &p);
	vector<Mail *> getMailToSend() const;
	vector<Mail *> getMailToDeliver() const;
	vector<Postman> getPostman() const;
	//-------
	vector<Mail *> removePostman(string name);
	vector<Mail *> endOfDay(unsigned int &balance);
	Postman addMailToPostman(Mail *m, string name);
};

template<class T>
unsigned int numberDifferent (const vector<T> &v1)
{
	vector<T> v2;
	for(size_t i = 0; i<v1.size();i++)
	{
		bool unique = true;
		for(size_t j=0;j<v2.size();j++)
		{
			if(v1[i] == v2[j])
				unique = false;
		}
		if(unique)
			v2.push_back(v1[i]);
	}
	return v2.size();
}

class NoPostmanException
{
private:
	string name;
public:
	NoPostmanException(string name) {this-> name = name;}
	string getName() { return name;}
};
#endif /* SRC_POSTOFFICE_H_ */
