#include <stdlib.h> 		
#include <time.h>
#include "conio_v3.2.4.h"   
#include "console_v1.5.4.h"
#include "graphics_v1.1.h"  
#include "arquivo_header_v1.h"
#include <Windows.h>



void Start()
{
    TELA *telaInicial,telaAux,*telaAtual,telaAux2;
    
   
    /*
    
    === CRIAÇÕES DAS VÁRIAVEIS PRINCIPAIS QUE USAREMOS EM TODO O PROGRAMA ===
    
    */
    QUADRADO *quadrado_principal, aux1,*quadrado_asteristico,aux2;

    
    telaInicial = &telaAux;
    telaAtual = &telaAux2;
    quadrado_principal = &aux1;
    quadrado_asteristico = &aux2;
    setTituloConsole("Quadrado Animado");     
    quadrado_asteristico = quadrado_asteristico;
    telaInicial->dimensao = MaxDimensaoJanela();         
    setDimensaoJanela(telaInicial->dimensao.X ,telaInicial->dimensao.Y);
    quadrado_principal->top  = 3;
    quadrado_principal->bottom = 37;


    /*

    altura = 1 a menos
    largura = 2 a menos

    */
    AtribuirTamanhoQuadrados(quadrado_principal,38,102);
    Quadrados(quadrado_principal,telaInicial->dimensao); 
   
    
    
    
    telaAtual->dimensao = tamanhoJanelaConsole();       
    
   
    quadrado_asteristico->posX_Atual = telaInicial->dimensao.X/4 - 9;
    quadrado_asteristico->posY_Atual = telaAtual->dimensao.Y/3 - 3;
    ComandoDirecao(quadrado_asteristico,quadrado_principal);
    /*
    gotoxy((telaInicial->dimensao.X   ),(telaAtual->dimensao.Y/2)-1);
    printf("***");
    gotoxy((telaInicial->dimensao.X  ),(telaAtual->dimensao.Y/2));
    printf("***");
    gotoxy((telaInicial->dimensao.X),(telaAtual->dimensao.Y/2)+1);
    printf("***");
    printf("%d\n",telaInicial->dimensao.Y);
   
    
  

    quadrado_asteristico->posX_Atual = telaAtual->dimensao.X;
    printf("\n%d\n",quadrado_asteristico->posX_Atual);   
    quadrado_asteristico->posY_Atual = telaAtual->dimensao.Y;
    printf("\n%d\n",quadrado_asteristico->posY_Atual);  
    quadrado_asteristico->posX = 0;
    quadrado_asteristico->posY = 0;
    EscolherDirecao(quadrado_asteristico);
     
  */ 
    
    
    
}


void ComandoDirecao(QUADRADO *quadrado_asteristico,QUADRADO *quadrado_principal)
{
    int i=0,j=0;
    
    i = j;
    j = i;
    /* semente para a função rand() */
    srand(time(NULL));

    /* gerar um número aleatório entre 0 e 3 */ 
    quadrado_asteristico->direcao = rand() % 4;
    /* adicionar 1 ao número para obter um número aleatório entre 1 e 4*/
    quadrado_asteristico->direcao=1;
    
    
    
    
    SwitchDirecao(quadrado_asteristico,quadrado_principal);


    

    
   
    


}

void SwitchDirecao(QUADRADO *quadrado_asteristico, QUADRADO *quadrado_principal)
{   
    
    EVENTO evento;
    printf("\n%d",quadrado_principal->bottom);
    switch(quadrado_asteristico->direcao)
    {
        case 1:
        /* INDO PARA BAIXO */
            
            do
            {             
                Sleep(50); 
                   
               
                
                if( hit(KEYBOARD_HIT) )
                {
                        evento = Evento();
                        if(evento.teclado.status_tecla == LIBERADA)
                        {  
                            if(evento.teclado.codigo_tecla == SETA_PARA_CIMA)
                            {
                                quadrado_asteristico->direcao = 2;                                  
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_DIREITA)
                            {                                                                
                                quadrado_asteristico->direcao = 3;                                 
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_ESQUERDA)
                            {
                                quadrado_asteristico->direcao = 4;                                 
                            }
                                        
                            SwitchDirecao(quadrado_asteristico,quadrado_asteristico);                
                        }
                }           
               else
               {
                    AjustarPosicaoQuadrado(quadrado_asteristico->posX_Atual,quadrado_asteristico->posY_Atual);
                    quadrado_asteristico->posY_Atual++;
                    
               }
                
            }while(quadrado_asteristico->posY_Atual != quadrado_principal->bottom);            
            quadrado_asteristico->direcao = 2;
            SwitchDirecao(quadrado_asteristico,quadrado_principal);
       
        break;
        case 2:
        
        /* INDO PARA CIMA */
            
            do
            { 
                Sleep(50);
                

                if( hit(KEYBOARD_HIT) )
                {
                        evento = Evento();
                        if(evento.teclado.status_tecla == LIBERADA)
                        {  
                            if(evento.teclado.codigo_tecla == SETA_PARA_BAIXO)
                            {
                                quadrado_asteristico->direcao = 1;                                  
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_DIREITA)
                            {                                                                
                                quadrado_asteristico->direcao = 3;                                 
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_ESQUERDA)
                            {
                                quadrado_asteristico->direcao = 4;                                 
                            }                  
                            SwitchDirecao(quadrado_asteristico,quadrado_asteristico);                
                        }
                } 
                else
                {
                AjustarPosicaoQuadrado(quadrado_asteristico->posX_Atual,quadrado_asteristico->posY_Atual);
                quadrado_asteristico->posY_Atual--;                
                }

            }while(quadrado_asteristico->posY_Atual != quadrado_principal->top);
            quadrado_asteristico->direcao = 1;
            SwitchDirecao(quadrado_asteristico,quadrado_principal);
             
        
        break;

        case 3:
        /* PARA DIREITA */
            do
            {
                Sleep(100);
                if( hit(KEYBOARD_HIT) )
                {
                        evento = Evento();
                        if(evento.teclado.status_tecla == LIBERADA)
                        {  
                            if(evento.teclado.codigo_tecla == SETA_PARA_BAIXO)
                            {
                                quadrado_asteristico->direcao = 1;                                  
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_CIMA)
                            {                                                                
                                quadrado_asteristico->direcao = 2;                                 
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_ESQUERDA)
                            {
                                quadrado_asteristico->direcao = 4;                                 
                            }                  
                            SwitchDirecao(quadrado_asteristico,quadrado_asteristico);                
                        }
                } 
                else
                {
                AjustarPosicaoQuadrado(quadrado_asteristico->posX_Atual,quadrado_asteristico->posY_Atual);
                quadrado_asteristico->posX_Atual++;
                }
 
                
            }
            while(quadrado_asteristico->posX_Atual != 99);
            quadrado_asteristico->direcao = 4;
            SwitchDirecao(quadrado_asteristico,quadrado_principal);
        
        break;

        case 4:
       /* PARA ESQUERDA */
            do
            {
                
                
                Sleep(100);
                if( hit(KEYBOARD_HIT) )
                {
                        evento = Evento();
                        if(evento.teclado.status_tecla == LIBERADA)
                        {  
                            if(evento.teclado.codigo_tecla == SETA_PARA_BAIXO)
                            {
                                quadrado_asteristico->direcao = 1;                                  
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_CIMA)
                            {                                                                
                                quadrado_asteristico->direcao = 2;                                 
                            }
                            if(evento.teclado.codigo_tecla == SETA_PARA_DIREITA)
                            {
                                quadrado_asteristico->direcao = 3;                          
                            }                  
                            SwitchDirecao(quadrado_asteristico,quadrado_asteristico);                
                        }
                } 
                else
                {
                AjustarPosicaoQuadrado(quadrado_asteristico->posX_Atual,quadrado_asteristico->posY_Atual);
                quadrado_asteristico->posX_Atual--;  
                }

                
            }
            while(quadrado_asteristico->posX_Atual != 1);
            quadrado_asteristico->direcao = 3;
            SwitchDirecao(quadrado_asteristico,quadrado_principal);
        
        break;
    }
    SwitchDirecao(quadrado_asteristico,quadrado_principal);
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
    textbackground(BLUE);
    window(janelaA_x, janelaA_y, (janelaA_x + quadrado->largura), (janelaA_y + quadrado->altura));
  
   
   
   
    
    
    clrscr();
  
    textbackground(BLACK);
    

    
    window(janelaB_x +1, (janelaB_y +1), (janelaB_x + quadrado->largura)-1 ,( janelaB_y + quadrado->altura)-1);
   

   
   
  
    
   
    
  
    
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


void AjustarPosicaoQuadrado(int x,int y)
{
   
    clrscr();
    gotoxy((x ),(y-2));
    printf("***");                                      
    gotoxy((x ),(y-1));
    printf("***");                                            
    gotoxy((x ),(y));
    printf("***");
    

}


void ImprimirDirecao(){
    
    
}
