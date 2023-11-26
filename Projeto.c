#include <stdio.h>
#include <stdlib.h>

int s0;
int s1;
int s2;

typedef struct{
    int codInst;
    int rd;
    int rs;
    int rt;
    int shamt;
    int funct;
    int endereco;
    int enderecoIme;
}formR;

// typedef struct{
//     int codInst;
//     int endereco;
// }formJ;

// typedef struct{
//     int codInst;
//     int rs;
//     int rt;
//     int enderecoIme;
// }formI;

// FORMATO R
formR memoriainstrucao(int i){
    formR r;
    printf("\n ################ MEMORIA DE INSTRUCAO ################");
    if (i == 0){
            printf("\n codigo salvo na linha 0: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD: 18 / shamt: 0 / funct: 32");
            r.codInst = 0;
            r.rs = 19;
            r.rt = 20;
            r.rd = 18;
            r.shamt = 0;
            r.funct = 32;
            return r;
    }
    return r;
};

formR registradores(formR r){
    printf("\n################ REGISTRADORES ################");
    if (r.rd == 18){
        r.rd = s0;
        printf("\n define o valor de rd como o resgistrador &s0");
    }else if (r.rs == 18){
        r.rs = s0;
        printf("\n define o valor de rs como o resgistrador &s0");
    }else if (r.rt == 18){
        r.rt = s0;
        printf("\n define o valor de rt como o resgistrador &s0");
    };
    if (r.rd == 19){
        r.rd = s1;
        printf("\n define o valor de rd como o resgistrador &s1");
    }else if (r.rt == 19){
        r.rt = s1;
        printf("\n define o valor de rt como o resgistrador &s1");
    }else if (r.rs == 19){
        r.rs= s1;
        printf("\n define o valor de rs como o resgistrador &s1");
    };
    if (r.rd == 20){
        r.rd = s2;
        printf("\n define o valor de rd como o resgistrador &s2");
    }else if (r.rt == 20){
        r.rt = s2;
        printf("\n define o valor de rt como o resgistrador &s2");
    }else if (r.rs == 20){
        r.rs= s2;
        printf("\n define o valor de rs como o resgistrador &s2");
    };
    return r;
};

formR ULA(formR r){
    printf("\n ################ ULA ################");
    if (r.codInst == 0 && r.funct == 32){
        r.rd = r.rs + r.rt;
        printf("\n realiza a soma do rs com rt");
        return r;
    }


    return r;
};
void memoriadados(formR r){
    printf("\n########## MEMORIA DE DADOS ##########");
    if (r.codInst == 0 && r.funct == 32){
        s0 = r.rd;
        printf("\n salva o valor da soma feita pela ULA e devolve para os registradores");
    }
}

//FIM FORMATO R




int main(){
    // talvez não use
    printf("\n Escreva o valor do resgistrado $s0: ");
    scanf("%i",&s0);
    printf("\n Escreva o valor do registradoor $s1: ");
    scanf("%i",&s1);
    printf("\n Escreva o valor do registrador $s2: ");
    scanf("%i",&s2);
    // fim talvez não use
    int menu=23;
    int pc=0;
    formR r;
    // formJ j;
    // formI I;

    // s0=18 s1=19 s2=20
    while (menu != 0){
    printf("\n ################ MENU ################ \n 0.sair \n 1.ADD $S0,$S1,$S2 \n");
    scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            if (pc != 0){
                pc = 0;
            };
            r=memoriainstrucao(pc);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);
            printf("\n valor de $s0: %i",s0);
            break;
        
        default:
            break;
        }




    }



    return 0;
}