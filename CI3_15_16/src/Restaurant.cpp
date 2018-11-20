/*
 * Restaurant.cpp
 *
 *  Created on: 17/11/2015
 *      Author: hlc
 */

#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant() { }

Restaurant::Restaurant(vector< stack<Dish*> >* cl, queue<Dish*>* di, list<Dish*>* dr) {
	if(cl != NULL) clean = *cl;
	if(di != NULL) dirty = *di;
	if(dr != NULL) drying = *dr;
}

void Restaurant::addTable(unsigned int n_places) {
	tables.push_back(Table(n_places));
}

void Restaurant::addTable(Table& t) {
	tables.push_back(t);
}

const Table& Restaurant::getTable(vector<Table>::size_type idx) const {
	return tables[idx];
}

/**
 * Gets the clean dishes stack for a given collection and type.
 * If there is none, adds and returns an empty stack.
 */
stack<Dish*>& Restaurant::getCleanDishStack(string collection, TypeOfDish type) {

	for(vector< stack<Dish*> >::iterator it = clean.begin(); it != clean.end(); ++it) {
		if((*it).empty() || ((*it).top()->getCollection() == collection && (*it).top()->getType() == type)) {
			return *it;
		}
	}

	stack<Dish*> st;
	clean.push_back(st);
	return clean.back();
}

const queue<Dish*>& Restaurant::getDirty() const {
	return dirty;
}

const list<Dish*>& Restaurant::getDrying() const {
	return drying;
}

/**
 * Adds a number of dishes of a collection/type to the respective clean stack.
 */
void Restaurant::addDishes(unsigned int n, string collection, TypeOfDish type) {

	for(unsigned int i = 0; i<n;i++) {
		Dish*  d1 = new Dish(collection,type);
		getCleanDishStack(collection,type).push(d1);
	}
}

/**
 * Washes a dish, getting if from the dirty queue and putting it in the wet list.
 * Returns the washed dish.
 */
Dish* Restaurant::washDish() {

	drying.push_back(dirty.front());
	Dish* d = dirty.front();
	dirty.pop();
	return d;
}

/**
 * Clears a table, placing all dishes that are on it in the dirty queue.
 */
void Restaurant::clearTable(vector<Table>::size_type idx) {

	if(idx >= tables.size())
		return;

	vector<Dish*> dirty_dish = tables[idx].clear();
	for(size_t i = 0;i < dirty_dish.size();i++) {
		dirty.push(dirty_dish[i]);
	}
}

/**
 * Stores in the respective clean stack all drying dishes of a given collection and type.
 */
void Restaurant::storeDryDishes(string collection, TypeOfDish type) {
	stack<Dish*> &stack = getCleanDishStack(collection,type);
	list<Dish*>::iterator it, it_aux;
	for(it = drying.begin();it != drying.end();) {
		if((*it)->getCollection() == collection && (*it)->getType() == type) {
			stack.push((*it));
			it_aux = it;
			it_aux++;
			drying.erase(it);
			it = it_aux;
		}
		else
			it++;
	}
}

/**
 * Puts Plates of a given collection in a table.
 * Throws TableNotReadyException when the table is not empty.
 * Throws NotEnoughDishesException when there are not enough clean plates of the collection.
 */
void Restaurant::setupTable(vector<Table>::size_type idx, string collection) {

	if(idx >= tables.size() || idx <0)
		return;
	if(!tables[idx].empty())
		throw TableNotReadyException();

	stack<Dish*> & dishes = getCleanDishStack(collection,Plate);

	if(dishes.size() < tables[idx].size())
		throw  NotEnoughDishesException();

	vector<Dish*> dishesToPutOn;
	for (unsigned int i=0 ; i<tables.at(idx).size() ; i++){
			dishesToPutOn.push_back(dishes.top());
			dishes.pop();
	}
	tables.at(idx).putOn(dishesToPutOn);
}

bool Compare (Dish* d1,Dish* d2) {
	if(d1->getCollection() == d2->getCollection()) {
		return d1->getType() < d2->getType();
	}
	else
		return d1->getCollection() < d2->getCollection();
}
/**
 * Picks the dry dishes and groups them.
 * Returns the grouped dishes.
 */
list<Dish*> Restaurant::pickupAndGroupDryDishes() {
	list<Dish*> dry_grouped = drying;
	drying.clear();

	dry_grouped.sort(Compare);

	return dry_grouped;
}

/**
 * Stores grouped dishes in the respective clean stacks.
 * Returns the number of stacks that have been updated.
 */
int Restaurant::storeGroupedDishes(list<Dish*> grouped_dishes) {
	int n =0;
	string collection;
	TypeOfDish type;
	list<Dish*>::iterator it;
	for(it=grouped_dishes.begin();it!=grouped_dishes.end();it++) {
		collection = (*it)->getCollection();
		type = (*it)->getType();
		n++;
		stack<Dish*> &stack = getCleanDishStack(collection,type);
		while (((*it)->getCollection()==collection) && ((*it)->getType()==type)) {
			stack.push(*it);
			it++;
			if (it == grouped_dishes.end())
				break;
		}
		it--;
	}
	return n;
}

