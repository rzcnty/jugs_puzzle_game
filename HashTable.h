#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "data_types.h"

// ========  YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) COMMANDS ============
#define HASH_TABLE_BASED_SIZE 25
#define HASH_TABLE_INCREASING_RATE 70
#define MAX_KEY_SIZE 12

/* Since MAX_KEY_SIZE is 16, we will support jugs up to two-digit numbers. Why? 
Because there are at most 3 jugs. 2*3=6. 2 commas came. 8. 
And a null came. 9. So 12 is a sufficient number. - Riza */

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================
typedef struct {
    unsigned int size;
    unsigned int count;
    unsigned char** State_Key;
} Hash_Table;


// =========  YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DECLARATIONS =======
void Generate_HashTable_Key(const State *const state, unsigned char* key);
//It is prototype, please don't touch -Riza

// ======= YOU DO NOT NEED TO CHANGE THIS COMPULSORY DECLARATIONS ==============
Hash_Table* New_Hash_Table(const int size);
void Resize_Hash_Table(Hash_Table *ht, const int size);
void Delete_Hash_Table(Hash_Table *ht);
void ht_insert(Hash_Table *ht, const State *const state);
void ht_insert_key(Hash_Table *ht, const char *key);
int ht_search(Hash_Table *ht, const State *const state);
void Show_Hash_Table(Hash_Table *ht);


#endif
