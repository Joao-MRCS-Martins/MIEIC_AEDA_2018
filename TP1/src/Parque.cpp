#include "Parque.h"
#include <vector>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot),numMaximoClientes(nMaxCli) {
	vagas = lotacao;
}

unsigned int ParqueEstacionamento::getNumLugares() const {
	return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const{
	return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
	for (size_t i=0; i<clientes.size();i++){
		if (clientes.at(i).nome == nome)
			return i;
	}
	return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
	if (clientes.size() == numMaximoClientes)
		return false;
	else {
		InfoCartao cliente;
		cliente.nome = nome;
		cliente.presente= false;
		clientes.push_back(cliente);
		return true;
	}
}

bool ParqueEstacionamento::entrar(const string & nome) {
	if (this->vagas == 0)
		return false;
	int i= posicaoCliente(nome);
	if (i == -1)
		return false;
	else if (clientes.at(i).presente == true )
		return false;
	else {
		clientes.at(i).presente = true;
		vagas--;
		return true;
	}

}

bool ParqueEstacionamento::retiraCliente(const string & nome) {
	int i = posicaoCliente(nome);
	if (i == -1 || clientes.at(i).presente == true)
		return false;
	else {
		clientes.erase(clientes.begin() + i);
		return true;
	}
}

bool ParqueEstacionamento::sair(const string & nome) {
	int i = posicaoCliente(nome);
	if (i == -1 || clientes.at(i).presente == false)
		return false;
	else {
		clientes.at(i).presente = false;
		vagas++;
		return true;
	}
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
	return (lotacao - vagas);
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
	return clientes.size();
}
