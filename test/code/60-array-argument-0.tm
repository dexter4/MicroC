// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -40(gp)
3: lda sp, -40(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 23
8: halt
// ====================
// fun()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 4
11: ldc 1, 4
12: mul 0, 1, 0
13: ld 1, -8(fp)
14: add 1, 1, 0
15: ld 2, -0(1)
16: out 2
17: ldc 0, 10
18: outc 0
19: ldc 27, 0
20: lda sp, 0(fp)
21: ld fp, 0(fp)
22: ld pc, -4(sp)
// ====================
// main()
// ====================
23: lda sp, -0(sp)
24: ldc 0, 4
25: ldc 1, 4
26: mul 0, 1, 0
27: add 1, gp, 0
28: lda 3, -36(1)
29: ldc 0, 444
30: st 0, 0(3)
31: ldc 0, 4
32: ldc 1, 4
33: mul 0, 1, 0
34: add 1, gp, 0
35: ld 2, -36(1)
36: out 2
37: ldc 0, 10
38: outc 0
39: lda sp, -8(sp)
40: lda 0, -36(gp)
41: push 0
42: st fp, -8(fp)
43: lda fp, -8(fp)
44: lda 0, 2(pc)
45: st 0, -4(fp)
46: ldc pc, 9
47: lda 0, 0(27)
48: ldc 27, 0
49: lda sp, 0(fp)
50: ld fp, 0(fp)
51: ld pc, -4(sp)
// ====================
