#include "hashtable.cpp"

int main() {
    HashTable<int, int> hash_table(5);
    hash_table.insert(1, 2);
    hash_table.insert(1, 3);
    hash_table.insert(2, 8);
    hash_table.insert(4, 9);
    hash_table.search(1);
    hash_table.remove(8);
    hash_table.remove(5);
    hash_table[3] = 5;
    cout << hash_table[3] << endl;
    return 0;
}
