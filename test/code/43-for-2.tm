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
9: lda sp, -8(sp)
10: ldc 0, 1
11: st 0, -8(fp)
12: ld 0, -8(fp)
13: ldc 1, 3
14: le 2, 0, 1
15: jne 2, 6(pc)
16: ldc pc, 44
17: ld 0, -8(fp)
18: ldc 1, 1
19: add 2, 0, 1
20: st 2, -8(fp)
21: ldc pc, 12
22: ld 0, -8(fp)
23: out 0
24: ldc 0, 10
25: outc 0
26: ldc 0, 11
27: st 0, -12(fp)
28: ld 0, -12(fp)
29: ldc 1, 13
30: le 2, 0, 1
31: jne 2, 6(pc)
32: ldc pc, 43
33: ld 0, -12(fp)
34: ldc 1, 1
35: add 2, 0, 1
36: st 2, -12(fp)
37: ldc pc, 28
38: ld 0, -12(fp)
39: out 0
40: ldc 0, 10
41: outc 0
42: ldc pc, 33
43: ldc pc, 17
44: ldc 27, 0
45: lda sp, 0(fp)
46: ld fp, 0(fp)
47: ld pc, -4(sp)
// ====================
