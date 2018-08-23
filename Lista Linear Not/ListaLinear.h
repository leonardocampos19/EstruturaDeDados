#ifndef LISTALINEAR_H_INCLUDED
#define LISTALINEAR_H_INCLUDED
#include "Triangulo.h"

template <typename Tipo>
// struct declaracao de objetos q dividem as mesmas caracteristicas
// struct lista de atributos da mesma classe
struct Lista {
    Tipo *v; // Ponteiro do tipo fornecido
    int indice;
    unsigned int tamanho;

    Lista(unsigned int tam) {
        tamanho = tam;
        v = new Tipo[tamanho];
        indice = -1;
    }

    void insere (Tipo x) {
        indice++;
        v[indice]=x;
    }

    Tipo remover(int i) {
        Tipo temp=v[i]; // Pega o objeto que será excluído
        do{ // Este laço reorganiza a lista
            if(i!=indice) { // Verifica se o indice do objeto é o último
            v[i] = v[i+1]; // Copia o objeto posterior para a posicao que será excluída
            }
            i++;
        } while(i <= indice);
        indice--; // Diminui o tamanho da lista
        return temp; // Retorna o objeto excluído
    }

    Tipo pegaValor(int pos) {
        return v[pos];
    }

    bool listaCheia(){ // Verifica se a lista está cheia
        return indice==tamanho-1;
    }

    bool listaVazia(){ // Verifica se a lista está vazia
        return indice==-1;
    }

};
#endif // LISTALINEAR_H_INCLUDED
