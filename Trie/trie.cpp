#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};
 

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
        pNode->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}

void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++) //percorre-se toda a palavra
    {
        index = CHAR_TO_INDEX(key[level]);//converte um caracter em um índice
        if (!pCrawl->children[index]) //se na trie aquela posição ainda não existir
            pCrawl->children[index] = getNode(); //cria a referencia naquela possição
 
        pCrawl = pCrawl->children[index];//realiza o  processo de descida na trie
    }
 
    // marca o último nó como verdadeiro, para definir que ali temos uma chave
    pCrawl->isEndOfWord = true;
}
 

bool search(struct TrieNode *root, const char *key)
{
    int level; //mesma variável para percorrer a chave busca
    int length = strlen(key); //calcula o tamanho da chave
    int index; //variável que armazena o índice correspondente ao caracter
    struct TrieNode *pCrawl = root; //ponteiro para cópia da trie
 
    for (level = 0; level < length; level++)//percorre-se toda a chave
    {
        index = CHAR_TO_INDEX(key[level]); //transforma o caracter em índice
 
        if (!pCrawl->children[index]) //se naquele ínidice não existir uma referencia 
            return false; //a chave não está na trie
 
        pCrawl = pCrawl->children[index]; //se o índice existir, segue pro próximo índice
    }
 
    return (pCrawl->isEndOfWord); //se toda a trie foi percorrida, os caracteres daquela chave estão na trie,
    //porém só se a variável isEndOfWord estiver marcada com verdadeiro é válido que a chave esteja na estrutura
}
 

int main()
{
    // o alfabeto é de a-z então as palavras incluídas para o teste devem ser neste alfabeto
    
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
