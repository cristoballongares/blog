---
date: '2026-03-09T18:15:34-06:00'
title: 'Second and Third Week :p'
---

# Introduction

This weeks has been mmmhh, hard?, probably xD, idk, but both week was very fun!
Lo malo is that i have 6 pending problems for make his editorial xD, not problem, i can, its very fun do it!

# Goals of the weeks
 - [ ] Do 30 problems
   - I do 25/30 :c
 - [x] Escribir sobre los 3 problemas mas dificiles de la semana (both weeks)
   - Product and GCD
   - Knight moves grid
   - Serval and Kaitenzushi Buffet
   - Imbalanced Array
   - Reverse Card
   - Subarray Distinct Values

# Product and GCD
This problem is so beautiful!, we have $N$ integers $a_1,a_2,...,a_n$ not less than 1. This values are uknow but $a_1*a_2*...*a_n = P$.
We need find the maximum possible greatest common divisor of $a_1,a_2,...,a_n$
### Constraints
- $1\leq N \leq 10^{12}$
- $1\leq P \leq 10^{12}$
## Analisis
we discart from the solutions everyone that have $O(n)$ in his, because is guarrented TLE 

First, reescribe the expression.
$gcd(a_1,a_2,...,a_n) = g$, then, 

$a_i = g *b_i $, so 

$ gb_1 * gb_2 * ... * gb_n = P$, 

$g^n (b_1*b_2*...*b_n) = P$

Now, if we are a little more explicit, for a number divides a otro o dicho de mejor modo, para que $a \mid b$, es necesario que, los exponentes de los factores primos de $b$ sean menores o iguales a los de $b$, esto por cada primo de forma independiente, formalmente, si:

$$ a = \prod_{}^{} p_i^{f_i} \quad y \quad b = \prod p_i^{e_i} $$ Entonces

$$ a \mid b \iff f_i \leq e_i \ \text{para todo primo }p_i$$

Sabiendo esto, buscaremos todos los $f_i$ de $g$ que sean menores o iguales a $e_i$ de $p$. Sin embargo, no olvidemos que $g$ es $g^n$, por lo tanto para cada exponente de $p$ se debe cumplir para cada exponente de $g$ lo siguiente:

$g^n = p_1^{e_1} * ... * p_n^{e_n}$, despejando a $g$

$g = p_1^{\frac{e_1}{n}} * ... * p_n^{\frac{e_n}{n}}$

Por lo tanto, al encontrar los exponentes de los primos de $g$ lo haremos de la siguiente forma:

$ f_i \leq \lfloor \frac{e_i}{n}  \rfloor $.

### Resumen
Encontramos y guardamos los factores primos de $P$, por cada uno de estos encontramos el $p_i^{f_i}$ mas grande posible, los multiplicamos y esa será la respuesta.

# Knight Moves Grid
Aun no le entiendo :c

# Serval and Kaitenzushi Buffet
Greeeeddy, this problem was very fun!