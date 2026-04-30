# Proyecto Especial — Frontend del compilador (Lexer + Parser)

Este repositorio implementa el **frontend de un compilador académico** como parte del Proyecto Especial de la materia Teoría de Lenguajes / Compiladores.

El objetivo de esta etapa es implementar:

1. Analizador léxico
2. Analizador sintáctico
3. AST (Abstract Syntax Tree)
4. Manejo de errores
5. Integración entre componentes

El frontend debe transformar un archivo fuente en una representación estructurada válida del programa.

---

# Arquitectura esperada del frontend

Pipeline esperado:

SOURCE CODE
→ Lexer
→ Token stream
→ Parser
→ AST
→ Validaciones
→ Output estructurado

Codex debe respetar esta arquitectura.

---

# Objetivos de la etapa actual (Frontend)

Implementar:

* Tokenización
* Parsing
* AST
* Manejo de errores
* Validación sintáctica completa

No implementar:

* Generación de código
* Interpretación
* Optimización
* Semantic analysis profundo (solo validaciones mínimas si se requieren)

---

# Lexer — Responsabilidades

Debe:

1. Leer caracteres
2. Agruparlos en tokens
3. Detectar errores léxicos
4. Reportar posición (línea / columna)

Tokens típicos esperados:

IDENTIFIER
NUMBER
STRING
KEYWORD
OPERATOR
SYMBOL
EOF

Debe ignorar:

* espacios
* saltos de línea
* comentarios

Formato esperado del token:

Token {
type
value
line
column
}

Ejemplo:

Token(IDENTIFIER, "variable", 3, 12)

---

# Parser — Responsabilidades

Debe:

1. Consumir tokens del lexer
2. Validar estructura gramatical
3. Construir AST
4. Detectar errores sintácticos

El parser debe implementar:

recursive descent parser

si la gramática es LL(1)

o

tabla predictiva

si el TP lo exige explícitamente

Codex debe inferir cuál usar según el repo existente.

---

# AST — Responsabilidades

El AST debe representar:

program
statements
expressions
declarations
assignments
control structures

Ejemplo:

Program
├── Statement
│    ├── Assignment
│    │     ├── Identifier
│    │     └── Expression
│
└── Statement

Debe implementarse con clases o structs.

Ejemplo:

ProgramNode
StatementNode
ExpressionNode
AssignmentNode

---

# Manejo de errores

Debe existir:

LexicalError
SyntaxError

Cada error debe incluir:

line
column
message

Ejemplo:

SyntaxError(line=5, column=8, message="Unexpected token")

El parser NO debe detenerse en el primer error si puede recuperarse.

---

# Diseño esperado del repo

Estructura recomendada:

src/

lexer/
token.py
lexer.py

parser/
parser.py
ast_nodes.py

errors/
lexical_error.py
syntax_error.py

main.py

Codex puede adaptar esto al lenguaje del repo existente.

---

# Reglas obligatorias

Codex debe:

1. NO romper código existente
2. respetar naming actual del proyecto
3. reutilizar estructuras existentes
4. seguir estilo actual del repo
5. agregar tests si el repo ya tiene tests
6. documentar funciones nuevas

---

# Objetivo funcional mínimo

El frontend debe:

leer archivo fuente
tokenizar correctamente
parsear correctamente
construir AST
reportar errores correctamente

---

# Objetivo funcional máximo

El frontend debe permitir:

ejecutar

compiler input.txt

y obtener:

AST válido

o

lista de errores

---

# Estrategia de implementación sugerida

Orden recomendado:

1. implementar Token class
2. implementar Lexer
3. implementar Parser base
4. implementar nodos AST
5. conectar Lexer + Parser
6. agregar errores
7. tests mínimos

---

# Supuestos del proyecto académico

Este compilador es:

determinístico
educativo
simplificado

No necesita:

optimización
tipado complejo
code generation

---

# Output esperado

Parser debe devolver:

AST object

o

error list

Nunca null

---

# Convención de desarrollo

Código claro > código optimizado

Prioridad:

correctitud
legibilidad
estructura modular
testeabilidad

---

# Comportamiento esperado de Codex

Codex debe:

explorar repo
detectar lenguaje
detectar estructura existente
integrar lexer
integrar parser
generar AST
agregar errores
no romper interfaces existentes
