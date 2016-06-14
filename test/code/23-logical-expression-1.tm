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
9: lda sp, -8(sp)
10: ldc 0, 10
11: st 0, -8(fp)
12: ldc 0, 20
13: st 0, -12(fp)
14: ld 0, -8(fp)
15: ldc 1, 0
16: gt 2, 0, 1
17: ld 0, -12(fp)
18: ldc 1, 0
19: gt 3, 0, 1
20: ldc 0, 1
21: jgt 2, 2(pc)
22: jgt 3, 1(pc)
23: ldc 0, 0
24: jle 0, 5(pc)
25: ld 0, -8(fp)
26: out 0
27: ldc 0, 10
28: outc 0
29: ld 0, -8(fp)
30: ldc 1, 0
31: lt 2, 0, 1
32: ld 0, -12(fp)
33: ldc 1, 0
34: gt 3, 0, 1
35: ldc 0, 1
36: jgt 2, 2(pc)
37: jgt 3, 1(pc)
38: ldc 0, 0
39: jle 0, 5(pc)
40: ld 0, -8(fp)
41: out 0
42: ldc 0, 10
43: outc 0
44: ld 0, -8(fp)
45: ldc 1, 0
46: lt 2, 0, 1
47: ld 0, -12(fp)
48: ldc 1, 0
49: lt 3, 0, 1
50: ldc 0, 1
51: jgt 2, 2(pc)
52: jgt 3, 1(pc)
53: ldc 0, 0
54: jle 0, 5(pc)
55: ld 0, -8(fp)
56: out 0
57: ldc 0, 10
58: outc 0
59: ldc 27, 0
60: lda sp, 0(fp)
61: ld fp, 0(fp)
62: ld pc, -4(sp)
// ====================
