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

## Guía operativa para Stage III — Backend

Esta sección fue agregada después de analizar los documentos:

- `(2026-03-12) Proyecto Especial (2).pdf`
- `(2024-05-16, v0.1.0) Generación de Código.pdf`
- `(2024-05-16, v0.1.0) Runtime.pdf`
- `(2024-09-25, v0.2.0) Análisis Semántico.pdf`
- `doc/specification.pdf`

El objetivo de Stage III es completar el compilador funcional. No alcanza con aceptar sintaxis: el compilador debe recorrer el AST, validar que el programa tenga sentido dentro del dominio de autómatas finitos y luego ejecutar o generar el artefacto final definido por el equipo.

### Estado real del repositorio al preparar Stage III

Antes de implementar, revisar de nuevo el repo, pero partir de estos hechos observados:

- La gramática vigente está en `src/main/c/frontend/syntactic-analysis/BisonGrammar.y`.
- El AST vigente está en `src/main/c/frontend/syntactic-analysis/AbstractSyntaxTree.h` y `.c`.
- Las acciones de Bison construyen nodos en `src/main/c/frontend/syntactic-analysis/BisonActions.c`.
- El lexer reconoce comentarios de línea, comentarios multilínea, `String`, `for`, `equivalent`, `print`, `show`, `test`, `convert`, `update`, tipos de autómata y operadores relacionales parcialmente.
- El backend actual es mínimo: `src/main/c/backend/domain-specific/Automaton.c` solo devuelve el tipo del autómata y `src/main/c/backend/code-generation/Generator.c` no genera salida real.
- `src/main/c/backend/domain-specific/Calculator.c` conserva código del ejemplo base y no está incluido en `CMakeLists.txt`; no usarlo como referencia del dominio salvo que se lo elimine o se lo reemplace conscientemente.
- `src/main/c/EntryPoint.c` actualmente ejecuta solo análisis sintáctico y destruye el AST. Stage III debe insertar las fases de análisis semántico y backend antes de destruir el AST.
- `CompilerState` contiene solo `abstractSyntaxtTree` y TODOs. Stage III probablemente necesita agregar tabla de símbolos, diagnósticos, configuración de salida y/o entorno de ejecución.
- `CMakeLists.txt` solo compila los `.c` listados manualmente. Todo nuevo módulo `.c` debe agregarse allí.
- Los tests en `src/test/c/accept` y `src/test/c/reject` nacieron para Stage II. Algunos casos `accept` son sintácticos pero semánticamente dudosos, por ejemplo `print myAutomaton;`, `show table of myAutomaton;` o updates con estados/símbolos no declarados. Para Stage III, no forzar el backend a aceptar programas inválidos solo para conservar falsos positivos de frontend; actualizar, mover o documentar esos tests.

### Fases obligatorias del compilador

La arquitectura recomendada para Stage III es:

1. Frontend: lexer + parser construyen el AST.
2. Análisis semántico: recorre el AST, construye símbolos/modelos de dominio, aplica validaciones y rechaza programas inválidos.
3. Backend: ejecuta las operaciones del DSL o genera el artefacto final definido.
4. Limpieza: destruye AST, tabla de símbolos, modelos runtime, strings clonados, listas y diagnósticos.

El `EntryPoint` debería quedar conceptualmente así:

```txt
status = executeSyntacticAnalysis()
if status == SUCCEEDED:
    status = executeSemanticAnalysis(&compilerState)
if status == SUCCEEDED:
    status = executeGenerator(&compilerState) o executeRuntime(&compilerState)
cleanup()
return status
```

No emitir salida de backend si la fase semántica falló. Todo error semántico debe producir estado de compilación fallido para que `src/main/bash/test.sh` pueda distinguir accept/reject.

### Análisis semántico

El documento de análisis semántico indica que esta fase opera sobre el AST porque la sintaxis aceptada puede ser un superconjunto del lenguaje válido. Para este DSL, implementar una pasada semántica explícita y no esconder validaciones de dominio en Bison salvo que sean puramente gramaticales.

Crear, si no existe, un módulo claro para esta fase, por ejemplo:

- `src/main/c/backend/semantic-analysis/SemanticAnalyzer.h`
- `src/main/c/backend/semantic-analysis/SemanticAnalyzer.c`
- módulos auxiliares para tabla de símbolos, scopes, conjuntos, diagnósticos y modelos runtime.

La fase semántica debería:

- Recorrer `Program->statements` en orden.
- Mantener una tabla de símbolos global y scopes locales para `for`.
- Registrar símbolos de tipo `Automata` y `String` como mínimo.
- Preparar el terreno para `Bool`, `State` y `Symbol` solo si la gramática real los incorpora.
- Validar usos antes de ejecución: `test`, `convert`, `show`, `print`, `equivalent` y `update` deben referenciar símbolos existentes cuando la política semántica lo exija.
- Resolver `test A with word;` contra una variable `String`.
- Resolver variables usadas dentro de `for`.
- Normalizar strings: el token `STRING` actualmente llega con comillas incluidas; la semántica o runtime debe convertir `"0011"` en `0011` y `""` en cadena vacía una sola vez.
- Emitir errores con mensajes claros y, cuando sea posible, nombre del símbolo y construcción involucrada. Si se agregan ubicaciones al AST, incluir línea/columna.

### Tabla de símbolos y scopes

Usar una tabla de símbolos simple y propia en C. No introducir librerías externas sin aprobación explícita del QRF.

Reglas recomendadas:

- No permitir dos autómatas con el mismo nombre en el mismo scope.
- No permitir declarar una `String` con el mismo nombre que otro símbolo del mismo scope.
- Una conversión `convert A to DFA as B;` crea un nuevo símbolo `B`; rechazar si `B` ya existe, salvo que el lenguaje documente sobrescritura.
- Un update `A { ... };` modifica un autómata existente; no crea uno nuevo.
- Un `for i in {...} { ... }` crea un scope local donde `i` es una `String` con el valor de la iteración.
- Si se permite shadowing, documentarlo y cubrirlo con tests. Si no hay decisión explícita, rechazar redeclaraciones en el mismo scope y evitar shadowing para mantener el lenguaje simple.

### Modelo de dominio interno

No operar el backend directamente sobre punteros del AST como si fueran el modelo runtime definitivo. El AST se destruye al final de la compilación y sus destructores son dueños de muchos strings/listas.

Crear un modelo de dominio separado o DTOs internos para autómatas, con ownership claro:

- `name`
- `type`: DFA, NFA, LNFA
- conjunto ordenado o lista única de estados
- conjunto ordenado o lista única de símbolos del alfabeto
- estado inicial
- conjunto de aceptación
- relación de transición `(source, symbol/lambda) -> set(destinations)`

Al copiar desde AST a runtime:

- clonar strings con ownership propio;
- normalizar destinos simples como conjunto singleton cuando convenga;
- preservar orden de inserción para que `print`, `show transitions` y `show table` tengan salida estable;
- liberar todo en destructores de backend;
- evitar aliasing entre AST, tabla de símbolos y autómatas generados por conversión.

Para operaciones de conjunto, implementar helpers pequeños y testeables:

- contains
- add unique
- union
- equality
- clone
- free
- stable string representation para salida

### Validaciones semánticas de autómatas

Para cada definición `automaton A : TYPE { ... };` validar:

- `A` no está redeclarado.
- `alphabet`, `states`, `start`, `accept` existen sintácticamente según la gramática vigente.
- No hay estados duplicados dentro de `states`.
- No hay símbolos duplicados dentro de `alphabet`.
- `lambda` no debe tratarse como símbolo regular del alfabeto.
- `start` pertenece a `states`.
- Cada estado de `accept` pertenece a `states`.
- Cada transición usa `source` perteneciente a `states`.
- Cada destino pertenece a `states`.
- Cada símbolo no-lambda pertenece a `alphabet`.
- No exigir que un DFA esté completo si la especificación permite autómatas vacíos o incompletos para completarlos después. La ausencia de transición se maneja como rechazo o conjunto vacío durante ejecución.

Reglas por tipo:

- DFA: no permite transiciones `lambda`; cada transición debe tener un único destino; no puede haber dos transiciones para el mismo par `(source, symbol)` con destinos distintos. Si un update redefine ese par, aplicar la política de sobrescritura antes de validar duplicados.
- NFA: permite uno o varios destinos por transición; no debería permitir `lambda` si se distingue de LNFA.
- LNFA: permite transiciones `lambda` y transiciones normales; los destinos simples pueden normalizarse como conjuntos singleton salvo que la gramática final decida exigir llaves.

Atención: el archivo actual `src/test/c/reject/04-invalid-lnfa` parece contradecir la especificación, porque está tipeado como `LNFA` y no como `DFA`. Revisarlo antes de usarlo como regla de dominio.

### Updates

La especificación contempla modificar autómatas existentes con:

```txt
A {
    states = {...}
    accept = {...}
    transitions {
        ...
    }
};
```

Como la sintaxis usa asignación pero el texto habla de agregar estados y redefinir aceptación, definir y documentar una política antes de implementar. Política recomendada:

- `states = {...}` en update agrega estados nuevos al conjunto existente y rechaza duplicados solo si se quiere una semántica estricta.
- `accept = {...}` reemplaza el conjunto de aceptación completo, validando que todos sus estados existan después de aplicar `states`.
- `transitions { ... }` agrega transiciones nuevas.
- Para DFA, una transición nueva con el mismo `(source, symbol)` sobrescribe la anterior, siguiendo el ejemplo comentado en la especificación.
- Para NFA/LNFA, una transición nueva puede unir destinos o reemplazar el conjunto; elegir una opción y cubrirla con tests. Si no hay decisión, preferir reemplazo por consistencia con el ejemplo de sobrescritura.
- Después de aplicar un update, revalidar el autómata completo con las mismas reglas de su tipo.

No aceptar updates que introduzcan símbolos fuera del alfabeto o estados inexistentes, salvo que primero se haya extendido explícitamente `states`.

### Ejecución de cadenas

`test A with "cadena";` y `test A with variable;` deben imprimir un resultado estable, idealmente `accept` o `reject`, porque la especificación dice que devuelve accept/reject. Si se elige otro formato, documentarlo en README y tests.

Reglas:

- La cadena vacía se representa con `""` y debe evaluarse sin consumir símbolos.
- Rechazar semánticamente una cadena que contenga símbolos fuera del alfabeto del autómata, o tratarla como `reject` solo si esa política queda documentada. Para tests de rechazo de dominio, es más claro rechazar semánticamente.
- DFA: mantener un único estado actual; si falta transición para un símbolo, rechazar la cadena.
- NFA: mantener conjunto de estados actuales; para cada símbolo, unir destinos.
- LNFA: aplicar clausura-lambda al estado inicial antes de consumir, y después de cada paso sobre símbolo aplicar clausura-lambda sobre el conjunto resultante.
- Aceptar si algún estado actual final pertenece al conjunto de aceptación al terminar la entrada.

### Conversiones

La especificación exige como mínimo:

- DFA -> NFA: conversión trivial.
- NFA -> DFA: construcción de subconjuntos.
- LNFA -> NFA: eliminación de lambda.
- LNFA -> DFA: directa o por composición `LNFA -> NFA -> DFA`.

Reglas generales:

- El autómata origen debe existir.
- El nombre destino no debe estar ocupado, salvo decisión explícita de sobrescritura.
- El tipo destino debe ser uno de los tipos válidos de la gramática.
- Rechazar conversiones no soportadas con error semántico claro.
- Si se decide soportar conversiones triviales adicionales, por ejemplo `NFA -> LNFA`, documentarlo y agregar tests. La especificación de rechazo menciona conversiones a tipo inválido; no asumir que todo widening está permitido.

Detalles algorítmicos:

- En `NFA -> DFA`, cada estado del DFA representa un conjunto de estados NFA. Usar nombres determinísticos, por ejemplo `{q0,q1}` normalizado o `S0`, `S1` con tabla interna para impresión estable.
- El estado inicial del DFA es el conjunto que contiene el inicial del NFA.
- Un estado DFA es de aceptación si su conjunto contiene algún estado de aceptación del origen.
- En `LNFA -> NFA`, para cada estado `q` y símbolo real `a`, calcular destinos usando clausuras lambda: `closure(move(closure(q), a))`.
- En `LNFA -> NFA`, los estados de aceptación nuevos deben incluir estados cuya clausura lambda intersecta con aceptación original.
- En `LNFA -> DFA`, preferir composición para reducir duplicación, salvo que una implementación directa quede más simple y testeada.

### Equivalencia

`equivalent A B;` es prestación opcional en la especificación inicial, pero ya existe en la gramática y tests. Para Stage III, implementarla o decidir explícitamente postergarla.

Implementación recomendada:

- Resolver ambos autómatas.
- Convertir ambos a DFA internamente, sin necesariamente registrar esos autómatas en la tabla de símbolos.
- Comparar lenguajes mediante recorrido BFS del producto de estados.
- Usar el alfabeto unión de ambos autómatas. Si falta una transición en un DFA, tratarla como transición a un estado sumidero no aceptador para la comparación.
- Si se encuentra un par donde uno acepta y el otro no, reportar `false` o `not equivalent`.
- Si no se encuentra diferencia alcanzable, reportar `true` o `equivalent`.

### Inspección y salida

Los comandos existentes son:

- `print A;`
- `show transitions of A;`
- `show table of A;`
- `show closure(q) in A;`

Para Stage III, deberían requerir que `A` exista. Si se mantienen casos sintácticos sin definición, dejarlos como tests de frontend separados, no como comportamiento semántico final.

La salida debe ser determinística:

- `print` muestra tipo, alfabeto, estados, start, accept y transiciones.
- `show transitions` muestra solo transiciones.
- `show table` usa filas por estado y columnas por símbolo del alfabeto; para LNFA, agregar columna `lambda` si se decide mostrarla.
- `show closure(q) in A` valida que `q` exista. En DFA/NFA sin lambda puede devolver `{q}` o rechazar por tipo; elegir y documentar. Para LNFA debe calcular clausura transitiva por transiciones lambda.

### For loops y strings

La gramática vigente soporta:

```txt
String word = "0011";
test A with word;

for i in {"001", "010"} {
    test A with i;
}
```

Para Stage III:

- `String` debe almacenarse como valor sin comillas.
- `test A with ID` debe buscar `ID` como variable string visible.
- El índice del `for` vive solo dentro del bloque.
- Las sentencias internas del `for` se ejecutan una vez por valor.
- Si se permite que la lista del `for` contenga IDs además de strings, el AST actual no distingue claramente literal vs variable en `StringList`; probablemente haya que extender el AST para conservar ese tipo de entrada antes de implementar resolución correcta.

No implementar `if`, `while`, `Bool`, `State`, `Symbol`, operadores lógicos o relacionales para Stage III salvo que una tarea concreta los incorpore al alcance real y actualice gramática, AST, semántica y tests.

### Runtime y generación de código

Los documentos de generación de código y runtime son genéricos: explican que la fase final debe traducir el AST válido y que el runtime puede estar embebido en el compilador o delegado al entorno destino.

Para este DSL hay dos caminos aceptables, siempre que queden documentados:

- Backend interpretativo: el compilador ejecuta directamente las operaciones del programa y emite resultados por stdout. En este caso, el runtime son las estructuras y algoritmos C incluidos en el binario.
- Generación de artefactos: el compilador produce otro archivo, por ejemplo DOT/Graphviz, C, Python u otro formato. En ese caso, documentar qué se genera, dónde se escribe, cómo se ejecuta y qué runtime externo necesita el usuario.

Recomendación para avanzar seguro: implementar primero backend interpretativo en C, porque el dominio pide operar con autómatas y los tests actuales ejecutan `.build/Flex-Bison-Compiler` sobre stdin sin revisar archivos generados. Si luego se agrega generación DOT u otro artefacto, mantenerla como salida explícita o adicional, no como requisito oculto para que funcionen `test`, `convert`, `show` y `equivalent`.

### Manejo de errores

Separar errores sintácticos de errores semánticos:

- Sintaxis inválida: falla `executeSyntacticAnalysis`.
- Dominio inválido: falla `executeSemanticAnalysis`.
- Fallo durante ejecución/generación: falla backend.

Para errores semánticos, preferir mensajes específicos:

- autómata no declarado;
- variable string no declarada;
- símbolo fuera del alfabeto;
- estado inexistente;
- estado inicial fuera de `states`;
- transición no determinista en DFA;
- `lambda` usado en DFA o NFA;
- conversión no soportada;
- nombre destino ya declarado.

No usar `assert` para validar programas de usuario. Los asserts pueden servir para invariantes internas, pero un input inválido debe producir error controlado y liberar memoria.

### Memoria y ownership

El proyecto está en C con AddressSanitizer. Cuidar especialmente:

- cada `calloc`/`malloc` tiene destructor correspondiente;
- cada string que sobreviva fuera del AST se clona;
- las conversiones crean autómatas nuevos con ownership completo;
- las tablas de símbolos no liberan dos veces objetos que pertenecen a otro contenedor;
- al fallar a mitad de análisis o conversión, liberar objetos parciales;
- no devolver punteros a buffers locales;
- no guardar punteros a lexemas del token después de que el token se destruye;
- mantener destructores idempotentes cuando sea razonable.

Cuando se agregue un módulo nuevo, registrar su destructor en `EntryPoint.c` si mantiene estado global o recursos persistentes.

### Testing esperado para Stage III

Mantener `src/main/bash/build.sh` y `src/main/bash/test.sh` como camino principal de verificación. El entorno académico esperado es Docker/Ubuntu; si se prueba localmente en Windows, confirmar también en Docker antes de entrega.

Agregar o ajustar tests unitarios compactos:

- aceptar DFA válido y testear cadenas aceptadas/rechazadas;
- aceptar cadena vacía;
- rechazar start/accept/source/destination fuera de `states`;
- rechazar símbolo fuera del alfabeto;
- rechazar `lambda` en DFA;
- rechazar transición múltiple o duplicada conflictiva en DFA;
- aceptar NFA con múltiples destinos y convertirlo a DFA;
- aceptar LNFA con lambda closure y convertirlo a NFA/DFA;
- rechazar conversión no soportada;
- rechazar uso de autómata o string no declarado;
- aceptar update válido y rechazar update inválido;
- aceptar `for` con strings literales y `test` interno;
- verificar `equivalent` con un caso verdadero y uno falso si la salida se testea;
- verificar `print`, `show transitions`, `show table` y `show closure` con salidas determinísticas si se agregan asserts de stdout.

Si los tests siguen siendo solo por exit code, asegurar que los programas aceptados puedan contener operaciones que imprimen `reject` sin que eso signifique fallo de compilación. Diferenciar “la cadena fue rechazada por el autómata” de “el programa DSL es inválido”.

### Documentación final de entrega

Stage III exige un documento final adicional en PDF, Notion o Confluence con, como mínimo:

- Introducción.
- Modelo Computacional: dominio y lenguaje.
- Implementación: frontend, backend, adicionales opcionales y dificultades encontradas.
- Futuras extensiones.
- Conclusiones.
- Referencias.
- Bibliografía.

No usar ese documento para esconder instrucciones necesarias de build/run. El repositorio debe ser autocontenido: comandos, dependencias, formato de salida y limitaciones reales deben estar también en `README.md` o documentación versionada.
