#define CATCH_CONFIG_MAIN
#include "../include/doctest.hpp"
#include "../include/Equacao.hpp"
#include "../include/PilhaEncadeada.hpp"
#include <string>

TEST_CASE("Testando conversão de equação posfixa para infixa", "[conversão]")
{
  // Definindo a equação posfixa a ser testada
  std::string teste = "1.627783  2.365861  5.771913  *  +  8.718286  3.609486  +  8.733775  *  /  1.229733  6.687142  9.455672  -  +  *  0.138964  8.688749  /  8.668175  4.996990  *  8.772412  +  +  -  9.200303  /  5.066756  8.889858  9.577672  -  +  1.427157  9.378698  *  +  8.158811  4.938767  +  5.053923  *  7.014099  7.524377  +  1.256127  /  +  +  +";
  // Criando um objeto Equacao com o tipo "POSFIXA" e a equação definida acima
  Equacao *equacaoPos = new Equacao("POSFIXA", &teste);
  // Verificando se a conversão para infixa está correta
  CHECK("( ( ( ( ( ( 1.627783 + ( 2.365861 * 5.771913 ) ) / ( ( 8.718286 + 3.609486 ) * 8.733775 ) ) * ( 1.229733 + ( 6.687142 - 9.455672 ) ) ) - ( ( 0.138964 / 8.688749 ) + ( ( 8.668175 * 4.996990 ) + 8.772412 ) ) ) / 9.200303 ) + ( ( ( 5.066756 + ( 8.889858 - 9.577672 ) ) + ( 1.427157 * 9.378698 ) ) + ( ( ( 8.158811 + 4.938767 ) * 5.053923 ) + ( ( 7.014099 + 7.524377 ) / 1.256127 ) ) ) )" == equacaoPos->getInfixa());
  // Deletando o objeto Equacao criado acima
  delete equacaoPos;

  // Definindo a equação posfixa a ser testada
  teste = "1.627783  2.365861  5.771913  *  +";
  // Criando um novo objeto Equacao com o tipo "POSFIXA" e a equação definida acima
  equacaoPos = new Equacao("POSFIXA", &teste);
  // Verificando se a conversão para infixa está correta
  CHECK("( 1.627783 + ( 2.365861 * 5.771913 ) )" == equacaoPos->getInfixa());
  // Deletando o objeto Equacao criado acima
  delete equacaoPos;
}

TEST_CASE("Testando conversão de equação infixa para posfixa", "[conversão]")
{
  // Criando um novo objeto Equacao com a equação infixa a ser testada
  Equacao *equacao;
  std::string teste = "1.627783  2.365861  5.771913  *  +";
  equacao = new Equacao("POSFIXA", &teste);
  // Verificando se a conversão para posfixa está correta
  CHECK("( 1.627783 + ( 2.365861 * 5.771913 ) )" == equacao->getInfixa());
  // Deletando o objeto Equacao criado acima
  delete equacao;
}

TEST_CASE("Testando resultado", "[Resultado]")
{
  // Definindo a equação posfixa a ser testada
  std::string teste = "1.627783  2.365861  5.771913  *  +  8.718286  3.609486  +  8.733775  *  /  1.229733  6.687142  9.455672  -  +  *  0.138964  8.688749  /  8.668175  4.996990  *  8.772412  +  +  -  9.200303  /  5.066756  8.889858  9.577672  -  +  1.427157  9.378698  *  +  8.158811  4.938767  +  5.053923  *  7.014099  7.524377  +  1.256127  /  +  +  +";
  // Criando um novo objeto Equacao com o tipo "POSFIXA" e a equação definida acima
  Equacao *equacao = new Equacao("POSFIXA", &teste);
  // Verificando se o resultado da equação está correto
  CHECK(89.845072 == equacao->getResult());
  // Definindo a equação infixa a ser testada
  teste = "( 1.627783 + ( 2.365861 * 5.771913 ) )";
  // Deletando o objeto Equacao criado acima
  delete equacao;
  // Criando um novo objeto Equacao com o tipo "INFIXA" e a equação definida acima
  equacao = new Equacao("INFIXA", &teste);
  // Verificando se o resultado da equação está correto
  CHECK(15.283327 == equacao->getResult());
  // Deletando o objeto Equacao criado acima
  delete equacao;
}

TEST_CASE("Testando Empilhamento de chave", "[Pilha]")
{
  // Teste do empilhamento de chaves (números inteiros)
  PilhaEncadeada *pilha;           // Declaração de um ponteiro para a pilha encadeada
  pilha = new PilhaEncadeada();    // Alocação dinâmica da pilha
  TipoItem primeiro(5);            // Cria um item do tipo chave com o valor 5
  TipoItem segundo(6);             // Cria um item do tipo chave com o valor 6
  pilha->Empilha(primeiro);        // Empilha o primeiro item na pilha
  pilha->Empilha(segundo);         // Empilha o segundo item na pilha
  CHECK(false == pilha->Vazia());  // Verifica se a pilha não está vazia
  CHECK(2 == pilha->GetTamanho()); // Verifica se a pilha tem tamanho 2
  delete pilha;                    // Desaloca a memória dinâmica da pilha
}

TEST_CASE("Testando Empilhamento de string", "[Pilha]")
{
  // Teste do empilhamento de strings
  PilhaEncadeada *pilha;           // Declaração de um ponteiro para a pilha encadeada
  pilha = new PilhaEncadeada();    // Alocação dinâmica da pilha
  TipoItem primeiro("primeira");   // Cria um item do tipo chave com a string "primeira"
  TipoItem segundo("segunda");     // Cria um item do tipo chave com a string "segunda"
  pilha->Empilha(primeiro);        // Empilha o primeiro item na pilha
  pilha->Empilha(segundo);         // Empilha o segundo item na pilha
  CHECK(false == pilha->Vazia());  // Verifica se a pilha não está vazia
  CHECK(2 == pilha->GetTamanho()); // Verifica se a pilha tem tamanho 2
  delete pilha;                    // Desaloca a memória dinâmica da pilha
}

TEST_CASE("Testando retorno do topo da pilha com string", "[Pilha]")
{
  // Teste do retorno do topo da pilha com strings
  PilhaEncadeada *pilha;             // Declaração de um ponteiro para a pilha encadeada
  pilha = new PilhaEncadeada();      // Alocação dinâmica da pilha
  TipoItem primeiro("primeira");     // Cria um item do tipo chave com a string "primeira"
  TipoItem segundo("segunda");       // Cria um item do tipo chave com a string "segunda"
  pilha->Empilha(primeiro);          // Empilha o primeiro item na pilha
  pilha->Empilha(segundo);           // Empilha o segundo item na pilha
  CHECK("segunda" == pilha->Topo()); // Verifica se o topo da pilha é a string "segunda"
  CHECK(2 == pilha->GetTamanho());   // Verifica se a pilha tem tamanho 2
  delete pilha;                      // Desaloca a memória dinâmica da pilha
}

TEST_CASE("Testando desempilha com string", "[Pilha]")
{
  PilhaEncadeada *pilha;              // cria um ponteiro para uma nova PilhaEncadeada
  pilha = new PilhaEncadeada();       // aloca dinamicamente memória para a nova PilhaEncadeada
  TipoItem primeiro("primeira");      // cria um novo TipoItem com um valor string
  TipoItem segundo("segunda");        // cria um novo TipoItem com um valor string
  pilha->Empilha(primeiro);           // empilha o primeiro TipoItem na pilha
  pilha->Empilha(segundo);            // empilha o segundo TipoItem na pilha
  CHECK("segunda" == pilha->Topo());  // verifica se o topo da pilha é o segundo item empilhado
  CHECK(2 == pilha->GetTamanho());    // verifica se o tamanho da pilha é 2
  pilha->Desempilha();                // desempilha o topo da pilha
  CHECK("primeira" == pilha->Topo()); // verifica se o topo da pilha agora é o primeiro item empilhado
  CHECK(1 == pilha->GetTamanho());    // verifica se o tamanho da pilha é agora 1
  delete pilha;                       // desaloca a memória alocada dinamicamente para a pilha
}

TEST_CASE("Testando desempilha com chave", "[conversão]")
{
  PilhaEncadeada *pilha;                      // cria um ponteiro para uma nova PilhaEncadeada
  pilha = new PilhaEncadeada();               // aloca dinamicamente memória para a nova PilhaEncadeada
  TipoItem primeiro(5);                       // cria um novo TipoItem com um valor inteiro
  TipoItem segundo(6);                        // cria um novo TipoItem com um valor inteiro
  pilha->Empilha(primeiro);                   // empilha o primeiro TipoItem na pilha
  pilha->Empilha(segundo);                    // empilha o segundo TipoItem na pilha
  CHECK(2 == pilha->GetTamanho());            // verifica se o tamanho da pilha é 2
  CHECK(6 == pilha->Desempilha().GetChave()); // verifica se o topo da pilha tem valor 6 após desempilhar o topo
  CHECK(1 == pilha->GetTamanho());            // verifica se o tamanho da pilha é agora 1
  CHECK(5 == pilha->Desempilha().GetChave()); // verifica se o topo da pilha tem valor 5 após desempilhar o topo
  delete pilha;                               // desaloca a memória alocada dinamicamente para a pilha
}