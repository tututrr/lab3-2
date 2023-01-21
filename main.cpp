#include "hashtable.cpp"

int main() {
    HashTable<int, int> hash_table(5);
    hash_table.insert(1, 2);
    hash_table.insert(1, 3);
    hash_table.insert(2, 8);
    hash_table.insert(4, 9);
    hash_table.remove(2);
    hash_table.print_table();
    return 0;
}

