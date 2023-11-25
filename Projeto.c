#include <stdio.h>
#include <stdlib.h>
#define s0 = 1;
#define s1 = 2;
#define s2 = 3;

typedef struct{
    int codInst;
    int rd;
    int rs;
    int rt;
    int shamt;
    int funct;
}formR;

typedef struct{
    int codInst;
    int endereco;
}formJ;

typedef struct{
    int codInst;
    int rs;
    int rt;
    int enderecoIme;
}formI;

// FORMATO R
formR memoriainstrucao(int i){
    formR r;
    if (i == 0){
            printf("\n cod.intrucao: 0 /  1 operando: 19 / 2 operando: 20 / 3 operando: 18 / shamt: 0 / funct: 32");
            r.codInst = 0;
            r.rs = 19;
            r.rt = 20;
            r.rd = 18;
            r.shamt = 0;
            r.funct = 32;
            return r;
    }
};
formR registradores(formR r){
    if (r.rd == 18){
        r.rd = s0;
    }else if (r.rs == 19){
        
    }

}

//FIM FORMATO R




int main(){
    // // talvez não use
    // int so,s1,s2;
    // printf("Escreva o valor do resgistrado $s0: ");
    // scanf("%i",&so);
    // printf("Escreva o valor do registradoor $s1: ");
    // scanf("%i",&s1);
    // Printf("Escreva o valro do registrador $s2: ");
    // scanf("%i",&s2);
    // // fim talvez não use
    int menu=23;
    int pc=0;
    formR r;
    formJ j;
    formI I;

    // s0=18 s1=19 s2=20
    while (menu != 0){
    printf("\n menu \n 1.ADD $S0,$S1,$S2");
    scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            pc = 0;
            r=memoriainstrucao(pc);

            printf("\n %i  %i  %i  %i  %i  %i  ",r.codInst,r.rs,r.rt,r.rd,r.shamt,r.funct);


            
            break;
        
        default:
            break;
        }




    }



    return 0;
}