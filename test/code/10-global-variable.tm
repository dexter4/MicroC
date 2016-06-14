// ====================
// c startup
// ====================
0: ld gp, 0(0)
1: st 0, 0(0)
2: lda fp, -16(gp)
3: lda sp, -16(gp)
4: push fp
5: lda 0, 2(pc)
6: push 0
7: ldc pc, 9
8: halt
// ====================
// main()
// ====================
9: lda sp, -0(sp)
10: ldc 0, 97
11: stb 0,  +3(gp)
12: ldc 0, 65
13: stb 0,  +2(gp)
14: ldc 0, 333
15: st 0, -4(gp)
16: ldc 0, 444
17: st 0, -8(gp)
18: ldc 0, 99
19: stb 0, -9(gp)
20: ld 0,  +3(gp)
21: outc 0
22: ldc 0, 10
23: outc 0
24: ld 0,  +2(gp)
25: outc 0
26: ldc 0, 10
27: outc 0
28: ld 0, -4(gp)
29: out 0
30: ldc 0, 10
31: outc 0
32: ld 0, -8(gp)
33: out 0
34: ldc 0, 10
35: outc 0
36: ld 0, -9(gp)
37: outc 0
38: ldc 0, 10
39: outc 0
40: ldc 27, 0
41: lda sp, 0(fp)
42: ld fp, 0(fp)
43: ld pc, -4(sp)
// ====================
