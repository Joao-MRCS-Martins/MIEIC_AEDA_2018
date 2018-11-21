/*
 * Supermercado.cpp
 *
 * Created on: Dec 3, 2014
 *
 */

#include "Supermercado.h"

int Cliente::numeroItens() const {
	int n=0;
	list<Cesto>::const_iterator it;
	for(it= cestos.begin();it!=cestos.end();it++) {
		n += it->getItens().size();
	}
	return n;
}

int Cliente::valorItens() const {
	int p =0;
	stack<Item> itens;
	list<Cesto>::const_iterator it;
	for(it = cestos.begin(); it!=cestos.end();it++) {
		itens = it->getItens();
		while(!itens.empty()) {
			p += itens.top().preco;
			itens.pop();
		}
	}
	return p;
}

int Cliente::trocarItem(Item &novoItem) {
	int n =0;
	list<Cesto>::iterator it;
	for(it=cestos.begin();it!=cestos.end();it++) {
		vector<Item> v1;
		int size = it->getItens().size();
		while(size >0) {
			if((it->getItens().top().produto == novoItem.produto) || (it->getItens().top().preco > novoItem.preco)) {
				v1.push_back(novoItem);
				n++;
			}
			else {
				v1.push_back(it->getItens().top());
			}
			it->popItem();
			size--;
		}
		for(size_t i = 0; i < v1.size();i++) {
			it->pushItem(v1[v1.size()-1-i]);
		}
	}
	return n;
}

bool Compare (Item &i1, Item &i2) {
	return i1.peso > i2.peso;
}

void Cliente::organizarCestos() {
	list<Cesto>::iterator it;
	vector<Item> v1;
	stack<Item> stk;
	for(it = cestos.begin();it != cestos.end();it++) {
		stk = it->getItens();
		while(!stk.empty()) {
			v1.push_back(stk.top());
			stk.pop();
			it->popItem();
		}
		sort(v1.begin(),v1.end(),Compare);
		for(size_t i=0;i<v1.size();i++) {
			it->pushItem(v1[i]);
		}
		v1.clear();
	}
}

vector<string> Cliente::contarItensPorTipo() {
	vector<pair<string,int>> pares;
	list<Cesto>::iterator it;
	stack<Item> stk;
	for(it=cestos.begin();it!=cestos.end();it++) {
		stk = it->getItens();
		int size = it->getItens().size();
		while(size >0) {
			Item current = stk.top();
			bool found = false;
			size_t i;
			for(i =0;i<pares.size();i++) {
				if(pares.at(i).first == current.tipo) {
					found = true;
					break;
				}
			}
			if(found)
				pares[i].second++;
			else
				pares.push_back(pair<string,int>(current.tipo,1));
			stk.pop();
			size--;
		}
	}
	vector<string> tipos;
	for(size_t j=0;j<pares.size();j++) {
		tipos.push_back(pares[j].first + " " + to_string(pares[j].second));
	}
	return tipos;
}

int Cesto::novoItem(const Item &umItem) {
	if(((umItem.peso + peso) > max_peso) || (umItem.volume + volume) >max_volume)
		return 0;
	else {
		itens.push(umItem);
		peso += umItem.peso;
		volume += umItem.volume;
		return itens.size();
	}
}

int Cliente::novoItem(const Item &umItem) {
	list<Cesto>::iterator it;
	bool placed = false;
	for(it = cestos.begin(); it != cestos.end(); it++) {
		if(it->novoItem(umItem) !=0)
			placed = true;
	}
	if(placed)
		return cestos.size();
	else {
		Cesto c;
		c.pushItem(umItem);
		cestos.push_back(c);
		return cestos.size();
	}
}

int Supermercado::novoCliente(Cliente &umCliente) {
	if(umCliente.getIdade() >= 65) {
		if(tamanhoFilaNormal() < tamanhoFilaPrioritaria()) {
			filaNormal.push(umCliente);
		}
		else
			filaPrioritaria.push(umCliente);
	}
	else
		filaNormal.push(umCliente);
	return getFilaNormal().size() + getFilaPrioritaria().size();
}

Cliente Supermercado::sairDaFila(string nome) {
	bool found = false;
	queue<Cliente> qc_n;
	queue<Cliente> qc_p;
	Cliente c;
	while(!filaNormal.empty()) {
		if(filaNormal.front().getNome()==nome) {
			found = true;
			c=filaNormal.front();
		}
		else
			qc_n.push(filaNormal.front());
		filaNormal.pop();
	}
	setFilaNormal(qc_n);
	if(found)
		return c;
	while(!filaPrioritaria.empty()) {
		if(filaPrioritaria.front().getNome() == nome) {
			found = true;
			c = filaPrioritaria.front();
		}
		else
			qc_p.push(filaPrioritaria.front());
		filaPrioritaria.pop();
	}
	setFilaPrioritaria(qc_p);
	if(found)
		return c;
	else
		throw ClienteInexistente(nome);
}
