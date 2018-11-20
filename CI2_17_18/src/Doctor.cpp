/*
 * Doctor.cpp
 */

#include "Doctor.h"


Patient::Patient(unsigned codP, string mS): codeP(codP), medicalSpecialty(mS)
{}

string Patient::getMedicalSpecialty() const {
	return medicalSpecialty;
}

unsigned Patient::getCode() const {
	return codeP;
}

Doctor::Doctor(unsigned codM, string mS): codeM(codM), medicalSpecialty(mS)
{}


Doctor::Doctor(unsigned codM, string mS, queue<Patient> patients1): codeM(codM), medicalSpecialty(mS), patients(patients1)
{}

unsigned Doctor::getCode() const {
	return codeM;
}

string Doctor::getMedicalSpecialty() const {
	return medicalSpecialty;
}

queue<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient &p1) {
	patients.push(p1);
}

Patient Doctor::removeNextPatient() {
	if (!patients.empty()) {
		Patient p1 = patients.front();
		patients.pop();
		return p1;
	}
	else throw PatientInexistent();
}

bool Doctor::operator <(const Doctor &d1)
{
	if(this->getPatients().size() < d1.getPatients().size())
		return true;
	else if (this->getPatients().size() == d1.getPatients().size())
		return this->getMedicalSpecialty() < d1.getMedicalSpecialty();
	else
		return false;
}


void Doctor::moveToFront(unsigned codP1) {
	queue<Patient> q1 = patients;
	queue<Patient> q2;
	while(!q1.empty()) {
		if(q1.front().getCode() == codP1) {
			q2.push(q1.front());
			break;
		}
		q1.pop();
	}

	while(patients.size() > 0) {
		if(patients.front().getCode() == codP1) {
			patients.pop();
			continue;
		}

		q2.push(patients.front());
		patients.pop();
	}
	patients = q2;
}

