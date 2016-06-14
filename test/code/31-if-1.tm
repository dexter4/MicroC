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
9: lda sp, -12(sp)
10: ldc 0, 10
11: st 0, -8(fp)
12: ldc 0, 999
13: st 0, -12(fp)
14: ldc 0, 30
15: st 0, -16(fp)
16: ld 0, -8(fp)
17: ld 1, -12(fp)
18: lt 2, 0, 1
19: jle 2, 14(pc)
20: ld 0, -12(fp)
21: ld 1, -16(fp)
22: lt 2, 0, 1
23: jle 2, 5(pc)
24: ld 0, -16(fp)
25: out 0
26: ldc 0, 10
27: outc 0
28: ldc pc, 33
29: ld 0, -12(fp)
30: out 0
31: ldc 0, 10
32: outc 0
33: ldc pc, 47
34: ld 0, -8(fp)
35: ld 1, -16(fp)
36: lt 2, 0, 1
37: jle 2, 5(pc)
38: ld 0, -16(fp)
39: out 0
40: ldc 0, 10
41: outc 0
42: ldc pc, 47
43: ld 0, -8(fp)
44: out 0
45: ldc 0, 10
46: outc 0
47: ldc 27, 0
48: lda sp, 0(fp)
49: ld fp, 0(fp)
50: ld pc, -4(sp)
// ====================
