#include "sample_hash_table.h"

Table* create_Table(void){

    Table* t = malloc(sizeof(Table));

    if (t == NULL){
        printf("ERROR: TABLE NOT CREATED\n");
        return NULL;
    }

    t->capacity = TABLE_CAPACITY;
    t->length = 0;
    t->entries = malloc(t->capacity * sizeof(Entry*));


    if (t->entries == NULL){
        printf("ERROR: ENTRIES NOT CREATED\n");
        free(t->entries);
        return NULL;
    }
    return t;
}

Entry* hash_lookup (const char* file, Table* t){

    
    int i;
    i = djb2_hash(file)%t->capacity; //index generated by the hash function
    Entry** e = &(t->entries[i]); ///The address of the Entry pointer found in the index 

    /*
    -IF e is not NULL
    -then there is already an entry at that hash index
    -IF its first in the list, 
    -   RETURN index
    -ELSE
    -   search through list for file, pointing e to it's own next
    -   IF is found then
    -       RETURN entry
    -   ELSE
    -       e now points to the tail of the list at that index so...
    -
    -
    -IF table at max capacity
    -   RETURN NULL
    -CREATE new entry at e
    -   set file name
    -   set chunk data #todo
    -   next is null
    -ELSE
        -RETURN entry
    */
   //printf("file: ");

    if(*e != NULL){
        if((strcmp((*e)->file,file)) == 0)
                return *e;
    
        while((*e)->next != NULL){
            e = &((*e)->next);
            if((strcmp((*e)->file,file)) == 0)
                return *e;
            
        }
        e = &((*e)->next);
    }

    if(t->length > t->capacity){
        printf("capacity is exceed\n");
        return NULL;
    }
    Entry* temp = malloc(sizeof(Entry));
    temp->file = file;
    temp->chunk = NULL; //to add
    temp->next = NULL;
    *e = temp;
    t->length++;
    return *e;
}

unsigned long djb2_hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}