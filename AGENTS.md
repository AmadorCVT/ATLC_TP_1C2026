# AGENTS.md — Contexto general del proyecto ATLC_TP_1C2026

Este archivo contiene contexto estable para que un agente de código pueda entender el proyecto antes de recibir tareas puntuales. No es una lista cerrada de tareas ni una orden de implementación. La idea es que el agente use esta información como marco general y, ante cada pedido concreto, inspeccione el repositorio y proponga cambios compatibles con el estado real del código.

## Proyecto

Este repositorio corresponde al Proyecto Especial de la materia Autómatas, Teoría de Lenguajes y Compiladores, Ingeniería Informática, ITBA.

El proyecto consiste en diseñar e implementar un lenguaje específico de dominio, DSL, junto con su compilador. El lenguaje elegido por el equipo permite describir, inspeccionar y operar con autómatas finitos.

Repositorio declarado por el equipo:

```txt
https://github.com/AmadorCVT/ATLC_TP_1C2026
```


## Contexto académico

El proyecto se desarrolla por etapas.

### Stage I — Diseño

En la primera etapa se definió el dominio, las funcionalidades previstas, ejemplos de sintaxis y casos de prueba iniciales.

### Stage II — Frontend

La etapa actual es el frontend del compilador. En este contexto, “frontend” no significa interfaz gráfica. Significa la parte inicial del compilador: análisis léxico, análisis sintáctico y construcción de una representación estructural del programa de entrada.

El proyecto base esperado por la materia utiliza C, Flex y Bison, tomando como base el repositorio Flex-Bison-Compiler, branch production, tag v2.0.0.

### Stage III — Backend

La etapa posterior incorporará validaciones semánticas completas, ejecución/interpretación/generación según corresponda, conversiones efectivas entre autómatas, minimización, equivalencia y demás comportamiento propio del dominio.

## Dominio del DSL

El DSL está pensado para trabajar con autómatas finitos:

- DFA: deterministic finite automaton
- NFA: nondeterministic finite automaton
- LNFA: lambda-NFA, autómata no determinista con transiciones lambda

El lenguaje busca reducir el trabajo mecánico de operar con autómatas, especialmente conversiones, minimización, pruebas de aceptación e inspección de estructuras.

## Funcionalidades previstas del lenguaje

La especificación inicial del equipo contempla las siguientes capacidades.

### Definición de autómatas

El lenguaje permite definir autómatas de tipo DFA, NFA o LNFA, especificando:

- alfabeto
- conjunto de estados
- estado inicial
- estados de aceptación
- transiciones

Ejemplo conceptual:

```txt
automaton ParidadCeros : DFA {
    alphabet = {0, 1}
    states = {q0, q1}
    start = q0
    accept = {q0}
    transitions {
        q0 -> 0 : q1
        q0 -> 1 : q0
        q1 -> 0 : q0
        q1 -> 1 : q1
    }
};
```

### Transiciones

Las transiciones se expresan con la forma:

```txt
estado_origen -> simbolo : destino
```

También se contemplan destinos múltiples mediante conjuntos:

```txt
q0 -> a : {q0, q1}
```

Las transiciones lambda se escriben usando la palabra reservada:

```txt
lambda
```

Ejemplo:

```txt
q0 -> lambda : {q1}
```

### Autómatas vacíos o incompletos

La especificación contempla poder crear autómatas sin transiciones, para completarlos después.

### Modificación de autómatas

El lenguaje contempla modificar un autómata ya definido mediante un bloque con el nombre del autómata:

```txt
ParidadCeros {
    transitions {
        q0 -> 1 : q1
    }
};
```

También se contempla la posibilidad de agregar nuevos estados y redefinir el conjunto de aceptación, aunque la sintaxis final de estas operaciones puede ajustarse durante el desarrollo.

### Testeo de cadenas

El lenguaje contempla probar si una cadena es aceptada por un autómata:

```txt
test ParidadCeros with "0011";
test ParidadCeros with "";
```

La cadena vacía debe estar representada como string vacío.

### Conversiones

La especificación contempla conversiones entre tipos de autómatas:

```txt
convert TieneAB to DFA as TieneAB_Det;
convert LambdaEjemplo to DFA as LambdaEjemplo_Det;
convert LambdaEjemplo to NFA as LambdaEjemplo_SinLambda;
```

Conversiones previstas:

- NFA a DFA, mediante construcción de subconjuntos
- LNFA a NFA, mediante eliminación de lambda
- LNFA a DFA, de forma directa o por composición de conversiones
- DFA a NFA, conversión trivial

### Visualización e inspección

La especificación contempla comandos de inspección:

```txt
print TieneAB;
show transitions of TieneAB;
show table of TieneAB_Det;
show closure(q0) in LambdaEjemplo;
```

Estos comandos están pensados para imprimir definiciones, mostrar transiciones, mostrar tablas de transición y calcular clausuras lambda.

### Tipos de datos previstos

La primera entrega menciona los siguientes tipos posibles:

- Automata
- String
- Bool
- State
- Symbol

### Estructuras de control previstas

La primera entrega menciona estructuras de control:

- if-then-else
- for
- while

También menciona operaciones lógicas y relacionales:

- AND
- OR
- NOT
- <
- >
- =
- ≠
- ≤
- ≥

Estas construcciones pertenecen al alcance conceptual del lenguaje, pero su sintaxis definitiva puede cambiar. Antes de implementarlas, revisar el estado actual del repo y la gramática vigente.

### Prestaciones opcionales

La primera entrega menciona como opcionales:

- minimización de DFA mediante algoritmo de Hopcroft
- equivalencia entre autómatas con una construcción del estilo `equivalent <A1> <A2>`

## Sintaxis de referencia existente

La primera entrega incluye ejemplos de referencia. Estos ejemplos no necesariamente son la gramática final, pero son el mejor punto de partida hasta que exista una gramática formal cerrada.

### DFA: paridad de ceros

```txt
automaton ParidadCeros : DFA {
    alphabet = {0, 1}
    states = {q0, q1}
    start = q0
    accept = {q0}
    transitions {
        q0 -> 0 : q1
        q0 -> 1 : q0
        q1 -> 0 : q0
        q1 -> 1 : q1
    }
};
```

### Modificación de autómata

```txt
ParidadCeros {
    transitions {
        q0 -> 1 : q1
    }
};
```

### Testeo

```txt
test ParidadCeros with "0011";
test ParidadCeros with "010";
test ParidadCeros with "";
```

### LNFA con lambda

```txt
automaton LambdaEjemplo : LNFA {
    alphabet = {a, b}
    states = {q0, q1, q2}
    start = q0
    accept = {q2}
    transitions {
        q0 -> lambda : {q1}
        q1 -> a : {q1}
        q1 -> b : {q2}
    }
};
```

### NFA con destino múltiple

```txt
automaton TieneAB : NFA {
    alphabet = {a, b}
    states = {q0, q1, q2}
    start = q0
    accept = {q2}
    transitions {
        q0 -> a : {q0, q1}
        q0 -> b : {q0}
        q1 -> b : {q2}
        q2 -> a : {q2}
        q2 -> b : {q2}
    }
};
```

### Conversiones

```txt
convert TieneAB to DFA as TieneAB_Det;
convert LambdaEjemplo to DFA as LambdaEjemplo_Det;
convert LambdaEjemplo to NFA as LambdaEjemplo_SinLambda;
```

### Inspección

```txt
print TieneAB;
show transitions of TieneAB;
show table of TieneAB_Det;
show closure(q0) in LambdaEjemplo;
```

## Conceptos de compiladores relevantes para este proyecto

### Lexer

El lexer transforma el texto de entrada en tokens. En este proyecto, el lexer debería reconocer palabras reservadas, identificadores, cadenas, símbolos de puntuación, operadores y construcciones propias del DSL.

Palabras y símbolos importantes del lenguaje:

```txt
automaton
DFA
NFA
LNFA
alphabet
states
start
accept
transitions
lambda
test
with
convert
to
as
print
show
table
closure
of
in
{
}
(
)
:
;
,
=
->
```

También pueden aparecer construcciones futuras como:

```txt
if
then
else
for
while
AND
OR
NOT
equivalent
minimize
```

No asumir que todos estos tokens ya deben estar implementados. Revisar la gramática y el estado real del repo antes de tocar código.

### Parser

El parser reconoce la estructura del programa a partir del stream de tokens. En este proyecto, la estructura general del programa debería ser una secuencia de sentencias relacionadas con autómatas.

Construcciones sintácticas esperables:

- definición de autómata
- modificación de autómata
- transición
- conjunto de estados o símbolos
- test de cadena
- conversión entre tipos
- impresión o inspección
- estructuras de control, si ya fueron incorporadas al alcance real

### AST

El AST representa la estructura del programa de forma interna. En este proyecto, un AST razonable debería poder representar:

- programa completo
- lista de sentencias
- definición de autómata
- tipo de autómata
- alfabeto
- estados
- estado inicial
- estados de aceptación
- bloque de transiciones
- transición individual
- destino simple o múltiple
- test de cadena
- conversión
- comandos de inspección
- modificaciones de autómata

No asumir nombres concretos de structs o archivos. Antes de implementar o modificar AST, inspeccionar el repo para respetar las convenciones existentes.

## Casos de prueba de referencia

La primera entrega propone casos de aceptación como:

- crear un DFA y testear múltiples cadenas
- crear un NFA, convertirlo a DFA y testear equivalencia de resultados
- crear un LNFA, calcular clausuras y convertirlo a NFA
- modificar un autómata existente y volver a testear cadenas
- mostrar tabla de transición de un DFA construido por conversión
- verificar cadena vacía
- convertir LNFA directamente a DFA
- usar estructuras de control para testear una lista de cadenas
- imprimir y mostrar transiciones antes y después de editar
- definir tres autómatas de distintos tipos y convertirlos entre sí

La primera entrega también propone casos de rechazo como:

- DFA sin estado inicial
- transición con símbolo fuera del alfabeto
- DFA con transición no determinista
- LNFA con transición lambda tipeado como DFA
- conversión a tipo inválido

Algunos de estos rechazos pueden ser sintácticos y otros semánticos. Antes de implementarlos, diferenciar si corresponden al frontend o al backend según el alcance actual.

## Diferencia importante entre sintaxis y semántica

En Stage II puede ser válido construir un AST para programas que luego serán rechazados semánticamente en Stage III.

Ejemplos de posibles errores semánticos:

- un símbolo de transición no pertenece al alfabeto declarado
- un estado usado en una transición no pertenece al conjunto de estados
- un DFA tiene transición con múltiples destinos
- un DFA usa `lambda`
- se convierte entre tipos no permitidos por las reglas del dominio
- se usa un autómata no declarado
- se redefine un autómata de forma inválida

No rechazar automáticamente estos casos desde el parser salvo que el diseño actual del proyecto ya haya decidido que se validan en esta etapa.

## Reglas de trabajo para agentes de código

Cuando se reciba una tarea puntual, el agente debe:

1. Inspeccionar primero la estructura real del repositorio.
2. Identificar archivos de Flex, Bison, AST, acciones semánticas, listas, errores y tests.
3. Respetar el estilo, naming y arquitectura ya existentes.
4. Evitar reescrituras grandes si el cambio puede integrarse de manera localizada.
5. Mantener compatibilidad con C, Flex y Bison.
6. Cuidar memoria dinámica: ownership, creación y destrucción de nodos, strings y listas.
7. No introducir librerías externas sin necesidad ni autorización explícita.
8. No inventar sintaxis nueva si existe una sintaxis definida en los documentos o en la gramática del repo.
9. Si falta información, inferir con cuidado a partir de la especificación y dejar claro el supuesto en el cambio o comentario asociado.
10. Priorizar que el proyecto compile y que los tests existentes sigan corriendo.

## Lo que este archivo no define

Este archivo no define la gramática formal definitiva.

Cuando exista una gramática formal con:

```txt
G = <Σ, N, P, S>
```

conviene actualizar este archivo para que el agente trabaje contra esa definición y no solo contra ejemplos de referencia.

Tampoco define decisiones finales sobre:

- nombres exactos de tokens
- nombres exactos de nodos AST
- si ciertas validaciones son sintácticas o semánticas
- formato final de salida
- extensión de archivos fuente del DSL
- comandos finales de build/test

Todas esas decisiones deben verificarse contra el estado real del repositorio.

## Prioridad conceptual del proyecto

El proyecto no busca un lenguaje general tipo Python o JavaScript. El centro del lenguaje son los autómatas finitos.

Cualquier implementación, refactor o test debería mantener el foco en:

- definición de autómatas
- transiciones
- testeo de cadenas
- conversiones
- inspección
- validación progresiva del dominio

Si una tarea parece alejarse de ese objetivo, conviene revisar si realmente pertenece al alcance del TP.
