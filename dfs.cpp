#include <bits/stdc++.h>
using namespace std;

//ALUNOS : DANILO, FELIPE E SAMUEL

enum Cor { BRANCO, CINZA, PRETO };

bool ciclico;

void DFS(int no, vector<vector<int>>& grafo, vector<Cor>& cores) {
    cores[no] = CINZA;  // Marca o nó como visitado (cinza)

    cout << "Visitando no : " << no << endl; 

    for (int i = 0; i < grafo[no].size(); i++) {
        int vizinho = grafo[no][i];
        
        if (cores[vizinho] == CINZA) { // Se o nó ja tiver sido visitado, então há ciclos
            ciclico = true;
        }
        if(cores[vizinho] == BRANCO){
            DFS(vizinho, grafo, cores);
        }
    }
    cores[no] = PRETO;  // Marca o nó como totalmente explorado (preto)
}

void Percorre(vector<vector<int>>& grafo, int numNos) {
    vector<Cor> cores(numNos, BRANCO);
    ciclico = false;
    for (int i = 0; i < numNos; i++) {
        if (cores[i] == BRANCO) {
            DFS(i, grafo, cores);
        }
    }
}

void Opcoes() {
    printf("\n\n");
    printf("Insira o numero da funcao desejada\n\n");
    printf("1 - Adicionar arestas\n");
    printf("2 - Imprimir grafo\n");
    printf("3 - Verificar se ha ciclos usando DFS\n");
    printf("0 - encerrar o programa\n\n");
}

void Imprime(vector<vector<int>> &grafo){
    printf("\n\n\n");
    for (int i = 0; i < grafo.size(); ++i) {
        cout << "Vertice " << i << " estah conectado a:";
        for (int j = 0; j < grafo[i].size(); ++j) {
            cout << " " << grafo[i][j];
        }
        cout << endl;
    }
    printf("\n\n\n");
}

int main() {
    int numNos, numArestas;
    cout << "Digite o numero de nos: ";
    cin >> numNos;

    vector<vector<int>> grafo(numNos);

    int resposta = 1;

    while(resposta){
        Opcoes();
        cin >> resposta;
        switch (resposta)
        {
        case 1:
            cout << "Quantas arestras deseja adicionar:" << endl;
            cin >> numArestas;
            cout << "Digite as arestas: (ex '1 2' lembre-se que comeca do 0)" << endl;
            for (int i = 0; i < numArestas; ++i) {
                int u, v;
                cin >> u >> v;
                if(find(grafo[u].begin(), grafo[u].end(), v)==grafo[u].end()) // verifica se a aresta ja existe
                    grafo[u].push_back(v);
            }
            break;
        case 2:
            Imprime(grafo);
            break;
        case 3:
            Percorre(grafo, numNos);
            if (ciclico) {
                cout << "O grafo contem pelo menos um ciclo." << endl;
            } else {
                cout << "O grafo eh aciclico." << endl;
                }
            break;
        case 0:
            break;
        default:
            printf("\nOpcao nao encontrada\n");
            break;
        }
    }
    return 0;
}
