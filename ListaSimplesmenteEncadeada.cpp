#include <stdlib.h>
#include "ListaSimplesmenteEncadeada.h"

SLlist *sllCreate(){
    SLlist *l = new SLlist;
    if(l!=NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

int sllDestroy(SLlist *l){
    if(l!=NULL){
        if(l->first==NULL){
            delete[]l;
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertFirst(SLlist *l, void *data){
    SLNode *newNode;
    if(l!=NULL){
        newNode = new SLNode;
        if(newNode!=NULL){
            newNode->next = l->first;
            newNode->data = data;
            l->first = newNode;
            return TRUE;
        }
    }
    return FALSE;
}

int cmp(void *a, void *b){
    int chave = 0;
    if(a==b){
        chave = 1;
    }
    return chave;
}

void *sllQuery(SLlist *l, void *key, int(*cmp)(void *data, void *data2)){
    SLNode *cur;
    int stat, n=0;
        if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            stat = cmp(key, cur->data);
            while(stat!=TRUE && cur->next!=NULL){
                cur = cur->next;
                stat = cmp(cur->data, key);
            }
                if(stat==TRUE){
                    return cur->data;
                }
            }
        }
    return NULL;
}

void *sllRemoveSpec(SLlist *l, void *key, int(*cmp)(void *data, void *data2)){
    SLNode *next, *prev, *cur;
    int stat;
    void* data;
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            prev = NULL;
            stat = cmp(cur->data, key);
            while(stat!=TRUE && cur->next!=NULL){
                prev = cur;
                cur = cur->next;
                stat = cmp(cur->data, key);
            }
            if(stat==TRUE){
                if(prev!=NULL){
                    prev->next = cur->next;
                }else{
                    l->first = cur->next;
                }
                data = cur->data;
                delete[]cur;
                return data;
            }
        }
    }
    return NULL;
}

