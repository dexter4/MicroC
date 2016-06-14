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
9: lda sp, -44(sp)
10: in 0
11: st 0, -8(fp)
12: ld 0, -8(fp)
13: out 0
14: ldc 0, 10
15: outc 0
16: ldc 0, 8
17: ldc 1, 4
18: mul 0, 1, 0
19: add 1, fp, 0
20: lda 3, -48(1)
21: in 0
22: st 0, 0(3)
23: ldc 0, 8
24: ldc 1, 4
25: mul 0, 1, 0
26: add 1, fp, 0
27: ld 2, -48(1)
28: out 2
29: ldc 0, 10
30: outc 0
31: ldc 27, 0
32: lda sp, 0(fp)
33: ld fp, 0(fp)
34: ld pc, -4(sp)
// ====================
