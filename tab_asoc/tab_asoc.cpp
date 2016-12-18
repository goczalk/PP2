# include <iostream>
# include <stdexcept>
# include <strings.h>
# include "tab_asoc.hpp"


AssocTab::AssocTab(){
	head = NULL;
}

AssocTab::AssocTab(const AssocTab& t){
	head = NULL;
	
	node_t* temp;
	for(temp=t.head; temp != NULL; temp = temp->next){
		insert(temp->key, temp->value);
	}
}

AssocTab::~AssocTab(){
    clear();
}

AssocTab& AssocTab::operator = (const AssocTab& t){
	if (&t == this){
		return *this;
	}
	
	AssocTab temp(t);
	swap(temp);
	return *this;
}

int& AssocTab::operator[](const char* key){
	return find(key)->value;
}

void AssocTab::print(){
	node_t * o;
    for(o = head; o != NULL; o = o->next){
        std::cout << "key: " << o->key << ", value: " << o->value << std::endl;
    }
}

//private
void AssocTab::clear(){
	node_t * o, *temp;
    for(o = head; o != NULL; o = temp){
        temp = o->next;
        delete o;
    }
}

void AssocTab::delete_node(const char* key){
	node_t* found;
	found = find(key);
	
	if (found == head){
		head = found->next;
	}
	else{
		node_t * o;
		for(o = head; o->next != found; o = o->next);
		o->next = found->next;
	}
	delete found;	
}

AssocTab::node_t* AssocTab::find(const char* key) const{
	node_t * o;
    for(o = head; o != NULL; o = o->next){
		if (o->key == key){
			break;
		}
		else{
			if (o->next == NULL){
				throw std::out_of_range("No such key in AssocTab");}
		}
	}
	return o;
}

AssocTab_CaseIns::node_t* AssocTab_CaseIns::find(const char* key) const{
	node_t * o;
    for(o = head; o != NULL; o = o->next){
		if (!strcasecmp(o->key, key)){
			break;
		}
		else{
			if (o->next == NULL){
				throw std::out_of_range("No such key in AssocTab");}
		}
	}
	return o;
}

void AssocTab::insert(const char* key, int value){
	node_t* wsk = new node_t;
	wsk->next = NULL;
	wsk->key = const_cast<char *>(key);
	wsk->value = value;

	if (head == NULL){
		head = wsk;
		return;
	}

	node_t * temp;
	//go to last element
    for(temp = head; temp->next != NULL; temp=temp->next);
    temp->next = wsk;
}

void AssocTab::swap(AssocTab& t){
	node_t* temp = t.head;
	t.head = head;
	head = temp;
}
