#include "zoo.h"


int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1) {
	animais.push_back(a1);
}

string Zoo::getInformacao() const {
	string s1;
	for (size_t i = 0; i< animais.size(); i++) {
		s1 += animais.at(i)->getInformacao() + "\n";
	}
	return s1;
}

bool Zoo::animalJovem(string nomeA) {
	for (size_t i = 0; i < animais.size(); i++) {
		if (animais.at(i)->getNome() == nomeA)
			if (animais.at(i)->eJovem()) {
				return true;
			}
	}
	return false;
}

void Zoo::alocaVeterinarios(istream &isV) {

	string nome;
	string cod;
	while(getline(isV,nome)) {
		getline(isV,cod);
		nome.pop_back();
		cod.pop_back();
		Veterinario *v1 = new Veterinario(nome,stoi(cod));
		veterinarios.push_back(v1);
	}
	size_t i = 0;
	while (i < animais.size()) {
		for (size_t i2=0; i2 < veterinarios.size(); i2++) {
			if (i<animais.size()) {
				animais.at(i)->setVeterinario(veterinarios.at(i2));
				++i;
			}
			else break;
		}
	}
}

bool Zoo::removeVeterinario (string nomeV) {
	size_t i=0;
	for (; i < veterinarios.size(); i++) {
		if (veterinarios.at(i)->getNome()  == nomeV)
			break;
	}

	if (i == veterinarios.size())
		return false;
	veterinarios.erase(veterinarios.begin() + i);
	if (i == (veterinarios.size()-1)) {
		for (size_t i3 = 0; i3 < animais.size() ; i3++) {
			if (animais.at(i3)->getNomeVet() == nomeV) {
				animais.at(i3)->setVeterinario(veterinarios.at(0));
			}
		}
		return true;
	}
	for (size_t i4 = 0; i4 < animais.size();i4++) {
		if (animais.at(i4)->getNomeVet() == nomeV) {
			animais.at(i4)->setVeterinario(veterinarios.at(i));
		}
	}
	return true;
}

int Zoo::sumIdade() const {
	int sum = 0;
	for (size_t i = 0; i < animais.size(); i++) {
		sum += animais.at(i)->getIdade();
	}
	return sum;
}
bool Zoo::operator <(Zoo &zoo2) const {
	if (this->sumIdade() < zoo2.sumIdade())
		return true;
	else return false;
}















