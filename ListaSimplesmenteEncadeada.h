#ifndef LISTASIMPLESMENTEENCADEADA_H
#define LISTASIMPLESMENTEENCADEADA_H
#define TRUE 1
#define FALSE 0

typedef struct _slnode_{
    struct _slnode_*next;
    void *data;
}SLNode;

typedef struct _sll_{
    SLNode *first;
}SLlist;

SLlist *sllCreate();

int sllDestroy(SLlist *l);

int sllInsertFirst(SLlist *l, void *data);

int cmp(void *data, void *data2);

//Retorna a quantidade de Elementos iguais a chave especificada.
void *sllQuery(SLlist *l, void *key, int(*cmp)(void *data, void *data2));

void *sllRemoveSpec(SLlist *l, void *key, int(*cmp)(void *data, void *data2));

//int sllInsertLast(SLlist *l, void *data);

#endif
