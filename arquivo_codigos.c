#include "arquivo_header_v1.h"
#include "console_v1.5.4.h" /*Funções utilizadas: setTituloConsole,MaxDimensaoJanela,setDimensaoJanela*/
#include "conio_v3.2.4.h" /* Funções utilizadas: clrscr,textbackground */
#include "graphics_v1.1.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h> /* Funções utilizadas: strcpy */

/*
    Essa função irá alterar a cor do quadrado, como parametro ela recebe uma estrutura ponteiro do tipo QUADRADO. Ela irá sortear um número aleatorio de 0 até 14, 
    iremos então icrementar mais um ao resultado final, para que ele o resultado fique entre 1 até 15,o resultado será armazenado na variavel COR do tipo COLORS da estrutura QUADRADO.
    Todo o código de cor aleatorio será feito de um DO WHILE, para que tenha a certeza de que nenhum quadrado irá receber a cor PRETO, para que o quadrado não suma no console.
*/
void AjustarCorQuadrado(QUADRADO *quadrado)
{
    srand(time(NULL)); 
    do
    {
    quadrado->cor = rand() % 14;
    quadrado->cor++;
    }while(quadrado->cor==BLACK);     
}


/*
    Nessa função iremos passar como parametro uma estrutura ponteiro do tipo QUADRADO, iremos criar as variaveis X e Y tipo inteiro. Aonde iremos amarzenar no X 
    a posição Horizontal do Quadrado, no Y a posição Vertical do Quadrado. após isso iremos limpar a tela e depois iremos imprimir o quadrado asteristico.
    Iremos primeiro posicionar o cursor dois pontos a menos na vertical de onde o quadrado se encontra e na posição horizontal X sem modificação, e iremos imprimir a primeira linha
    em seguida iremos posicionar o cursor na posição horizontal X sem alteração e na posição Y menos um e imprimir a segunda linha do quadrado, após isso iremos imprimir a ultima linha
    aonde iremos posicionar o cursos na posição horizontal X sem alteração e na posição Y sem alteração também, e em seguida iremos imprimir a ultima linha, e iremos fazer o programa "dormir",
    passando como parametro para a função SLEEP a velocidade do quadrado recebido como parametro. 

    Com essa função iremos criar o quadrado e arrumar a sua posição, e com o sleep no final, iremos conseguir controlar a velocidade que o quadrado irá ser gerado no proximo 
*/
void AjustarPosicaoQuadrado(QUADRADO *quadrado)
{
    int x,y;
  
    x = quadrado->posX_Atual;
    y = quadrado->posY_Atual;
    
    clrscr();
    gotoxy((x),(y-2));    
    printf("***");                                  
    gotoxy((x),(y-1));    
    printf("***");  ;                                             
    gotoxy((x),(y));    
    printf("***");
   /* Sleep(quadrado->VELOCIDADE);*/
    
}



/*
    Iremos receber 1 estruturas ponteiro QUADRADO.
    Nessa função iremos utilizar um número aleatorio para definir a direção do quadrado. Iremos usar o rand para retornar um numero de 0 até 3 e usaremos um icremento 
    para que retorne de 1 até 4, depois disso iremos armazenar a direção na variavel direcao da estrutura QUADRADO e chamamos a função principal do código todo.
*/
void SorteioDirecao(QUADRADO *quadrado_asteristico)
{
    /* semente para a função rand() */
    srand(time(NULL));

    /* gerar um número aleatório entre 0 e 3 */ 
    quadrado_asteristico->direcao = rand() % 4;
    textcolor(LIGHTGRAY);
    /* adicionar 1 ao número para obter um número aleatório entre 1 e 4*/
    quadrado_asteristico->direcao++;
    
    
    

}

/*
    Nessa função iremos imprimir um menu que irá mostrar a cor dos dois quadrados e a direção do quadrado asteristico e a sua velocidade;
*/

void EscreverTela(QUADRADO *quadradro_asteristico, QUADRADO *quadradro_principal)
{    
/*
    Definimos 3 string, sendo elas usadas para guardar a direção, e as cores dos quadrados;
*/
    char direcao[10],corQuadradoPrincipal[20],corQuadradoAsteristico[20]; 
   
/*
    Código para fazer o programa ser executado em 1 milisegundo, começando desse ponto até o ponto  timeEndPeriod( 1 )
*/
    timeBeginPeriod( 1 );   
    
/*
    Nesse switch iremos ver os casos em que a direção está, sendo o caso 1 para baixo, o caso 2 para cima, caso 3 para direita e caso 4 para esquerda:
    se for o caso 1, passaremos para a string direcao a palavra INFERIOR
    se for o caso 2, passaremos para a string direcao a palavra SUPERIOR
    se for o caso 3, passaremos para a string direcao a palavra DIREITA
    se for o caso 4, passaremos para a string direcao a palavra ESQUERDA    
*/    
    switch(quadradro_asteristico->direcao)
    {
        case 1:
        strcpy(direcao,"Inferior");
        break;
        case 2:
        strcpy(direcao,"Superior");
        break;
        case 3:
        strcpy(direcao,"Direita");
        break;
        case 4:
        strcpy(direcao,"Esquerda");
        break;
    }

/*
    Chamaremos duas vezes a função SWITCHCOR, para que seja alocado nas strings a cor dos quadrados em portugues a cor que está alocado nas estrtuturas
*/
    SwitchCor(quadradro_asteristico->cor,corQuadradoAsteristico);
    SwitchCor(quadradro_principal->cor,corQuadradoPrincipal);  
     
/*
    Iremos colocar o cursor no ponto inferior esquerdo do quadrado principal e trocaremos a cor do texto para BRANCO
*/
    gotoxy(1,quadradro_principal->area.bottom);
    textcolor(WHITE);
/*
    Será utilizado o \n no começo para que seja quebrado a area e que seja impresso todas as informações desejadas na borda do console original.
    Em seguida alteramos a cor do textColor para a cor original do quadrado asteristico, para que a cor do quadradoAsteristico seja alterado também.
    
*/
    printf("\nVELOCIDADE: %d Milisegundos\nDirecao:%s\nCor Quadrado Principal: %s\nCor Quadrado Asteristico: %s\n",quadradro_asteristico->VELOCIDADE,direcao,corQuadradoPrincipal,corQuadradoAsteristico);           clrscr();
    textcolor(quadradro_asteristico->cor);
    timeEndPeriod( 1 );
}

/*
    Essa função será utilizada para imprimir o quadrado prinicpal, a area aonde o quadrado asteristico irá andar.
    Recebemos como parametro a estrutura ponteiro QAUDRADO e a estrutura TELA
*/
void Quadrados(QUADRADO *quadrado,COORD tela)
{
/*
    Criamos 4 variaveis do tipo inteiro, que irá armazenar os valores para criarmos a janela, sendo as duas variaveis que começam com janelaA para a janela maior e as
    que começam com janelaB para a tela que irá ficar dentro da janela maior.
*/   
    int janelaA_x;
    int janelaA_y;
    int janelaB_x;
    int janelaB_y;

   
/*
    Será feito o calculo para definirmos o valor de cada variavel, tela.X/2 e tela.Y/2 representa o ponto do meio da tela. 
    Em seguido iremos apagar toda a tela, pois, essa mesma função será usada para recriamos novamente o quadrado, para isso temos que apagar toda a tela.
    Após isso iremos definir a cor dessa janela, iremos utilizar como parametro a cor definida da estrutura quadrada, usando a variavel COR
*/
    janelaA_x = (tela.X/2) - (quadrado->largura / 2);
    janelaA_y = (tela.Y/2) - (quadrado->altura / 2);               
    janelaB_x = ((tela.X/2) - (quadrado->largura / 2)) ;
    janelaB_y = ( (tela.Y/2) - (quadrado->altura / 2)) ;
   
    system("cls"); 
    textbackground(quadrado->cor);
   
    
/*
    Depois de definido todas as variaveis utilizadas e ter sido setada a cor da janela, iremos imprimir ela.
*/
    window(
    janelaA_x - quadrado->lados.ladoEsquerdo,
    janelaA_y + quadrado->lados.ladoSuperior,
    (janelaA_x + quadrado->largura) + quadrado->lados.ladoDireito,
    (janelaA_y + quadrado->altura) + quadrado->lados.ladoInferior);
  
    
    clrscr();
  
    textbackground(BLACK);
    

    /*    Esse será o quadrado Menor */
    window(
    (janelaB_x +1) - quadrado->lados.ladoEsquerdo,
    (janelaB_y +1) + quadrado->lados.ladoSuperior,
    ((janelaB_x + quadrado->largura)-1)+ quadrado->lados.ladoDireito ,
    (( janelaB_y + quadrado->altura)-1)+ quadrado->lados.ladoInferior);
      
}

/*
    Nessa função iremos receber uma variavel
*/
void SwitchCor(COLORS cor, char string[])
{
    switch (cor)
    {
    case BLACK:
    strcpy(string, "Preto");
    break;
    case BLUE:
    strcpy(string, "Azul");
    break;
    case GREEN:
    strcpy(string, "Verde");
    break;
    case CYAN:
    strcpy(string, "Ciano");
    break;
    case RED:
    strcpy(string, "Vermelho");
    break;
    case MAGENTA:
    strcpy(string, "Magenta");
    break;
    case BROWN:
    strcpy(string, "Marrom");
    break;
    case LIGHTGRAY:
    strcpy(string, "Cinza Claro");
    break;
    case DARKGRAY:
    strcpy(string, "Cinza Escuro");
    break;
    case LIGHTBLUE:
    strcpy(string, "Azul Claro");
    break;
    case LIGHTGREEN:
    strcpy(string, "Verde Claro");
    break;
    case LIGHTCYAN:
    strcpy(string, "Ciano Claro");
    break;
    case LIGHTRED:
    strcpy(string, "Vermelho Claro");
    break;
    case LIGHTMAGENTA:
    strcpy(string, "Magenta Claro");
    break;
    case YELLOW:
    strcpy(string, "Amarelo");
    break;
    case WHITE:
    strcpy(string, "Branco");
    break;
    
    }
}



void SwitchDirecao(QUADRADO *quadrado_asteristico, QUADRADO *quadrado_principal, TELA *tela)
{   
    
    EVENTO evento;
    int i=0;
    timeBeginPeriod( 1 );
    switch(quadrado_asteristico->direcao)
    {
        case 1:
        /* INDO PARA BAIXO */
            
            EscreverTela(quadrado_asteristico,quadrado_principal);
            do
            {   
                for(i=0;i<10000;i++)
                {
                    if( hit(KEYBOARD_HIT) )
                    {
                    evento = Evento();
                    if(evento.teclado.status_tecla == LIBERADA)
                    {       
                                            
                        SwitchTeclas(evento.teclado.codigo_tecla,quadrado_asteristico,quadrado_principal,tela );
                        SwitchDirecao(quadrado_asteristico,quadrado_principal,tela); 
                          
                    }
                    }           
                    else
                    {
                    if(i==1000)
                    {
                    AjustarPosicaoQuadrado(quadrado_asteristico);
                    quadrado_asteristico->posY_Atual+=1;   
                    printf("1s");
                    }


                    
                    }
                }          
                
                       
            }
            while(quadrado_asteristico->posY_Atual <= quadrado_principal->area.bottom);            
            quadrado_asteristico->direcao = 2;
           
            SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);
       
        break;
        case 2:
        
        /* INDO PARA CIMA */
            EscreverTela(quadrado_asteristico,quadrado_principal);
            do
            {     
                if( hit(KEYBOARD_HIT) )
                {
                    evento = Evento();
                    if(evento.teclado.status_tecla == LIBERADA)
                    {                                
                        SwitchTeclas(evento.teclado.codigo_tecla,quadrado_asteristico,quadrado_principal,tela );
                        SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);  
                    }
                } 
                else
                {
                   
                    AjustarPosicaoQuadrado(quadrado_asteristico);                
                    quadrado_asteristico->posY_Atual=quadrado_asteristico->posY_Atual-1; 
                              
                }
                
            }while(quadrado_asteristico->posY_Atual >= quadrado_principal->area.top);
            quadrado_asteristico->direcao = 1;
            SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);
             
        
        break;

        case 3:
        /* PARA DIREITA */
            EscreverTela(quadrado_asteristico,quadrado_principal);
            do
            {  
                if( hit(KEYBOARD_HIT) )
                {
                    evento = Evento();
                    if(evento.teclado.status_tecla == LIBERADA)
                    {                              
                        SwitchTeclas(evento.teclado.codigo_tecla,quadrado_asteristico,quadrado_principal,tela );                                   
                        SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);  
                    }
                } 
                else
                {
                    
                    AjustarPosicaoQuadrado(quadrado_asteristico);
                    quadrado_asteristico->posX_Atual++;                 
                }               
                
            }
            while(quadrado_asteristico->posX_Atual <= quadrado_principal->area.right);
            quadrado_asteristico->direcao = 4;
            SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);
        
        break;

        case 4:
       /* PARA ESQUERDA */
            EscreverTela(quadrado_asteristico,quadrado_principal);
            do
            {     
                if( hit(KEYBOARD_HIT) )
                {
                    evento = Evento();
                    if(evento.teclado.status_tecla == LIBERADA)
                    {                             
                        SwitchTeclas(evento.teclado.codigo_tecla,quadrado_asteristico,quadrado_principal,tela );
                        SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);   
                    }
                } 
                else
                {
                     
                    AjustarPosicaoQuadrado(quadrado_asteristico);
                    quadrado_asteristico->posX_Atual--;
                  
                }                
                
            }
            while(quadrado_asteristico->posX_Atual >= quadrado_principal->area.left);
            quadrado_asteristico->direcao = 3;
            SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);
        
        break;
    }
    timeEndPeriod( 1 );
}


void SwitchTeclas(DWORD tecla, QUADRADO *quadrado_asteristico,QUADRADO *quadrado_principal, TELA *tela )
{
	

    switch (tecla)
    {       
        case SETA_PARA_BAIXO:
            quadrado_asteristico->direcao = 1;
            SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);  
        break;
        
        case SETA_PARA_CIMA:
            quadrado_asteristico->direcao = 2;
        break;

        case SETA_PARA_DIREITA:
            quadrado_asteristico->direcao = 3;
        break;

        case SETA_PARA_ESQUERDA: 
            quadrado_asteristico->direcao = 4;
        break;

        case ESPACO:    
            AjustarCorQuadrado(quadrado_asteristico);
            textcolor(quadrado_asteristico->cor);    
        break;

        case TAB:
            AjustarCorQuadrado(quadrado_principal);
            Quadrados(quadrado_principal,tela->dimensao);
        break;

        case F1:
            if(quadrado_asteristico->VELOCIDADE>=1)
            {
                quadrado_asteristico->VELOCIDADE-=100;
                SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);  
            } 
        break;

        case F2:
            if(quadrado_asteristico->VELOCIDADE<=2000)
            {
                quadrado_asteristico->VELOCIDADE+=100;  
            }
        break;

        /* O BOTÃO F3 VAI AUMENTAR A AREA DO QUADRADO, ADICIONADO UMA COLUNA PARA A ESQUERDA*/
        case F3:                 
            if(quadrado_principal->lados.largura <= 102)
            {   
                quadrado_principal->lados.largura++; 
                quadrado_principal->area.right++;                
                quadrado_principal->lados.ladoEsquerdo++;            
            }
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
            
        break;

        /* O BOTÃO F4 VAI DIMINUIR A AREA DO QUADRADO, DIMINUINDO UMA COLUNA PARA A ESQUERDA*/
        case F4:        
            if(quadrado_principal->lados.largura > 5)
            {
                
                quadrado_principal->lados.largura--;
                quadrado_principal->lados.ladoEsquerdo--;
                quadrado_principal->area.right--; 

            }
        /* Essa condição serve para irmos empurrando o quadrado para cima, para ele não ser "comido" pela barra da esquerda*/
             if(quadrado_principal->lados.largura >=5 && quadrado_asteristico->posX_Atual <= quadrado_principal->area.left  )
            {
                if(quadrado_asteristico->posX_Atual <= quadrado_principal->area.right)
                {
                    quadrado_asteristico->posX_Atual++;
                }
                else
                {
                    quadrado_asteristico->posX_Atual--;
                }
                     
            }
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F5 VAI AUMENTAR A AREA DO QUADRADO, ADICIONADO UMA COLUNA PARA A DIREITA*/
        case F5:            
            if(quadrado_principal->lados.largura <= 102)
            {
                quadrado_principal->area.right++;
                quadrado_principal->lados.largura++;                
                quadrado_principal->lados.ladoDireito++;
            }
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);   
        break;

        /* O BOTÃO F6 VAI DIMINUIR A AREA DO QUADRADO, DIMINUINDO UMA COLUNA PARA A DIREITA*/
        case F6:   
            if(quadrado_principal->lados.largura >= 6)
            {
                quadrado_principal->lados.ladoDireito--;
                quadrado_principal->area.right--;
                quadrado_principal->lados.largura--; 
            }          
        /* Essa condição serve para irmos empurrando o quadrado para cima, para ele não ser "comido" pela barra da direita*/       
            if(quadrado_principal->largura >=6 && quadrado_asteristico->posX_Atual >= quadrado_principal->area.right)
            {
                quadrado_asteristico->posX_Atual++;
            }
            if(quadrado_principal->lados.largura >=5 && quadrado_asteristico->posX_Atual == quadrado_principal->area.right  )
            {
                if(quadrado_asteristico->posX_Atual == quadrado_principal->area.left)
                {
                    quadrado_asteristico->posX_Atual++;
                }
                else
                {
                    quadrado_asteristico->posX_Atual--;
                }
                     
            }
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F7 VAI AUMENTAR A AREA DO QUADRADO, ADICIONADO UMA LINHA PARA O LADO SUPERIOR */

        case F7:     
            if(quadrado_principal->lados.altura <= 38)  
            {
            quadrado_principal->lados.ladoSuperior--;
            quadrado_principal->area.top++;
            quadrado_principal->lados.altura++;
            }   

            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F8 VAI DIMUNUIR A AREA DO QUADRADO, DIMINUINDO UMA LINHA PARA O LADO SUPERIOR */
        case F8:            
            if(quadrado_principal->lados.altura >= 6)  
            {
                quadrado_principal->lados.ladoSuperior++;            
                quadrado_principal->area.bottom--;            
                quadrado_principal->lados.altura--;           
            }     
        /* Essa condição serve para irmos empurrando o quadrado para baixo, para ele não ser "comido" pela barra superior*/
            if(quadrado_principal->lados.altura >=6 && quadrado_asteristico->posY_Atual >= quadrado_principal->area.top  )
            {
                if(quadrado_asteristico->posY_Atual >= quadrado_principal->area.bottom)
                {
                    quadrado_asteristico->posY_Atual++;
                }
                else
                {
                    quadrado_asteristico->posY_Atual--;
                }
                     
            }
            
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F9 VAI AUMENTAR A AREA DO QUADRADO, ADICIONANDO UMA LINHA PARA O LADO INFERIOR */
        case F9:
            if(quadrado_principal->lados.altura <= 38)   
            {
            quadrado_principal->lados.ladoInferior++;
            quadrado_principal->area.bottom++;
            quadrado_principal->lados.altura++;           
            
            }
                                 
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F10 VAI DIMINUIR A AREA DO QUADRADO, DIMINUINDO UMA LINHA PARA O LADO INFERIOR */
        case F10:      
            if(quadrado_principal->lados.altura >= 5)     
            {
            quadrado_principal->lados.ladoInferior--;
            quadrado_principal->area.bottom--;
            quadrado_principal->lados.altura--;                             
            }     
        /* Essa condição serve para irmos empurrando o quadrado para cima, para ele não ser "comido" pela barra inferior*/
              
            if(quadrado_principal->lados.altura >=5 && quadrado_asteristico->posY_Atual >= quadrado_principal->area.bottom  )
            {
                if(quadrado_asteristico->posY_Atual >= quadrado_principal->area.top)
                {
                    quadrado_asteristico->posY_Atual--;
                }
                else
                {
                    quadrado_asteristico->posY_Atual++;
                }
                     
            }
            AjustarPosicaoQuadrado(quadrado_asteristico);
            Quadrados(quadrado_principal,tela->dimensao);
        break;

        case ESC:
            _setcursortype(_NORMALCURSOR);  
            textcolor(WHITE);
            exit(0);
        break;

    }



    
}


