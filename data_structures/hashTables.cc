#include <iostream>
#include "hashTables.h"

using std::cout;
using std::endl;


data_structures_hashTables::HashTable::HashTable()
{
  for(int i=0; i<NUM_HASH_ENTRIES; i++)
  {
    _hashTable[i] = NULL;
  }
}

data_structures_hashTables::HashTable::~HashTable()
{
  for(int i=0; i<NUM_HASH_ENTRIES; i++)
  {
    HashEntry* curr = _hashTable[i];
    while (curr != NULL)
    {
      HashEntry* next = curr->next();
      delete curr;
      curr = next;
    }
  }
}

int data_structures_hashTables::HashTable::get(int key) const
{
  int index = key % NUM_HASH_ENTRIES;
  HashEntry* iter = _hashTable[index];
  int value = -1;
  while (iter != NULL)
  {
    if (iter->key() == key)
    {
      value = iter->value();
      break;
    }
    iter = iter->next();
  }
  
  return value;
}

void data_structures_hashTables::HashTable::put(int key, int value)
{
  int index = key % NUM_HASH_ENTRIES;
  HashEntry* newEntry = new HashEntry(key, value);
  newEntry->setNext(_hashTable[index]);
  _hashTable[index] = newEntry;
}

using data_structures_hashTables::HashTable;

int main(int argc, char* argv[])
{
  HashTable table;
  
  int testValues[] = { 50, 23, 84, 31, 64, 90, 13, 29, 85, 30, -1 };
  
  int idx = 0;
  while (testValues[idx] != -1)
  {
    table.put(testValues[idx], testValues[idx]);
    idx++;
  }
  
  idx = 0;
  while (testValues[idx] != -1)
  {
    cout << table.get(testValues[idx]) << endl;
    idx++;
  }
  
  return 0;
}
