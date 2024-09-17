#include <iostream>
using namespace std;

// Definição de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

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
        cout << "Menu Lista Ligada Ordenada";
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
    
    // Caso especial: lista vazia
    if (primeiro == NULL) {
        novo->prox = NULL;
        primeiro = novo;
        return;
    }

    // Caso especial: inserir no início da lista
    if (novo->valor < primeiro->valor) {
        novo->prox = primeiro;
        primeiro = novo;
        return;
    }

    // Inserir no meio ou final da lista (mantendo a ordem e evitando duplicados)
    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < novo->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se já existe um nó com o mesmo valor, não inserir
    if (atual != NULL && atual->valor == novo->valor) {
        free(novo);
        cout << "Elemento duplicado, não inserido.\n";
        return;
    }

    // Inserir o novo nó na posição encontrada
    novo->prox = atual;
    anterior->prox = novo;
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia. Nada a excluir.\n";
        return;
    }

    int numero;
    cout << "Digite o elemento a ser excluido: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    // Encontrar o elemento a ser excluído
    while (atual != NULL && atual->valor < numero) {
        anterior = atual;
        atual = atual->prox;
    }

    // Verificar se o elemento foi encontrado
    if (atual == NULL || atual->valor != numero) {
        cout << "Elemento não encontrado.\n";
        return;
    }

    // Elemento encontrado, remover da lista
    if (anterior == NULL) {
        // Remover o primeiro elemento
        primeiro = atual->prox;
    } else {
        // Remover um elemento no meio ou final da lista
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido.\n";
}

void buscarElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia.\n";
        return;
    }

    int numero;
    cout << "Digite o elemento a ser buscado: ";
    cin >> numero;

    NO* atual = primeiro;

    // Otimização: Parar quando encontrar um elemento maior que o buscado
    while (atual != NULL && atual->valor < numero) {
        atual = atual->prox;
    }

    // Verificar se o elemento foi encontrado
    if (atual != NULL && atual->valor == numero) {
        cout << "ENCONTRADO\n";
    } else {
        cout << "ELEMENTO NAO ENCONTRADO\n";
    }
}
