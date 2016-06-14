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
10: ldc 0, 10
11: st 0, -8(fp)
12: ldc 0, 20
13: st 0, -12(fp)
14: ld 0, -8(fp)
15: ld 1, -12(fp)
16: lt 2, 0, 1
17: jle 2, 5(pc)
18: ld 0, -12(fp)
19: out 0
20: ldc 0, 10
21: outc 0
22: ldc pc, 27
23: ld 0, -8(fp)
24: out 0
25: ldc 0, 10
26: outc 0
27: ldc 27, 0
28: lda sp, 0(fp)
29: ld fp, 0(fp)
30: ld pc, -4(sp)
// ====================
