$$
\Large
\begin{aligned}

13 &= b1101\\
13 &= 1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0\\ 
13 &= 1 \times 8+ 1 \times 4 + 0 \times 2 + 1 \times 1\\ 
\\\

13 &= 8a + 4b + 2c + 1d &d=1\\ 

12 &= 8a + 4b + 2c\\\

6 &= 4a + 2b + 1c &c=0\\

6 &= 4a + 2b\\\

3 &= 2a + b1 &b=1\\

2 &= 2a\\\

1 &= a &a=1\\

\end{aligned}
$$



---

```c

128  64  32  16   8   4   2   1   <-- starting 8 columns for 8 digits
  0   0   0   0   0   0   1   1   <-- multiply each columns by binary digits
  --- --- --- --- --- --- --- ---
  0   0   0   0   0   0   2   1   <-- add these up:  2 + 1  =  3
```