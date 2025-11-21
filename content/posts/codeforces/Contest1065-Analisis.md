---
date: '2025-11-20'
draft: false
title: 'Codeforces- Contest1065 Analisis'
---

![Pinguino](/images/pinguino_pensando.webp)

# Introduccion
Participar en este contest fue todo un reto y no lo digo por los problemas jajaja, lamentablemente llegue un poco mas de 15 minutos despues de iniciar (9:05AM aprox) *mal mal*. La razon principal a esto es porque tuve que caminar un largo tramo para llegar a la escuela, cosa que no tenia previsto pero bueno, no habia nada que hacer, solo caminar rapido para tratar de llegar a tiempo.
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
- Simplificando: sol = $\frac{n+2}{4}$. Porque?. Primero, indendientemente de que *n* sea o no divisible entre 4, al sumarle 2 a *n* hacemos que al hacer la division, esta incluya las patas de la vacas y la de los pollos, sin depender de que 4 divida exactamente a *n*. De forma simple, hacemos un *empujon* a *n* de tal forma que se alcance el proximo de divisor de 4. Por ejemplo, si *n=10 (n+2=12)* la cantidad minima seria 2 vacas y 1 pollo. Si n = 12
  
  
Dicho problema es *casi* el mismo planteamiento, con la diferencia de que en el actual problema nos pide la cantidad de *diferentes* configuraciones posibles.
