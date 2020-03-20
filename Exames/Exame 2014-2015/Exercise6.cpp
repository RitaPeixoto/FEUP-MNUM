#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;
/*
TEORICA:
1-- O m�todo de levenberg-Marquardt, porque � o mais vantajoso para fun��es que como esta t�m depressoes alongadas.
2--
3--


O m�todo n�merico mais adequado � o de Levenberg-Marquardt.
Este m�todo � uma combina��o do m�todo do gradiente com o m�todo da qu�drica.
Assim, colmata os problemas de um dos m�todos com as vantagens do outro,
aliando o melhor desempenho do m�todo da qu�drica na vizinhan�a, extendendo a
sua aplicabilidade para l� da vizinhan�a deste. Tamb�m � um m�todo que lida
bem com depress�es alongadas, j� que a qu�drica permite detetar esse
alongamento. Esse caso verifica-se nesta fun��o.
???Outra situa��o complicada que surge no caso apresentado � o da proximidade
entre m�nimos. O m�todo ir� convergir para um deles, no entanto este pode n�o
ser o menor ou ter caracter�sticas que n�o se aplicam ao contexto mais alargado
do problema. Para combater isso seria necess�rio definir constri��es a aplicar
ao m�todo de modo a "for�ar" a converg�ncia para o m�nimo pretendido.???
{don't quote me on this}


*/