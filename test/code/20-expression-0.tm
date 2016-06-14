// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -4(gp)
3: lda sp, -4(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 1
11: ldc 1, 2
12: add 2, 0, 1
13: ldc 0, 3
14: sub 1, 2, 0
15: st 1, -0(gp)
16: ld 0, -0(gp)
17: out 0
18: ldc 0, 10
19: outc 0
20: ldc 0, 1
21: ldc 1, 2
22: ldc 2, 3
23: mul 3, 1, 2
24: sub 1, 0, 3
25: st 1, -0(gp)
26: ld 0, -0(gp)
27: out 0
28: ldc 0, 10
29: outc 0
30: ldc 0, 1
31: ldc 1, 2
32: sub 2, 0, 1
33: ldc 0, 3
34: mul 1, 2, 0
35: st 1, -0(gp)
36: ld 0, -0(gp)
37: out 0
38: ldc 0, 10
39: outc 0
40: ldc 0, 1
41: ldc 1, 2
42: ldc 2, 3
43: div 3, 1, 2
44: add 1, 0, 3
45: st 1, -0(gp)
46: ld 0, -0(gp)
47: out 0
48: ldc 0, 10
49: outc 0
50: ldc 0, 4
51: ldc 1, 2
52: add 2, 0, 1
53: ldc 0, 3
54: div 1, 2, 0
55: st 1, -0(gp)
56: ld 0, -0(gp)
57: out 0
58: ldc 0, 10
59: outc 0
60: ldc 27, 0
61: lda sp, 0(fp)
62: ld fp, 0(fp)
63: ld pc, -4(sp)
// ====================
