#include <iostream>
#include <unordered_set>
using namespace std;
 
template<class T>
void union_(unordered_set<T>& h1, unordered_set<T>& h2, unordered_set<T>& united) {
    united.insert(h1.begin(), h1.end());
    united.insert(h2.begin(), h2.end());
}
template<class T>
void intersection_(unordered_set<T>& h1, unordered_set<T>& h2, unordered_set<T>& crossed) {
    for (auto& el1 : h1) {
        for (auto& el2 : h2) {
            if (el1 == el2)
            crossed.insert(el1);
        }
    }
}
template<class T>
void delete_(unordered_set<T>& h, const T& key) {
    h.erase(key);
}
template<class T>
void print_(unordered_set<T> & final) {
    for (auto& el : final) cout << el << ' ';
    cout << endl;
}
 
int main() {
    unordered_set<int> unord_set1, unord_set2, unord_set3;
    unord_set1.insert(1);
    unord_set1.insert(7);
    unord_set2.insert(1);
    unord_set2.insert(8);
    union_(unord_set1, unord_set2, unord_set3);
    print_(unord_set3);
    return 0;
}
