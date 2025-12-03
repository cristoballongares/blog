---
date: '2025-11-20'
draft: false
title: 'Codeforces- Contest1065 Analisis'
---

![Pinguino](/images/pinguino_pensando.webp)

# Introduccion
Participar en este contest fue todo un reto y no lo digo el problemset, lamentablemente llegue un poco mas de 15 minutos despues de que iniciara (9:05AM aprox) *mal mal*. La razon principal a esto es porque tuve que caminar un largo tramo para llegar a la escuela, cosa que no tenia previsto pero bueno, no habia nada que hacer, solo caminar rapido para tratar de llegar a tiempo.
Otro detalle es que resolvia mientras estaba en clase jajaja, el estar haciendo apuntes, pensar en las preguntas del maestro, en el problema, etc. Afortunadamente *quiero pensar* que el maestro no se dio cuenta:p.
Lamentablemente solo resolvi 2 problemas (A,B), el ultimo casi a 30 minutos de terminar la competencia 😞.
Bueno, el analisis a los problemas es el siguiente:

## A. Shizuku Hoshikawa and Farm Legs
El problema es el siguiente:

At Farmer John's farm, Shizuku counts *n* legs. It is known that only chickens and cows live on the farm; a chicken has 2 legs, while a cow has 4.

Count how many different configurations of Farmer John's farm are possible. Two configurations are considered different if they contain either a different number of chickens, a different number of cows, or both.

Note that Farmer John's farm may contain zero chickens or zero cows.

**Input**
The first line contains a single integer $t\ (1<=t<=100)$ - the number of test case
The only line of each test case contains a single integer $n\ (1<=n<=100).$

**Output**
For each test case, output a single integer, the number of different configurations of Farmer John's farm that are possible.

### Detalles a destacar.
La palabra *It is known that* en Codeforces esta como un hipervinculo que nos redirige a un problema bastante similar! [A. Legs](https://codeforces.com/contest/1996/problem/A). Para ese problema tenemos que encontrar la cantidad minima de animales que viven en la granja :p, sabiendo que las vacas tienen 4 patas y los pollos 2. Cabe destacar que *n* siempre es par. 
La solucion es: 
*n* es multiplo de 4?
- Si: sol = $\frac{n}{4}$. Todas vacas
- No: sol = $\frac{n-2}{4}$. 
- Simplificando: sol = $\frac{n+2}{4}$. Porque?. Primero, indendientemente de que *n* sea o no divisible entre 4, al sumarle 2 a *n* hacemos que al hacer la division, esta incluya las patas de la vacas y la de los pollos, sin depender de que 4 divida exactamente a *n*. De forma simple, hacemos un *empujon* a *n* con el fin de que si la division tuviera residuo, esta se aproxime a un divisor de 4 y en caso de que no haya residuo, no se redondaria al proximo divisor de 4.
  
  
Dicho problema es *casi* el mismo planteamiento, con la diferencia de que en el actual problema nos pide la cantidad de *diferentes* configuraciones posibles.
### ¿Que significa *configuraciones posibles*?
Dos configuraciones son diferentes si ambas tienen una cantidad diferente de pollos, de vacas o ambas. Tambien es importante destacar que pueden exisitir 0 vacas o 0 pollos
Casos simple:
$$
n = 8, \text{Configuraciones: 3 (2 Vacas, 4 Pollos, 1 Vaca y 2 Pollos)}\\
n = 4, \text{Configuraciones: 2 (1 Vaca, 2 Pollos)}\\
n = 14, \text{Configuraciones: 4 (3 Vacas y 1 Pollo, 7 Pollos, 2 Vacas y 3 Pollos, 1 Vaca y 5 Pollos)}
$$

Lo pueden ver?, hay detalles importantes para resolver el problema y es saber ¿Cuantas vacas caben en n? y otro importante, cada vez que quitamos una vaca, se suman dos pollos! jjsjsjs, pero, solo es suficiente con saber cuantas vacas caben en n y tomar en cuenta el caso de 0 vacas!. Entonces, formalmente la respuesta seria
$$sol=\frac{n}{4}$$

### Observacion

**Peroooo...**, esto solo funciona cuando *n* es par! ¿Porque?, veamos que pasa cuando sumamos la cantidad de patas que puede haber en total:
$$
 4v + 2p = x, \text{Donde v es vacas y p es pollos}\\
 \text{Notese que x siempre sera par debido a la suma de productos pares:)}
$$
Por lo tanto, no podemos tener a *n* como impar ya que esto implicaria que haya *una patita de mas*, UNA SOLA ¿De quien?, no se, un pollito sin patita o una vaca sin 3 patitas, quizas, pero el problema no menciona eso jajaja. Ademas, al inicio de problema se menciona eso y que solo viven vacas y pollos. listo!

### Errores
Envie 2 soluciones, la primera incorrecta, ¿Cual fue mi error?, tenia el *caso base* $Si x=3 : sol = 0$, cosa que es incorrecta jajaja, pero, porque hice eso?. *Mal analisis del problema y por las prisas de resolverlo rapido*, no pense en otros casos y no analice lo suficientemente bien el problema en casos no pares, ademas de que al inicio no habia entendido tan bien el detalle de configuraciones y como dato extra, llegue a la respuesta de $\frac{n}{4}+1$ a pura observacion de los ejemplos jajaja.


## B. Yuu Koito and Minimum Absolute Sum
El problema es el siguiente:
$$
\text{You are given a partially filled array of nonnegative integers} a_1,a_2, \text{where blank elements are denoted with −1 . You would like to fill in the blank elements with nonnegative integers, such that the absolute value of the sum of the elements in its difference array is minimized.}
$$