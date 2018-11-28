#include "Jogo.h"

BinaryTree<Circulo> & Jogo::getJogo() {
	return jogo;
}


ostream &operator << (ostream &os, Circulo &c1)
{
	os << c1.getPontuacao();
	if(c1.getEstado()) {
		os << "-true-";
	}
	else
		os <<"-false-";
	os << c1.getNVisitas() << endl;
	return os;
}


BinaryTree<Circulo> Jogo::comecaJogo(int pos,int niv,vector<int> &pontos,vector<bool> &estados) {
	Circulo c1(pontos[pos],estados[pos]);

	if(niv ==0) {
		return BinaryTree<Circulo>(c1);
	}

	BinaryTree<Circulo> left = comecaJogo(2*pos+1,niv-1,pontos,estados);
	BinaryTree<Circulo> right = comecaJogo(2*pos+2,niv-1,pontos,estados);

	return BinaryTree<Circulo>(c1,left,right);
}
Jogo::Jogo(int niv, vector<int> &pontos, vector<bool> &estados)
{
	jogo = comecaJogo(0,niv,pontos,estados);
}


string Jogo::escreveJogo()
{
	stringstream ss;
	BTItrLevel<Circulo> bt(jogo);
	while(!bt.isAtEnd()) {
		ss << bt.retrieve();
		bt.advance();
	}
	return ss.str();
}


int Jogo::jogada()
{
	BTItrLevel<Circulo> bt(jogo);
	int pos = 1;
	int pontos = 0;
	while(!bt.isAtEnd()) {
		Circulo &c1 = bt.retrieve();
		if(c1.getPontuacao() != pos) {
			bt.advance();
			continue;
		}

		if(!c1.getEstado()) {
			pos *= 2;
		}
		else
			pos = 2*pos+1;
		c1.trocaEstado();
		c1.incVisitas();
		pontos = c1.getPontuacao();
		bt.advance();
	}

	return pontos;
}



int Jogo::maisVisitado()
{
	int vis=0;
	BTItrLevel<Circulo> bt(jogo);
	while(!bt.isAtEnd()) {
		Circulo & c1 = bt.retrieve();
		if(c1.getPontuacao() == 1) {
			bt.advance();
			continue;
		}
		if(c1.getNVisitas()> vis) {
			vis = c1.getNVisitas();
		}
		bt.advance();
	}
	return vis;
}




