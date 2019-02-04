/*
 * FEUPConsulting.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "FEUPConsulting.h"

FEUPConsulting::FEUPConsulting(): expertizes(Expertize("", 0)) {
}

FEUPConsulting::FEUPConsulting(vector<Project*> projects): expertizes(Expertize("", 0)) {
	this->projects = projects;
}

void FEUPConsulting::addProjects(vector<Project*> projects) {
	this->projects = projects;
}

vector<Project*> FEUPConsulting::getProjects() const{
	return this->projects;
}


// get the expertize objet with the given name, including all students with the corresponding skills
Expertize FEUPConsulting::getExpertize(string name, unsigned cost) {
	Expertize itemNotFound("", 0);
	Expertize expertize(name, cost);
	Expertize search = expertizes.find(expertize);

	return search;
}


void FEUPConsulting::addProject(Project* project) {
	//TODO
	Expertize itemNotFound("", 0);
	Expertize expertize(project->getExpertize(), project->getCost());
	Expertize search = expertizes.find(expertize);

	if(search == itemNotFound) {
		this->expertizes.insert(expertize);
	}

	projects.push_back(project);
}

BST<Expertize> FEUPConsulting::getExpertizes() const {
	return this->expertizes;
}

void FEUPConsulting::addNewExpertize(const Expertize & expertize1) {
	this->expertizes.insert(expertize1);
}

vector<StudentPtr> FEUPConsulting::getStudents() const {
	vector<StudentPtr> ptrs;
	HashTabStudentPtr::const_iterator it1 = this->students.begin();
	HashTabStudentPtr::const_iterator it2 = this->students.end();
	for(; it1 != it2; it1++) {
			ptrs.push_back(*it1); //We can make it a bit more complex by considering only records with a condition!
	}
	return ptrs;
}

void FEUPConsulting::setStudents(vector<StudentPtr>& newStudents) {
	for(int i = 0; i < newStudents.size(); i++) students.insert(newStudents[i]);
}

priority_queue<Student> FEUPConsulting::getActiveStudents() const {
	return activeStudents;
}
void FEUPConsulting::setActiveStudents(priority_queue<Student>& students) {
	activeStudents = students;
}


//
// TODO: Part I   - BST
//

void FEUPConsulting::addAvailability(Student* student, string expertizeAvailable, unsigned cost) {
	BSTItrLevel<Expertize> bt(expertizes);
	Expertize exp(expertizeAvailable,cost);
	while(!bt.isAtEnd()) {
		Expertize exp1 = bt.retrieve();
		if(exp == exp1) {
			exp = exp1;
			expertizes.remove(exp1);
			break;
		}
		bt.advance();
	}
	exp.addConsultant(student);
	expertizes.insert(exp);
}

vector<Student*> FEUPConsulting::getCandidateStudents(Project* project) const {
	BSTItrLevel<Expertize> bt(expertizes);
	Expertize exp(project->getExpertize(),project->getCost());
	bool flag=true;
	while(!bt.isAtEnd()) {
		Expertize exp1 = bt.retrieve();
		if(exp == exp1) {
			exp = exp1;
			flag = false;
			break;
		}
			bt.advance();
		}
	if(flag)
		return {};
	vector<Student *> temp = exp.getConsultants();
	for(size_t i = 0; i < temp.size();i++) {
		if(temp[i]->getCurrentProject() != "")
		{
			temp.erase(temp.begin()+i);
			i--;
		}
	}
	return temp;
	}




bool FEUPConsulting::assignProjectToStudent(Project* project, Student* student) {
	if(project->getConsultant() != NULL)
		return false;
	BSTItrLevel<Expertize> bt(expertizes);
	Expertize exp(project->getExpertize(),project->getCost());
	bool found = false;
	while(!bt.isAtEnd()) {
		Expertize exp1 = bt.retrieve();
		if(exp == exp1) {
			exp = exp1;
			found = true;
			break;
		}
		bt.advance();
	}
	if(!found)
		return found;
	vector<Student *> temp = exp.getConsultants();
	Student *st = NULL;
	for(size_t i = 0; i < temp.size();i++) {
		if(temp[i]->getName() == student->getName())
		{
			st=student;
			break;
		}
	}
	if(st == NULL)
		return false;
	else if(st->getCurrentProject() != ""){
		return false;
	}
	else {
		project->setConsultant(st);
		student->addProject(project->getTitle());
		return true;
	}



}

//
// TODO: Part II  - Hash Table
//

void FEUPConsulting::addStudent(Student* student) {

students.insert(student);
}

void FEUPConsulting::changeStudentEMail(Student* student, string newEMail) {
	student->setEMail(newEMail);

}


//
// TODO: Part III - Priority Queue
//

void FEUPConsulting::addActiveStudents(const vector<Student>& candidates, int min) {
	for(size_t i = 0; i< candidates.size();i++) {
		if(candidates[i].getPastProjects().size() >= min)
			this->activeStudents.push(candidates[i]);
	}

}


int FEUPConsulting::mostActiveStudent(Student& studentMaximus) {

	priority_queue<Student> queue = this->getActiveStudents();
	if(queue.empty())
		return 0;
	Student top = queue.top();
	cout << "Top student n: " << top.getPastProjects().size() << endl;
	queue.pop();
	Student temp("","");
	while(!queue.empty()) {
		cout << "Top student n: " << queue.top().getPastProjects().size() << endl;
		temp = queue.top();
		if(temp.getPastProjects().size() == top.getPastProjects().size())
			return 0;
		queue.pop();
	}
	studentMaximus = top;
	return activeStudents.size();

}





















