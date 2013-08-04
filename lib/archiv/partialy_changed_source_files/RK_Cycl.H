// nozicija pazovoi komaNdu v kadpe byP i free-zoNe faila-konii
//    Nomep kaNala (iNfopmacioNNogo slova) kadpa byP/free-zoNu faila-konii
#define RK5       5
#define UKR5      5
#define RK8       8
#define RKO8      8
#define UKR18    18
#define RKO24    24
#define UKR38    38
#define RKO40    40
#define UKR51    51
#define UKR52    52
#define UKR55    55
#define RKO56    56
#define UKR60    60
// nozicija (Nomep pazpjada) pazovoi komaNdu v iNfopmacioNNom slove
// PK caNal 5
#define oPGB  1 // dim v bagajNom otdeleNii
#define iSy   3 // vklucheNie SAy (sistema avtomatich.ynpavleN.) no pylu NanpavleNja
#define oSx   4 // otkaz kaNala kpeNa SAy
#define oSz   5 // otkaz kaNala taNgaja SAy
#define iSx   6 // vklucheNie SAy no kpeny
#define iSz   7 // vklucheNie SAy no taNgajy
#define kOl   8 // POD (pykojatka ostaNova dvigatelja) v nolojeNie STOP levogo dvigatelja
#define kOs   9 // POD v nolojeNie STOP spedNego dvigatelja
#define kOp  10 // POD v nolojeNie STOP npavogo dvigatelja
#define oSM  11 // stpyjka/nepegpev masla dvigatelja
#define iKG  12 // isnpavNost BGMK-6 levogo
#define iRWl 13 // isnpavNost PV-5 levogo
#define oSP  14 // snoilepu NeisnpavNu
#define oG   15 // otkaz tpex geNepatopov
#define oGT  17 // tonlivo 320 kg
#define iPTS 18 // avtomaticheskoe vklucheNie nTS-800
#define iPOS 19 // avtomaticheskoe vklucheNie nOS-1000
#define nPMp 20 // min.davleNie masla Na vxode npavogo dvigatelja
#define nPMl 21 // min.davleNie masla Na vxode levogo dvigatieja
#define nPMs 22 // min.davleNie masla Na vxode spedNego dvigatelja
#define oTN  23 // ybav pejim dvigatelja
#define iWU  24 // vuxod VSy (vsnomogatelNaja silovaja ystaNovka) Na pejim
#define kEOl 25 // nitaNie elektpoklanaNa ostaNova levogo dvigatelja
#define kEOs 26 // nitaNie elektpoklanaNa ostaNova spedNego dvigatelja
#define kEOp 27 // nitaNie elektpoklanaNa ostaNova npavogo dvigatelja
// PK caNal 8
#define vA    0 // prevusheNie npedelNogo ygla ataki
#define vUK   1 // kpeN velik
#define kMM   2 // npolet MPM/ynpavleNie MnS pezepv. g/s
#define oVY   3 // npedynpejdeNie ot SSOS (sistema sigNalizac.onasNogo sblijeNija s zemlei)
#define iVY   4 // vklucheNie SSOS
#define gRSK  5 // gotovNost 1 kaNala zoNu kypsa KPM (kypsovoi padiomajak)
#define gRSG  6 // gotovNost 1 kaNala zoNU glissadu GPM (glissadNui)
#define oVl   8 // onasNaja vibpacija levogo dvigatelja
#define oVs   9 // onasNaja vibpacija spedNego dvigatelja
#define oVp  10 // onasNaja vibpacija npavogo dvigatelja
#define nPTl 11 // malo davleNie tonliva levogo dvigatelja
#define nPTs 12 // malo davleNie tonliva spedNego dvigatelja
#define nPTp 13 // malo davleNie tonliva npavogo dvigatelja
#define iPSP 15 // nepekluchatel SnOILEPU v AVTOMATICH.VUnySK
#define oLND 16 // k nosadke Ne gotov
#define iSP  17 // snoilepu vinyscheNu
#define oGS  18 // otkaz osNovNoi gidposistemu
#define oGSa 19 // otkaz avapijNoi gidposistemu
#define kMST 20 // ynpavleNie MnS ot osNovNoi gidposistemu
#define iGMd 21 // isnpavNost MGV pezepvNoi
#define iAGp 22 // isnpavNost AG npavogo
#define iAGl 23 // isnpavNost AG levogo
#define iRWp 24 // isnpavNost RV-5 npavogo
#define oTR  25 // otkaz kaNala avtotpimmepa
#define oGSZ 26 // vukluchenie gidposistemu npi kpiticheskom ygle passoglasovanija zakpulkov
#define oiSH 27 // vunysk shassi
#define iSH  28 // shassi vunyscheNo
#define oPG  30 // nojap
#define iPS  31 // nOS (npotivoobledeNitelNaja sistema) vklucheNa
// IPK caNal 18
#define IRK1  18
#define pZEM  0 // npizNak zemlja
#define pVOZD 1 // npizNak vozdyx
#define pWZLv 8 // npizNak vzleta vozdyx
// IPK caNal 24
#define IRK2  24
#define pMZv  0 // npizNak zakpulki vunysk
#define pMZu  1 // npizNak zakpulki ybopka
// IPK (sobutie) caNal 51
#define SOB  51
#define S9    0 // pylejNaja massa bolee donystimoi
#define S109  1 // ybopki zakpulkov, vusota < 120 m
#define S110  2 // ybopka zakpulkov, npibopNaja skopost < V3
#define S112  3 // topmojeNie npi ybopke zakpulkov
