#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define LIST_NODE_HEAD( NODE )    \
typedef struct TAG_##NODE NODE;   \
struct TAG_##NODE                 \
{                                 \
  LIST list;
#define LIST_NODE_TAIL(NODE)      \
};

// Double linked List structure.
// The LIST structure is the link element of the double linked List.
// It is used as either a List Head, or as link entry.
//
// By means of such elements any structures may be handled as a double linked List.
// The LIST structure is to be inserted into the structure which is to be handled.
typedef struct TAG_LIST LIST;
struct TAG_LIST
{
  LIST * next;     // Pointer to the successor (forward link).
  LIST * prev;     // Pointer to the predecessor (backward link).
};

typedef struct TAG_LIST_HEAD LIST_HEAD;
struct TAG_LIST_HEAD
{
  LIST * first;
  uint32_t count;
};

typedef uint32_t LIST_QUERY_CB( void * list, void * context );

void LIST_InitHead( LIST_HEAD * head );
void LIST_Insert( LIST_HEAD * head, void * list );
void LIST_Remove( LIST_HEAD * head, void * list );
void LIST_RemoveAll( LIST_HEAD * head );
void * LIST_Query( LIST_HEAD * head, LIST_QUERY_CB * cb, void * context );
void * LIST_GetFirst( LIST_HEAD * head );
void * LIST_GetNext( void * current );
uint32_t LIST_GetCount( LIST_HEAD * head );

#endif /* __LIST_H__ */
