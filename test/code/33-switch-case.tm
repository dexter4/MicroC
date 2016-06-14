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
10: ldc 0, 2
11: st 0, -8(fp)
12: ld 0, -8(fp)
13: ldc 1, 0
14: eq 2, 0, 1
15: jle 2, 9(pc)
16: ld 1, -8(fp)
17: ldc 2, 1
18: add 3, 1, 2
19: st 3, -8(fp)
20: ld 1, -8(fp)
21: out 1
22: ldc 1, 10
23: outc 1
24: ldc pc, 61
25: ldc 1, 1
26: eq 2, 0, 1
27: jle 2, 9(pc)
28: ld 1, -8(fp)
29: ldc 2, 2
30: add 3, 1, 2
31: st 3, -8(fp)
32: ld 1, -8(fp)
33: out 1
34: ldc 1, 10
35: outc 1
36: ldc pc, 61
37: ldc 1, 2
38: eq 2, 0, 1
39: jle 2, 9(pc)
40: ld 1, -8(fp)
41: ldc 2, 3
42: add 3, 1, 2
43: st 3, -8(fp)
44: ld 1, -8(fp)
45: out 1
46: ldc 1, 10
47: outc 1
48: ldc pc, 61
49: ldc 1, 3
50: eq 2, 0, 1
51: jle 2, 9(pc)
52: ld 1, -8(fp)
53: ldc 2, 4
54: add 3, 1, 2
55: st 3, -8(fp)
56: ld 1, -8(fp)
57: out 1
58: ldc 1, 10
59: outc 1
60: ldc pc, 61
61: ldc 27, 0
62: lda sp, 0(fp)
63: ld fp, 0(fp)
64: ld pc, -4(sp)
// ====================
