#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


typedef struct pair {
    char* key;
    int val;
    struct pair* next;
} Pair;

typedef struct hashmap {
    Pair** list;
    unsigned int cap;
    unsigned int len;
} HashMap;

unsigned hashcode(HashMap*, char*);
Pair* getLastNode(HashMap*);
void set(HashMap*, char*, int);

HashMap* newHashMap() {
    HashMap* this = malloc(sizeof(HashMap*));
    this->cap = 8;
    this->len = 0;
    this->list = calloc(this->cap, sizeof(Pair*));
    return this;
}

int get(HashMap* this, char* key) {
    for (Pair* current = this->list[hashcode(this, key)]; current; current = current->next) {
        if (!strcmp(current->key, key)) {
            return current->val;
        }
    }
    fprintf(stderr, "%s is not found\n", key);
    exit(EXIT_FAILURE);
}

void set(HashMap* this, char* key, int val) {
    unsigned index = hashcode(this, key); 
    for (Pair* current = this->list[index]; current; current = current->next) {
        if (!strcmp(current->key, key)) {
            current->val = val;
            return;
        }
    }
    Pair* pair = malloc(sizeof(Pair*));
    pair->key = key;
    pair->val = val;
    pair->next = this->list[index];
    this->list[index] = pair;
    this->len++;
}

unsigned hashcode(HashMap* this, char* key) {
    unsigned code;
    for (code = 0; *key != '\0'; key++) {
        code = *key + 31 * code;
    }
    return code & (this->cap);
}

void destroyHashMap(HashMap* this) {
    free(this);
}
