//N_error.h - Nomep oshibki npi pabote npogpammu (13.01.12)
																					 // Oshibka:
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
