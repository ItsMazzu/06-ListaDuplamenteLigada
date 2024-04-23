#include <iostream>
using namespace std;

//Fiz o desafio (bom... pelo menos tentei)

//Feito por Italo Mazzucatto

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ant;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void exibirReverso();
void inserirElemento();
void excluirPrimeiroElemento();
void excluirUltimoElemento();
void inserirQqPosOrdem();
void ordenarElementos();
NO* posElemento(int numero);

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 8) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Exibir quantidade de elementos \n";
		cout << "4 - Exibir elementos  \n";
		cout << "5 - Exibir elementos na ordem reversa \n";
		cout << "6 - Excluir primeiro elemento \n";
		cout << "7 - Excluir ultimo elemento \n";
		cout << "8 - Exlcuir elemento \n";
		cout << "9 - Inserir em ordem \n";
		cout << "10 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:inserirElemento();
			break;
		case 3: exibirQuantidadeElementos(); 
			break;
		case 4: exibirElementos();
			break;
		case 5: exibirReverso();
			break;
		case 6: excluirPrimeiroElemento();
			break;
		case 7: excluirUltimoElemento();
			break;
		case 8: excluirElemento();
			break;
		case 9: inserirOrdem();
			break;
		case 10:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista ja possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
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
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;
	NO* jaExiste = posicaoElemento(novo->valor);

	if (jaExiste)
	{
		cout << "O numero digitado ja esta presente na lista. Digite outro. \n";
		return;
	}
	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		novo->ant = ultimo;
		ultimo->prox = novo;
		ultimo = novo;
	}
}


// funções a serem implementadas no exericio
void exibirReverso()
{
	if (primeiro == NULL || ultimo == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = ultimo;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->ant;
		}
	}
}

void excluirPrimeiroElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	if (primeiro == ultimo)
	{
		NO* aux = primeiro;
		free(aux);
		aux = NULL;
	}
	else
	{
		NO* aux = primeiro;
		free(aux);
		aux = aux->prox;
		cout << "ELEMENTO DELETADO COM SUCESSO\n";
	}
}

	void excluirUltimoElemento()
	{
	if (ultimo == NULL) 
	{
		cout << "Lista vazia \n";
		return;
	}
	else if (ultimo == primeiro)
	{
		NO* aux = ultimo;
		free(aux);
		aux = NULL;
		cout << "ELEMENTO DELETADO COM SUCESSO\n";
	}
	else
	{
		NO* aux = ultimo;
		free(aux);
		aux = aux->ant;
		cout << "ELEMENTO DELETADO COM SUCESSO\n";
	}
}

	void inserirOrdem()
	{
		NO* novo = (NO*)malloc(sizeof(NO));
		if (novo == NULL)
		{
			return;
		}

		cout << "Digite o elemento: ";
		cin >> novo->valor;
		novo->prox = NULL;
		system("cls");
		ordenarElementos();

		NO* jaExiste = posicaoElemento(novo->valor);

		if (jaExiste)
		{
			cout << "O numero digitado ja esta presente na lista. Digite outro. \n";
			return;
		}
	}

	void excluirElemento()
	{
		int valorD;
		cout << "Digite o valor que quer excluir: ";
		cin >> valorD;

		NO* naoExiste = posicaoElemento(valorD);
		if (primeiro == NULL)
		{
			cout << "Lista vazia. \n";
			return;
		}
		else if (naoExiste == NULL) {
			cout << "O numero digitado nao existe na lista. Digite outro. \n";
			exibirElementos();
			return;
		}
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			NO* proxElemento = aux->prox;

			if (primeiro->valor == valorD) {
				free(primeiro);
				primeiro = proxElemento;
				cout << "Elemento deletado com sucesso! \n";
				break;
			}

			if (proxElemento->valor == valorD) {
				aux->prox = proxElemento->prox;

				free(proxElemento);
				cout << "Elemento deletado com sucesso! \n";
				break;
			}
			aux = aux->prox;
	}
	void ordenarElementos()
	{
		if (primeiro == NULL || primeiro->prox == NULL)
		{
			cout << "Lista Vazia \n";
			return;
		}

		bool PosTrocada = true;
		while (PosTrocada)
		{
			PosTrocada = false;
			NO* atual = primeiro;
			NO* proximo = primeiro->prox;
			while (proximo != NULL)
			{
				if (atual->valor > proximo->valor)
				{
					swap(atual->valor, proximo->valor);
					PosTrocada = true;
				}
				atual = proximo;
				proximo = proximo->prox;
			}
		}
	}
	NO* posicaoElemento(int numero) {
		NO* aux = primeiro;
		while (aux != NULL) {
			if (aux->valor == numero)
			{
				break;
			}
			aux = aux->prox;
		}
		return aux;
	}






