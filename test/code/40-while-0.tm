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
13: ldc 1, 10
14: lt 2, 0, 1
15: jle 2, 9(pc)
16: ld 0, -8(fp)
17: out 0
18: ldc 0, 10
19: outc 0
20: ld 0, -8(fp)
21: ldc 1, 1
22: add 2, 0, 1
23: st 2, -8(fp)
24: ldc pc, 12
25: ldc 27, 0
26: lda sp, 0(fp)
27: ld fp, 0(fp)
28: ld pc, -4(sp)
// ====================
