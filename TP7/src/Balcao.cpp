#include <queue>
#include <cstdlib>
#include "Balcao.h"

using namespace std;


Cliente::Cliente() {
	numPresentes = rand() % 5 + 1;
}


int Cliente::getNumPresentes() const {
	return numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te) {
	tempo_atual = 0;
	clientes_atendidos = 0;
	prox_chegada= rand() % 20 +1;
	prox_saida = 0;
}      


void Balcao:: proximoEvento()
{
	if(tempo_atual ==0)
	{
		chegada();
		if(prox_saida < prox_chegada)
			tempo_atual = prox_saida;
		else
			tempo_atual = prox_chegada;
	}
	else if (prox_saida<prox_chegada)
	{
		saida();
		tempo_atual=prox_saida;
	}
	else
	{
		chegada();
		tempo_atual=prox_chegada;
	}
}


void Balcao::chegada()
{
	Cliente c;
	if(clientes.empty())
		prox_saida = tempo_atual + c.getNumPresentes()*tempo_embrulho;
	clientes.push(c);
	prox_chegada = rand() % 20 +1;
	cout << "tempo= " << tempo_atual << "\nchegou novo clientes com " << c.getNumPresentes() << " presentes\n";

}   


void Balcao::saida()
{
	Cliente c = getProxCliente();
	clientes.pop();
	clientes_atendidos++;
	prox_saida = tempo_atual + clientes.front().getNumPresentes()*tempo_embrulho;
	cout << "tempo= " << tempo_atual << "\nsaiu cliente com " << c.getNumPresentes() << " presentes\n";

}


int Balcao::getTempoAtual() const { return tempo_atual; }


int Balcao::getProxChegada() const { return prox_chegada; }

int Balcao::getClientesEmEspera() const
{
	return clientes.size();
}

ostream & operator << (ostream & out, const Balcao & b1)
{
	out << "Numero de clientes atendidos: " << b1.getClientesAtendidos() << "\nNumero de clientes em espera: " << b1.getClientesEmEspera() << endl;
     return out;
}


int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}


int Balcao::getProxSaida() const {
	return prox_saida;
}


int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}


Cliente & Balcao::getProxCliente() {
	if(clientes.empty())
		throw FilaVazia();
	else
		return clientes.front();
}

      
