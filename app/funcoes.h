#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int id;
    char nome[50];
    char telefone[25];
} Contato;

int proximoid();
void cadastro(Contato contato);
void consultacontato();
void excluicontato(int id);

void excluicontato(int id){
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
        }
    }
}

int proximoid(){
    Contato contato; 
    int id;

    FILE *file_bin;
    file_bin = fopen("database/contatos.bin", "rb");

    if(file_bin == NULL){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }

    while(fread(&contatos[0], sizeof(Contato), 1, file_bin) == 1){
        id = Contato.id;
    }
    fclose(file_bin);

    id++;

    return id;
}

void consultacontato(){
    Contato contato;

    FILE *file_bin;
    file_bin = fopen("database/contatos.bin", "rb");

    if(file_bin == NULL){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while(fread(&contatos[0], sizeof(Contato), 1, file_bin) == 1){
        printf("%i\t", contato.id);    
        printf("%s\t", contato.nome);    
        printf("%s\t", contato.telefone);    
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

    fwrite(&contatos[0], sizeof(Contato), 1, file_bin);
    fclose(file_bin);    
}

#endif
