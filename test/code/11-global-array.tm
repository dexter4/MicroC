// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -68(gp)
3: lda sp, -68(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 111
11: stb 0,  +3(gp)
12: ldc 0, 222
13: st 0, -4(gp)
14: ldc 0, 0
15: ldc 1, 1
16: mul 0, 1, 0
17: add 1, gp, 0
18: lda 3, -9(1)
19: ldc 0, 33
20: st 0, 0(3)
21: ldc 0, 7
22: ldc 1, 4
23: mul 0, 1, 0
24: add 1, gp, 0
25: lda 3, -52(1)
26: ldc 0, 444
27: st 0, 0(3)
28: ldc 0, 10
29: ldc 1, 1
30: mul 0, 1, 0
31: add 1, gp, 0
32: lda 3, -63(1)
33: ldc 0, 55
34: st 0, 0(3)
35: ld 0,  +3(gp)
36: outc 0
37: ldc 0, 10
38: outc 0
39: ld 0, -4(gp)
40: out 0
41: ldc 0, 10
42: outc 0
43: ldc 0, 0
44: ldc 1, 1
45: mul 0, 1, 0
46: add 1, gp, 0
47: ld 2, -9(1)
48: outc 2
49: ldc 0, 10
50: outc 0
51: ldc 0, 7
52: ldc 1, 4
53: mul 0, 1, 0
54: add 1, gp, 0
55: ld 2, -52(1)
56: out 2
57: ldc 0, 10
58: outc 0
59: ldc 0, 10
60: ldc 1, 1
61: mul 0, 1, 0
62: add 1, gp, 0
63: ld 2, -63(1)
64: outc 2
65: ldc 0, 10
66: outc 0
67: ldc 27, 0
68: lda sp, 0(fp)
69: ld fp, 0(fp)
70: ld pc, -4(sp)
// ====================
