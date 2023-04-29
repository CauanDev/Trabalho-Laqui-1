#include <stdlib.h> 		
#include <time.h>


#include "conio_v3.2.4.h"   
#include "console_v1.5.4.h"
#include "graphics_v1.1.h"  
#include "arquivo_header_v1.h"


/*
gcc arquivo.c conio_v3.2.4.c console_v1.5.4.c  arquivo_codigos.c -o arquivo.exe -Wall -Werror -Wextra -pedantic -lgdi32 -lwinmm
*/


int main(int argc, char *argv[])
{
/*    
    === CRIAÇÕES DAS VÁRIAVEIS PRINCIPAIS QUE USAREMOS EM TODO O PROGRAMA ===
    Criamos 3 ponteiros e 3 endereços, para aonde os ponteiros irão apontar.
*/
    TELA *tela,telaAux;
    QUADRADO *quadrado, aux1,*quadrado_asteristico,aux2;    
    tela = &telaAux;    
    quadrado = &aux1;
    quadrado_asteristico = &aux2; 
    /* Artifício para silenciar warning */
    argc = argc;
	argv = argv;
    /* Artifício para silenciar warning */


/* 
    Definimos aqui qual será o titulo do nosso console utilizando a função setTituloConsole.
*/
    setTituloConsole("Quadrado Animado");   

/* 
    Iremos pegar o tamanho maximo permitido da janela e armazenar na estrutura tela utilizando a função MaxDimensaoJanela, que ira retornar 
    uma estrutura tipo COORD, que irá ter duas variaveis, X e Y, aonde X é o tamanho máximo da largura e Y a altura.
*/
    tela->dimensao = MaxDimensaoJanela();  

/*
    Passaremos os valores inicias que as variaveis irão ter no começo do programa
*/

/*
    Definimos aqui as variaveis da estrutura AREA.
    Elas serão utilizadas como referencia para aonde o quadrado asteristico não pode encostar, serão as bordas do quadrado principal, inicialmente elas são inicializadas
    com esses valores pois:
    top: a area irá ficar apenas com 4 de distancia da janela console.
    bottom: o quadrado principal tem 40 de largura, esses dois pixeis que faltam são para que quando o quadrado asteristico chegue perto, ele já seja redirecionado para outro lado.
    left: o valor é 2 pois, o primeiro pixel é o ponto 1, 2 fará com que o quadrado assim que chegue no 2, já seja rediriconado para o proximo lado
    right: o quadrado tem o tamanho de 100, será o ponto aonde quando o quadrado chegar ele seja redirecionado para o proximo ponto
*/
    quadrado->area.top = 4;    
    quadrado->area.bottom = 38;
    quadrado->area.right = 98;
    quadrado->area.left = 2;
/*
    Essas são as cores inicias dos quadrados
*/
    quadrado->cor = BLUE;
    quadrado_asteristico->cor = WHITE;
/*
    As variaveis: lados.ladoEsquerdo,lados.ladoDireito,ladoInferior e ladoSuperior servem para o seguinte proposito:
    Quando for solicitado pelo usuario o aumento ou a dimunuiçao da tela, vai ser sempre para um lado apenas que terá que aumentar, para isso, será utilizado
    essas quatros variaveis, para que quando for criar o quadrado novamente seja somado a essas variaveis, são auxiliares, no inicio elas são criadas com valor 0
    e são incrementadas somente quando o usuario solicitar o aumento do quadrado.
*/
    quadrado->lados.ladoDireito = 0;
    quadrado->lados.ladoEsquerdo = 0;
    quadrado->lados.ladoInferior = 0;
    quadrado->lados.ladoSuperior = 0;

/*
    Tamanho do quadrado para iniciar, ele terá que começar com 40 de altura e 100 de largura, porém, como a borda usa 2 pixel de cada lado, então a gente diminui para 
    que o quadrado de dentro fique com o tamanho exato
*/

    quadrado->altura =42 ;
    quadrado->largura = 102;    
    quadrado->lados.altura = 42;
    quadrado->lados.largura = 102;
    quadrado_asteristico->posX_Atual = tela->dimensao.X/3 - 3;
    quadrado_asteristico->posY_Atual = tela->dimensao.Y/2 - 3;
    quadrado_asteristico->VELOCIDADE = 50;   



/*
    Iremos Uitlizar as variaveis que armazenamos em tela->Dimensão e passaremos eles como referencia para definir o novo tamanho da janela.
    Dessa forma a janela irá ter o tamanho máximo possível
*/
    setDimensaoJanela(tela->dimensao.X ,tela->dimensao.Y);  

/*
    Após definirmos o tamanho e a posição inicial do quadrado, iremos fazer ele ser impresso pela primeira vez.
*/
    Quadrados(quadrado,tela->dimensao); 
   
/*
   Nessa função iremos fazer com que o cursos não fique aparecendo, para a experiencia do usuario seja melhor.
*/
    _setcursortype(_NOCURSOR);     
    
/*
   Após colocarmos o primeiro quadrado, iremos chamar a função principal do programa, será nela que todo o programa irá funcionar.
*/
SorteioDirecao(quadrado_asteristico);    

/*
    Após deixarmos todas as variaveis prontas para o começo, chamamos a função principal do código, que irá comandar todos os passos adiante.
*/
SwitchDirecao(quadrado_asteristico,quadrado,tela);
 
    return 0;
}
