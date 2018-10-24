#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <vector>
#include <algorithm>
using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

bool InfoCartao::operator ==(const InfoCartao & ic1) const{
	if(this->nome == ic1.nome)
		return true;
	else return false;
}

bool InfoCartao::operator <(const InfoCartao &ic1) const {
	if(this->frequencia == ic1.frequencia) {
		if(this->nome < ic1.nome)
			return true;
		else return false;
	}
	else if(this->frequencia > ic1.frequencia)
		return true;
	else
		return false;
}
bool comparaNome(const InfoCartao &ic1,const InfoCartao &ic2)  {
	return (ic1.nome <= ic2.nome);
}

bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;  // a fazer
	clientes.push_back(info);
	numClientes++;
	return true;
}
 
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}
  
unsigned int ParqueEstacionamento::getNumLugares() const
{
	return lotacao;
}
                   
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
	return lotacao-vagas;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	vagas--;
	clientes[pos].frequencia++;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

int ParqueEstacionamento::getFrequencia(const string &nome) const {
	int pos = posicaoCliente(nome);
	if (pos == -1)
		throw ClienteNaoExistente(nome);
	else return clientes[pos].frequencia;
}

void ParqueEstacionamento::ordenaClientesPorFrequencia() {
	insertionSort(clientes);
}
void ParqueEstacionamento::ordenaClientesPorNome() {
	sort(clientes.begin(),clientes.end(),comparaNome);
}

vector<string> ParqueEstacionamento::clientesGamaUso(int n1,int n2){
	ordenaClientesPorFrequencia();
	vector<string> v1;
	for(int i =0; i<clientes.size(); i++) {
		if (clientes[i].frequencia >= n1 && clientes[i].frequencia <= n2)
			v1.push_back(clientes[i].nome);
	}
	return v1;
}

ostream & operator << (ostream &os, const ParqueEstacionamento &pe) {
	vector<InfoCartao> cl = pe.getClientes();
	for(int i =0; i<cl.size();i++) {
		os << "Nome: " << cl[i].nome << "Presente: " << cl[i].presenteImprime()
				<< " Frequencia: " << cl[i].frequencia << endl;
	}
	return os;
}

InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const {
	if (p>=clientes.size())
		throw PosicaoNaoExistente(p);
	return clientes[p];
}
// a alterar
int ParqueEstacionamento::posicaoCliente(const string & nome) const {
	InfoCartao a;
	a.nome = nome;
	return sequentialSearch(clientes, a);
}
