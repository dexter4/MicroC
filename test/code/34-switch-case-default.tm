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
10: ldc 0, 0
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
24: ldc pc, 46
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
36: ldc pc, 46
37: ld 1, -8(fp)
38: ldc 2, 3
39: add 3, 1, 2
40: st 3, -8(fp)
41: ld 1, -8(fp)
42: out 1
43: ldc 1, 10
44: outc 1
45: ldc pc, 46
46: ldc 27, 0
47: lda sp, 0(fp)
48: ld fp, 0(fp)
49: ld pc, -4(sp)
// ====================
