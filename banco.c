#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct CLIENTE{
	int conta;
	char nome[100];
	float lim_cred;
	float saldo;
}cliente;



void abrir_c(){
	cliente atual;
	FILE * lista;
	int tam;
	lista=fopen("clientes.bin","w+b");
	fread(&tam,sizeof(int),1,lista);
	do{
		system("clear");
		printf("Digite seu nome: ");
		gets(atual.nome);
		printf("Esta correto(y/n)?\n\n");
		puts(atual.nome);
	}while(getchar()=='y');
	atual.conta=tam;
	atual.lim_cred=0;
	atual.saldo=0;
	tam++;
	rewind(lista);
	fwrite(&tam,sizeof(int),1,lista);
	fseek(lista,sizeof(cliente)*(tam-1),SEEK_CUR);
	fwrite(&(atual.conta),sizeof(int),1,lista);
	fwrite(atual.nome,sizeof(char),100,lista);
	fwrite(&(atual.lim_cred),sizeof(float),1,lista);
	fwrite(&(atual.saldo),sizeof(float),1,lista);
	printf("Sua conta é:\n\nNome: %s\nnumero de conta: %04d\n",atual.nome,atual.conta);
	getchar();	
}


int main(){
	int i,j;
	int o;
	while(o){
		system("clear");
		printf("Bem vindo ao banco Big G\n\nescolha sua operação:\n\n(1)Abrir uma conta\n(2)Listagem de saldo\n(3)Deposito\n(4)Saque\n(0)Sair");
		scanf("%d",&o);
		if(o==1)
			abrir_c();
	
	
	}
}
