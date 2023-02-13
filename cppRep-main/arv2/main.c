#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int key;
  int value;
  struct Node *next;
};

struct HashTable
{
  int size;
  struct Node **table;
};

struct HashTable *createHashTable(int size)
{
  struct HashTable *ht = (struct HashTable *)malloc(sizeof(struct HashTable));
  ht->size = size;
  ht->table = (struct Node **)malloc(sizeof(struct Node *) * size);

  for (int i = 0; i < size; i++)
  {
    ht->table[i] = NULL;
  }

  return ht;
}

int hashCode(struct HashTable *ht, int key)
{
  return key % ht->size;
}

void insert(struct HashTable *ht, int key, int value)
{
  int index = hashCode(ht, key);

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = ht->table[index];

  ht->table[index] = newNode;
}

int search(struct HashTable *ht, int key)
{
  int index = hashCode(ht, key);

  struct Node *node = ht->table[index];
  while (node != NULL)
  {
    if (node->key == key)
    {
      return node->value;
    }
    node = node->next;
  }

  return -1;
}

void delete(struct HashTable *ht, int key)
{
  int index = hashCode(ht, key);

  struct Node *prev = NULL;
  struct Node *node = ht->table[index];
  while (node != NULL)
  {
    if (node->key == key)
    {
      if (prev == NULL)
      {
        ht->table[index] = node->next;
      }
      else
      {
        prev->next = node->next;
      }
      free(node);
      break;
    }
    prev = node;
    node = node->next;
  }
}

int main()
{
  struct HashTable *ht = createHashTable(10);

  insert(ht, 1, 10);
  insert(ht, 2, 20);
  insert(ht, 3, 30);

  printf("%d\n", search(ht, 1));
  printf("%d\n", search(ht, 2));
  printf("%d\n", search(ht, 3));

  delete (ht, 2);

  printf("%d\n", search(ht, 2));

  return 0;
}
