#include "arquivo_header_v1.h"
#include "console_v1.5.4.h"
#include "conio_v3.2.4.h"
#include "graphics_v1.1.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>


void Start()
{
    TELA *tela,telaAux;
   
    
   
    /*
    
    === CRIAÇÕES DAS VÁRIAVEIS PRINCIPAIS QUE USAREMOS EM TODO O PROGRAMA ===
    
    */
    QUADRADO *quadrado, aux1,*quadrado_asteristico,aux2;

    
    tela = &telaAux;    
    quadrado = &aux1;
    quadrado_asteristico = &aux2;
    
    setTituloConsole("Quadrado Animado");     
    quadrado_asteristico = quadrado_asteristico;
    tela->dimensao = MaxDimensaoJanela();         
    setDimensaoJanela(tela->dimensao.X ,tela->dimensao.Y);   
    quadrado->area.top = 4;    
    quadrado->area.bottom = 36;
    quadrado->area.right = 98;
    quadrado->area.left = 2;
    quadrado->cor = BLUE;
    quadrado->lados.ladoDireito = 0;
    quadrado->lados.ladoEsquerdo = 0;
    quadrado->lados.ladoInferior = 0;
    quadrado->lados.ladoSuperior = 0;
    



    /*

    altura = 1 a menos
    largura = 2 a menos

    */
    AtribuirTamanhoQuadrados(quadrado,38,102);
    Quadrados(quadrado,tela->dimensao); 
   
    
    
    
    tela->dimensao = tamanhoJanelaConsole();  
    _setcursortype(_NOCURSOR);     
    
   
    quadrado_asteristico->posX_Atual = tela->dimensao.X/3 - 3;
    quadrado_asteristico->posY_Atual = tela->dimensao.Y/2 - 3;
    quadrado_asteristico->VELOCIDADE = 1000;
    ComandoDirecao(quadrado_asteristico,quadrado,tela);    
    
    
}


void ComandoDirecao(QUADRADO *quadrado_asteristico,QUADRADO *quadrado_principal,TELA *tela)
{
    int i=0,j=0;
    
    i = j;
    j = i;
    /* semente para a função rand() */
    srand(time(NULL));

    /* gerar um número aleatório entre 0 e 3 */ 
    quadrado_asteristico->direcao = rand() % 4;
    textcolor(LIGHTGRAY);
    /* adicionar 1 ao número para obter um número aleatório entre 1 e 4*/
    quadrado_asteristico->direcao++;
    
    
    
    
    
    SwitchDirecao(quadrado_asteristico,quadrado_principal,tela);
    

    

    
   
    


}

void SwitchDirecao(QUADRADO *quadrado_asteristico, QUADRADO *quadrado_principal, TELA *tela)
{   
    
    EVENTO evento;
    /*
    printf("\nDIREITA: %d\nESQUERDA: %d\nBAIXO: %d\nTOPO: %d",quadrado_principal->area.right,quadrado_principal->area.left,quadrado_principal->area.bottom,quadrado_principal->area.top);
    printf("\n%d",quadrado_asteristico->VELOCIDADE);
    */
    timeBeginPeriod( 1 );
    switch(quadrado_asteristico->direcao)
    {
        case 1:
        /* INDO PARA BAIXO */
            
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
                    Sleep(quadrado_asteristico->VELOCIDADE);
                    AjustarPosicaoQuadrado(quadrado_asteristico);
                    quadrado_asteristico->posY_Atual+=1;
                    
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
                Sleep(quadrado_asteristico->VELOCIDADE); 
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
                Sleep(quadrado_asteristico->VELOCIDADE);
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
                Sleep(quadrado_asteristico->VELOCIDADE); 
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




void Quadrados(QUADRADO *quadrado,COORD tela)
{


   
    int janelaA_x;
    int janelaA_y;
    int janelaB_x;
    int janelaB_y;

   

    janelaA_x = (tela.X/2) - (quadrado->largura / 2);
    janelaA_y = (tela.Y/2) - (quadrado->altura / 2);
                        
    
    janelaB_x = ((tela.X/2) - (quadrado->largura / 2)) ;
    janelaB_y = ( (tela.Y/2) - (quadrado->altura / 2)) ;
   
    
    clrscr();
    
    textbackground(quadrado->cor);
   
    /* ESSE SERÁ O QUADRADO GRANDE*/
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

void Atualiza_Centro(TELA *tela)
{
   
    tela->dimensao = tamanhoJanelaConsole();       
    
   

    clrscr();

}

void AtribuirTamanhoQuadrados(QUADRADO *quadrado,int altura1,int largura1)
{
    quadrado->altura = altura1;
    quadrado->largura = largura1;    
}


void AjustarPosicaoQuadrado(QUADRADO *quadrado)
{
    int x,y;
    x = quadrado->posX_Atual;
    y = quadrado->posY_Atual;
    
    clrscr();

    gotoxy((x ),(y-2));
    
    printf("***");  
                                        
    gotoxy((x ),(y-1));
    
    printf("***");  
                                             
    gotoxy((x ),(y));
    
    printf("***");
  
    
    

}
void AjustarCorQuadrado(QUADRADO *quadrado)
{
    srand(time(NULL));
    
    quadrado->cor = rand() % 14;
    quadrado->cor++;
    switch (quadrado->cor) 
    { 
    case BLACK:        
        quadrado->cor = quadrado->cor;
        break;
    case BLUE:
        quadrado->cor = BLUE;
        break;
    case GREEN:
        quadrado->cor = GREEN;      
        break;
    case CYAN:
        quadrado->cor = CYAN;    
        break;
    case RED:
        quadrado->cor = RED;        
        break;
    case MAGENTA:
        quadrado->cor = MAGENTA;
        break;
    case BROWN:
        quadrado->cor = BROWN;
        break;
    case LIGHTGRAY:
        quadrado->cor = LIGHTGRAY;
        break;
    case DARKGRAY:
        quadrado->cor = DARKGRAY;
        break;
    case LIGHTBLUE:
        quadrado->cor = LIGHTBLUE;
        break;
    case LIGHTGREEN:
        quadrado->cor = LIGHTGREEN;
        break;
    case LIGHTCYAN:
        quadrado->cor = LIGHTCYAN;
        break;
    case LIGHTRED:
        quadrado->cor = LIGHTRED;
        break;
    case LIGHTMAGENTA:
        quadrado->cor = LIGHTMAGENTA;
        break;
    case YELLOW:
        quadrado->cor = YELLOW;
        break;
    case WHITE:
        quadrado->cor = WHITE;
        break;
    }

    

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
                 
            quadrado_principal->lados.ladoEsquerdo--;      
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F4 VAI DIMINUIR A AREA DO QUADRADO, DIMINUINDO UMA COLUNA PARA A ESQUERDA*/
        case F4:
            
            
            quadrado_principal->lados.ladoEsquerdo++;        
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F5 VAI AUMENTAR A AREA DO QUADRADO, ADICIONADO UMA COLUNA PARA A DIREITA*/
        case F5:
           
            
            quadrado_principal->lados.ladoDireito++;
            quadrado_principal->area.right++;
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F6 VAI DIMINUIR A AREA DO QUADRADO, DIMINUINDO UMA COLUNA PARA A DIREITA*/
        case F6:
                  
            quadrado_principal->lados.ladoDireito--;
            quadrado_principal->area.right++;
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F7 VAI AUMENTAR A AREA DO QUADRADO, ADICIONADO UMA LINHA PARA O LADO SUPERIOR */

        case F7:
          
            quadrado_principal->lados.ladoSuperior--;
            quadrado_principal->area.top--;
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F8 VAI DIMUNUIR A AREA DO QUADRADO, DIMINUINDO UMA LINHA PARA O LADO SUPERIOR */
        case F8:
            
            quadrado_principal->lados.ladoSuperior++;            
            quadrado_principal->area.bottom--;
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F9 VAI AUMENTAR A AREA DO QUADRADO, ADICIONANDO UMA LINHA PARA O LADO INFERIOR */
        case F9:

           
            quadrado_principal->lados.ladoInferior--;
            quadrado_principal->area.bottom--;
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;

        /* O BOTÃO F9 VAI AUMENTAR A AREA DO QUADRADO, DIMINUINDO UMA LINHA PARA O LADO INFERIOR */
        case F10:
  
            
            quadrado_principal->lados.ladoInferior++;
            quadrado_principal->area.bottom++;
            Quadrados(quadrado_principal,tela->dimensao);
            AjustarPosicaoQuadrado(quadrado_asteristico);
        break;


    }



    
}

void EscreverTela(QUADRADO *quadradro_asteristico, QUADRADO *quadradro_principal)
{    
    char direcao[10],corQuadradoPrincipal[20],corQuadradoAsteristico[20]; 
    timeBeginPeriod( 1 );   
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
    SwitchCor(quadradro_asteristico->cor,corQuadradoPrincipal);
    SwitchCor(quadradro_principal->cor,corQuadradoAsteristico);    
    gotoxy(35,35);
   
    printf("\nVELOCIDADE: %d Milisegundos\nDirecao:%s ",quadradro_asteristico->VELOCIDADE,direcao);    
    printf("\nCor Quadrado Principal %s\nCor Quadrado Asteristico: %s",corQuadradoPrincipal,corQuadradoAsteristico);
  
    
    
    timeEndPeriod( 1 );
}

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
