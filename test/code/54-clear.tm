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
9: lda sp, -16(sp)
10: ldc 0, 1634036835
11: ldc 1, 0
12: st 0, 0(1)
13: ldc 0, 114
14: ldc 1, 0
15: st 0, 4(1)
16: ldc 0, 0
17: ldc 1, 0
18: st 0, 8(1)
19: st 1, -8(fp)
20: ldc 0, 3
21: st 0, -12(fp)
22: ldc 0, 2
23: st 0, -16(fp)
24: ldc 0, 1
25: st 0, -20(fp)
26: ld 0, -8(fp)
27: outs 0
28: ldc 0, 10
29: outc 0
30: slp 1000
31: ld 0, -12(fp)
32: out 0
33: ldc 0, 10
34: outc 0
35: slp 1000
36: ld 0, -16(fp)
37: out 0
38: ldc 0, 10
39: outc 0
40: slp 1000
41: ld 0, -20(fp)
42: out 0
43: ldc 0, 10
44: outc 0
45: slp 1000
46: clr
47: ldc 27, 0
48: lda sp, 0(fp)
49: ld fp, 0(fp)
50: ld pc, -4(sp)
// ====================
