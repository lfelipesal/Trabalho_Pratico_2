
# Trabalho de Implementação - Algoritmos de Ordenação

Este trabalho consiste na implementação de um sistema que utiliza diferentes algoritmos de ordenação em conjunto com o algoritmo de scan de Graham. O programa recebe como entrada um arquivo contendo uma sequência de pontos no plano cartesiano, onde cada ponto é representado por um par de coordenadas inteiras. O objetivo é aplicar os algoritmos de ordenação implementados (MergeSort, Insertion Sort e um algoritmo de ordenação linear) e integrá-los com o algoritmo de scan de Graham.

O algoritmo de scan de Graham é utilizado para encontrar o fecho convexo de um conjunto de pontos no plano cartesiano. O fecho convexo é o menor polígono convexo que contém todos os pontos do conjunto. O algoritmo de scan de Graham utiliza uma estratégia baseada em ângulos para realizar a ordenação dos pontos e determinar o fecho convexo.
  
## 🔨 Funcionalidades
O programa deve ser capaz de executar as seguintes configurações:

Graham + Insertion Sort: Utilizar o algoritmo de ordenação Insertion Sort para ordenar os pontos antes de aplicar o algoritmo de scan de Graham.

Graham + Ordenação Linear (Counting, Bucket ou Radix): Utilizar um algoritmo de ordenação linear (Counting Sort, Bucket Sort ou Radix Sort) para ordenar os pontos antes de aplicar o algoritmo de scan de Graham.

Jarvis: Utilizar o algoritmo de marcha de Jarvis (também conhecido como algoritmo do embrulho convexo) para encontrar o fecho convexo dos pontos, sem a necessidade de um algoritmo de ordenação prévia.

O programa deve ler o arquivo de entrada, passado como argumento na linha de comando, e executar todas as quatro configurações possíveis, produzindo a saída correspondente para cada uma delas.
  - `Graham + MergeSort`:  Utilizar o algoritmo de ordenação Insertion Sort para ordenar os pontos antes de aplicar o algoritmo de scan de Graham.
  
  - `Tiro básico`:  O jogador deve ter acesso a uma tecla que dispara o tiro do canhão do tanque. O tiro não deve 
mudar de direção depois que ele foi lançado e só deve para depois que ele sair da tela ou colidir: 1) com o tanque inimigo 
ou 2) com um obstáculo do cenário. Além disso, um canhão só pode disparar 1 tiro por vez. A tecla utilizada para o tiro foi o espaço.
  
  - `Tiro avançado`:  Ao segurar o botão de tiro, o tiro deve aumentar de tamanho e, quando disparado no
seu tamanho máximo, deve ser capaz de eliminar todos os inimigos que estejam em sua rota.
  
  - `Bloco`:  O cenário deve conter pelo menos um bloco que elimina o jogador e inimigos que colidem com
ele. Além disso, blocos devem ter tamanhos e posições variáveis, mas devem ocupar, no mínimo, um
quinto da altura da tela e devem ter comprimento pelo menos equivalente à largura da tela. Enquanto
inimigos podem ser destruídos, blocos não podem.
  
  - `Controle de coliões`:  Os objetos presentes no cenário não podem se sobrepor. Tiros não podem
atravessar obstáculos e nem inimigos. Da mesma forma, os movimentos dos inimigos e da nave do
jogador devem ser limitados aos espaços vazios do cenário, ou seja, não podem sair da tela e não
podem atravessar blocos.
 
  - `Pontuação`: Cada inimigo destruído deve aumentar a pontuação do jogador. Inimigos devem oferecer
valores em pontuação diferentes, de acordo com algum critério (ex: tamanho). O cenário deve exibir
os pontos ganhos pelos jogadores.
  
  - `Fim de jogo`:  O jogo deve terminar quando o jogador colidir com um inimigo ou com um bloco.
  
  - `Recorde`:  A maior pontuação registrada (recorde) deve ser armazenada em um arquivo. O valor do
recorde deve ser exibido sempre que o personagem terminar o jogo de forma vitoriosa. Se além disso
ele também bater o recorde, uma mensagem informativa deve ser apresentada para ele. 


## ✔️ Técnicas e tecnologias utilizadas

- `Linguagem C`
- `Biblioteca Allegro5`
- `Windows - MinGW`

## 📁 Acesso ao projeto

Você pode acessar o codigo fonte que foi desenvolvido para jogo [aqui](https://github.com/lfelipesal/R-type/blob/main/tp.c).

## 🛠️ Abrir e rodar o projeto

Para jogar o que foi desenvolvido basta clonar esse repositório na maquina local no ambiente Windows, entrar na pasta pelo prompt de comando(cmd),
e dentro da pasta digitar o comando make.
