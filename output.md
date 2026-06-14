# Automaton program

## Automaton LambdaEjemplo (LNFA) declared.

## show closure of q0 in LambdaEjemplo

```
closure(q0) in LambdaEjemplo = {q0, q1}
```

## test LambdaEjemplo with "aaaaaab"

**Result:** ACCEPTED

## test LambdaEjemplo with "ab"

**Result:** ACCEPTED

## test LambdaEjemplo with "aab"

**Result:** ACCEPTED

## print LambdaEjemplo (LNFA)

- *ID*: LambdaEjemplo
- *Type*: LNFA
- *Alphabet*: a, b
- *States*: q0, q1, q2
- *Start state*: q0
- *Accept states*: q2
- *Transitions*:
  - q0 --lambda--> q1
  - q1 --a--> q1
  - q1 --b--> q2

## for i

### i = "aaaaaab"

## test LambdaEjemplo with "aaaaaab"

**Result:** ACCEPTED

### i = "ab"

## test LambdaEjemplo with "ab"

**Result:** ACCEPTED

### i = "aab"

## test LambdaEjemplo with "aab"

**Result:** ACCEPTED

