#include <bits/stdc++.h>

using namespace std;

//ALUNOS : DANILO, FELIPE E SAMUEL

vector<int> pai, qtd;// Vetor dos pais e quantidade de elementos dos conjuntos

struct Aresta {
    int origem, destino, peso;
};

bool comparar(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

// Função para encontrar o pAi de um conjunto
int find(int vertice) {
    if (pai[vertice] == vertice)
        return vertice;
    return find(pai[vertice]);
}

// Função para unir dois conjuntos
void uniao(int paiOrigem, int paiDestino) {
    if(qtd[paiOrigem]>qtd[paiDestino]){
        pai[paiDestino] = paiOrigem;
        qtd[paiOrigem] += qtd[paiDestino];
    } else {
        pai[paiOrigem] = paiDestino;
        qtd[paiDestino] += qtd[paiOrigem];
    }
}

void kruskal(vector<Aresta>& arestas, int V) {
    vector<Aresta> resultado; // Vetor para armazenar as arestas da árvore geradora mínima

    sort(arestas.begin(), arestas.end(), comparar); // ordena todas as arestras por peso na ordem crescente   

    for (int i=0; i < arestas.size(); i++) {
        Aresta aresta = arestas[i];       
        int paiOrigem = find(aresta.origem); // o grafo é não dirigido!
        int paiDestino = find(aresta.destino);

        if (paiOrigem != paiDestino) { //verifica se os dois vertices de uma aresta nao estão no mesmo conjunto
            resultado.push_back(aresta);
            uniao(paiOrigem, paiDestino);
        }
    }

    cout << "Arestas da Arvore Geradora Minima:" << endl;
    for (int i =0; i < resultado.size(); i++) {
        cout << resultado[i].origem << " - " << resultado[i].destino << " : " << resultado[i].peso << endl;
    }
}

int main() {
    int V, A;
    printf("Insira o numero de Vertices e Arestas\n\n");
    cin >> V >> A;
    
    pai.resize(V);
    qtd.resize(V);
    for (int i = 0; i < V; i++) {  // inicialização dos vetores do Union Find
        pai[i]=i;
        qtd[i]=1;
    }

    vector<Aresta> arestas(A);
    printf("Insira as Arestas no formato 'A B P' onde A e B sao os vertices e P eh o peso\n\n");
    for (int i = 0; i < A; ++i) {
        cin >> arestas[i].origem >> arestas[i].destino >> arestas[i].peso;
    }
    kruskal(arestas, V);
    return 0;
}
