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
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
	
    pCrawl->isEndOfWord = true;
}
 

bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isEndOfWord);
}
 

int main()
{
	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};		
    char output[][32] = {"Palavra nao Encontrada", "Palavra Encontrada"};
 
 	char termosBusca[][8] = {"then", "and", "these", "answer", "any", "by", "bye", "thaw"};
    struct TrieNode *root = getNode();
 
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);
 
    for (i = 0; i < ARRAY_SIZE(termosBusca); i++)
    	printf("%s --- %s\n", termosBusca[i], output[search(root, termosBusca[i])] );
 
    return 0;
}
