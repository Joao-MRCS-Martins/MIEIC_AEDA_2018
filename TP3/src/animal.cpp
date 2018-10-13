
#include "animal.h"

string Animal::getNome() const {
	return nome;
}

int Animal::maisJovem = 1000;

Animal::Animal(string nome,int idade) {
	this->nome = nome;
	this->idade = idade;
	if (idade < getMaisJovem())
		maisJovem = idade;
}

Cao::Cao(string nome, int idade, string raca) : Animal(nome,idade) {
	this->raca = raca;
}

Voador::Voador(int vmax,int amax) {
	velocidade_max = vmax;
	altura_max = amax;
}

Morcego::Morcego(string nome,int idade,int vmax,int amax) : Animal(nome,idade) , Voador(vmax,amax) {

}

int Animal::getMaisJovem() {
	return maisJovem;
}

bool Cao::eJovem() const {
	if(idade < 5)
		return true;
	else return false;
}

bool Morcego::eJovem() const {
	if (idade < 4)
		return true;
	else return false;
}


bool Animal::eJovem() const{
	return true;
}

string Animal::getInformacao() const{
	string s1;
	s1 = nome + ", " + to_string(idade) + ", " ;
	if(vet == NULL)
		return s1;
	s1 += vet->getNome() + ", " + to_string(vet->getCod()) + ", ";
	return s1;
}

string Cao::getInformacao() const {
	string s1 = Animal::getInformacao();
	s1 += raca;
	return s1;
}

string Voador::getInformacao() const {
	string s1 = to_string(velocidade_max) + ", " + to_string(altura_max);
	return s1;
}

string Morcego::getInformacao() const {
	string s1 = Animal::getInformacao() + Voador::getInformacao();
	return s1;
}

void Animal::setVeterinario(Veterinario *v1) {
	vet = v1;
}

string Animal::getNomeVet() const {
	return vet->getNome();
}

long Animal::getCodVet() const {
	return vet->getCod();
}

int Animal::getIdade() const {
	return idade;
}
