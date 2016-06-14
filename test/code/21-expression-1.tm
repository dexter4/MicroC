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
12: gt 2, 0, 1
13: st 2, -0(gp)
14: ld 0, -0(gp)
15: out 0
16: ldc 0, 10
17: outc 0
18: ldc 0, 1
19: ldc 1, 2
20: ge 2, 0, 1
21: st 2, -0(gp)
22: ld 0, -0(gp)
23: out 0
24: ldc 0, 10
25: outc 0
26: ldc 0, 1
27: ldc 1, 2
28: lt 2, 0, 1
29: st 2, -0(gp)
30: ld 0, -0(gp)
31: out 0
32: ldc 0, 10
33: outc 0
34: ldc 0, 2
35: ldc 1, 2
36: le 2, 0, 1
37: st 2, -0(gp)
38: ld 0, -0(gp)
39: out 0
40: ldc 0, 10
41: outc 0
42: ldc 0, 1
43: ldc 1, 2
44: eq 2, 0, 1
45: st 2, -0(gp)
46: ld 0, -0(gp)
47: out 0
48: ldc 0, 10
49: outc 0
50: ldc 0, 1
51: ldc 1, 2
52: ne 2, 0, 1
53: st 2, -0(gp)
54: ld 0, -0(gp)
55: out 0
56: ldc 0, 10
57: outc 0
58: ldc 27, 0
59: lda sp, 0(fp)
60: ld fp, 0(fp)
61: ld pc, -4(sp)
// ====================
