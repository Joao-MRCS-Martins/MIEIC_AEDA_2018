/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
	unsigned num=0;
	list<Doctor>::const_iterator it;
	for(it = doctors.begin(); it != doctors.end();it++) {
		if(it->getMedicalSpecialty() == medicalSpecialty)
			num += it->getPatients().size();
	}
	return num;
}

void Hospital::sortDoctors() {

	doctors.sort();

}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	int num=0;
	list<Doctor>::iterator it;
	for(it = doctors.begin();it != doctors.end();it++) {
		if(it->getMedicalSpecialty() == medicalSpecialty1)
			num++;
	}
	if(num >= 3)
		return false;
	Doctor doc = Doctor(codM1,medicalSpecialty1);
	doctors.push_back(doc);
	return true;
}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	queue<Patient> p1;
	list<Doctor>::iterator it;
		for(it = doctors.begin();it != doctors.end();it++) {
			if(it->getCode()==codM1) {
				p1 = it->getPatients();
				doctors.erase(it);
				return p1;
			}
		}
		throw DoctorInexistent();
}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
	unsigned comp = 1000;
	list<Doctor>::iterator it;
	list<Doctor>::iterator it2;
	bool flag = false;
	for(it2 = doctors.begin(); it2 != doctors.end();it2++) {
		if(it2->getMedicalSpecialty() == medicalSpecialty1 && it2->getPatients().size() < comp) {
			comp = it2->getPatients().size();
			it = it2;
			flag = true;
		}
	}
	if(!flag)
		return false;
	Patient p = Patient(cod1,medicalSpecialty1);
	it->addPatient(p);
	return true;

}



void Hospital::processPatient(unsigned codM1) {
	Patient p(codM1,"complete");
	list<Doctor>::iterator it;
	bool flag=true;
	for(it = doctors.begin(); it != doctors.end();it++) {
		if(it->getCode()==codM1) {
			try
			{
				p=it->removeNextPatient();
			}
			catch(Doctor::PatientInexistent &e)
			{
				return;
			}
			flag=false;
			break;
		}
	}
	if(flag)
		return;
	bool stacked = false;
	list<stack<Patient>>::iterator it2;
	for(it2=letterTray.begin();it2 != letterTray.end();it2++) {
		if(it2->size() < trayCapacity) {
			it2->push(p);
			stacked = true;
			break;
		}
	}
	if(!stacked) {
		stack<Patient> stk;
		stk.push(p);
		letterTray.push_back(stk);
	}

}


unsigned Hospital::removePatients(unsigned codP1) {
	unsigned num=0;
	list<stack<Patient>>::iterator it;
	list<stack<Patient>>::iterator it_aux;
	for(it=letterTray.begin(); it != letterTray.end();it++) {
		if(it->top().getCode()== codP1) {
			num++;
			it->pop();
			if(it->empty()) {
				it_aux = it;
				it_aux++;
				letterTray.erase(it);
				it = it_aux;
			}
		}
	}
	return num;
}



