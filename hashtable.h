#pragma once
#ifndef _HASH_TABLE_
#define _HASH_TABLE_
template<class K, class V>
class HT_Node {
public:
 	K key;
 	V value;

	HT_Node();
 	HT_Node(const K& key, const V& value);
};

template<class K, class V>
class HashTable {
 	int size_of_HT = 16;
 	vector<list<HT_Node<K, V> > > table;
 	int count;
 	double load_factor = 0.75;
public:
	HashTable();
 	HashTable(int size_of_HT);
 	~HashTable();

	int hash(const K& key);
	const V operator[](int key);
 	void insert(const K& key, const V& value);
 	bool search(const K& key);
	void remove(const K& key);
};

#endif
