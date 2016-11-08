namespace data_structures_hashTables
{
  class HashEntry
  {
    public:
      HashEntry(int key, int value) : _key(key), _value(value), _next(NULL) {}
      int key() const { return _key; }
      int value() const { return _value; }
      HashEntry* next() const { return _next; }
      void setNext(HashEntry* next) { _next = next; }
      
    private:
      int _key;
      int _value;
      HashEntry* _next;
  };
  
  class HashTable
  {
    public:
      HashTable();
      ~HashTable();
      int get(int key) const;
      void put(int key, int value);
      
    private:
      static const int NUM_HASH_ENTRIES = 20;
      HashEntry* _hashTable[NUM_HASH_ENTRIES];
  };
}