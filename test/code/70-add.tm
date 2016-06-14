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
7: ldc pc, 18
8: halt
// ====================
// add()
// ====================
9: lda sp, -0(sp)
10: ld 0, -8(fp)
11: ld 1, -12(fp)
12: add 2, 0, 1
13: st 2, -0(gp)
14: ldc 27, 0
15: lda sp, 0(fp)
16: ld fp, 0(fp)
17: ld pc, -4(sp)
// ====================
// main()
// ====================
18: lda sp, -0(sp)
19: lda sp, -8(sp)
20: ldc 0, 111
21: push 0
22: ldc 0, 222
23: push 0
24: st fp, -8(fp)
25: lda fp, -8(fp)
26: lda 0, 2(pc)
27: st 0, -4(fp)
28: ldc pc, 9
29: lda 0, 0(27)
30: ld 0, -0(gp)
31: out 0
32: ldc 0, 10
33: outc 0
34: ldc 27, 0
35: lda sp, 0(fp)
36: ld fp, 0(fp)
37: ld pc, -4(sp)
// ====================
