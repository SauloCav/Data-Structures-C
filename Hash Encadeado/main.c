#include"libHashEnc.h"

int main(void) {
	int op;
	TLista L;
	Tdado dado;
	criar(&L);
	int hash;
	do{    
		
        system("cls");
        puts("\n\t\t\t\tEDITOR DE LISTAS\n");
        puts("\t1  - EXIBIR LISTA\n\t2  - INSERIR UM ELEMENTO\n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);
        
    	switch(op)
        	{
        		case 1:{
        			exibir(L);
					break;
				}
				
				case 2:{
					printf("Informe uma chave: ");
	                scanf("%d", &dado.chave);
	                
	                printf("Informe um valor: ");
	                scanf("%d", &dado.valor);
	                
	                hash = hashing(dado.chave);
	                
	                inserir(&L,hash, dado);
					break;
				}
    		default:
    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
        }
	getch();
    }while(op!=0);
  
  system("PAUSE");	
  return 0;
}
