// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -36(gp)
3: lda sp, -36(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 0
11: add 0, gp, 0
12: lda 2, -32(0)
13: ldc 0, 111
14: st 0, 0(2)
15: ldc 0, 4
16: add 0, gp, 0
17: lda 2, -32(0)
18: ldc 0, 67
19: st 0, 0(2)
20: ldc 1, 3
21: ldc 0, 4
22: mul 0, 1, 0
23: ldc 2, 8
24: add 0, 0, 2
25: add 0, gp, 0
26: lda 3, -32(0)
27: ldc 0, 333
28: st 0, 0(3)
29: ldc 1, 4
30: ldc 0, 1
31: mul 0, 1, 0
32: ldc 2, 24
33: add 0, 0, 2
34: add 0, gp, 0
35: lda 3, -32(0)
36: ldc 0, 44
37: st 0, 0(3)
38: ldc 0, 0
39: add 0, gp, 0
40: ld 1, -32(0)
41: out 1
42: ldc 0, 10
43: outc 0
44: ldc 0, 4
45: add 0, gp, 0
46: ld 1, -32(0)
47: outc 1
48: ldc 0, 10
49: outc 0
50: ldc 1, 3
51: ldc 0, 4
52: mul 0, 1, 0
53: ldc 2, 8
54: add 0, 0, 2
55: add 0, gp, 0
56: ld 2, -32(0)
57: out 2
58: ldc 0, 10
59: outc 0
60: ldc 1, 4
61: ldc 0, 1
62: mul 0, 1, 0
63: ldc 2, 24
64: add 0, 0, 2
65: add 0, gp, 0
66: ld 2, -32(0)
67: outc 2
68: ldc 0, 10
69: outc 0
70: ldc 27, 0
71: lda sp, 0(fp)
72: ld fp, 0(fp)
73: ld pc, -4(sp)
// ====================
