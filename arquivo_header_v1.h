#include "console_v1.5.4.h"
#include "conio_v3.2.4.h"
#include "graphics_v1.1.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef struct
{
    int top;
    int right;
    int left;
    int bottom;
}AREA;

typedef struct
{
    int ladoDireito,ladoEsquerdo,ladoSuperior,ladoInferior;
}LadoAcrescentar;

typedef struct
{
    int largura;
    int altura;    
    int direcao;
    int posX_Atual;
    int posY_Atual;
    AREA area;
    LadoAcrescentar lados;
    int VELOCIDADE;
    COLORS cor;
    
}QUADRADO;

typedef struct
{
    COORD dimensao;
    

}TELA;



void Quadrados(  QUADRADO * ,  COORD );
void Atualiza_Centro( TELA * );
void AtribuirTamanhoQuadrados(QUADRADO *,int ,int );
void Start();
void AjustarPosicaoQuadrado(QUADRADO *);
void ComandoDirecao(QUADRADO *, QUADRADO *, TELA *);
void SwitchDirecao(QUADRADO *, QUADRADO* , TELA *);
void AjustarCorQuadrado(QUADRADO *);
void SwitchTeclas(DWORD , QUADRADO *,QUADRADO *, TELA * );
void EscreverTela(QUADRADO*, QUADRADO*);
void SwitchCor(COLORS , char[]);

    
