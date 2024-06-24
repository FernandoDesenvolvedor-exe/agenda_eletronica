#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(void){
    int opcao;

    do{
        system("clear");

        printf("         \n\nAGENDA ELETRONICA CATOLCIA SC\n\n");
        printf("         Menu:\n");
        printf("         Opcao 1: Cadastro;\n");
        printf("         Opcao 2: Consulta;\n");
        printf("         Opcao 1: Exclusao;\n");
        printf("         Opcao 1: Sair;\n");
        printf("         Digite uma das opcoes: ");
        scanf("%i", &opcao);
        fflush(stdin);
        system("clear");

        switch (opcao)
        {
        case 1:
            Contato contato;
            contato.id = proximoidlivre();

            printf("Digite o nome do contato: ");
            getc(stdin);
            fgets(contato.nome,50,stdin);
            contato.nome[strcspn(contato.nome,"\n")] = 0;
            fflush(stdin);

            printf("Digite o numero do contato no formato (99)99999-9999: ");
            fgets(contato.telefone,25,stdin);
            contato.nome[strcspn(contato.telefone,"\n")] = 0;

            cadastro(contato);
            break;        
        case 2:
            int idc;

            printf("Digite um ID (0 - Mostrar todos os contatos): ")
            scanf("%i". &idc);
            fflush(stdin);

            system("clear");

            printf("ID\t       NOME\t      TELEFONE\t\n");
            consultacontato(idc);

            printf("\n\nDigite qualquer numero e aperte ENTER para voltar ao menu: ");
            scanf("%i", &opcao);            
            fflush(stdin);
            opcao = 0;

            break;
        case 3: 
            int id;
            printf("Digite o ID do contato que deseja excluir");
            scanf("%i", &id);
            fflush(stdin);

            excluicontato(id);
            break;
        case 4:
            printf("\n\n                   Obrigado por utilizar nossa agenda eletronica!");
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    }while(opcao != 4);

    return 0;
}