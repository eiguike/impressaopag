#include <stdio.h>
#include <stdlib.h>

// calcula o numero de paginas por bloco
int calcular(int paglivro){
	int i;
	for(i=8;i>1;i--){
		if(paglivro%(i*4) == 0){
			return i;
		}
	}
	return calcular(paglivro+1);
}

// funcao que gera a sequencia de impressao, para que
// forme um livro.
int sequencia(int blocofolhas, int paglivro){
	FILE * arquivo = fopen("sequencia.txt","w+");

	// folhas da frente
	int voltar = paglivro/2;
	int avancar = (paglivro/2)+1;
	// folhas de tras
	int	voltar1 = (paglivro/2)-1;
	int	avancar1 = (paglivro/2)+2;

	//contadores
	int i,i2;

	// numero de blocos no livro
	int nblocos = paglivro/(blocofolhas*4);
	int aux;
	
	if((aux = paglivro-(blocofolhas*4*nblocos)) != 0){
		printf("ATENCAO, NAO FOI POSSIVEL CRIAR BLOCOS EXATOS.\nHA %d FOLHAS EM BRANCO.\n", aux);
	}

	for(i2=0;i2<nblocos;i2++){
		fprintf(arquivo,"BLOCO NUMERO: %d\n", i2+1);
		for(i=blocofolhas-1;i>=0;i--){
			fprintf(arquivo,"%d, %d",voltar, avancar);
			if(i>0)
				fprintf(arquivo,", ");
			voltar-=2;
			avancar+=2;
		}
		fprintf(arquivo,"\n");
		
		for(i=blocofolhas-1;i>=0;i--){
			fprintf(arquivo,"%d, %d",voltar1, avancar1);
			if(i>0)
				fprintf(arquivo,", ");
			voltar1-=2;
			avancar1+=2;
		}

		fprintf(arquivo,"\n\n");
	}
	fprintf(arquivo,"\n");
	fclose(arquivo);

}

int main(){
	int bloco_de_folhas; // quantos folhas tera cada bloco
	int pag_do_livro;	// quantas paginas tem o livro no total
	int paglivro; // nova quantidade de folhas, contando com as brancas.

	scanf("%d",&pag_do_livro);

	bloco_de_folhas = calcular(pag_do_livro);
	sequencia(bloco_de_folhas,pag_do_livro);
}