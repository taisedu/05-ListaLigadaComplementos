#include <iostream>
using namespace std;

// Definição de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL; // Ponteiro para o último elemento

// Headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no windows
    }
}

void inicializar()
{
    // Se a lista já possuir elementos, libera a memória ocupada
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    ultimo = NULL; // Inicializa o ponteiro para o último elemento
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {
    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    else {
        cout << "Elementos: \n";
        NO* aux = primeiro;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
        }
    }
}

void inserirElemento()
{
    // Aloca memória dinamicamente para o novo elemento
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    if (primeiro == NULL)
    {
        // Lista vazia, primeiro e último apontam para o novo nó
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        // Usa o ponteiro 'ultimo' para inserir diretamente no final
        ultimo->prox = novo;
        ultimo = novo; // Atualiza o ponteiro 'ultimo'
    }
}

void excluirElemento()
{
     int valor;
    cout << "Digite o numero para excluir: ";
    cin >> valor;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            // Elemento encontrado
            if (anterior == NULL) {
                // Remove o primeiro elemento
                primeiro = atual->prox;
                if (primeiro == NULL) { // Se a lista ficar vazia, atualiza 'ultimo'
                    ultimo = NULL;
                }
            } else {
                // Remove um elemento que não é o primeiro
                anterior->prox = atual->prox;
                if (anterior->prox == NULL) { // Se removemos o último elemento
                    ultimo = anterior;
                }
            }
            free(atual);
            cout << "Elemento excluído com sucesso.\n";
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    cout << "ELEMENTO NAO ENCONTRADO\n";
}

void buscarElemento()
{
	int valor;
	cout << "Digite o numero para buscar: ";
	cin >> valor;

	NO* elemento = posicaoElemento(valor);
	if (elemento != NULL) {
		cout << "ENCONTRADO\n";
	}
	else {
		cout << "ELEMENTO NAO ENCONTRADO\n";
	}
    
}
