#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int id;
    char nome[50];
    char telefone[25];
} Contato;

int proximoidlivre();
void cadastro(Contato contato);
void consultacontato(int id);
void excluicontato(int id);

void excluicontato(int id){
    char encontrado = 'N';
    char arquivo[] = "database/contatos.bin";
    Contato contato;
    Contato contatos[100];
    int num_contatos = 0;

    FILE *file_bin;
    file_bin = fopen(arquivo,"rb");

    if(file_bin == NULL){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    while(fread(&contato, sizeof(Contato), 1, file_bin) == 1){
        contatos[num_contatos++] = contato;
    }
    fclose(file_bin);

    for(int n = 0; n < num_contatos; n++){
        if(contatos[n].id == id){
            for(int i = n; i < num_contatos; i++){
                contatos[i] = contatos[i+1];
            }
            num_contatos--;

            FILE *file_write;
            file_write = fopen(arquivo, "wb");
            fwrite(&contatos[0], sizeof(Contato), 1, file_write);
            fclose(file_write);

            FILE *file_update;
            file_update = fopen(arquivo, "ab");
            for(int i = 1; i < num_contatos; i++){
                fwrite(&contatos[0], sizeof(Contato), 1, file_update);
            }
            fclose(file_update);

            encontrado = 'S';
        }
    }

    if(econtrado == 'N'){
        printf("Contato com id %i nao encontrado!",id);
    } else {
        printf("Contato com id %i excluido com sucesso!",id);
    }
}

int proximoidlivre(){
    Contato contato; 
    int id = 0, cont = 1, idr = 0;

    FILE *file_bin;
    file_bin = fopen("database/contatos.bin", "rb");

    if(file_bin == NULL){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    while(fread(&contatos[0], sizeof(Contato), 1, file_bin) == 1){
        if(cont != contato.id){
            idr = cont;
        }

        id = Contato.id;
        cont++;
    }    
    fclose(file_bin);

    if(idr != 0){
        id = idr;
    } else {
        id++;
    }

    return id;
}

void consultacontato(int id){
    Contato contato;
    Contato contatos[100];
    int num_contatos = 0;

    FILE *file_bin;
    file_bin = fopen("database/contatos.bin", "rb");

    if(file_bin == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    if(id != 0){
        char sucesso = 'N';

        while(fread(&contatos[0], sizeof(Contato), 1, file_bin) == 1){
            if(contato.id == id){
                sucesso = 'S';
                printf("%i\t", contato.id);    
                printf("%s\t", contato.nome);    
                printf("%s\t\n", contato.telefone);    
            }            
        }

        if(sucesso == 'N'){
            printf("Usuario nao encontrado");
        }
    } else {
        while(fread(&contatos[0], sizeof(Contato), 1, file_bin) == 1){
            printf("%i\t", contato.id);    
            printf("%s\t", contato.nome);    
            printf("%s\t\n", contato.telefone);    
        }
    }
    
    fclose(file_bin);
}

void cadastro(Contato contato){
    FILE *file_bin;
    file_bin = fopen("database/contatos.bin", "ab");

    if(file_bin == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    fwrite(&contato, sizeof(Contato), 1, file_bin);
    fclose(file_bin);    
}

#endif
