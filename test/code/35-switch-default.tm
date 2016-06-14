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
10: ldc 0, 1
11: st 0, -8(fp)
12: ld 0, -8(fp)
13: ld 1, -8(fp)
14: ldc 2, 3
15: add 3, 1, 2
16: st 3, -8(fp)
17: ld 1, -8(fp)
18: out 1
19: ldc 1, 10
20: outc 1
21: ldc pc, 22
22: ldc 27, 0
23: lda sp, 0(fp)
24: ld fp, 0(fp)
25: ld pc, -4(sp)
// ====================
