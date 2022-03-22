#include "ListaSimplesmenteEncadeada.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    SLlist *novo = sllCreate();
    int opcao, teste;
    SLNode *aux;
    void *data, *key;
    char letras;
    char *auxLetras;


    do{
        cout << "---------------------------Menu de Alfabeto-------------------------------" << endl;
        cout << "Digite 1 para Inserir uma letra na Lista" << endl;
        cout << "Digite 2 para Pesquisar a Letra na Lista" << endl;
        cout << "Digite 3 para Remover a Letra" << endl;
        cout << "Digite 4 para Imprimir toda a Lista" << endl;
        cout << "Digite 0 para Destruir a Lista e Sair do Programa" << endl;
        cout << endl << endl << "Informe a opcao Desejada: ";
        cin >> opcao;
        cout << endl;

        switch(opcao){
        case 0:
            teste = sllDestroy(novo);
            if(teste==TRUE){
                cout << "Saindo do Programa, Lista Destruida com Sucesso!!" << endl;
            }
            else{
                cout << "Impossivel Destruir Lista, Remova todos os Elementos antes de Destruir!!" << endl;
            }
            break;

        case 1:
            cout << "Informe o Elemento que quer Inserir na Lista: ";
            cin>>letras;
            cout << endl;
            teste = sllInsertFirst(novo, &letras);
            if(teste==TRUE){
                auxLetras = (char*)novo->first->data;
                cout << "Elemento " << auxLetras << " inserido com Sucesso!!" << endl;
            }
            else{
                cout << "Erro, elemento " << (char*)novo->first->data << " nao pode ser inserido" << endl;
            }
            break;

        case 2:
            cout << "Informe o Elemento que quer pesquisar: ";
            cin >> letras;
            cout << endl;

            data = sllQuery(novo, &letras, &cmp);

            if(data!=NULL){
               // numAux = (int)data;
                cout << "O Elemento " << letras << " esta na Lista" << endl;
            }
            else{
                cout << "Erro, Impossivel realizar Busca!!" << endl;
            }
            break;

        case 3:
            cout << "Insira o Elemento que deseja Remover da Lista: ";
            cin >> letras;
            cout << endl;

            data = sllRemoveSpec(novo, &letras, &cmp);

            if(data!=NULL){
                cout << "Elemento " << (char*)data << " encontrado e removido com Sucesso da Lista!!" << endl;
            }
            else{
                cout << "Erro, Elemento " << (char*)data << " nao encontrado na Lista!!" << endl;
            }
            break;

        case 4:
            if(novo!=NULL){
                if(novo->first!=NULL){
                    cout << "Imprimindo Lista Completa:" << endl;
                    aux = novo->first;
                    while(aux!=NULL){
                        cout << (char*)aux->data << " ";
                        aux = aux->next;
                    }
                }
            }
            else{
                cout << "Erro, Impossivel Imprimir Lista" << endl;
            }
            break;
        }
    }
    while(opcao!=0);

    delete []aux;
    delete []data;
    delete []key;
}
