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
7: ldc pc, 39
8: halt
// ====================
// sum()
// ====================
9: lda sp, -4(sp)
10: ld 0, -8(fp)
11: ldc 1, 1
12: eq 2, 0, 1
13: jle 2, 6(pc)
14: ldc 0, 1
15: lda 27, 0(0)
16: lda sp, 0(fp)
17: ld fp, 0(fp)
18: ld pc, -4(sp)
19: ldc pc, 39
20: lda sp, -8(sp)
21: ld 0, -8(fp)
22: ldc 1, 1
23: sub 2, 0, 1
24: push 2
25: st fp, -16(fp)
26: lda fp, -16(fp)
27: lda 0, 2(pc)
28: st 0, -4(fp)
29: ldc pc, 9
30: lda 0, 0(27)
31: st 0, -12(fp)
32: ld 0, -8(fp)
33: ld 1, -12(fp)
34: add 2, 0, 1
35: lda 27, 0(2)
36: lda sp, 0(fp)
37: ld fp, 0(fp)
38: ld pc, -4(sp)
// ====================
// main()
// ====================
39: lda sp, -8(sp)
40: ldc 0, 100
41: st 0, -8(fp)
42: lda sp, -8(sp)
43: ld 0, -8(fp)
44: push 0
45: st fp, -16(fp)
46: lda fp, -16(fp)
47: lda 0, 2(pc)
48: st 0, -4(fp)
49: ldc pc, 9
50: lda 0, 0(27)
51: st 0, -12(fp)
52: ld 0, -12(fp)
53: out 0
54: ldc 0, 10
55: outc 0
56: ldc 27, 0
57: lda sp, 0(fp)
58: ld fp, 0(fp)
59: ld pc, -4(sp)
// ====================
