/*
1. x(n+1) = x(n) + i --> A soma acumulada de n�meros inteiros tem pouca suscetibilidade a erros de
arredeondamento, o que aumenta a fiabilidade dos resultados, contudo,
como s� � poss�vel iterar em intervalos inteiros, a defini��o dos resultados
est� limitada. (defini��o = precis�o)

2. x(n+1) = x(n) + h --> A soma acumulada de n�meros em v�rgula flutuante tem muita propens�o a
erros de arredondamento, devido aos sucessivos arredondamentos da mantissa.
Tem a vantagem de permitir obter resultados mais granulares do que o iterador
1, mas a desvantagem de uma consider�vel perda de precis�o � medida que o
n�mero de itera��es aumenta.

3. x(n+1) = x0 + h*i --> Neste iterador s�o somados, � semelhan�a do iterados 2, n�meros em v�rgula
flutuante, no entanto, esta n�o � uma soma acumulada. O valor a somar ao valor
inicial � atualizado por meio de uma multiplica��o com um inteiro, o que
diminui o erro cometido pela acumula��o de somas. Assim, este iterador
apresenta a vantagem de permitir maior granularidade que 1 e maior precis�o que
2, mas a desvantagem de continuar suscet�vel a alguns erros na soma de VF.
Por exemplo, no caso em que as ordens de grandeza de x0 e h s�o muito d�spares,
o resultado da adi��o poderia simplesmente ser igual ao maior dos dois n�meros.


4. x(n+1)= xn +(1/2) ^m --> Este iterador � t�o suscet�vel a erros como o 2. � efetuada uma soma
acumulada de n�meros em v�rgula flutuante. Como a fra��o exponenciada tem
representa��o absoluta em bin�rio, desta opera��o n�o s�o criados mais erros do
que se a soma fosse acumulando um valor constante. No entanto, como este valor
� decrescente, quando atingir uma ordem de grandeza muito menor do que xn, a
precis�o do resultado da adi��o ser� prejudicada, sendo que no pior caso o
valor do iterador deixa de variar. Tem como vantagem permitir variar o valor do
iterador de uma maneira que pode ser �til, mas a desvantagem de se
realizarem muitas opera��es com v�rgula flutuante e de as ordens de grandeza
dos n�meros se afastarem progressivamente.


*/