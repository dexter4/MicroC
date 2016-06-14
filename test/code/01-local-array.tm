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
9: lda sp, -56(sp)
10: ldc 0, 111
11: st 0, -8(fp)
12: ldc 0, 99
13: stb 0, -9(fp)
14: ldc 0, 7
15: ldc 1, 4
16: mul 0, 1, 0
17: add 1, fp, 0
18: lda 3, -52(1)
19: ldc 0, 333
20: st 0, 0(3)
21: ldc 0, 3
22: ldc 1, 1
23: mul 0, 1, 0
24: add 1, fp, 0
25: lda 3, -57(1)
26: ldc 0, 60
27: st 0, 0(3)
28: ld 0, -8(fp)
29: out 0
30: ldc 0, 10
31: outc 0
32: ld 0, -9(fp)
33: outc 0
34: ldc 0, 10
35: outc 0
36: ldc 0, 7
37: ldc 1, 4
38: mul 0, 1, 0
39: add 1, fp, 0
40: ld 2, -52(1)
41: out 2
42: ldc 0, 10
43: outc 0
44: ldc 0, 3
45: ldc 1, 1
46: mul 0, 1, 0
47: add 1, fp, 0
48: ld 2, -57(1)
49: outc 2
50: ldc 0, 10
51: outc 0
52: ldc 0, 1819043176
53: ldc 1, 0
54: st 0, 0(1)
55: ldc 0, 8559
56: ldc 1, 0
57: st 0, 4(1)
58: ldc 0, 0
59: ldc 1, 0
60: st 0, 8(1)
61: outs 1
62: ldc 0, 10
63: outc 0
64: ldc 27, 0
65: lda sp, 0(fp)
66: ld fp, 0(fp)
67: ld pc, -4(sp)
// ====================
