#include "EDE.h"

int main() {
	
	srand(time(NULL));
	
	//matrizes e vetores
	int espelho[QNT][QNT], posicao[36];
	char letras[QNT][QNT], vetor[18], vetor36[AA];
	//jogadas, auxiliares de jogadas e auxiliares na construção das matrizes
	int lin, col, pl, pc, a, fim, x, y, z, b, c, acertos=0, tentativas=0, igual,   aux1,   numero1;
	char  jogada1 = 0, jogada2 = 0, numero, tecla;
	

	//gerando 18 numeros aleatorios sem repeticao
	numero = 'A' + rand() %26;
	vetor[0] = numero;
	
	for(x=0 ; x<18 ; x++){
				
		do{	
			igual = 0;
			numero = 'A' + rand() %26;
				
					for(y=0 ; y<18 ; y++){
					
						if(numero == vetor[y]){
							igual = 1;
						}
					}
				
			}while(igual == 1);
		vetor[x] = numero;
		
	}
	//duplicando as letras
	for(x=0,y=0 ; y<AA ; y++, x++){
		if(x==18){
			x=0;
		}
		vetor36[y] = vetor[x];
		
	}
	
	//fazendo um vetor para determinar as posicoes
	numero1 = rand() % 36 + 0;
	posicao[0] = 0;
	for(z=0 ; z<AA ; z++){
		
			do{	
				igual = 0;
				numero1 = rand() % 36 + 0;
				
					for(y=0 ; y<AA ; y++){
					
						if(numero1 == posicao[y]){
							igual = 1;
						}
					}
				
			}while(igual == 1);
			posicao[z] = numero1;
			posicao[0]= 0;
			
	}
	
	//colocando os numeros na matriz
	for(x=0, lin=0 ; lin<QNT ; lin++){
	printf("\n    ");
	
		for(col=0 ;col<QNT; col++, x++){
			aux1 = posicao[x];
			letras[lin][col] = vetor36[aux1];
			
			
		}
			
	}
	
	//Criando uma matriz espelho
	for(lin=0 ; lin < QNT ; lin++){
	
		for(col=0 ; col<QNT ; col++){
			
			espelho[lin][col] = 0;
			
		}
	}
	
	// apresentando a matriz e utilizando o sleep
	for(a=TIME; a >= 0; a--) {	 
		system("cls");
		printf("===================\n");
		printf("= JOGO DA MEMORIA =\n");
		printf("===================");
		
		for( lin=0 ; lin < QNT ; lin++){
			printf("\n    ");
				for(col=0 ; col<QNT ; col++){
					
					printf("%c ", letras[lin][col]);
			
				}		
			}
	
		
		printf("\n===================\n");
		printf("   %i segundo(s)", a);
		printf("\n===================");
		fflush(stdout);
		sleep(1);
	
	}
	
	// apresentando a matriz fechada
		system("cls");
		printf("===================\n");
		printf("= JOGO DA MEMORIA =\n");
		printf("===================");
		
		for(lin=0 ; lin < QNT ; lin++){
			printf("\n    ");
				for(col=0 ; col<QNT ; col++){
				
					printf("@ " );
			
				}		
			}
	
		
		printf("\n===================\n");
		printf("  Acertos: %i | %i", acertos, tentativas );
		printf("\n===================");
	
	
	//JOGANDO
	jogada1 = fim = pl = pc = 0;
	while(fim == 0) {
		

		system("cls");
		printf("===================\n");
		printf("= JOGO DA MEMORIA =\n");
		printf("===================");
		
		for(lin=0; lin<QNT; lin++) {
			printf("\n    ");
			for(col=0; col<QNT; col++) {
				
				//o usuario errou, atribuindo valor 0 as jogadas e aumentando tentativas
				 if(jogada1 != 0 && jogada2 != 0 && jogada1 != jogada2  ){
						jogada1=0;
						jogada2=0;
						tentativas++;
				}
				//fazendo as jogadas
				if(tecla == 13 && col == pc && lin == pl){
									
					//atribuindo um valor a jogada1 e verificando se a jogada ja foi feita nessa posição
					if(jogada1 == 0 && jogada2 == 0 && espelho[lin][col] == 0){
					
						jogada1 = letras[lin][col];
						y=lin;
						z=col;
						printf("%c ", letras[lin][col]);
						fflush(stdin);
					}
					// atribuindo valor a jogada 2 e verificando se a jogada ja foi feita nessa posição
					else if(jogada2 == 0 && jogada1 != 0 && espelho[pl][pc] == 0  ){
						jogada2 = letras[lin][col];
						b=lin;
						c=col;
						printf("%c ", jogada2);
						fflush(stdin);
					}
					// zerando caso clique em uma posição na qual ja foi escolhida anteriormente
					if(pl==y && pc==z && y==b && c==z){
						jogada1=0;
						jogada2=0;
					}
					
				}
				
				//mostrando a jogada1
				else if(jogada1 != 0 && jogada1 == letras[lin][col] && y==lin && col==z){
					
					printf("%c ", jogada1);
					
				}
				//mostrando a jogada2
				else if(jogada2 != 0 && jogada2 == letras[lin][col] && b==lin && col==c){
					
					printf("%c ", jogada2);
					
				}
				
				//fim da jogada, o usuario acertou e aumenta acertos e tentativas e seta 1 nas posicoes espelhos da matriz
				else if(jogada1 == jogada2 && jogada1!= 0 && jogada2 !=0 ){
					acertos++;
					tentativas++;
					espelho[y][z] = 1;
					espelho[b][c] = 1;
					jogada1=0;
					jogada2=0;
				}
			
				//navegar
				else if(lin == pl && col == pc) {
					printf("_ ");
					
				}
				//mostrando os acertos
				else if(espelho[lin][col] == 1){
					printf("%c ", letras[lin][col]);
				}
				//preenchendo a matriz
				else{
				
					printf("@ ");
				}
				
				
				
			}
			
		}
		printf("\n===================\n");
		printf("  Acertos: %i | %i", acertos, tentativas );
		printf("\n===================");

		// CAPTURA TECLA
		tecla = getche();
		
		// CIMA
		if(tecla == 72) {
                 if(pl > 0) pl--;
        }
        //BAIXO
		else if(tecla == 80) {
             if(pl < QNT-1) pl++;
        }
        //DIREITA
        else if(tecla == 77) {
             if(pc < QNT-1) pc++;
        } 
        //ESQUERDA
        else if(tecla == 75) {
             if(pc > 0) pc--;
        }
		//fim do jogo
		else if(acertos == 18){
			fim = 1;
		}
					
	}
		//fim de jogo, o jogador venceu!
		system("cls");
		printf("===================\n");
		printf("=== FIM DO JOGO ===\n");
		printf("===================\n");
		printf("==== PARABENS =====\n");	
		printf("====== VOCE =======\n");
		printf("===== VENCEU ======\n");
		printf("===================\n");
		printf("=== COM APENAS ====\n");
		printf("  Acertos: %i | %i", acertos, tentativas );
		printf("\n===================");
	
	
	

	
	
		
	

printf("\n\n");
	return 0;
} 
  
