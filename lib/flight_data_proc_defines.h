// Flight data processing defines
// original, reorganized by B-GangsteR 2013.03.29

//--- Typ_Par.H-------
// tin napametpa
#define TYP_SLUGEB 0   // slugebNiy napametp
#define TYP_AP     1   // aNalogoviy napametp
#define TYP_APR    2   // aNalogoviy napametp paschetNy
#define TYP_RKD    3   // pazovaja komaNda osNovNaja (dvoichNaja)
#define TYP_RKA    4   // pazovaja komaNda aNalogovaja
#define TYP_RKR    5   // pazovaja komaNda iskustveNNaja (paschetNaja)
//--- Typ_Par.H-------

//----SST_FK.H--------
// onisaNie bitov slova sostojaNia faila-konii
#define AFK_INP        01  // atpibytu faila-konii (01)
#define OD_INP         02  // onozNavatelNue daNNue (03)
#define APOL_INP       04  // atpibytu noleta (07)
#define FRM_BP        010  // PK modificipovaNNue (017)
#define FIZ_AP        020  // An npeobpazovaNue iz koda v fiziky (037)
#define FRM_CP_1     0100  // sfopmipovaNu paschetNue An, npohod 1
#define FRM_CP_2     0200  // sfopmipovaNu paschetNue An, npohod 2
#define FRM_CP_3     0400  // sfopmipovaNu paschetNue An, npohod 3
#define FRM_IRK_1   01000  // sfopmipovaNu paschetNue PK, npohod 1
#define FRM_IRK_2   02000  // sfopmipovaNu paschetNue PK, npohod 2
#define FRM_IRK_3   04000  // sfopmipovaNu paschetNue PK, npohod 3
#define FRM_SB     010000  // sfopmipovaNu sobutija
//----SST_FK.H--------


//----SPB_Zone.H--------
// Nachalo zonu opisania v sunepbloke:   (13.01.13)
#define POZ_SPB        0l // atpibutu faila-kopii
#define POZ_OD        12l // onozNavatelnue daNNue
#define POZ_SZSPB     96l // pazmepa synepbloka
#define POZ_APOL     100l // atpibutu noleta
//----SPB_Zone.H--------


//----SIZE_DEF.H--------
// size_def.h - pazmepu (bait):      (13.01.13)
#define DL_SKD     10             // dliNa subkadpa (kadpu)
//----SIZE_DEF.H--------


//----RK_Cycl.H--------
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
//----RK_Cycl.H--------



//----OD_lim.H--------
// OD_lim.cpp - gpaNicu atpibytov onozNavatelNux daNNux
#define MIN_TIME       0	// vremja
#define MAX_HOUR      24  // chasu
#define MAX_MIN       60  // miNytu
#define MAX_SEC       60  // sekyNdu
#define MIN_DATE       1	// data
#define MAX_DATE      31  //
#define MIN_MONTH      1	// mesjac
#define MAX_MONTH     12	//
#define MIN_YEAR    1960	// god
#define MAX_YEAR    2013	//
#define MIN_REIS       1	// N peisa
#define MAX_REIS    9999	//
#define MIN_BORT       1	// N bopta
#define MAX_BORT   99999	//
//----OD_lim.H--------


//----N_error.H--------
//N_error.h - Nomep oshibki npi pabote npogpammu (13.01.12)																	 // Oshibka:
#define E_OPEN_BASE            0
#define E_OPEN_FK             (E_OPEN_BASE   + 1)   // otkputia faila-kopii (OpenFK)
#define E_OPEN_CYCL           (E_OPEN_BASE   + 2)   // otkputia faila ciklogpammu (ReadCyclogram)

#define E_MEM_BASE            10                    // vudeleNia namjati
#define E_MEM_BUFKADR         (E_MEM_BASE)          // vudeleNia namjati nod byfep kadpa faila-konii (main)
#define E_MEM_MASCODPAR       (E_MEM_BASE + 1)      // vudeleNia namjati Na massiv kodov vizyalizipyemogo napametpa (PrintParam)

#define E_ATR_FK_BASE         20                       // npogpamma - ReadAtrFK
#define E_ATR_FK_POZSPB       (E_ATR_FK_BASE)       // pozicioNipovaNija Na Nachalo synepbloka
#define E_ATR_FK_RD_SSFK      (E_ATR_FK_BASE + 1)   // chteNija slova sostojaNia faila-konii v atpibytax faila-konii
#define E_ATR_FK_SSFK         (E_ATR_FK_BASE + 2)   // slova sostojaNia faila-konii v atpibytax faila-konii
#define E_ATR_FK_RD_SZKDR     (E_ATR_FK_BASE + 3)   // chteNija pazmepa kadra faila-konii v atpibytax faila-konii
#define E_ATR_FK_SZKDR        (E_ATR_FK_BASE + 4)   // pazmepa kadra faila-konii v atpibytax faila-konii
#define E_ATR_FK_RD_DLFK      (E_ATR_FK_BASE + 5)		// chteNija dliNu faila-konii v atpibytax faila-konii
#define E_ATR_FK_DLFK         (E_ATR_FK_BASE + 6)		// dliNu faila-konii v atpibytax faila-konii
#define E_ATR_FK_RD_DLBURKDR  (E_ATR_FK_BASE + 7)   // chteNija dliNu kadpa BYP faila-konii v atpibytax faila-konii
#define E_ATR_FK_DLBURKDR	    (E_ATR_FK_BASE + 8)   // dliNu kadpa BYP faila-konii v atpibytax faila-konii
#define E_ATR_FK_RD_SZBURKDR	(E_ATR_FK_BASE + 9)   // chteNija pazmepa kadpa BYP faila-konii v atpibytax faila-konii
#define E_ATR_FK_SZBURKDR	    (E_ATR_FK_BASE +10)   // pazmepa kadpa BYP faila-konii v atpibytax faila-konii
#define E_ATR_FK_RD_SZFREEZONE (E_ATR_FK_BASE+11)   // chteNija pazmepa free-zoNu faila-konii v atpibytax faila-konii
#define E_ATR_FK_SZFREEZONE	  (E_ATR_FK_BASE +12)   // pazmepa free-zoNu faila-konii v atpibytax faila-konii
#define E_ATR_FK_POZSZSPB     (E_ATR_FK_BASE +13)   // pozicioNipovaNija Na pazmep synepbloka
#define E_ATR_FK_RD_SZSPB     (E_ATR_FK_BASE +14)   // chteNija pazmepa synepbloka
#define E_ATR_FK_SZSPB        (E_ATR_FK_BASE +15)   // pazmepa synepbloka

#define E_ATR_POL_BASE        40                       // npogpamma - ReadAtrFlight
#define E_ATR_POL_POZAPOL     (E_ATR_POL_BASE)      // pozicioNipovaNija Na atpibytu noleta
#define E_ATR_POL_RD_WEIGHT   (E_ATR_POL_BASE + 1)  // chteNija vesa samoleta v atpibytax noleta
#define E_ATR_POL_WEIGHT      (E_ATR_POL_BASE + 2)  // vesa samoleta v atpibytax noleta
#define E_ATR_POL_RD_SAX	    (E_ATR_POL_BASE + 3)  // chteNija SAX v atpibytax noleta
#define E_ATR_POL_SAX	    	  (E_ATR_POL_BASE + 4)  // SAX v atpibytax noleta
#define E_ATR_POL_RD_PRESW		(E_ATR_POL_BASE + 5)  // chteNija davleNia a/n vzleta v atpibytax noleta
#define E_ATR_POL_PRESW		    (E_ATR_POL_BASE + 6)  // davleNia a/n vzleta v atpibytax noleta
#define E_ATR_POL_RD_NAMEAP   (E_ATR_POL_BASE + 7)  // chteNija NazvaNie a/n vzleta/nosadki v atpibytax noleta
#define E_ATR_POL_RD_UNBBP	  (E_ATR_POL_BASE + 8)  // chteNija kypsa Vnn v atpibytax noleta
#define E_ATR_POL_UNBBP	  	  (E_ATR_POL_BASE + 9)  // kypsa Vnn v atpibytax noleta
#define E_ATR_POL_RD_LBBP	  	(E_ATR_POL_BASE +10)  // chteNija dliNu Vnn v atpibytax noleta
#define E_ATR_POL_LBBP	  	  (E_ATR_POL_BASE +11)  // dliNu Vnn v atpibytax noleta
#define E_ATR_POL_RD_HKR		  (E_ATR_POL_BASE +12)  // chteNija vusotu kpyga v atpibytax noleta
#define E_ATR_POL_HKR		      (E_ATR_POL_BASE +13)  // vusotu kpyga v atpibytax noleta
#define E_ATR_POL_RD_HE       (E_ATR_POL_BASE +14)  // chteNija vusotu esheloNa v atpibytax noleta
#define E_ATR_POL_HE          (E_ATR_POL_BASE +15)  // vusotu esheloNa v atpibytax noleta
#define E_ATR_POL_RD_HTVG		  (E_ATR_POL_BASE +16)  // chteNija vusotu vhoda v glisadu v atpibytax noleta
#define E_ATR_POL_HTVG		    (E_ATR_POL_BASE +17)  // vusotu vhoda v glisadu v atpibytax noleta
#define E_ATR_POL_RD_LTVG	  	(E_ATR_POL_BASE +18)  // chteNija passtojaNia do tochki vhoda v glissadu v atpibytax noleta
#define E_ATR_POL_LTVG	  	  (E_ATR_POL_BASE +19)  // passtojaNia do tochki vhoda v glissadu v atpibytax noleta
#define E_ATR_POL_RD_HBPRM		(E_ATR_POL_BASE +20)  // chteNija vusotu npoleta BnPM v atpibytax noleta
#define E_ATR_POL_HBPRM		    (E_ATR_POL_BASE +21)  // vusotu npoleta BnPM v atpibytax noleta
#define E_ATR_POL_RD_LBPRM	  (E_ATR_POL_BASE +22)  // chteNija passtojaNia ot Vnn do BnPM v atpibytax noleta
#define E_ATR_POL_LBPRM	  	  (E_ATR_POL_BASE +23)  // passtojaNia ot Vnn do BnPM v atpibytax noleta
#define E_ATR_POL_RD_HDPRM		(E_ATR_POL_BASE +24)  // chteNija vusotu npoleta DnPM v atpibytax noleta
#define E_ATR_POL_HDPRM		    (E_ATR_POL_BASE +25)  // vusotu npoleta DnPM v atpibytax noleta
#define E_ATR_POL_RD_LDPRM	  (E_ATR_POL_BASE +26)  // chteNija passtojaNia ot Vnn do BnPM v atpibytax noleta
#define E_ATR_POL_LDPRM	  	  (E_ATR_POL_BASE +27)  // passtojaNia ot Vnn do BnPM v atpibytax noleta
#define E_ATR_POL_RD_HVPR  		(E_ATR_POL_BASE +28)  // chteNija vusotu gpiNjatia pesheNia v atpibytax noleta
#define E_ATR_POL_HVPR  		  (E_ATR_POL_BASE +29)  // vusotu gpiNjatia pesheNia v atpibytax noleta

#define E_ATR_OD_BASE         70                       // npogpamma - ReadOD
#define E_ATR_OD_POZOD        (E_ATR_OD_BASE)       // pozicioNipovaNija Na atpibytu noleta
#define E_ATR_OD_RD_HOUR      (E_ATR_OD_BASE + 1)   // chteNija chasov v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_HOUR         (E_ATR_OD_BASE + 2)   // chasov v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_MINUTE    (E_ATR_OD_BASE + 3)   // chteNija miNut v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_MINUTE       (E_ATR_OD_BASE + 4)   // miNut v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_SECOND    (E_ATR_OD_BASE + 5)   // chteNija sekuNd v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_SECOND       (E_ATR_OD_BASE + 6)   // sekuNd v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_DATE      (E_ATR_OD_BASE + 7)   // chteNija datu v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_DATE         (E_ATR_OD_BASE + 8)   // datu v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_MONTH     (E_ATR_OD_BASE + 9)   // chteNija mesjaca v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_MONTH        (E_ATR_OD_BASE +10)   // mesjaca v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_YEAR      (E_ATR_OD_BASE +11)   // chteNija goda v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_YEAR         (E_ATR_OD_BASE +12)   // goda v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_REIS      (E_ATR_OD_BASE +13)   // chteNija Nomepa peisa v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_REIS         (E_ATR_OD_BASE +14)   // Nomepa peisa v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_RD_BORT      (E_ATR_OD_BASE +15)   // chteNija Nomepa bopta v atpibytax onozNavatelNux daNNux
#define E_ATR_OD_BORT         (E_ATR_OD_BASE +16)   // Nomepa bopta v atpibytax onozNavatelNux daNNux

#define E_ATR_CYCL_BASE       90                       // npogpamma - ReadCyclogram
#define E_ATR_CYCL_ATRFILE    (E_ATR_CYCL_BASE)     // nolycheNia atpibytov faila ciklogpammu
#define E_ATR_CYCL_EMPTYFILE  (E_ATR_CYCL_BASE + 1) // nystoi fail ciklogpammu
#define E_ATR_CYCL_MEMFILE    (E_ATR_CYCL_BASE + 2) // vudeleNia namjati nod fail ciklogpammu
#define E_ATR_CYCL_FILETOMEM  (E_ATR_CYCL_BASE + 3) // chteNia v namjat faila ciklogpammu
#define E_ATR_CYCL_NOLINE     (E_ATR_CYCL_BASE + 4) // Net strok v faile ciklogpammu
#define E_ATR_CYCL_MEMLINE    (E_ATR_CYCL_BASE + 5) // vudeleNia namjati nod massiv yKZT Na stpoki ciklogpammu
#define E_ATR_CYCL_MEMMASAn   (E_ATR_CYCL_BASE + 6) // vudeleNia namjati nod massiv yKZT Na stpyktypu An ciklogpammu
#define E_ATR_CYCL_MEMMASPK   (E_ATR_CYCL_BASE + 7) // vudeleNia namjati nod massiv yKZT Na stpyktypu PK ciklogpammu
#define E_ATR_CYCL_BORT       (E_ATR_CYCL_BASE + 8) // N bopta onozNavatelNux daNNux i ciklogpammu
#define E_ATR_CYCL_MEMSTPKTAn (E_ATR_CYCL_BASE + 9) // vudeleNia namjati Na stpyktypy An faila ciklogpammu
#define E_ATR_CYCL_IDAn       (E_ATR_CYCL_BASE +10) // vudeleNia namjati nod ideNtifikatop An faila ciklogpammu
#define E_ATR_CYCL_NAMEAn     (E_ATR_CYCL_BASE +11) // vudeleNia namjati nod NaimeNovaNie An faila ciklogpammu
#define E_ATR_CYCL_FIZAn      (E_ATR_CYCL_BASE +12) // vudeleNia namjati nod massiv fiziki v stpyktype An
#define E_ATR_CYCL_MEMSTPKTRK (E_ATR_CYCL_BASE +13) // vudeleNia namjati Na stpyktypy PK faila ciklogpammu
#define E_ATR_CYCL_IDRK       (E_ATR_CYCL_BASE +14) // vudeleNia namjati nod ideNtifikatop PK faila ciklogpammu
#define E_ATR_CYCL_NAMERK     (E_ATR_CYCL_BASE +15) // vudeleNia namjati nod NaimeNovaNie PK faila ciklogpammu
#define E_ATR_CYCL_FIZRK      (E_ATR_CYCL_BASE +16) // vudeleNia namjati nod massiv fiziki v stpyktype PK

#define E_PARKDR_RW_BASE     110
#define E_PARKDR_RW_NOFIZ 		(E_PARKDR_RW_BASE)    // fail-konia v kodax (ReadFreeZone)
#define E_PARKDR_RW_READKDR   (E_PARKDR_RW_BASE +1) // chteNia daNNux kadpa faila-konii (ReadKdr)
#define E_PARKDR_RW_WRFIZAP   (E_PARKDR_RW_BASE +2) // zanisi fiziki An v free-zony kadpa (WriteFizAP)
#define E_PARKDR_RW_WRFIZRK   (E_PARKDR_RW_BASE +3) // zanisi fiziki PK v free-zony kadpa (WriteFizRK)
#define E_PARKDR_RW_WRFREE    (E_PARKDR_RW_BASE +4) // zanisi free-zoNu kadpa v file-koniy (WriteKdr)
#define E_PARKDR_RW_WRPARAM   (E_PARKDR_RW_BASE +5) // zanis daNNux kaNala v kadp file-koniy (WriteParam)

#define E_ATRFK_RW_BASE      120
#define E_ATRFK_RW_RDPOZSPB   (E_ATRFK_RW_BASE)     // pozicioNipovaNija Na Nachalo synepbloka (ReadSSFK)
#define E_ATRFK_RW_RD_RDSSFK  (E_ATRFK_RW_BASE + 1) // chteNia slova sostojaNia faila-konii (ReadSSFK)
#define E_ATRFK_RW_RDSSFK     (E_ATRFK_RW_BASE + 2) // slova sostojaNia faila-konii (ReadSSFK)
#define E_ATRFK_RW_WRPOZSPB   (E_ATRFK_RW_BASE + 3) // pozicioNipovaNija Na Nachalo synepbloka (WriteSSFK)
#define E_ATRFK_RW_RD_WRSSFK  (E_ATRFK_RW_BASE + 4) // chteNia slova sostojaNia faila-konii (WriteSSFK)
#define E_ATRFK_RW_WRSSFK     (E_ATRFK_RW_BASE + 5) // slova sostojaNia faila-konii (WriteSSFK)
#define E_ATRFK_RW_WR_WRSSFK  (E_ATRFK_RW_BASE + 6) // chteNia slova sostojaNia faila-konii (WriteSSFK)

#define E_LSEEK_BASE         130
#define E_LSEEK_READKDR	      (E_LSEEK_BASE)        // nozicioNipovaNija Na kadp faila-konii (ReadKdr)
#define E_LSEEK_WRFIZAP       (E_LSEEK_BASE     +1) // nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizAP)
#define E_LSEEK_WRFIZRK       (E_LSEEK_BASE     +2) // nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizRK)
#define E_LSEEK_WRFREE        (E_LSEEK_BASE     +3) // nozicioNipovaNija Na free-zoNy kadpa faila-konii (WriteKdr)
#define E_LSEEK_WRPARAM       (E_LSEEK_BASE     +4) // nozicioNipovaNija Na kaNal kadpa faila-konii (WriteParam)
//----N_error.H--------


//----Func_fl.H--------
// flagi pabotu fyNkcui
#define FL_ERR        -1  // oshibka
#define FL_OK          0  // Nopma
//----Func_fl.H--------


//----FK_lim.H--------
// FK_lim.h - gpaNicu atpibutov faila-konii:      (13.01.13)
#define MIN_SS_FK            0    // gpanicu slova sostojaNija (obpabotki) faila-konii
#define MIN_SZ_KDR          24    // gpanicu pazmepa kadpa faila-konii (byte)
#define MAX_SZ_KDR         400
#define MIN_DL_BUR_KDR      24    // gpanicu dliNu zoNu kadpa-bYP faila-konii (iNfopmacioNNux slov)
#define MAX_DL_BUR_KDR     128
#define MIN_SZ_BUR_KDR      24    // gpanicu pazmepa zoNu kadp-bYP faila-konii (byte)
#define MAX_SZ_BUR_KDR     128
#define MIN_SZ_FREE_ZONE    48    // gpanicu pazmepa free-zoNu faila-konii (byte)
#define MAX_SZ_FREE_ZONE   400
#define MIN_DL_FK           60    // gpanicu dliNu faila-kopii (kadpov)
#define MAX_DL_FK         1000
#define MIN_SZ_SPB        1024    // gpanicu pazmepa synepbloka
#define MAX_SZ_SPB       20480
//----FK_lim.H--------


//----def_com.H--------
// def_com.h - obschie makposu (13.01.12)
#define BYTE_2    2  // 2 baita
#define BYTE_4    4  // 4 baita
#define BYTE_16  16  // 16 bait
//----def_com.H--------


//----Cycl_Fld.H--------
// opisanie poley cyclogrammy
#define CFLD_ID    0   // ideNtifikatop
#define CFLD_NM    1   // imya
#define CFLD_TP    2   // tin
#define CFLD_FO    3   // chastota pegistpacii
#define CFLD_CN    4   // kaNal onpos 1
#define CFLD_CN2   5   // kaNal onpos 2
#define CFLD_CN3   6   // kaNal onpos 3
#define CFLD_CN4   7   // kaNal onpos 4
#define CFLD_RZ    5   // pazpjad byP
#define CFLD_CNC   6   // kaNal PK fail-konia
#define CFLD_RZC   7   // pazpjad fail-konia
//----Cycl_Fld.H--------


//----AP_Cycl.H--------
// nozicija aNalogovogo napametpa v kadpe bYP i free-zoNe faila-konii
//  (imja smotpi v ciklogpamme)
#define OPOZ_DAN  0 // opozNavatelnue daNNue (kadp byP)
#define NUM_KDR   0 // Nomep kadpa (free-zoNa)
#define TH        1 // temnepatypa NapyjNogo vozdyxa
#define HB        2 // visota bapometpicheskaja
#define HG        3 // visota geometpicheskaja
#define VP        4 // skopost npibopNaja
// zaNjato PK  5
#define VUx       6 // yglovaja skopost kpeNa
#define Az        7 // nepegpyzka bokovaja
// zaNjato PK  8
#define Ay        9 // nepegpyzka veptikalNaja
#define SV       10 // nolojeNie pylja vusotu
#define UK       11 // ygol kpeNa
#define UN       12 // ygol kypsa gipomagNitNogo
#define UT       13 // ygol taNgaja
#define UKd      14 // ygol kpeNa pezepvNui
#define ZK       15 // otkloNeNie ot PSZ (pavNosigNalNaja zoNa) kypsa
#define KN       16 // kalibpovka miNimyma
#define ZG       17 // otkloNeNie ot PSZ glissadu
// zaNjato IPK1 caNal 18
#define RDl      19 // nolojeNie PyD (pykojatka ynpavleN.dvigatelem) levogo dvigatelja
#define Nnl      20 // obopotu veNtiljatopa levogo dvigatelja
#define Nvl      21 // obopotu KVD (komnpessopa vusokogo davleNia) levogo dvigatelja
#define Tl       22 // temnepatypa gaza za typbiNoi levogo dvigatelja
#define RDs      23 // nolojeNie PyD spedNego dvigatelja
// zaNjato IPK2 caNal 24
#define Ay_2     25 // nepegpyzka veptikalNaja (2 onpos)
#define SV_2     26 // nolojeNie pylja vusotu  (2 onpos)
#define UK_2     27 // ygol kpeNa              (2 onpos)
#define Nns      28 // obopotu veNtiljatopa spedNego dvigatelja
#define Nvs      29 // obopotu KVD spedNego dvigatelja
#define Ts       30 // temnepatypa gaza za typbiNoi spedNego dvigatelja
#define RDp      31 // nolojeNie PyD npavogo dvigatelja
#define Nnp      32 // obopotu veNtiljatopa npavogo dvigatelja
#define Nvp      33 // obopotu KVD npavogo dvigatelja
#define Tp       34 // temnepatypa gaza za typbiNoi npavogo dvigatelja
#define BDl      35 // vibpacia levogo dvigatelja
#define BDs      36 // vibpacia spedNego dvigatelja
#define BDp      37 // vibpacia npavogo dvigatelja
// zaNjato dVP   --> 38
#define dVP      38 // npoizvodNaja npibopNoi skoposti
#define RB       39 // nolojeNie bapaNki shtypvala
// zaNjato dHG   --> 40
#define dHG      40 // npoizvodNaja vusotu geometpicheskoi
#define Ay_3     41 // nepegpyzka veptikalNaja (3 onpos)
#define SV_3     42 // nolojeNie pylja vusotu  (3 onpos)
#define UK_3     43 // ygol kpeNa              (3 onpos)
#define RP       44 // nolojeNie nedalei
#define RKL      45 // nolojeNie koloNki shtypvala
#define SE       46 // nolojeNie elepoNa
#define SN       47 // nolojeNie pylja NanpavleNija
#define KM       48 // kalibpovka maksimyma
#define SVS      49 // nolojeNie stabilizatopa
#define MZ       50 // nolojeNie zakpulka
// zaNjato IPK (sobutie) --> 51
// zaNjato HBotn --> 52
#define HBotn    52 // vusota bapometpicheskaja otNositelNaja
// zaNjato dMZ   --> 53
#define dMZ      53 // npoizvodNaja nolojeNija zakpulka
#define DKA      54 // nepenad davleNija kabiNa-atmosfepa
											// svobodNo	--> 55
// zaNjato V3    --> 56
#define V3       56 // miNimalNaja npibopnaja skopost ybopki zakpulkov
#define Ay_4     57 // nepegpyzka veptikalNaja (4 onpos)
#define SV_4     58 // nolojeNie pylja vusotu  (4 onpos)
#define UK_4     59 // ygol kpeNa              (4 onpos)
#define QS       60 // ves samoleta s tonlivom
#define MTV      61 // nolojeNie tpimmepa pylja vusotu
#define EA27     62 // NanpjajeNie 27B Na avapiNoi shiNe
#define QT       63 // ostatok tonliva symmapNui
//----AP_Cycl.H--------


//----APOL_lim.H--------
// apol_lim.h - gpaNicu atpibytov noleta
#define MIN_VES_VZLET    20.0	// vzletNui ves bez tonliva, t
#define MAX_VES_VZLET    40.0
#define MIN_SAX_VZLET    10.0 // SAX Na vzlete, %
#define MAX_SAX_VZLET    30.0
#define MIN_DAVLENIE    700	  // davleNie, mm.pt.st.
#define MAX_DAVLENIE    780
#define MIN_UN_Vnn        0   // ygol kypsa Vnn
#define MAX_UN_Vnn      360
#define MIN_L_Vnn      1000   // dliNa Vnn, m
#define MAX_L_Vnn		   4000
#define MIN_Hkp         300   // vusota kpyga, m
#define MAX_Hkp         900
#define MIN_Hep_POS     800   // vusota esheloNa nepexoda nosadka, m
#define MAX_Hep_POS    1500
#define MIN_Htvg			  300   // vusota tochki vhoda v glissady, m
#define MAX_Htvg        900
#define MIN_Ltvg		   4000   // passtojaNie ot topca Vnn do tochki vhoda v glissady, m
#define MAX_Ltvg      12000
#define MIN_Hbprm		 	   50   // vusota npoleta bnPM, m
#define MAX_Hbprm       100
#define MIN_Lbprm				800   // passtojaNie ot topca Vnn do bnPM, m
#define MAX_Lbprm      1500
#define MIN_Hdprm			  150   // vusota npoleta DnPM, m
#define MAX_Hdprm       300
#define MIN_Ldprm			 2000   // passtojaNie ot topca Vnn do DnPM, m
#define MAX_Ldprm      5000
#define MIN_Hvpr         20   // vusota npiNjatia pesheNia, m
#define MAX_Hvpr        100
//----APOL_lim.H--------

#define maxChannel		64