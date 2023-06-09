#include <iostream>
#include <fstream>
#include <string>
#include "../include/Equacao.hpp"
#include "../include/PilhaEncadeada.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // declaração de variáveis
    Equacao *equacao;
    ifstream arquivo;
    PilhaEncadeada pilha;
    string linha, comando;

    // abre o arquivo passado como argumento na linha de comando
    arquivo.open(argv[1], ifstream::in);

    // verifica se o arquivo foi aberto com sucesso
    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            // lê o comando
            size_t pos = linha.find(" ");
            comando = linha.substr(0, pos);

            // verifica o comando lido e executa a ação correspondente
            if (comando == "LER")
            {
                // lê o tipo de expressão e a expressão em si
                size_t aux = linha.find("  ");
                string tipo = linha.substr(pos + 1, aux - 4);
                string eq = linha.substr(aux + 2, linha.find("/n"));

                // cria um objeto Equacao e empilha na PilhaEncadeada
                equacao = new Equacao(tipo, &eq);
                TipoItem aux1(equacao);
                TipoItem aux2(tipo);
                pilha.Empilha(aux1);
                pilha.Empilha(aux2);

                // imprime mensagem de sucesso
                cout << "EXPRESSAO OK:  " << eq << endl;
            }
            else if (comando == "INFIXA")
            {
                // verifica se há uma expressão empilhada na PilhaEncadeada
                if (pilha.Vazia())
                {
                    cout << "ERRO: EXP NAO EXISTE" << endl;
                }
                else
                {
                    // obtém a expressão em notação infixa e imprime na tela
                    string I = equacao->getInfixa();
                    cout << "INFIXA: " << I << endl;
                }
            }
            else if (comando == "POSFIXA")
            {
                if (pilha.Vazia())
                {
                    cout << "ERRO: EXP NAO EXISTE" << endl;
                }
                else
                {
                    // obtém a expressão em notação pós-fixa e imprime na tela
                    string P = equacao->getPosfixa();
                    cout << "POSFIXA: " << P << endl;
                }
            }
            else if (comando == "RESOLVE")
            {
                // verifica se há uma expressão empilhada na PilhaEncadeada
                if (pilha.Vazia())
                {
                    cout << "ERRO: EXP NAO EXISTE" << endl;
                }
                else
                {
                    // obtém o resultado da expressão e imprime na tela
                    double res = equacao->getResult();
                    cout << pilha.Topo() << ": ";
                    printf("%f", res);
                    cout << endl;
                }
            }
        }
        // desaloca o objeto Equacao criado anteriormente
        delete equacao;
    }
    else
    {
        // imprime mensagem de erro se o arquivo não foi encontrado
        cout << "Nao achei o arquivo!" << endl;
        exit(1);
    }
    // limpa a PilhaEncadeada e finaliza a função
    pilha.Limpa();
    return 0;
}
