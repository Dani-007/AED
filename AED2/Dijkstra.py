import math

class HeapMin:

    def __init__(self):
        self.nos = 0
        self.heap = []

    def add_no(self, u, indice):
        self.heap.append([u, indice])
        self.nos += 1
        f = self.nos
        while True:
            if f == 1:
                break
            p = f // 2
            if self.heap[p-1][0] <= self.heap[f-1][0]:
                break
            else:
                self.heap[p-1], self.heap[f-1] = self.heap[f-1], self.heap[p-1]
                f = p

    def remove_no(self):
        x = self.heap[0]
        self.heap[0] = self.heap[self.nos - 1]
        self.heap.pop()
        self.nos -= 1
        p = 1
        while True:
            f = 2 * p
            if f > self.nos:
                break
            if f + 1 <= self.nos:
                if self.heap[f][0] < self.heap[f-1][0]:
                    f += 1
            if self.heap[p-1][0] <= self.heap[f-1][0]:
                break
            else:
                self.heap[p-1], self.heap[f-1] = self.heap[f-1], self.heap[p-1]
                p = f
        return x

    def tamanho(self):
        return self.nos


class Grafo:

    def __init__(self, vertices):
        self.vertices = vertices
        self.aresta = [[0] * self.vertices for i in range(self.vertices)]

    def add_aresta(self, u, v, peso, tipo):
        if tipo == 'd':
            self.aresta[u-1][v-1] = peso
        else:
            self.aresta[u-1][v-1] = peso
            self.aresta[v-1][u-1] = peso

    def mostra_matriz(self):
        print('A matriz de adjacências é:')
        for i in range(self.vertices):
            print(self.aresta[i])
        print('\n')

    def dijkstra(self, origem):
        custo_vem = [[-1, 0] for i in range(self.vertices)]
        custo_vem[origem - 1] = [0, origem]
        h = HeapMin()
        h.add_no(0, origem)
        while h.tamanho() > 0:
            dist, v = h.remove_no()
            for i in range(self.vertices):
                if self.aresta[v-1][i] != 0:
                    if custo_vem[i][0] == -1 or custo_vem[i][0] > dist + self.aresta[v-1][i]:
                        custo_vem[i] = [dist + self.aresta[v-1][i], v]
                        h.add_no(dist + self.aresta[v-1][i], i+1)
        return custo_vem
    
    def bellmanFord(self, origem):
        custo_vem = [[math.inf, None] for _ in range(self.vertices)]
        custo_vem[origem - 1] = [0, origem]
        
        for _ in range(self.vertices - 1):
            for u in range(self.vertices):
                for v in range(self.vertices):
                    if self.aresta[u][v] != 0:
                        if custo_vem[u][0] + self.aresta[u][v] < custo_vem[v][0]:
                            custo_vem[v] = [custo_vem[u][0] + self.aresta[u][v], u + 1]
        
        for u in range(self.vertices):
            for v in range(self.vertices):
                if self.aresta[u][v] != 0:
                    if custo_vem[u][0] + self.aresta[u][v] < custo_vem[v][0]:
                        print("O grafo contém um ciclo negativo")
                        return custo_vem
        
        return custo_vem

def teste_dijkstra():
    g = Grafo(6)

    g.add_aresta(1, 2, 18, 'n')
    g.add_aresta(1, 4, 15, 'n')
    g.add_aresta(2, 3, 9, 'n')
    g.add_aresta(2, 4, 2, 'n')
    g.add_aresta(3, 4, 14, 'n')
    g.add_aresta(3, 5, 10, 'n')
    g.add_aresta(3, 6, 28, 'n')
    g.add_aresta(4, 5, 7, 'n')
    g.add_aresta(5, 6, 36, 'n')
    

    g.mostra_matriz()

    resultado_dijkstra = g.dijkstra(1)
    print('Dijkstra: ', resultado_dijkstra)

def teste_bellmanFord():
    g = Grafo(4)

    g.add_aresta(1, 2, 1, 'd')
    g.add_aresta(1, 3, 3, 'd')
    g.add_aresta(1, 4, 99, 'd')
    g.add_aresta(2, 3, 1, 'd')
    g.add_aresta(4, 2, -300, 'd')

    g.mostra_matriz()

    resultado_bellman_ford = g.bellmanFord(1)
    print('Bellman-Ford Resultado: ', resultado_bellman_ford)

if __name__ == "__main__":
    teste_dijkstra()
    teste_bellmanFord()