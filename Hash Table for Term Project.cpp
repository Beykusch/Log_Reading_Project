#include <iostream>
#include <string>

using namespace std;

struct HT_element {
    string key = "";
    int value = 0;
};

class filenameHashTable {

public:
    bool is_full() const;
    void print_table() const;
    void insert_item(HT_element item);
    HT_element get_item(const string key) const;
    // void remove_item(const string key);
    int hash_function(const string key) const;
    // int search_key(const string key) const;
    filenameHashTable(int size);
    ~filenameHashTable();

private:
    int table_size;
    int count;
    HT_element* hash_table;

};

bool filenameHashTable::is_full() const {
    return count == table_size;
}

void filenameHashTable::print_table() const {
    for (int i = 0; i < table_size; i++) {
        cout << hash_table[i].key << endl;
    }
}

filenameHashTable::filenameHashTable(int size) {
    count = 0;
    table_size = size;
    hash_table = new HT_element[table_size];
}

filenameHashTable::~filenameHashTable() {
    delete[] hash_table;
}
// this hash function will be changed with a better one.
int filenameHashTable::hash_function(const string key) const {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        hash += (key[i] * 57);
    }
    return hash % table_size;
}

void filenameHashTable::insert_item(HT_element item) {
    if (is_full()) {
        cerr << "Hash Table Is Full" << endl;
    }
    else {
        int position = hash_function(item.key);
        if (hash_table[position].key == "") {
            item.value++;
            hash_table[position] = item;
        }
        else if (hash_table[position].key == item.key) {
            hash_table[position].value++;
        }

    }
}

HT_element filenameHashTable::get_item(const string key) const {
    int position = hash_function(key);
    return hash_table[position];
}

int main() {
    string names[] = { "index.html", "1.html", "2.gif", "2.html", "1.html" };
    filenameHashTable my_ht = filenameHashTable(50);
    
    for (string name : names) {
        HT_element te;
        te.key = name;
        my_ht.insert_item(te);
    }

    my_ht.print_table();
    HT_element testing_elem = my_ht.get_item("1.html");
    cout << "----------------------------" << endl;
    cout << testing_elem.key << endl;
    cout << testing_elem.value << endl;

    return 0;
}