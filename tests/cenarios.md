# Cenários


- Cenário 1: Expressão Padrão (Misturada)

| Entrada| Saída esperada |
| 90 * 100 / 18.0 - 48 + 77 | '<token: 1, atrib: 90>' |
| | '<token: 4>' | 
| | <token: 1, atrib: 100> |
| | <token: 5> |
| | <token: 1, atrib: 18.0> |
| | <token: 3> |
| | <token: 1, atrib: 48> |
| | <token: 2> |
| | <token: 1, atrib: 77> | 


- Cenário 2: Números Decimais e Espaçamento Denso

| Entrada                   | Saída esperada |
| 0.5+12.99*3               | <token: 1, atrib: 0.5> |
|                           | <token: 2> | 
|                           | <token: 1, atrib: 12.99> |
|                           | <token: 4> |
|                           | <token: 1, atrib: 3> |

- Cenário 3: Reporta Erro Léxico

| Entrada                   | Saída esperada |
| 45 $ 2                    | <token: 1, atrib: 45> |
|                           | lexical error, char $ | 
|                           | <token: 1, atrib: 2> |

- Cenário 4: Entrada com constante real malformada

| Entrada                   | Saída esperada |
| 90 * 100 / .0 - 777       | <token: 1, atrib: 90>  |
|                           | <token: 4> |
|                           | <token: 1, atrib: 100> |
|                           | <token: 5> |
|                           | lexical error, char .  |
|                           | <token: 1, atrib: 0>   | 
|                           | <token: 3>             |
|                           | <token: 1, atrib: 777> |

