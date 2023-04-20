#include "console_v1.5.4.h"
#include "conio_v3.2.4.h"


typedef struct{
    int largura;
    int altura;    
    int direcao;
    int posX_Atual;
    int posY_Atual;
    int top,right,left,bottom;
}QUADRADO;

typedef struct{
    COORD dimensao;
    

}TELA;

void Quadrados(  QUADRADO * ,  COORD );
void Atualiza_Centro( TELA * );
void AtribuirTamanhoQuadrados(QUADRADO *,int ,int );
void Start();
void AjustarPosicaoQuadrado(int ,int );
void ComandoDirecao(QUADRADO *, QUADRADO *);
void SwitchDirecao(QUADRADO *, QUADRADO* );
void ImprimirDirecao();
void VerificarEvento(EVENTO );
    
