// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -0(gp)
3: lda sp, -0(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -4(sp)
10: ldc 0, 100
11: st 0, -8(fp)
12: ld 0, -8(fp)
13: ldc 1, 0
14: lt 2, 0, 1
15: jle 2, 5(pc)
16: ldc 0, -777
17: out 0
18: ldc 0, 10
19: outc 0
20: ld 0, -8(fp)
21: ldc 1, 0
22: gt 2, 0, 1
23: jle 2, 5(pc)
24: ldc 0, 777
25: out 0
26: ldc 0, 10
27: outc 0
28: ldc pc, 33
29: ldc 0, 0
30: out 0
31: ldc 0, 10
32: outc 0
33: ld 0, -8(fp)
34: ldc 1, 0
35: lt 2, 0, 1
36: jle 2, 5(pc)
37: ldc 0, -777
38: out 0
39: ldc 0, 10
40: outc 0
41: ld 0, -8(fp)
42: ldc 1, 0
43: gt 2, 0, 1
44: jle 2, 5(pc)
45: ldc 0, 777
46: out 0
47: ldc 0, 10
48: outc 0
49: ldc pc, 52
50: ldc 0, 0
51: out 0
52: ldc 27, 0
53: lda sp, 0(fp)
54: ld fp, 0(fp)
55: ld pc, -4(sp)
// ====================
