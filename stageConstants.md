
```
stageEdit.bin declarations

ext = Number of blocks extended on the element
ext: 0x03 = +1 block space to top and bottom; 0x02 = +1 block space to both sides and top; 0x05 = +1 block space to top

Unlock: 0x00 = Default(unlocked); 0x01 = Stage Builder Parts A; 0x02 = Stage Builder Parts B; 0x03 = Stage Builder Parts C

*_Used = 0 if size is not used, 1 if it is used.

*_X/*_Y = number of blocks for the element

*_LIMIT = The amount added before the stage builder decides you can't place any more blocks. Total must equal less or equal to 8000.

	ID	Name				Unlock	LR	S_Y	S_X	ext	Flip	M_Used	M_Y	M_X	L_Used	L_Y	L_X	S_LIMIT	M_LIMIT	L_LIMIT

0	a	NATURE_BASIC_01L             	0	0	1	1	0	b	1	1	2	1	1	3	64	86	a8	
1	b	NATURE_BASIC_01R                0	1	1	1	0	a	1	1	2	1	1	3	64	86	a8	
2	14	NATURE_BASIC_02L                0	0	1	1	5	15	1	1	2	1	1	3	86	ca	10e	
3	15	NATURE_BASIC_02R                0	1	1	1	5	14	1	1	2	1	1	3	86	ca	10e	
4	1e	NATURE_BASIC_03L                0	0	1	1	0	1f	1	1	2	1	1	3	64	86	a8	
5	1f	NATURE_BASIC_03R                0	1	1	1	0	1e	1	1	2	1	1	3	64	86	a8	
6	32	NATURE_BASIC_05L                0	0	1	1	0	33	1	2	2	1	3	3	64	ca	174	
7	33	NATURE_BASIC_05R                0	1	1	1	0	32	1	2	2	1	3	3	64	ca	174		
8	3c	NATURE_BASIC_06L                0	0	1	1	5	3d	1	1	2	1	1	3	86	ca	10e		
9	3d	NATURE_BASIC_06R                0	1	1	1	5	3c	1	1	2	1	1	3	86	ca	10e		
a	46	NATURE_BASIC_07L                0	0	1	1	5	47	1	2	2	1	3	3	86	10e	1da		
b	47	NATURE_BASIC_07R                0	1	1	1	5	46	1	2	2	1	3	3	86	10e	1da		
c	5a	NATURE_BASIC_09L                0	0	1	2	5	5b	1	1	3	1	1	4	ca	10e	152		
d	5b	NATURE_BASIC_09R                0	1	1	2	5	5a	1	1	3	1	1	4	ca	10e	152		

e	2d0	NATURE_FIX_02L                  0	0	1	2	2	2d1	1	1	3	1	2	4	152	196	2a6		
f	2d1	NATURE_FIX_02R                  0	1	1	2	2	2d0	1	1	3	1	2	4	152	196	2a6		
10	2da	NATURE_FIX_03L                  0	0	1	1	2	2db	1	2	2	1	3	3	10e	1da	2ea		
11	2db	NATURE_FIX_03R                  0	1	1	1	2	2da	1	2	2	1	3	3	10e	1da	2ea		
12	2e4	NATURE_FIX_04L                  0	0	2	2	2	2e5	1	3	3	1	4	4	1da	2ea	43e		
13	2e5	NATURE_FIX_04R                  0	1	2	2	2	2e4	1	3	3	1	4	4	1da	2ea	43e	
14	30c	NATURE_FIX_08L                  0	0	2	2	2	30d	1	3	3	1	4	4	1da	2ea	43e	
15	30d	NATURE_FIX_08R                  0	1	2	2	2	30c	1	3	3	1	4	4	1da	2ea	43e		
16	320	NATURE_FIX_10L                  0	0	2	2	2	321	1	3	3	1	4	4	1da	2ea	43e		
17	321	NATURE_FIX_10R                  0	1	2	2	2	320	1	3	3	1	4	4	1da	2ea	43e		
18	32a	NATURE_FIX_11L                  1	0	1	2	2	32b	1	2	3	1	3	4	152	240	372		
19	32b	NATURE_FIX_11R                  1	1	1	2	2	32a	1	2	3	1	3	4	152	240	372		
1a	334	NATURE_FIX_12L                  2	0	2	2	2	335	1	3	3	1	4	4	1da	2ea	43e		
1b	335	NATURE_FIX_12R                  2	1	2	2	2	334	1	3	3	1	4	4	1da	2ea	43e		
1c	33e	NATURE_FIX_13L                  3	0	2	1	2	33f	1	3	2	1	4	3	174	262	394	
1d	33f	NATURE_FIX_13R                  3	1	2	1	2	33e	1	3	2	1	4	3	174	262	394		

1e	38e	GIMMICK_01L                     0	0	3	1	3	38f	1	4	2	1	5	3	ec	1da	30c	
1f	38f	GIMMICK_01R                     0	1	3	1	3	38e	1	4	2	1	5	3	ec	1da	30c		
20	398	GIMMICK_02L                     0	0	1	3	0	399	1	1	4	1	1	5	a8	ca	ec		
21	399	GIMMICK_02R                     0	1	1	3	0	398	1	1	4	1	1	5	a8	ca	ec		
22	3a2	GIMMICK_03L                     3	0	4	4	5	3a3	1	5	5	1	6	6	2ea	43e	5d6		
23	3a3	GIMMICK_03R                     3	1	4	4	5	3a2	1	5	5	1	6	6	2ea	43e	5d6		
24	3ac	GIMMICK_04L                     1	0	1	1	5	3ad	1	1	2	1	1	3	86	ca	10e		
25	3ad	GIMMICK_04R                     1	1	1	1	5	3ac	1	1	2	1	1	3	86	ca	10e		
26	3b6	GIMMICK_05L                     0	0	1	1	0	3b7	1	1	2	1	1	3	64	86	a8		
27	3b7	GIMMICK_05R                     0	1	1	1	0	3b6	1	1	2	1	1	3	64	86	a8		
28	3c0	GIMMICK_06L                     0	0	1	1	3	3c1	1	2	2	1	3	3	a8	152	240		
29	3c1	GIMMICK_06R                     0	1	1	1	3	3c0	1	2	2	1	3	3	a8	152	240		
2a	3ca	GIMMICK_07L                     2	0	1	2	5	3cb	1	1	3	1	1	4	10e	152	174		
2b	3cb	GIMMICK_07R                     2	1	1	2	5	3ca	1	1	3	1	1	4	10e	152	174		
2c	3d4	GIMMICK_08L                     0	0	1	1	5	3d5	1	1	2	1	1	3	86	ca	10e		
2d	3d5	GIMMICK_08R                     0	1	1	1	5	3d4	1	1	2	1	1	3	86	ca	10e		
2e	3de	GIMMICK_09L                     0	0	1	1	0	3df	0	0	0	0	0	0	64	0	0		
2f	3df	GIMMICK_09R                     0	1	1	1	0	3de	0	0	0	0	0	0	64	0	0		

30	3f2	FACTORY_BASIC_01L               0	0	1	1	0	3f3	1	1	2	1	1	3	64	86	a8		
31	3f3	FACTORY_BASIC_01R               0	1	1	1	0	3f2	1	1	2	1	1	3	64	86	a8		
32	3fc	FACTORY_BASIC_02L               0	0	1	1	5	3fd	1	1	2	1	1	3	86	ca	10e		
33	3fd	FACTORY_BASIC_02R               0	1	1	1	5	3fc	1	1	2	1	1	3	86	ca	10e		
34	406	FACTORY_BASIC_03L               0	0	1	1	0	407	1	1	2	1	1	3	64	86	a8		
35	407	FACTORY_BASIC_03R               0	1	1	1	0	406	1	1	2	1	1	3	64	86	a8		
36	41a	FACTORY_BASIC_05L               0	0	1	1	0	41b	1	2	2	1	3	3	64	ca	174		
37	41b	FACTORY_BASIC_05R               0	1	1	1	0	41a	1	2	2	1	3	3	64	ca	174		
38	424	FACTORY_BASIC_06L               0	0	1	1	5	425	1	1	2	1	1	3	86	ca	10e		
39	425	FACTORY_BASIC_06R               0	1	1	1	5	424	1	1	2	1	1	3	86	ca	10e		
3a	42e	FACTORY_BASIC_07L               0	0	1	1	5	42f	1	2	2	1	3	3	86	10e	1da		
3b	42f	FACTORY_BASIC_07R               0	1	1	1	5	42e	1	2	2	1	3	3	86	10e	1da		
3c	442	FACTORY_BASIC_09L               0	0	1	2	5	443	1	1	3	1	1	4	ca	10e	152		
3d	443	FACTORY_BASIC_09R               0	1	1	2	5	442	1	1	3	1	1	4	ca	10e	152		

3e	6b8	FACTORY_FIX_02L                 0	0	1	2	2	6b9	1	1	3	1	2	4	152	196	2a6		
3f	6b9	FACTORY_FIX_02R                 0	1	1	2	2	6b8	1	1	3	1	2	4	152	196	2a6		
40	6c2	FACTORY_FIX_03L                 0	0	2	2	2	6c3	1	3	3	1	4	4	1da	2ea	43e		
41	6c3	FACTORY_FIX_03R                 0	1	2	2	2	6c2	1	3	3	1	4	4	1da	2ea	43e		
42	6cc	FACTORY_FIX_04L                 0	0	1	2	2	6cd	1	1	3	1	2	4	152	196	2a6		
43	6cd	FACTORY_FIX_04R                 0	1	1	2	2	6cc	1	1	3	1	2	4	152	196	2a6		
44	6e0	FACTORY_FIX_06L                 0	0	1	1	2	6e1	1	2	2	1	3	3	10e	1da	2ea		
45	6e1	FACTORY_FIX_06R                 0	1	1	1	2	6e0	1	2	2	1	3	3	10e	1da	2ea		
46	6f4	FACTORY_FIX_08L                 0	0	1	2	2	6f5	1	1	3	1	2	4	152	196	2a6		
47	6f5	FACTORY_FIX_08R                 0	1	1	2	2	6f4	1	1	3	1	2	4	152	196	2a6		
48	6fe	FACTORY_FIX_09L                 1	0	2	2	2	6ff	1	3	3	1	4	4	1da	2ea	43e		
49	6ff	FACTORY_FIX_09R                 1	1	2	2	2	6fe	1	3	3	1	4	4	1da	2ea	43e		
4a	71c	FACTORY_FIX_12L                 2	0	2	1	2	71d	1	3	2	1	4	2	174	262	2ea		
4b	71d	FACTORY_FIX_12R                 2	1	2	1	2	71c	1	3	2	1	4	2	174	262	2ea		
4c	726	FACTORY_FIX_13L                 3	0	1	2	2	727	1	2	3	1	2	4	152	240	2a6		
4d	727	FACTORY_FIX_13R                 3	1	1	2	2	726	1	2	3	1	2	4	152	240	2a6		

4e	7da	REMAINS_BASIC_01L               0	0	1	1	0	7db	1	1	2	1	1	3	64	86	a8		
4f	7db	REMAINS_BASIC_01R               0	1	1	1	0	7da	1	1	2	1	1	3	64	86	a8		
50	7e4	REMAINS_BASIC_02L               0	0	1	1	5	7e5	1	1	2	1	1	3	86	ca	10e		
51	7e5	REMAINS_BASIC_02R               0	1	1	1	5	7e4	1	1	2	1	1	3	86	ca	10e		
52	7ee	REMAINS_BASIC_03L               0	0	1	1	0	7ef	1	1	2	1	1	3	64	86	a8		
53	7ef	REMAINS_BASIC_03R               0	1	1	1	0	7ee	1	1	2	1	1	3	64	86	a8		
54	802	REMAINS_BASIC_05L               0	0	1	1	0	803	1	2	2	1	3	3	64	ca	174		
55	803	REMAINS_BASIC_05R               0	1	1	1	0	802	1	2	2	1	3	3	64	ca	174		
56	80c	REMAINS_BASIC_06L               0	0	1	1	5	80d	1	1	2	1	1	3	86	ca	10e		
57	80d	REMAINS_BASIC_06R               0	1	1	1	5	80c	1	1	2	1	1	3	86	ca	10e		
58	816	REMAINS_BASIC_07L               0	0	1	1	5	817	1	2	2	1	3	3	86	10e	1da		
59	817	REMAINS_BASIC_07R               0	1	1	1	5	816	1	2	2	1	3	3	86	10e	1da		
5a	82a	REMAINS_BASIC_09L               0	0	1	2	5	82b	1	1	3	1	1	4	ca	10e	152		
5b	82b	REMAINS_BASIC_09R               0	1	1	2	5	82a	1	1	3	1	1	4	ca	10e	152		

5c	aa0	REMAINS_FIX_02L                 0	0	2	1	2	aa1	1	3	2	1	4	3	174	262	394		
5d	aa1	REMAINS_FIX_02R                 0	1	2	1	2	aa0	1	3	2	1	4	3	174	262	394		
5e	ab4	REMAINS_FIX_04L                 0	0	1	2	2	ab5	1	1	3	1	2	4	152	196	2a6		
5f	ab5	REMAINS_FIX_04R                 0	1	1	2	2	ab4	1	1	3	1	2	4	152	196	2a6		
60	abe	REMAINS_FIX_05L                 0	0	2	2	2	abf	1	3	3	1	4	4	1da	2ea	43e		
61	abf	REMAINS_FIX_05R                 0	1	2	2	2	abe	1	3	3	1	4	4	1da	2ea	43e		
62	ac8	REMAINS_FIX_06L                 0	0	1	2	2	ac9	1	1	3	1	2	4	152	196	2a6		
63	ac9	REMAINS_FIX_06R                 0	1	1	2	2	ac8	1	1	3	1	2	4	152	196	2a6		
64	adc	REMAINS_FIX_08L                 0	0	1	2	2	add	1	1	3	1	2	4	152	196	2a6		
65	add	REMAINS_FIX_08R                 0	1	1	2	2	adc	1	1	3	1	2	4	152	196	2a6		
66	ae6	REMAINS_FIX_09L                 1	0	2	2	2	ae7	1	3	3	1	4	4	1da	2ea	43e		
67	ae7	REMAINS_FIX_09R                 1	1	2	2	2	ae6	1	3	3	1	4	4	1da	2ea	43e		
68	afa	REMAINS_FIX_11L                 2	0	2	2	2	afb	1	3	3	1	4	4	1da	2ea	43e		
69	afb	REMAINS_FIX_11R                 2	1	2	2	2	afa	1	3	3	1	4	4	1da	2ea	43e		
6a	b04	REMAINS_FIX_12L                 3	0	2	2	2	b05	1	3	3	1	4	4	1da	2ea	43e		
6b	b05	REMAINS_FIX_12R                 3	1	2	2	2	b04	1	3	3	1	4	4	1da	2ea	43e		
```