# Project 0

# N-mesis
“Nêmesis, a deusa da vingança, irou-se contra Euterpe, a musa dos prazeres, e a pôs
num labirinto infestado de bestas. Agora, apenas Hércules poderá salvar Euterpe. Iniciando sua
jornada em alguma posição do labirinto, Hércules só pode avançar para uma posição do
labirinto guardada por uma besta se matar a besta. Embora terrível, uma besta nunca deixa a
posição que guarda. Ainda, bestas diferentes podem exigir de Hércules quantias diferentes de
energia para serem mortas. Ajude Hércules a salvar Euterpe gastando o mínimo de energia
possível, sabendo que ele só pode se mover nas direções horizontal e vertical e, apesar de ser
um herói invencível e de possuir energia infinita, Hércules não consegue destruir as paredes do
labirinto.”

## Explicação do problema:
O problema mostrado acima foi interpretado por nosso
grupo como um problema que procurava o caminho de menor custo, sendo que o que
determinava o custo eram as bestas do labirinto, cada aresta teria uma besta e essa determinaria o
custo da aresta. O programa deve encontrar o caminho de menor custo dentro desse grafo, sendo
que sai do vértice zero e a chegada é no vértice 23.

## Complexidade do problema:
No nosso trabalho foi utilizado algoritmo de dijkstra. O
algoritmo de Djikstra tem tempo de computação igual a O(E + Vlog V). É da classe P por estar
na ordem linear logarítmica.

## Modelagem do problema: 
Utilizamos para a resolução do problema a estrutura de
grafo (vide imagem 1.0) de matriz de incidência, não orientada para criar o labirinto. Para termos
4
soluções diferentes cada vez que o programa rodasse utilizamos uma lista com bestas com
valores associados a elas e, utilizando a função rand, escolhemos bestas aleatórias da lista para as
arestas. Para resolver o problema foi implementado o algoritmo de Dijsktra para encontrar o
caminho de menor custo, cuja soma dos valores das arestas que precisamos passar por para
chegar ao fim seja o menor possível, entre início e fim do labirinto feito com o grafo.

##Como Compilar:
É preciso ter um complidaro de C e digitar o comando gcc makefile