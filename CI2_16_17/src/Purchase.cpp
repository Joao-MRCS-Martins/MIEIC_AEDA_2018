/*
 * Purchase.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: hlc
 */

#include "Purchase.h"

using namespace std;

Purchase::Purchase(long cli) : client (cli) {
}

long Purchase::getClient() const {
	return client;
}

list< stack<Article*> > Purchase::getBags() const {
	return bags;
}

/**
 * Create an Article associated with the client of this purchase.
 */
Article* Purchase::createArticle(long barCode, bool present, bool deliverHome) {

	Article* a1 = new Article(client,barCode);
	a1->setPresent(present);
	a1->setDeliverHome(deliverHome);
	return a1;

}

/**
 * Add an Article to the bags of this purchase. A new bag is added when the last bag is full.
 */
void Purchase::putInBag(Article* article) {
	list<stack<Article*>>::iterator it;
	bool flag = true;
	for(it=bags.begin(); it!=bags.end();it++) {
		if(it->size() < BAG_SIZE) {
			it->push(article);
			flag= false;
			break;
		}
	}
	if(flag) {
		stack<Article*> stk;
		stk.push(article);
		bags.push_back(stk);
	}
}

/**
 * Pop from the bags all articles that are presents.
 * All other articles are pushed back into the bags where they were, maintaining order.
 */
vector<Article*> Purchase::popPresents() {
	vector<Article*> vec;
	list<stack<Article*>>::iterator it;

	for(it = bags.begin(); it != bags.end(); it++) {
		vector<Article*> v1;
		while(!it->empty()) {
			if(it->top()->getPresent()) {
				vec.push_back(it->top());
				it->pop();
			}
			else {
				v1.push_back(it->top());
				it->pop();
			}
		}
			for(size_t i = v1.size()-1;i>=0;i--) {
				it->push(v1[i]);
			}

	}
	return vec;

}

