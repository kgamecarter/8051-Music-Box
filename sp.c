#include <REGX51.H>

#define DO0   0
#define DO0_  1
#define RE0   2
#define RE0_  3
#define MI0   4
#define FA0   5
#define FA0_  6
#define SO0   7
#define SO0_  8
#define LA0   9
#define LA0_ 10
#define SI0  11
#define DO1  12
#define DO1_ 13
#define RE1  14
#define RE1_ 15
#define MI1  16
#define FA1  17
#define FA1_ 18
#define SO1  19
#define SO1_ 20
#define LA1  21
#define LA1_ 22
#define SI1  23
#define DO2  24
#define DO2_ 25
#define RE2  26
#define RE2_ 27
#define MI2  28
#define FA2  29
#define FA2_ 30
#define SO2  31
#define SO2_ 32
#define LA2  33
#define LA2_ 34
#define SI2  35
#define DO3  36
#define DO3_ 37
#define RE3  38
#define RE3_ 39
#define MI3  40
#define FA3  41
#define FA3_ 42
#define SO3  43
#define SO3_ 44
#define LA3  45
#define LA3_ 46
#define SI3  47
#define DO4  48
#define DO4_ 49
#define RE4  50
#define RE4_ 51
#define MI4  52
#define FA4  53
#define FA4_ 54
#define SO4  55
#define SO4_ 56
#define LA4  57
#define LA4_ 58
#define SI4  59
#define DO5  60
#define DO5_ 61
#define RE5  62
#define RE5_ 63
#define MI5  64
#define FA5  65
#define FA5_ 66
#define SO5  67
#define SO5_ 68
#define LA5  69
#define LA5_ 70
#define SI5  71
#define DO6  72
#define DO6_ 73
#define RE6  74
#define RE6_ 75
#define MI6  76
#define FA6  77
#define FA6_ 78
#define SO6  79
#define SO6_ 80
#define LA6  81
#define LA6_ 82
#define SI6  83
#define DO7  84
#define DO7_ 85
#define RE7  86
#define RE7_ 87
#define MI7  88
#define FA7  89
#define FA7_ 90
#define SO7  91
#define SO7_ 92
#define LA7  93
#define LA7_ 94
#define SI7  95
#define DO8  96
#define DO8_ 97
#define RE8  98
#define RE8_ 99

#define RES  0xFF
#define SETTEMPOTIME 0xFD
#define SETSCALEOFFSET 0xFC
#define SETREPERTPOS 0xFB
#define REPERT 0xFA

#define byte unsigned char
#define sbyte signed char
#define uint unsigned int 

code uint scaleTable[] =
{
    0x91E9, 0x9813, 0x9DE8, 0xA374, 0xA89F, 0xAD8B, 0xB225, 0xB688, 0xBAAA, 0xBE8C, 0xC23B, 0xC5B1, 
    0xC8F4, 0xCC0D, 0xCEF8, 0xD1B7, 0xD450, 0xD6C3, 0xD915, 0xDB44, 0xDD53, 0xDF46, 0xE11C, 0xE2D8, 
    0xE47B, 0xE607, 0xE77C, 0xE8DC, 0xEA28, 0xEB62, 0xEC8A, 0xEDA2, 0xEEAA, 0xEFA3, 0xF08E, 0xF16C, 
    0xF23D, 0xF303, 0xF3BE, 0xF46E, 0xF514, 0xF5B1, 0xF645, 0xF6D1, 0xF755, 0xF7D1, 0xF847, 0xF8B6, 
    0xF91F, 0xF982, 0xF9DF, 0xFA37, 0xFA8A, 0xFAD9, 0xFB23, 0xFB68, 0xFBAA, 0xFBE9, 0xFC23, 0xFC5B, 
    0xFC8F, 0xFCC1, 0xFCEF, 0xFD1B, 0xFD45, 0xFD6C, 0xFD91, 0xFDB4, 0xFDD5, 0xFDF4, 0xFE12, 0xFE2D, 
    0xFE48, 0xFE60, 0xFE78, 0xFE8E, 0xFEA3, 0xFEB6, 0xFEC9, 0xFEDA, 0xFEEB, 0xFEFA, 0xFF09, 0xFF17, 
    0xFF24, 0xFF30, 0xFF3C, 0xFF47, 0xFF51, 0xFF5B, 0xFF64, 0xFF6D, 0xFF75, 0xFF7D, 0xFF84, 0xFF8B, 
    0xFF92, 0xFF98, 0xFF9E, 0xFFA3
};                                            

typedef struct _note
{
    byte scale;
    byte tempo;
} Node;

code Node UNowen[] = // U.N.オーエンは彼女なのか？
{
    { SETTEMPOTIME, 100 }, { SETSCALEOFFSET, 0 }, { SETREPERTPOS, 3 },
    { RE6, 1 }, { SI5, 1}, { FA5_, 1}, { RE6, 1 }, { SI5, 1}, { FA5_, 1}, { RE6, 1 }, { SI5, 1}, { FA5_, 1 },
    { RE6, 1 }, { SI5, 1}, { FA5_, 1}, { SETTEMPOTIME, 66 }, { DO6_, 4 }, { DO6_, 4 }, { DO6_, 4 }, { SETTEMPOTIME, 100 },
    { RE6, 1 }, { SI5, 1}, { FA5_, 1}, { RE6, 1 }, { SI5, 1}, { FA5_, 1}, { RE6, 1 }, { SI5, 1 }, { FA5_, 1 },
    { RE6, 1 }, { SI5, 1}, { FA5_, 1}, { SETTEMPOTIME, 66 }, { MI6, 4 }, { MI6, 4 }, { MI6, 4 }, { SETTEMPOTIME, 100 },
    { REPERT, 0 },

    { RE6, 8 }, { DO6_, 8 }, { FA6, 8 }, { MI6, 8 }, { RES, 2 }, { RE6, 2 }, { RES, 2 }, { RE6, 2 }, { RES, 2 }, { DO6_, 2 },
    { RES, 2 }, { DO6_, 2 }, { RES, 2 }, { FA6, 2 }, { RES, 2 }, { FA6, 2 }, { RES, 2 }, { MI6, 2 }, { RES, 2 }, { MI6, 2 },
    { RES, 2 }, { RE6, 2 }, { RES, 2 }, { RE6, 2 }, { RES, 2 }, { DO6_, 2 }, { RES, 2 }, { DO6_, 2 }, { RES, 2 }, { FA6, 2 },
    { RES, 2 }, { FA6, 2 }, { RES, 2 }, { MI6, 2 }, { RES, 2 }, { MI6, 2 }, 

    { FA6_, 4 }, { RE6, 4 }, { FA6, 4 }, { DO6_, 4 }, { SO6_, 4 }, { FA6, 4 }, { MI6, 4 }, { SO6, 4 }, { FA6_, 4 },
    { RE6, 4 }, { FA6, 4 }, { DO6_, 4 }, { SO6_, 4 }, { FA6, 4 }, { MI6, 8 }, { FA6_, 4 }, { RE6, 4 }, { FA6, 4 },
    { DO6_, 4 }, { SO6_, 4 }, { FA6, 4 }, { MI6, 4 }, { SO6, 4 }, { FA6_, 4 }, { RE6, 4 }, { FA6, 4 }, { DO6_, 4 },
     { SO6_, 4 }, { FA6, 4 }, { MI6, 8 }, 

    { SETREPERTPOS, 1 },
    { SI5, 4 }, { FA6_, 4}, { DO6_, 4}, { FA6_, 4}, { RE6, 4 }, { MI6, 2 }, { FA6_, 2 }, { MI6, 4 }, { LA6, 4 },
    { SI6, 2 }, { FA6_, 2 }, { DO7_, 2 }, { RE7, 2 }, { DO7_, 2 }, { RE7, 1 }, { DO7_, 1 }, { SI6, 2 }, { LA6, 2 },
    { FA6_, 2 }, { LA6, 2 }, { MI6, 2 }, { FA6_, 2 }, { RE6,  8 },
    { SI5, 4 }, { FA6_, 4}, { DO6_, 4 }, { FA6_, 4 }, { RE6, 4 }, { MI6, 2 }, { FA6_, 2 }, { MI6, 4 }, { LA6, 4 },
    { SI6, 2 }, { FA6_, 2 }, { DO7_, 2 }, { RE7, 2 }, { DO7_, 2 }, { RE7, 1 }, { DO7_, 1 }, { SI6, 2 }, { LA6, 2 }, { SI6, 16 },
    { REPERT, 0 },

    { SETTEMPOTIME, 66 },
    { SETREPERTPOS, 7 }, { LA6_, 2 }, { FA6, 2 }, { DO6_, 2 }, { REPERT, 0 }, 
    { SETREPERTPOS, 9 }, { LA6_, 2 }, { FA6, 2 }, { RE6, 2 }, { REPERT, 0 }, { LA6_, 2 }, { FA6, 2 }, { DO6, 2}, { LA6_, 2 }, { FA6, 2 }, { DO6, 2 },
    
    { SETTEMPOTIME, 100 }, { FA6, 4}, { SETTEMPOTIME, 66 }, { MI6, 2 }, { FA6, 2 }, { SO6, 2 }, { SETTEMPOTIME, 100 }, { RE6, 6 },
    { LA5, 1 }, { DO6, 1 },  { RE6, 2 }, { LA5, 2 },  { RE6, 2 }, { LA5, 2 }, { MI6, 2 }, { DO6, 2 }, { MI6, 2 }, { DO6, 2 },
    { FA6, 4 }, { SETTEMPOTIME, 66 }, { MI6, 2 }, { FA6, 2 }, { SO6, 2 }, { SETTEMPOTIME, 100 }, { LA6, 6 }, { FA6, 1 }, { SO6, 1},
    { SETTEMPOTIME, 66 },  { LA6_, 2 }, { FA6, 2 }, { RE6, 2 }, { LA6_, 2 }, { FA6, 2 }, { RE6, 2 }, { LA6_, 2 }, { FA6, 2 }, { DO6, 2 }, { LA6_, 2 }, { FA6, 2 }, { DO6, 2 },
    { SETTEMPOTIME, 100 }, { FA6, 4}, { SETTEMPOTIME, 66 }, { MI6, 2 }, { FA6, 2 }, { SO6, 2 }, { SETTEMPOTIME, 100 }, { RE6, 6 },
    { LA5, 1 }, { DO6, 1 },  { RE6, 2 }, { LA5, 2 },  { RE6, 2 }, { LA5, 2 }, { MI6, 2 }, { DO6, 2 }, { MI6, 2 }, { DO6, 2 },
    { FA6, 2 }, { DO6_, 2 }, { FA6, 2 }, { DO6_, 2 }, { SETTEMPOTIME, 66 }, { LA6, 4 }, { LA6, 4 }, { LA6, 4 }, { SETTEMPOTIME, 100 },  


    { SETREPERTPOS, 1 }, { RE5, 8 }, { DO5_, 8 }, { FA5, 8 }, { MI5, 8}, { REPERT, 0 }, 

    { FA6_, 4 }, { RE6, 4 }, { FA6, 4 }, { DO6_, 4 }, { SO6_, 4 }, { FA6, 4 }, { MI6, 4 }, { SO6, 4 }, { FA6_, 4 }, { RE6, 4 },
    { FA6, 4 }, { DO6_, 4 }, { SO6_, 4 }, { FA6, 4 }, { MI6, 8 }, { FA6_, 4 }, { RE6, 4 }, { FA6, 4 }, { DO6_, 4 }, { SO6_, 4 },
    { FA6, 4 }, { MI6, 4 }, { SO6, 4 }, { FA6_, 4 }, { RE6, 4 }, { FA6, 4 }, { DO6_, 4 }, { SO6_, 4 }, { FA6, 4 }, { MI6, 8 }, 
    { RES, 8 },
    { SI5, 4 }, { FA6_, 4 }, { DO6_, 4 }, { FA6_, 4 }, { RE6, 4 }, { MI6, 2 }, { FA6_, 2 }, { MI6, 4 }, { LA6, 4 }, { SI6, 2 },{ FA6_, 2 },
    { DO7_, 2 }, { RE7, 2 }, { DO7_, 2 }, { RE7, 1 }, { DO7_, 1 }, { SI6, 2 }, { LA6, 2 }, { FA6_, 2 }, { LA6, 2 }, { MI6, 2 }, { FA6_, 2 }, { RE6,  8},
    { SI5, 4 }, { FA6_, 4 }, { DO6_, 4 }, { FA6_, 4 }, { RE6, 4 }, { MI6, 2 }, { FA6_, 2 }, { MI6, 4 }, { LA6, 4 }, { SI6, 2 }, { FA6_, 2 },
    { DO7_, 2 }, { RE7, 2 }, { DO7_, 2}, { RE7, 1}, { DO7_, 1}, { SI6, 2 }, { LA6, 2 }, { SI6, 16 },
    { SI5, 4 }, { FA6_, 4 }, { DO6_, 4 }, { FA6_, 4 }, { RE6, 4 }, { MI6, 2 }, { FA6_, 2 }, { MI6, 4 }, { LA6, 4 }, { SI6, 2 },{ FA6_, 2 },
    { DO7_, 2 }, { RE7, 2 }, { DO7_, 2 }, { RE7, 1 }, { DO7_, 1 }, { SI6, 2 }, { LA6, 2 }, { FA6_, 2 }, { LA6, 2 }, { MI6, 2 }, { FA6_, 2 }, { RE6,  8},
    { SI5, 4 }, { FA6_, 4 }, { DO6_, 4 }, { FA6_, 4 }, { RE6, 4 }, { MI6, 2 }, { FA6_, 2 }, { MI6, 4 }, { LA6, 4 }, { SI6, 2 }, { FA6_, 2 },
    { DO7_, 2 }, { RE7, 2 }, { DO7_, 2}, { RE7, 1}, { DO7_, 1}, { SI6, 2 }, { LA6, 2 }, { SI6, 32 },
    {0xFE, 0xFE}
}, suimu[] = // 萃夢想
{
    { SETTEMPOTIME, 150 },
    { MI6, 2 }, { FA6_, 2}, { LA6, 2 }, { SI6, 2}, { FA6_, 2}, { MI6, 2}, { FA6_, 2 }, { SI5, 2}, { RE6, 2}, { MI6, 2},
    { DO6_, 2 }, { RE6, 2 }, { DO6_, 2 }, { LA5, 2 }, { SI5, 2 }, { FA5_, 2 }, { RE6, 2 }, { MI6, 2}, { FA6_, 4 }, { SI5, 2},
    { FA6_, 2 }, { SETTEMPOTIME, 188 }, { MI6, 2 }, { RE6, 2 }, { SETTEMPOTIME, 250 }, { DO6_, 4 }, { SETTEMPOTIME, 125 }, { SI5, 32 },
    
    { SI4, 3 }, { SI4, 1 }, { SI4, 2 }, { LA4, 2}, { SI4, 3 }, { SI4, 1 }, { SI4, 2 }, { LA4, 2}, { SI4, 3 }, { SI4, 1 }, { SI4, 2 }, { LA4, 2}, { SI4, 6},
    { SI5, 2 }, { DO6_, 2 }, { RE6, 6 }, { FA6_, 2 }, { MI6, 2 }, { RE6, 2 }, { DO6_, 2 }, { MI6, 2 }, { SI5, 6 }, { DO6_, 2 },
    { RE6, 6 }, { SI5, 2 }, { MI6, 6 }, { RE6, 2 }, { MI6, 2 }, { MI6, 1}, { RE6, 1 }, { MI6, 2 }, { FA6_, 2 }, { FA6_, 6 }, { MI6, 2 }, { FA6_, 4 },
    { SI5, 2 }, { DO6_, 2 }, { RE6, 6 }, { FA6_, 2 }, { MI6, 2 }, { RE6, 2 }, { MI6, 2 }, { FA6_, 2 }, { LA6, 6 }, { SI6, 2 },
    { RE6, 6 }, { SI5, 2 }, { DO6_, 6 }, { SI5, 2 }, { DO6_, 2 }, { RE6, 2 }, { MI6, 2 }, { DO6_, 2 }, { DO6_, 6 }, { RE6, 1 }, { DO6_, 1 }, { SI5, 4 }, 
        

    {0xFE, 0xFE}
}, mahou[] = // 魔法少女達の百年祭
{
    { SETTEMPOTIME, 100 },
    { RE7, 2 }, { LA6, 2 }, { DO7, 2 }, { SO6, 2 }, { LA6, 2 }, { FA6, 2 }, { SO6, 2 }, { MI6, 2 }, { FA6, 2 }, { RE6, 2 }, { MI6, 2 }, { DO6, 2 },
    { RE6, 2 }, { LA5, 2 }, { DO6, 2 }, { SO5, 2 }, { RE7, 2 }, { LA6, 2 }, { DO7, 2 }, { SO6, 2 }, { LA6, 2 }, { FA6, 2 }, { SO6, 2 }, { MI6, 2 },
    { FA6, 2 }, { RE6, 2 }, { MI6, 2 }, { DO6, 2 }, { RE6, 2 }, { LA5, 2 }, { DO6, 2 }, { SO5, 2 },
    { LA5, 6 }, { FA6, 16 }, { DO7, 6 }, { LA6_/**/, 4 }, { LA6, 32 },
    {0xFE, 0xFE}
};

union
{
    uint u16;
    byte u8[2];
} hfreq;

void delay(uint time)  // 延時函數, 用計時器1
{
    if (time == 0)
        return;
    time = 65536 - time;
    TL1 = time;
    TH1 = time >> 8;
    TF1 = 0;
    TR1 = 1;
    while (TF1 == 0);
    TR1 = 0;
}

void delayms(uint time)  //延時函數
{
    while (time-- > 0)
        delay(900);    // 11.0592每ms約921.6
}

void T0_int(void) interrupt 1  //計時0中斷函數
{                           
    TH0 = hfreq.u8[0];
    TL0 = hfreq.u8[1]; //重新存入計時值
    P2_7 = !P2_7;      //P3.7反相輸出，令喇叭發出聲音
}

#define DELAYTIME 5
void Play(Node* ptrNode)
{
    byte tempoTime = 150, repeatTime;
    Node* repeatPos;
    sbyte scaleOffset = 0; // 移調變數
    for (; ptrNode->tempo != 0xFE; ptrNode++)
    {
        byte tempo;
        switch (ptrNode->scale)
        {
        case SETTEMPOTIME: // 設定節拍時間
            tempoTime = ptrNode->tempo;
            continue;
        case SETSCALEOFFSET: // 設定移調
            scaleOffset = ptrNode->tempo;
            continue;
        case SETREPERTPOS: // 設置反覆起點, 反覆次數
            repeatPos = ptrNode;
            repeatTime =  ptrNode->tempo;
            continue;
        case REPERT: // 反覆終點
            if (repeatTime--) // 反覆次數0前跳回反覆起點
                ptrNode = repeatPos;
            continue;
        case RES: // 休止符
            break;
        default: // 普通音符
            hfreq.u16 = scaleTable[(sbyte)ptrNode->scale + scaleOffset];
            TR0 = 1;
            break;
        }
        for (tempo = ptrNode->tempo - 1; tempo > 0; tempo--) // (延遲節拍長度-1) *  節拍時間
            delayms(tempoTime);
        delayms(tempoTime - DELAYTIME); // 保留DELAYTIME ms作為節拍間隔
        TR0 = 0;
        P2_7 = 1;
        delayms(DELAYTIME); // 節拍間隔
    }
}

void main()
{
    IE = 0x82;   //致能計時0中斷
    TMOD = 0x11; //設定計時0,1的MODE1工作
    while (1)    //重覆執行
    {
        if (P3_0 == 0)
            Play(UNowen);
        if (P3_1 == 0)
            Play(suimu);
        if (P3_2 == 0)
            Play(mahou);
    }
}