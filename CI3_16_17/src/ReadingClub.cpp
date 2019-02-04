/*
 * ReadingClub.cpp
 *
 *  Created on: 11/12/2016
 *      Author: RRossetti
 */

#include "ReadingClub.h"

ReadingClub::ReadingClub(): catalogItems(BookCatalogItem("", "", 0)) {
	//do nothing!
}

ReadingClub::ReadingClub(vector<Book*> books): catalogItems(BookCatalogItem("", "", 0)) {
	this->books = books;
}

void ReadingClub::addBook(Book* book) {
	this->books.push_back(book);
}

void ReadingClub::addBooks(vector<Book*> books) {
	this->books = books;
}

vector<Book*> ReadingClub::getBooks() const{
	return this->books;
}

BookCatalogItem ReadingClub::getCatalogItem(string title, string author) {
	BookCatalogItem itemNotFound("", "", 0);
	BSTItrIn<BookCatalogItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getTitle() == title && it.retrieve().getAuthor() == author) {
			BookCatalogItem bci(it.retrieve().getTitle(), it.retrieve().getAuthor(), 0);
			bci.setItems(it.retrieve().getItems());
			return bci;
		}
		it.advance();
	}
	return itemNotFound;
}

void ReadingClub::addCatalogItem(Book* book) {
	BookCatalogItem itemNotFound("", "", 0);
	BookCatalogItem bci(book->getTitle(), book->getAuthor(), book->getYear());
	BookCatalogItem bciX = catalogItems.find(bci);
	if(bciX == itemNotFound) {
		bci.addItems(book);
		this->catalogItems.insert(bci);
	}
	else {
		this->catalogItems.remove(bciX);
		bciX.addItems(book);
		this->catalogItems.insert(bciX);
	}
	books.push_back(book);
}

BST<BookCatalogItem> ReadingClub::getCatalogItems() const {
	return this->catalogItems;
}

vector<UserRecord> ReadingClub::getUserRecords() const {
	vector<UserRecord> records;
	HashTabUserRecord::const_iterator it1 = this->userRecords.begin();
	HashTabUserRecord::const_iterator it2 = this->userRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void ReadingClub::setUserRecords(vector<UserRecord>& urs) {
	for(int i = 0; i < urs.size(); i++) userRecords.insert(urs[i]);
}

priority_queue<User> ReadingClub::getBestReaderCandidates() const {
	return readerCandidates;
}
void ReadingClub::setBestReaderCandidates(priority_queue<User>& candidates) {
	readerCandidates = candidates;
}



//
// TODO: Part I   - BST
//

void ReadingClub::generateCatalog() {
<<<<<<< Updated upstream
	BookCatalogItem null("","",0);
	for(int i = 0; i < this->books.size(); i++) {
		BookCatalogItem b1 = this->getCatalogItem(books[i]->getTitle(),books[i]->getAuthor());
		BookCatalogItem b2(books[i]->getTitle(),books[i]->getAuthor(),books[i]->getYear());

		if(b1 == null) {
			b2.addItems(books[i]);
						this->catalogItems.insert(b2);
				}
		else {

			b1.addItems(books[i]);
			this->catalogItems.remove(b2);
			this->catalogItems.insert(b1);


		}
	}
=======
	//TODO:
	//...

>>>>>>> Stashed changes
}

vector<Book*> ReadingClub::getAvailableItems(Book* book) const {
	vector<Book*> temp;
<<<<<<< Updated upstream
	BSTItrIn<BookCatalogItem> bt(this->catalogItems);
	while(!bt.isAtEnd()) {
		BookCatalogItem b1 = bt.retrieve();
		if(b1.getAuthor() == book->getAuthor() && b1.getTitle() == book->getTitle()) {
			for(auto i : b1.getItems()) {
				if(i->getReader() == NULL)
					temp.push_back(i);
			}
		}
		bt.advance();
	}
=======
	//TODO:
	//...

>>>>>>> Stashed changes
	return temp;
}

bool ReadingClub::borrowBookFromCatalog(Book* book, User* reader) {
<<<<<<< Updated upstream

	vector<Book*> avail = this->getAvailableItems(book);
	if(avail.size() == 0)
		return false;
	reader->addReading(book->getTitle(),book->getAuthor());
	avail[0]->setReader(reader);
	return true;

=======
	//TODO:
	//...

	return false;
>>>>>>> Stashed changes
}


//
// TODO: Part II  - Hash Table
//

void ReadingClub::addUserRecord(User* user) {
<<<<<<< Updated upstream
	this->userRecords.insert(user);
=======
	//TODO:
	//...
>>>>>>> Stashed changes

}

void ReadingClub::changeUserEMail(User* user, string newEMail) {
<<<<<<< Updated upstream
	for(auto i: this->userRecords) {
		if(i.getEMail() == user->getEMail()) {
			userRecords.erase(i);
			user->setEMail(newEMail);
			userRecords.insert(user);
		}
	}
=======
	//TODO:
	//...

>>>>>>> Stashed changes
}


//
// TODO: Part III - Priority Queue
//

void ReadingClub::addBestReaderCandidates(const vector<User>& candidates, int min) {
<<<<<<< Updated upstream

	for(size_t i =0; i< candidates.size();i++) {
		if(candidates[i].getReadings().size() +1>= min)
			this->readerCandidates.push(candidates[i]);
	}
=======
	//TODO:
	//...
>>>>>>> Stashed changes

}

int ReadingClub::awardReaderChampion(User& champion) {
<<<<<<< Updated upstream
	if(this->readerCandidates.empty())
		return 0;
	if(this->readerCandidates.size() == 1) {
		champion = this->readerCandidates.top();
		return 1;
	}
	else {
		priority_queue<User> temp = readerCandidates;
		User n1 = temp.top();
		int n = readerCandidates.top().getReadings().size();
		temp.pop();
		if(temp.top().getReadings().size() == n)
			return 0;
		champion = n1;
		return readerCandidates.size();
	}
=======
	//TODO:
	//...

	return 0;
>>>>>>> Stashed changes
}
























