# 8051-Music-Box
單晶片系統實作作業二 音樂盒

## 題目
請設計一個音樂盒，可以按照以下方式運作： KEY 0為啟動/暫停按鈕，按下Key 1播放第1首歌曲，按下Key 2播放第2首歌曲，按下Key 3播放第3首歌曲。請自行選擇歌曲。

## 解題摘要
使用計時器來計算辦週期的長度，時間到就改變蜂鳴器的電位來達到音階的變化，因為我的樂譜音域很廣，所以我建立了一張完整的音樂頻率表給樂譜使用，方便完成我的音樂。然後使用定義符號DO, RE, MI來對應音階表，使樂譜更又可讀性。

公式: TH:TL = 11.0592 * 1000000 / Freq.Hz / 2

MidiCo   |Note   |Freq.Hz |TH:TL 
---------|--------|---------|------
0  |C0  |16.35 |0x91E9
1  |C#0/Db0  |17.32 |0x9813
2  |D0  |18.35 |0x9DE8
3  |D#0/Eb0  |19.45 |0xA374
4  |E0  |20.6 |0xA89F
5  |F0  |21.83 |0xAD8B
6  |F#0/Gb0  |23.12 |0xB225
7  |G0  |24.5 |0xB688
8  |G#0/Ab0  |25.96 |0xBAAA
9  |A0  |27.5 |0xBE8C
10 |A#0/Bb0  |29.14 |0xC23B
11 |B0  |30.87 |0xC5B1
12 |C1  |32.7 |0xC8F4
13 |C#1/Db1  |34.65 |0xCC0D
14 |D1  |36.71 |0xCEF8
15 |D#1/Eb1  |38.89 |0xD1B7
16 |E1  |41.2 |0xD450
17 |F1  |43.65 |0xD6C3
18 |F#1/Gb1  |46.25 |0xD915
19 |G1  |49 |0xDB44
20 |G#1/Ab1  |51.91 |0xDD53
21 |A1  |55 |0xDF46
22 |A#1/Bb1  |58.27 |0xE11C
23 |B1  |61.74 |0xE2D8
24 |C2  |65.41 |0xE47B
25 |C#2/Db2  |69.3 |0xE607
26 |D2  |73.42 |0xE77C
27 |D#2/Eb2  |77.78 |0xE8DC
28 |E2  |82.41 |0xEA28
29 |F2  |87.31 |0xEB62
30 |F#2/Gb2  |92.5 |0xEC8A
31 |G2  |98 |0xEDA2
32 |G#2/Ab2  |103.83 |0xEEAA
33 |A2  |110 |0xEFA3
34 |A#2/Bb2  |116.54 |0xF08E
35 |B2  |123.47 |0xF16C
36 |C3  |130.81 |0xF23D
37 |C#3/Db3  |138.59 |0xF303
38 |D3  |146.83 |0xF3BE
39 |D#3/Eb3  |155.56 |0xF46E
40 |E3  |164.81 |0xF514
41 |F3  |174.61 |0xF5B1
42 |F#3/Gb3  |185 |0xF645
43 |G3  |196 |0xF6D1
44 |G#3/Ab3  |207.65 |0xF755
45 |A3  |220 |0xF7D1
46 |A#3/Bb3  |233.08 |0xF847
47 |B3  |246.94 |0xF8B6
48 |C4  |261.63 |0xF91F
49 |C#4/Db4  |277.18 |0xF982
50 |D4  |293.66 |0xF9DF
51 |D#4/Eb4  |311.13 |0xFA37
52 |E4  |329.63 |0xFA8A
53 |F4  |349.23 |0xFAD9
54 |F#4/Gb4  |369.99 |0xFB23
55 |G4  |392 |0xFB68
56 |G#4/Ab4  |415.3 |0xFBAA
57 |A4  |440 |0xFBE9
58 |A#4/Bb4  |466.16 |0xFC23
59 |B4  |493.88 |0xFC5B
60 |C5  |523.25 |0xFC8F
61 |C#5/Db5  |554.37 |0xFCC1
62 |D5  |587.33 |0xFCEF
63 |D#5/Eb5  |622.25 |0xFD1B
64 |E5  |659.26 |0xFD45
65 |F5  |698.46 |0xFD6C
66 |F#5/Gb5  |739.99 |0xFD91
67 |G5  |783.99 |0xFDB4
68 |G#5/Ab5  |830.61 |0xFDD5
69 |A5  |880 |0xFDF4
70 |A#5/Bb5  |932.33 |0xFE12
71 |B5  |987.77 |0xFE2D
72 |C6  |1046.5 |0xFE48
73 |C#6/Db6  |1108.73 |0xFE60
74 |D6  |1174.66 |0xFE78
75 |D#6/Eb6  |1244.51 |0xFE8E
76 |E6  |1318.51 |0xFEA3
77 |F6  |1396.91 |0xFEB6
78 |F#6/Gb6  |1479.98 |0xFEC9
79 |G6  |1567.98 |0xFEDA
80 |G#6/Ab6  |1661.22 |0xFEEB
81 |A6  |1760 |0xFEFA
82 |A#6/Bb6  |1864.66 |0xFF09
83 |B6  |1975.53 |0xFF17
84 |C7  |2093 |0xFF24
85 |C#7/Db7  |2217.46 |0xFF30
86 |D7  |2349.32 |0xFF3C
87 |D#7/Eb7  |2489.02 |0xFF47
88 |E7  |2637.02 |0xFF51
89 |F7  |2793.83 |0xFF5B
90 |F#7/Gb7  |2959.96 |0xFF64
91 |G7  |3135.96 |0xFF6D
92 |G#7/Ab7  |3322.44 |0xFF75
93 |A7  |3520 |0xFF7D
94 |A#7/Bb7  |3729.31 |0xFF84
95 |B7  |3951.07 |0xFF8B
96 |C8  |4186.01 |0xFF92
97 |C#8/Db8  |4434.92 |0xFF98
98 |D8  |4698.64 |0xFF9E
99 |D#8/Eb8  |4978.03 |0xFFA3

## 流程圖

## 成果展示
[![](http://img.youtube.com/vi/J6hVnez536Y/0.jpg)](http://www.youtube.com/watch?v=J6hVnez536Y "")

## 心得
 音樂盒的構造是以8051外加一個喇叭(或蜂鳴器) ，利用8051的程式來產生頻率，送至輸出阜(喇叭或蜂鳴器)。但是課本的程式碼寫得有夠難看，還用了goto，一整個不知所云，所以整個砍掉重寫，還加入了移調功能，動態拍速功能，甚至還加入了反覆記號來節省樂譜所佔用了記憶體空間，使程式碼看起來更有可讀性。音樂部分使用了我最喜歡的東方Project系列，希望各位會喜歡。