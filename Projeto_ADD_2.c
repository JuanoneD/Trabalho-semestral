#include <stdio.h>
#include <stdlib.h>

int s0;
int s1;
int s2;
int ra = -4;
int pc=0;


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
    if (pc == 0){ 
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
    }else if (pc == 4) {
        printf(" \n instrucao  da linha %i:SUB $S0,$S1,$S2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD: 18 / shamt: 0 / funct: 34",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 20;
        r.rd = 18;
        r.shamt = 0;
        r.funct = 34;
        return r;
    }else if (pc == 8){
        printf(" \n instrucao  da linha %i: AND $S0,$S1,$S2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD:18 / shamt: 0 / funct: 36",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 20;
        r.rd = 18;
        r.shamt = 0;
        r.funct = 36;
        return r;
    }else if(pc == 12){
        printf(" \n instrucao  da linha %i: OR $S0,$S1,$S2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD: 18 / shamt: 0 / funct: 37",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 20;
        r.rd = 18;
        r.shamt = 0;
        r.funct = 37;
        return r;
    }else if (pc == 16){
        printf(" \n instrucao  da linha %i: JR $RA",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 0 / RT: 0 / RD: 31 / shamt: 0 / funct: 37",pc);
        r.codInst = 0;
        r.rs = 0;
        r.rt = 0;
        r.rd = 31;
        r.shamt = 0;
        r.funct = 8;
        return r;
    }else if (pc == 20){
        printf(" \n instrucao  da linha %i: SLL $S0,$S2,2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 20 / RT: 0 / RD: 18 / shamt: 2 / funct: 0",pc);
        r.codInst = 0;
        r.rs = 20;
        r.rt = 0;
        r.rd = 18;
        r.shamt = 2;
        r.funct = 0;
        return r;
    }else if (pc == 24){
        printf(" \n instrucao  da linha %i: SRL $S0,$S1,2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 0 / RD: 18 / shamt: 2 / funct: 2",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 0;
        r.rd = 18;
        r.shamt = 2;
        r.funct = 2;
        return r;
    }else if (pc == 28){
        printf(" \n instrucao  da linha %i: SLT $S0,$S1,$S2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD: 18 / shamt: 0 / funct: 42",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 20;
        r.rd = 18;
        r.shamt = 0;
        r.funct = 42;
        return r;
    }else if (pc == 32){
        printf(" \n instrucao  da linha %i: ADDU $S0,$S1,$S2",pc);
        printf("\n codigo salvo na linha %i: \n cod.intrucao: 0 /  RS: 19 / RT: 20 / RD: 18 / shamt: 0 / funct: 33",pc);
        r.codInst = 0;
        r.rs = 19;
        r.rt = 20;
        r.rd = 18;
        r.shamt = 0;
        r.funct = 33;
        return r;
    };
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
    if (r.rs == 31){
        r.rs = ra;
        printf("\n define o valor de rs como o resgistrador &ra");
    }else if (r.rd == 31){
        r.rd = ra;
        printf("\n define o valor de rs como o resgistrador &ra"); 
    }else if (r.rd == 31){
        r.rd = ra;
        printf("\n define o valor de rs como o resgistrador &ra"); 
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
    }else if (r.codInst == 0 && r.funct == 36 ){
        r.rs = r.rs & r.rt;
        printf("\n realiza a operacao AND de rs com rt");
    }else if (r.codInst == 0 && r.funct == 37){
        r.rs = r.rs | r.rt;
        printf("\n realiza a operacao OR de rs com rt");
    }else if (r.codInst == 0 && r.funct == 8){
        pc = r.rs;
        printf("\n define o valor de pc igual ao $ra");
    }else if (r.codInst == 0 && r.funct == 0){
        r.rs= r.rs << r.shamt;
        printf("\n realiza a operacao SHIFT LEFT de rs com o valor de shamt");
    }else if (r.codInst == 0 && r.funct == 2){
        r.rs= r.rs >> r.shamt;
        printf("\n realiza a operacao SHIFT  RIGHT de rs com o valor de shamt");
    }else if (r.codInst == 0 && r.funct == 42){
        printf("verifica qual é menor e devolve 1 caso rs seja menor que rt");
        if ( r.rs < r.rt){
            r.rs = 1;
        }else{
            r.rs = 0;
        };
    }else if (r.codInst == 0 && r.funct == 33){
        r.rs += r.rt;
        printf("\n realiza a soma do rs com rt sem sinal");
        return r;
    };
    return r;
};
void memoriadados(formR r){
    printf("\n########## MEMORIA DE DADOS ##########");
    if (r.codInst == 0 && (r.funct == 32 || r.funct == 34 || r.funct == 36 || r.funct == 37 || r.funct == 0 || r.funct == 2 || r.funct == 42 || r.funct == 33)){
        if (r.rd == s0){
            s0 = r.rs;
            printf("\n Devolve o valor  obitido pela a ULA  para o 1 operando");
            printf("\n n Valor atual do registrador $S0: %i \n ",s0);
        }else if (r.rd == s1){
            s1 = r.rs;
            printf("\n Devolve o valor  obitido pela a ULA  para o 1 operando");
            printf("\n n Valor atual do registrador $S1: %i \n ",s1);
        }else if (r.rd == s2){
            s2 = r.rs;
            printf("\n Devolve o valor  obitido pela a ULA para o 1 operando");
            printf("\n n Valor atual do registrador $S2: %i \n ",s2);
        };
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
void exe_prox(){
    formR r;
    int primeiro,segundo,terceiro; // operandos 
    int aux=1;
    while (aux == 1){
        printf("\n Executar proxima instrução?\n  1.sim 2.nao ");
        scanf("%i",&aux);
        if (aux == 1){
            pc += 4;
            printf(" valor de PC: %i",pc);
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);            
        };
    };
}

int main(){
    int menu=23;
    int primeiro,segundo,terceiro; // operandos 
    formR r;
    while (menu != 0){
    printf("\n ################ MENU ################\n lista de instrucoes(podem ser executadas sequencialemnte apos escolher a desejada) \n 0.sair \n 1.ADD  \n 2.SUB \n 3.AND \n 4.OR \n");
    printf(" 5.JR \n 6.SLL \n 7.SRL \n 8.SLT \n 9.ADDU");
    scanf("%i",&menu);
        switch (menu)
        {
        case 1:
            def_valores();
            def_operandos(&primeiro,&segundo,&terceiro);
            if (pc != 0){
                pc = 0;
            };
                r=memoriainstrucao(pc,primeiro,segundo,terceiro);
                r=registradores(r);
                r=ULA(r);
                memoriadados(r);
                exe_prox();
            break;
        case 2: 
            def_valores();
            if(pc != 4) {
                pc = 4;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);
            exe_prox();
        break;
        case 3:
            def_valores();
            if (pc != 8){
            pc = 8;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);
            exe_prox();
        break;
        case 4:
            def_valores();
            if (pc != 12){
                pc = 12;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);

            exe_prox();
        break;
        case 5:
            if (pc != 16){
                pc = 16;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);

            exe_prox();
        break;
        case 6:
            def_valores();
            if (pc != 20){
                pc = 20;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);

            exe_prox();
            break;
        case 7:
            def_valores();
            if (pc != 24){
                pc = 24;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);

            exe_prox();
            break;
        case 8:
            def_valores();
            if (pc != 28){
                pc = 28;
            };
            r=memoriainstrucao(pc,primeiro,segundo,terceiro);
            r=registradores(r);
            r=ULA(r);
            memoriadados(r);

            exe_prox();
        break;
        default:
            break;
        }
    }

    return 0;
}