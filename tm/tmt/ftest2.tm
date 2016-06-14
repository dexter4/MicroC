// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -256(gp)
3: lda sp, -256(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 14
8: halt
// ====================
// lala()
// ====================
9: lda sp, -0(sp)
10: ldc 27, 0
11: lda sp, 0(fp)
12: ld fp, 0(fp)
13: ld pc, -4(sp)
// ====================
// main()
// ====================
14: lda sp, -260(sp)
15: ldc 0, 17
16: ldc 1, 1
17: mul 0, 1, 0
18: add 1, gp, 0
19: lda 3, -252(1)
20: ldc 0, 18
21: st 0, 0(3)
22: ldc 0, 27
23: ldc 1, 1
24: mul 0, 1, 0
25: add 1, fp, 0
26: lda 3, -260(1)
27: ldc 0, 28
28: st 0, 0(3)
29: lda sp, -8(sp)
30: lda 0, -252(gp)
31: push 0
32: st fp, -268(fp)
33: lda fp, -268(fp)
34: lda 0, 2(pc)
35: st 0, -4(fp)
36: ldc pc, 9
37: lda 0, 0(27)
38: lda sp, -8(sp)
39: lda 0, -260(gp)
40: push 0
41: st fp, -268(fp)
42: lda fp, -268(fp)
43: lda 0, 2(pc)
44: st 0, -4(fp)
45: ldc pc, 9
46: lda 0, 0(27)
47: ldc 27, 0
48: lda sp, 0(fp)
49: ld fp, 0(fp)
50: ld pc, -4(sp)
// ====================
