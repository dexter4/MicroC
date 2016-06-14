// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -40(gp)
3: lda sp, -40(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 22
8: halt
// ====================
// fun()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 5
11: ldc 1, 4
12: mul 0, 1, 0
13: ld 1, -8(fp)
14: add 1, 1, 0
15: lda 3, -0(1)
16: ldc 0, 555
17: st 0, 0(3)
18: ldc 27, 0
19: lda sp, 0(fp)
20: ld fp, 0(fp)
21: ld pc, -4(sp)
// ====================
// main()
// ====================
22: lda sp, -0(sp)
23: ldc 0, 4
24: ldc 1, 4
25: mul 0, 1, 0
26: add 1, gp, 0
27: lda 3, -36(1)
28: ldc 0, 444
29: st 0, 0(3)
30: ldc 0, 4
31: ldc 1, 4
32: mul 0, 1, 0
33: add 1, gp, 0
34: ld 2, -36(1)
35: out 2
36: ldc 0, 10
37: outc 0
38: ldc 0, 5
39: ldc 1, 4
40: mul 0, 1, 0
41: add 1, gp, 0
42: ld 2, -36(1)
43: out 2
44: ldc 0, 10
45: outc 0
46: lda sp, -8(sp)
47: lda 0, -36(gp)
48: push 0
49: st fp, -8(fp)
50: lda fp, -8(fp)
51: lda 0, 2(pc)
52: st 0, -4(fp)
53: ldc pc, 9
54: lda 0, 0(27)
55: ldc 0, 4
56: ldc 1, 4
57: mul 0, 1, 0
58: add 1, gp, 0
59: ld 2, -36(1)
60: out 2
61: ldc 0, 10
62: outc 0
63: ldc 0, 5
64: ldc 1, 4
65: mul 0, 1, 0
66: add 1, gp, 0
67: ld 2, -36(1)
68: out 2
69: ldc 0, 10
70: outc 0
71: ldc 27, 0
72: lda sp, 0(fp)
73: ld fp, 0(fp)
74: ld pc, -4(sp)
// ====================
