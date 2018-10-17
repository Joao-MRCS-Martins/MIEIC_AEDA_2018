
#include "veterinario.h"


string Veterinario::getNome() const {
	return nome;
}

Veterinario::Veterinario(string nome, int cod) {
	this->nome = nome;
	codOrdem = cod;
}

long Veterinario::getCod() const {
	return codOrdem;
}

void Veterinario::setNome(string nomeA) {
	nome = nomeA;
}

void Veterinario::setCod(long cod) {
	codOrdem = cod;
}

bool Veterinario::sameNome(const string & nameV) {
	return (nameV == getNome());
}

