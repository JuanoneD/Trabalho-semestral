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
}formR;

formR memoriainstrucao(int pc,int primeiro,int segundo,int terceiro){
    formR r;
    printf("\n ################ MEMORIA DE INSTRUCAO ################");
    if (pc == -4){ 
        printf("\n codigo salvo na linha %i \n cod.intrucao: 0 /",pc);
        r.codInst = 0;
        if (segundo == 1){
            r.rs = 18;
            printf(" RS: %i /",r.rs);
        }else if (segundo == 2){
            r.rs = 19;
            printf(" RS: %i /",r.rs);
        }else if (segundo == 3){
            r.rs = 20;
            printf(" RS: %i /",r.rs);
        };
        if (terceiro == 1){
            r.rt = 18;
            printf(" RT : %i /",r.rt);
        }else if (terceiro == 2){
            r.rt = 19;
            printf(" RT : %i /",r.rt);
        }else if (terceiro == 3){
            r.rt = 20;
            printf(" RT : %i /",r.rt);
        };        
        if (primeiro == 1){
            r.rd = 18;
            printf(" RD : %i /",r.rd);
        }else if (primeiro == 2){
            r.rd = 19;
            printf(" RD: %i /",r.rd);
        }else if (primeiro == 3){
            r.rd = 20;
            printf(" RD: %i /",r.rd);
        };
        printf(" shamt: 0 / funct: 32 \n");
        r.shamt = 0;
        r.funct = 32;
        return r;
    }else if (pc == 0){
            printf(" \n instrucao  da linha %i:ADD $S0,$S1,$S2",pc);
            printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD: 18 / shamt: 0 / funct: 32",pc);
            r.codInst = 0;
            r.rs = 19;
            r.rt = 20;
            r.rd = 18;
            r.shamt = 0;
            r.funct = 32;
            return r;
    }else if (pc == 4){
            printf(" \n instrucao  da linha %i:ADD $S1,$S0,$S2",pc);
            printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 18 / RT: 20 / RD: 19 / shamt: 0 / funct: 32",pc);
            r.codInst = 0;
            r.rs = 18;
            r.rt = 20;
            r.rd = 19;
            r.shamt = 0;
            r.funct = 32;
            return r;
    }else if (pc == 8) {
        printf(" \n instrucao  da linha %i:SUB $S0,$S1,$S2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 18 / RT: 20 / RD: 19 / shamt: 0 / funct: 34",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 20;
        r.rd = 18;
        r.shamt = 0;
        r.funct = 34;
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
        r.rs += r.rt;
        printf("\n realiza a soma do rs com rt");
        return r;
    }else if (r.codInst == 0 && r.funct == 34 ){
        r.rs -= r.rt;
        printf("\n realiza a subtracao de rs com rt");
    };
    return r;
};
void memoriadados(formR r){
    printf("\n########## MEMORIA DE DADOS ##########");
    if (r.codInst == 0 && (r.funct == 32 || r.funct == 34)){
        if (r.rd == s0){
            s0 = r.rs;
            printf("\n Devolve o valor  obitido pela a ULA e devolve para o 1 operando");
            printf("\n n Valor atual do registrador $S0: %i \n ",s0);
        }else if (r.rd == s1){
            s1 = r.rs;
            printf("\n Devolve o valor  obitido pela a ULA e devolve para o 1 operando");
            printf("\n n Valor atual do registrador $S1: %i \n ",s1);
        }else if (r.rd == s2){
            s2 = r.rs;
            printf("\n Devolve o valor  obitido pela a ULA e devolve para o 1 operando");
            printf("\n n Valor atual do registrador $S2: %i \n ",s1);
        }

    }
}

//FIM FORMATO R
void def_operandos(int *primeiro,int *segundo,int *terceiro){
    printf("Escolha o primeiro operando: 1 = $S0 / 2 = $S1 / 3 = $S2 ");
    scanf("%i",&*primeiro);
    printf("Escolha o segundo operando: 1 = $S0 / 2 = $S1 / 3 = $S2 ");
    scanf("%i",&*segundo);
    printf("Escolha o terceiro operando: 1 = $S0 / 2 = $S1 / 3 = $S2 ");
    scanf("%i",&*terceiro);
};

void def_valores() {
    printf("\n Escreva o valor do resgistrador $s0: ");
    scanf("%i",&s0);
    printf("\n Escreva o valor do registrador $s1: ");
    scanf("%i",&s1);
    printf("\n Escreva o valor do registrador $s2: ");
    scanf("%i",&s2);
};

int main(){
    int menu=23;
    int pc=-4;
    int aux=1;
    int primeiro,segundo,terceiro; // operandos 
    formR r;
    def_valores();
    while (menu != 0){
    printf("\n ################ MENU ################\n lista de instrucoes(podem ser executadas sequencialemnte apos escolher a desejada) \n 0.sair \n 1.ADD  \n 2.SUB");
    scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            aux = 1;
            def_operandos(&primeiro,&segundo,&terceiro);
            if (pc != -4){
                pc = -4;
            };
                r=memoriainstrucao(pc,primeiro,segundo,terceiro);
                r=registradores(r);
                r=ULA(r);
                memoriadados(r);

            while (aux == 1){
                printf("\n Executar proxima instrução?\n  1.sim 2.nao ");
                scanf("%i",&aux);
                pc += 4;
                printf(" valor de PC: %i",pc);
                r=memoriainstrucao(pc,primeiro,segundo,terceiro);
                r=registradores(r);
                r=ULA(r);
                memoriadados(r);
            };
            break;
        case 2: 
            aux = 1;
            if(pc != 8) {
                pc = 8;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);
            while(aux == 1) {
                printf("\n Executar proxima instrução?\n  1.sim 2.nao ");
                scanf("%i", &aux);
                pc += 4;
                printf(" valor de PC: %i",pc);
                r=memoriainstrucao(pc,primeiro,segundo,terceiro);
                r=registradores(r);
                r=ULA(r);
                memoriadados(r);
            }
            break;

        default:
            break;
        }
    }

    return 0;
}