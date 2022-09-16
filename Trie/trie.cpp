// Autoria: https://www.geeksforgeeks.org/trie-insert-and-search/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//fun��o para calcular o tamanho de um vetor preenchido
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// N�mero de s�mbolos no alfabeto
#define ALPHABET_SIZE (26)
 
// Converte o caractere atual da chave em �ndice
// usa apenas letras pequenas
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
	// isEndOfWord � o terminador de palavras. se verdadeiro o n� representar� o fim de uma palavra
    bool isEndOfWord;
};
 

struct TrieNode *getNode(void) //inicia a estrutura
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 
        pNode->isEndOfWord = false;
 
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;//todas as refer�ncias s�o nulas
    }
 
    return pNode;
}
 
// Se a chave n�o existir insere esta na trie
// Se seu prefixo estiver j� na trie realiza a marca��o da existencia da chave
void insert(struct TrieNode *root, const char *key)
{
    int level;//vari�vel para percorrer a palavra (chave)
    int length = strlen(key); //calcula o tamanho da chave que ser� inserida
    int index;
 
    struct TrieNode *pCrawl = root; //ponteiro de c�pia para a trie
 
    for (level = 0; level < length; level++) //percorre-se toda a palavra
    {
        index = CHAR_TO_INDEX(key[level]);//converte um caracter em um �ndice
        if (!pCrawl->children[index]) //se na trie aquela posi��o ainda n�o existir
            pCrawl->children[index] = getNode(); //cria a referencia naquela possi��o
 
        pCrawl = pCrawl->children[index];//realiza o  processo de descida na trie
    }
 
    // marca o �ltimo n� como verdadeiro, para definir que ali temos uma chave
    pCrawl->isEndOfWord = true;
}
 

bool search(struct TrieNode *root, const char *key)
{
    int level; //mesma vari�vel para percorrer a chave busca
    int length = strlen(key); //calcula o tamanho da chave
    int index; //vari�vel que armazena o �ndice correspondente ao caracter
    struct TrieNode *pCrawl = root; //ponteiro para c�pia da trie
 
    for (level = 0; level < length; level++)//percorre-se toda a chave
    {
        index = CHAR_TO_INDEX(key[level]); //transforma o caracter em �ndice
 
        if (!pCrawl->children[index]) //se naquele �nidice n�o existir uma referencia 
            return false; //a chave n�o est� na trie
 
        pCrawl = pCrawl->children[index]; //se o �ndice existir, segue pro pr�ximo �ndice
    }
 
    return (pCrawl->isEndOfWord); //se toda a trie foi percorrida, os caracteres daquela chave est�o na trie,
    //por�m s� se a vari�vel isEndOfWord estiver marcada com verdadeiro � v�lido que a chave esteja na estrutura
}
 

int main()
{
    // o alfabeto � de a-z ent�o as palavras inclu�das para o teste devem ser neste alfabeto
    
	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};		
    char output[][32] = {"Palavra nao Encontrada", "Palavra Encontrada"};
 
 	char termosBusca[][8] = {"then", "and", "these", "answer", "any", "by", "bye", "thaw"};
    struct TrieNode *root = getNode();
 
    //populando a trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);
 
    //procurando palavras
    for (i = 0; i < ARRAY_SIZE(termosBusca); i++)
    	printf("%s --- %s\n", termosBusca[i], output[search(root, termosBusca[i])] );
    
 
    return 0;
}
