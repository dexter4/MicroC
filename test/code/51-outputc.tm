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
10: ldc 0, 97
11: stb 0, -5(fp)
12: ld 0, -5(fp)
13: outc 0
14: ldc 0, 10
15: outc 0
16: ldc 27, 0
17: lda sp, 0(fp)
18: ld fp, 0(fp)
19: ld pc, -4(sp)
// ====================
