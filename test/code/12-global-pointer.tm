// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -32(gp)
3: lda sp, -32(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: lda 0,  +3(gp)
11: st 0, -16(gp)
12: lda 0, -4(gp)
13: st 0, -20(gp)
14: lda 0, -8(gp)
15: st 0, -24(gp)
16: lda 0, -9(gp)
17: st 0, -28(gp)
18: ld 0, -16(gp)
19: ldc 1, 111
20: stb 1, 0(0)
21: ld 0, -20(gp)
22: ldc 1, 222
23: st 1, 0(0)
24: ld 0, -24(gp)
25: ldc 1, 333
26: st 1, 0(0)
27: ld 0, -28(gp)
28: ldc 1, 44
29: stb 1, 0(0)
30: ld 0,  +3(gp)
31: outc 0
32: ldc 0, 10
33: outc 0
34: ld 0, -4(gp)
35: out 0
36: ldc 0, 10
37: outc 0
38: ld 0, -8(gp)
39: out 0
40: ldc 0, 10
41: outc 0
42: ld 0, -9(gp)
43: outc 0
44: ldc 0, 10
45: outc 0
46: ld 0, -16(gp)
47: ld 1, 0(0)
48: outc 1
49: ldc 0, 10
50: outc 0
51: ld 0, -20(gp)
52: ld 1, 0(0)
53: out 1
54: ldc 0, 10
55: outc 0
56: ld 0, -24(gp)
57: ld 1, 0(0)
58: out 1
59: ldc 0, 10
60: outc 0
61: ld 0, -28(gp)
62: ld 1, 0(0)
63: outc 1
64: ldc 0, 10
65: outc 0
66: ldc 27, 0
67: lda sp, 0(fp)
68: ld fp, 0(fp)
69: ld pc, -4(sp)
// ====================
