#include <iostream>
#include "ListaLinear.h"
#include "Triangulo.h"
#include "windows.h"

using namespace std;

int main()
{
    unsigned int opc,a,b,c;
    int tlista, i;
    Triangulo aux;

    do {
        cout << "Digite o tamanho da lista: ";
        cin >> tlista;
        if(tlista < 1) {
            cout << "Tamanho invalido!" << endl;
            system("pause");
            system("cls");
        } else {
            // Cria uma lista de triângulos
            Lista<Triangulo> lista(tlista);
            do{
                cout << "1-Inserir" << endl;
                cout << "2-Remover" << endl;
                cout << "3-Calcular perimetro" << endl;
                cout << "4-Calcular area" << endl;
                cout << "5-Listar" << endl;
                cout << "0-Sair" << endl;
                cout << "Escolha--> ";
                cin >> opc;

                switch(opc) {
                    case 1: {
                        if(!lista.listaCheia()) { // Verifica se a lista está cheia
                            cout << endl << "Digite as medidas do triangulo" << endl;
                            cout << "A: "; cin >> a;
                            cout << "B: "; cin >> b;
                            cout << "C: "; cin >> c;

                            // Cria o triângulo
                            Triangulo t(a,b,c);

                            // Checa se as medidas fornecidas formam um triângulo
                            if(t.isTriangulo()) {
                                lista.insere(t);
                                cout << "Inserido com sucesso!" << endl;
                                system("pause");
                                system("cls");
                            } else {
                                cout << "Nao eh um triangulo!" << endl;
                                system("pause");
                                system("cls");
                            }
                        } else {
                            cout << "A lista esta cheia!" << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    break;

                    case 2:
                        cout << "Digite o indice do objeto que sera excluido: ";
                        cin >> i;
                        lista.remover(i);
                        cout << endl;
                    break;

                    case 3:
                        cout << endl;
                        cout << "Informe o indice: ";
                        cin >> i;
                        if(i < 0 || i > lista.indice) {
                            cout << "Este indice nao existe!" << endl;
                        } else {
                            aux = lista.pegaValor(i);
                            cout << "A area eh: " << aux.mostrarPerimetro() << endl;
                        }
                        system("pause");
                        system("cls");
                    break;

                    case 4:
                        cout << endl;
                        cout << "Informe o indice: ";
                        cin >> i;
                        if(i < 0 || i > lista.indice) {
                            cout << "Este indice nao existe!" << endl;
                        } else {
                            aux = lista.pegaValor(i);
                            cout << "A area eh: " << aux.mostrarArea() << endl;
                        }
                        system("pause");
                        system("cls");
                    break;

                    case 5: {
                        system("cls");
                        if(lista.listaVazia()) {
                            system("cls");
                            cout << "Nao ha triangulos!" << endl;
                            system("pause");
                            system("cls");
                        } else {
                                for(int i=0; i <= lista.indice; i++) {
                                aux = lista.pegaValor(i);
                                cout << endl << "Triangulo " << i << ": " << "A: " << aux.a << " B: " << aux.b << " C: " << aux.c << endl;
                            }
                            cout << endl;
                            system("pause");
                            cout << endl;
                        }
                    }
                    break;
                    case 0:
                        system("cls");
                        cout << "Saindo..." << endl;
                    break;
                    default:
                        cout << "Opcao Invalida!" << endl;
                        system("pause");
                        system("cls");
                    break;
                }
            } while(opc != 0);
        }
    } while(tlista < 1);

    return 0;
}
