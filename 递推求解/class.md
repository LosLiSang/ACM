
```c
1 (1)
M
2 (2)
FF MM
3 (4)
FFF MMM FFM MFF
4 (7)
FFFF MMMM FFFM MFFF FFMM MMFF MFFM
5 (13)
FFFFF FFFFM MMMMM FFFMM MFFFM FFFFM MMFFF MFFFF FFMMM MMMFF MMFFM MFFMM FFMFF

f(n) = f(n-1) + f(n-2) + f(n-4)

```

------

ABC, A不能跟在B的后面，B不能跟着C的后面

```c
1 (3)
A B C
2 (7)
AA BB CC AB AC BC CA 
3 


1) 最后一位是A  f(n-2) + f(n-3)
2) 最后一位是C　f(n-1)
3) 最后一位是B  f(n-2) + f(n-3)
```

--

错排问题

```c

d[n] = (n-1)*(d[n-1] + d[n-2])

```

--

```c

1 (1)
1-2
2 (2)
1-2 3-4
1-4 2-3
3 (5)
1-2 3-4 5-6
1-6 4-5 2-3
1-2 3-6 4-5
1-6 2-5 3-4
1-4 2-3 5-6

Catalan
f(n) = (f(n-1) * f(0) + f(n-2) * f(1) + ... + f(0) * f(n-1))

```
