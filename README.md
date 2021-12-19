# test

Textes will be added

Output for SearchPathProgram osm10.cpp:

Legende: Start, Ziel, Fahrzeugspur, x-Hindernis

|------------------------------|
|  Z    x    F -- F -- F -- F  |
|            |    |    |    |  
|  F    x    F -- F -- F -- F  |
|  |         |    |    |    |  
|  F    x    F -- F -- F -- F  |
|  |         |    |    |    |  
|  F    x    F -- F -- F -- F  |
|  |         |                 
|  F -- F -- F    0    x    S  |
|
|------------------------------|

Legende: Start, Ziel, Fahrzeugspur, x-Hindernis

|------------------------------|
|  Z    x    F -- F -- F -- F  |
|            |              |  
|  F    x    F    x    x    F  |
|  |         |              |  
|  F    x    F -- F    x    F  |
|  |         |              |  
|  F    x    F    x    x    F  |
|  |         |                 
|  F -- F -- F    0    x    S  |
|
|------------------------------|

Legende: Start, Ziel, Fahrzeugspur, x-Hindernis

|------------------------------------------------------------|
|  Z    x    F -- F -- F -- F -- F -- F -- F -- F -- F -- F  |
|            |                                            |  
|  F    x    F    x    x    x    x    x    x    x    x    F  |
|  |         |                                            |  
|  F    x    F -- F    x    F -- F -- F -- F -- F    x    F  |
|  |         |              |         |         |         |  
|  F    x    F    x    x    F    x    F    x    F    x    F  |
|  |         |                        |         |         |  
|  F -- F -- F    0    x    S    x    F -- F -- F -- F -- F  |
|
|------------------------------------------------------------|

Legende: Start, Ziel, Fahrzeugspur, x-Hindernis

|------------------------------------------------------------|
|  Z    x    F -- F -- F -- F -- F -- F -- F -- F -- F -- F  |
|            |                             |              |  
|  F    x    F    x    x    x    x    x    F    x    x    F  |
|  |         |                             |                 
|  F    x    F -- F    x    F -- F -- F -- F -- F    x    0  |
|  |         |              |         |         |            
|  F    x    F    x    x    F    x    F    x    F    x    0  |
|  |         |                        |         |            
|  F -- F -- F    0    x    S    x    F -- F -- F -- F    0  |
|
|------------------------------------------------------------|

