100 rem: pi
110 rem: copyright 1979 by phil feldman and tom rugg
150 random: clear 50:defint j
160 t=0:th=0
300 gosub 600
310 input"sample size for printing";np
320 np=int(np):if np<1 then 300
330 gosub 600