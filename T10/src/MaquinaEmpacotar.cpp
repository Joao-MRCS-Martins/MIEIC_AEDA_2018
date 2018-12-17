/*
 * Empacotador.cpp
 */

#include "MaquinaEmpacotar.h"


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


/* a implementar pelos estudantes */

unsigned MaquinaEmpacotar::getCapacidade() const {
	return capacidadeCaixas;
}
unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	unsigned n =0;
	for(size_t i = 0; i < objs.size();i++) {
		if (objs[i].getPeso() <= this->getCapacidade())
		{
			this->objetos.push(objs[i]);
			objs.erase(objs.begin() + i);
			i--;
			n++;
		}
	}
	return n;
}


Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {

	vector<Caixa> vec;
	Caixa cx;
	while(!this->caixas.empty()) {
		if(caixas.top().getCargaLivre() >= obj.getPeso()) {
			cx = caixas.top();
			caixas.pop();
			break;
		}
		else {
		vec.push_back(caixas.top());
		caixas.pop();
		}
	}
	for(size_t i = 0; i < vec.size() ; i++) {
		caixas.push(vec[i]);
	}

	return cx;
}


unsigned MaquinaEmpacotar::empacotaObjetos() {

	vector<unsigned> ids;

	Caixa cx;
	while (!this->objetos.empty()) {
		Objeto obj = objetos.top();
		objetos.pop();
		cx = procuraCaixa(obj);
		if(find(ids.begin(),ids.end(),cx.getID()) == ids.end())
			ids.push_back(cx.getID());
		cx.addObjeto(obj);
		this->caixas.push(cx);
	}
	return ids.size();
}

string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
	if(objetos.empty())
		return "Nao ha objetos!\n";
	vector<Objeto> v1;
	HEAP_OBJS objs=objetos;
	string str;
	while(!objs.empty()) {
		str += "O" + to_string(objs.top().getID()) + ": " + to_string(objs.top().getPeso()) + "\n";
		v1.push_back(objs.top());
		objs.pop();
	}
	return str;
}



Caixa MaquinaEmpacotar::caixaMaisObjetos() const {

	int n =-1;
	HEAP_CAIXAS cxs = caixas;
	Caixa cx;
	if(caixas.empty())
		throw MaquinaSemCaixas();
	while(!cxs.empty()) {
		if(cxs.top().getSize() > n) {
			n = cxs.top().getSize();
			cx = cxs.top();
		}
		cxs.pop();
	}
	return cx;
}



