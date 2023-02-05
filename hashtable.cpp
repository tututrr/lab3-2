#pragma once
#include<iostream>
#include <vector>
#include <list>
#include "others.h"
#include "hashtable.h"
using namespace std;

template<class K, class V>
using slist = list<HT_Node<K, V> >;

template<class K, class V>
HT_Node<K,V>::HT_Node() {
    key = 0;
 	value = 0;
}
template<class K, class V>
 HT_Node<K, V>::HT_Node(const K& key,const V& value) {
 	this->key = key;
 	this->value = value;
}

template<class K, class V>
HashTable<K,V>::HashTable() {
 	count = 0;
	table.resize(size_of_HT, list<HT_Node<K, V> >());
}
template<class K, class V>
HashTable<K, V>::HashTable(int size_of_HT) { 
 	this->size_of_HT = size_of_HT;
	count = 0;
 	table.resize(size_of_HT, list<HT_Node<K, V> >());
}
 template<class K, class V>
 HashTable<K, V>::~HashTable() {
	table.clear();
}

template<class K, class V>
int HashTable<K, V>::hash(const K& key) {
 	return key % nearest_prime_number(size_of_HT);
}
template<class K, class V>
void HashTable<K, V>::insert(const K& key, const V& value) {
	int pos = hash(key);
 	HT_Node<K, V> b(key, value);
	slist<K, V>& ls = table.at(pos);
	if(!ls.empty()){
		for(typename slist<K, V>::iterator it = ls.begin(); it != ls.end(); ++it){
			if(it->key == key){
				ls.push_front(b);
				return;
			}
		}
	}
	table[pos].push_front(b);
	count++;
}
template<class K, class V>
bool HashTable<K, V>::search(const K& key) {
 	int pos = hash(key);
	slist<K, V> ls = table.at(pos);
	if (ls.size() < 1){
		return false;
	}
	for (typename slist<K, V>::iterator it = ls.begin() ; it != ls.end() ; ++it ) {
		if (it->key == key ) {
			return true;
		}
	}
	return false;
}
template<class K, class V>
const V HashTable<K, V>::operator[](int key){
	int pos = hash(key);
	slist<K, V>& ls = table.at(pos);

	if(ls.size() < 1){
		return (V) 0;
	}
	for(typename slist<K, V>::iterator it = ls.begin() ; it != ls.end() ; ++it){
		if(it->key == key){
			return (it->value);
		}
	}
	insert(key, V());
	return operator[](key);
}

template<class K, class V>
void HashTable<K, V>::remove(const K& key) {
 	int pos = hash(key);
	slist<K, V>& ls = table.at(pos);
	if(!ls.empty()){
		for(typename slist<K, V>::iterator it = ls.begin(); it != ls.end(); ++it){
			if(it->key == key){
				ls.clear();
				return;
			}
		}
	}
 	else {
 		cout << "Can't remove, hash table doesn't have the key" << key << endl;
		return;
 	}
}

