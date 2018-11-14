/*
 * Agencia.cpp
 */

#include "Agencia.h"

int nID =0;
//Conta
Conta::Conta(int nConta, float sd, int nTrans): numConta(nConta), saldo(sd), numTransacoes(nTrans), titular2(NULL)
{ }

int Conta::getNumConta() const
{ return numConta; }

float Conta::getSaldo() const
{ return saldo; }

int Conta::getNumTransacoes() const
{ return numTransacoes; }


void Conta::setTitular2(Cliente *cli2)
{ titular2=cli2; }

Cliente *Conta::getTitular2() const
{ return titular2; }

bool Conta::levantamento(float valor) {return true;}

void Conta::deposito(float valor) {}

Normal::Normal(int nConta, float sd, int nTrans): Conta(nConta, sd, nTrans)
{}

bool Normal::levantamento(float valor)
{
	if(saldo < valor)
		return false;
	saldo -= valor;
	numTransacoes++;
	return true;
}

void Normal::deposito(float valor)
{
	saldo += valor;
	numTransacoes++;
}

DeOperacao::DeOperacao(int nConta, float tx, float sd, int nTrans): Conta(nConta, sd, nTrans), taxa(tx)
{}

bool DeOperacao::levantamento(float valor)
{
	if(saldo < valor + taxa)
		return false;
	saldo -= (valor + taxa);
	numTransacoes++;
	return true;
}

void DeOperacao::deposito(float valor)
{
	saldo += valor;
	numTransacoes++;
}

//Cliente
Cliente::Cliente (string nm): nome(nm)
{}

string Cliente::getNome() const
{ return nome; }

vector<Conta *> Cliente::getContas() const
{ return contas; }

void Cliente::adicionaConta(Conta *c1)
{ contas.push_back(c1); }


//Agencia
Agencia::Agencia(string desig): designacao(desig)
{}

string Agencia::getDesignacao() const
{ return designacao; }

vector<Cliente *> Agencia::getClientes() const
{ return clientes; }

vector<Gerente> Agencia::getGerentes() const
{ return gerentes; }

void Agencia::adicionaCliente(Cliente *cli1)
{ clientes.push_back(cli1); }

Conta * Agencia::levantamento(string nomeCli,float valor)
{
	for(size_t i=0;i<clientes.size();i++)
	{
		if(clientes[i]->getNome()==nomeCli)
		{
			for(size_t j=0;j<clientes[i]->getContas().size();j++)
			{
				if(clientes[i]->getContas()[j]->levantamento(valor))
					return clientes[i]->getContas()[j];
			}
		}
	}
	Conta* inex = new Conta(-1);
	return inex;
}

float Agencia::fimMes() const
{
	float sum =0;
	for(size_t i = 0; i < clientes.size(); i++)
	{
		for(size_t j=0;j<clientes[i]->getContas().size();j++)
		{
			if(clientes[i]->getContas()[j]->eNormal())
				clientes[i]->getContas()[j]->levantamento(1.5);
			sum += clientes[i]->getContas()[j]->getSaldo();
		}
	}
	return sum;
}

vector<Conta*> Agencia::removeCliente(string nomeCli)
{
	vector<Conta*> contaselim;
	for(size_t i = 0; i< clientes.size();i++)
	{
		if(clientes[i]->getNome() != nomeCli)
		{
			for(size_t k=0;k<clientes[i]->getContas().size();k++)
			{
				if(clientes[i]->getContas()[k]->getTitular2() ==NULL)
					continue;
				if(clientes[i]->getContas()[k]->getTitular2()->getNome()==nomeCli)
					clientes[i]->getContas()[k]->setTitular2(NULL);
			}
		}
	}
	for(size_t i =0; i< clientes.size();i++)
	{
		if(clientes[i]->getNome()==nomeCli)
		{
			for(size_t j=0; j<clientes[i]->getContas().size();j++)
			{
				if(clientes[i]->getContas()[j]->getTitular2() == NULL)
				{
					contaselim.push_back(clientes[i]->getContas()[j]);
				}
				else
				{
					clientes[i]->getContas()[j]->getTitular2()->adicionaConta(clientes[i]->getContas()[j]);
					clientes[i]->getContas()[j]->setTitular2(NULL);
				}
			}
			clientes.erase(clientes.begin()+i);
			break;
		}
	}
	return contaselim;
}

bool Agencia::operator <(const Agencia &a1) const
{
	float sum1 =0, sum2 =0;
	for(size_t i =0;i<clientes.size();i++)
	{
		for(size_t j=0;j<clientes[i]->getContas().size();j++)
		{
			sum1 += clientes[i]->getContas()[j]->getSaldo();
		}
	}
	for(size_t i =0;i<a1.getClientes().size();i++)
	{
		for(size_t j=0;j<a1.getClientes()[i]->getContas().size();j++)
		{
			sum2 += a1.getClientes()[i]->getContas()[j]->getSaldo();
		}
	}
	return (sum1/clientes.size()) < (sum2/a1.getClientes().size());
}

float Agencia::operator ()(const string & name)const
{
	for(size_t i=0;i<clientes.size();i++)
	{
		if(clientes[i]->getNome()==name)
		{
			float saldototal=0;
			for(size_t j=0;j < clientes[i]->getContas().size();j++)
			{
				saldototal += clientes[i]->getContas()[j]->getSaldo();
			}
			return saldototal;
		}
	}
	return -1;
}

void Agencia::setGerenteID(int IDinicio)
{
	nID = IDinicio;
}

void Agencia::adicionaGerente(string nome)
{
	Gerente g(nome);
	gerentes.push_back(g);
}
//Gerente
Gerente::Gerente(string nm)
{
	nome=nm;
	ID = nID;
	nID++;
}

int Gerente::getID() const
{ return ID; }

string Gerente::getNome() const
{ return nome; }


