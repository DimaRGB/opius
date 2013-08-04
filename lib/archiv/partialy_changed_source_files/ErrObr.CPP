// ErrObr.cpp - okoNchaNie pabotu no oshibke (13.01.12)
// n_err - Nomep Oshibki
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include "func_obr.h"
#include "N_error.h"

#include <conio.h>

void ErrObr(int n_err)
{
	if (n_err>=E_ATR_FK_BASE && n_err<=E_ATR_POL_BASE)
		PrintAtrFK();
	if (n_err>=E_ATR_POL_BASE && n_err<=E_ATR_OD_BASE)
		PrintAtrFlight();
	if (n_err>=E_ATR_OD_BASE && n_err<=E_ATR_CYCL_BASE)
		PrintOD();
	printf("\nERROR_%d ", n_err);
	switch (n_err)
	{ case E_OPEN_FK            : printf("otkputia faila-kopii (OpenFK)"); break;
		case E_OPEN_CYCL		  	  : printf("otkputia faila ciklogpammu (ReadCyclogram)"); break;
		case E_MEM_BUFKADR        : printf("vudeleNia namjati nod byfep kadpa faila-konii (main)"); break;
		case E_MEM_MASCODPAR      : printf("vudeleNia namjati Na massiv kodov napametpa (PrintParam)"); break;
		case E_ATR_FK_POZSPB      : printf("pozicioNipovaNija Na Nachalo synepbloka"); break;
		case E_ATR_FK_RD_SSFK     : printf("chteNija slova sostojaNia"); break;
		case E_ATR_FK_SSFK        : printf("slova sostojaNia"); break;
		case E_ATR_FK_RD_SZKDR    : printf("chteNija pazmepa kadra"); break;
		case E_ATR_FK_SZKDR       : printf("pazmepa kadra"); break;
		case E_ATR_FK_RD_DLFK     : printf("chteNija dliNu faila-konii"); break;
		case E_ATR_FK_DLFK        : printf("dliNu faila-konii"); break;
		case E_ATR_FK_RD_DLBURKDR : printf("chteNija dliNu kadpa BYP"); break;
		case E_ATR_FK_DLBURKDR    : printf("dliNu kadpa BYP"); break;
		case E_ATR_FK_RD_SZBURKDR : printf("chteNija pazmepa kadpa BYP"); break;
		case E_ATR_FK_SZBURKDR    : printf("pazmepa kadpa BYP"); break;
		case E_ATR_FK_RD_SZFREEZONE:printf("chteNija pazmepa free-zoNu"); break;
		case E_ATR_FK_SZFREEZONE  : printf("pazmepa free-zoNu"); break;
		case E_ATR_FK_POZSZSPB    : printf("pozicioNipovaNija Na pazmep synepbloka"); break;
		case E_ATR_FK_RD_SZSPB    : printf("chteNija pazmepa synepbloka"); break;
		case E_ATR_FK_SZSPB       : printf("pazmepa synepbloka"); break;
		case E_ATR_POL_POZAPOL    : printf("pozicioNipovaNija Na atpibytu noleta"); break;
		case E_ATR_POL_RD_WEIGHT  : printf("chteNija vesa samoleta"); break;
		case E_ATR_POL_WEIGHT     : printf("vesa samoleta"); break;
		case E_ATR_POL_RD_SAX	    : printf("chteNija SAX"); break;
		case E_ATR_POL_SAX	      : printf("SAX"); break;
		case E_ATR_POL_RD_PRESW		: printf("chteNija davleNia a/n vzleta"); break;
		case E_ATR_POL_PRESW		  : printf("davleNia a/n vzleta"); break;
		case E_ATR_POL_RD_NAMEAP	: printf("chteNija NazvaNija a/n vzleta/nosadki"); break;
		case E_ATR_POL_RD_UNBBP	  : printf("chteNija kypsa Vnn"); break;
		case E_ATR_POL_UNBBP	    : printf("kypsa Vnn"); break;
		case E_ATR_POL_RD_LBBP	  : printf("chteNija dliNu Vnn"); break;
		case E_ATR_POL_LBBP	  	  : printf("dliNu Vnn"); break;
		case E_ATR_POL_RD_HKR		  : printf("chteNija vusotu kpyga"); break;
		case E_ATR_POL_HKR		    : printf("vusotu kpyga"); break;
		case E_ATR_POL_RD_HE      : printf("chteNija vusotu esheloNa"); break;
		case E_ATR_POL_HE         : printf("vusotu esheloNa"); break;
		case E_ATR_POL_RD_HTVG		: printf("chteNija vusotu vhoda v glisady"); break;
		case E_ATR_POL_HTVG		    : printf("vusotu vhoda v glisady"); break;
		case E_ATR_POL_RD_LTVG	  : printf("chteNija passtojaNia do tochki vhoda glissady"); break;
		case E_ATR_POL_LTVG	  	  : printf("passtojaNia do tochki vhoda glissady"); break;
		case E_ATR_POL_RD_HBPRM		: printf("chteNija vusotu npoleta BnPM"); break;
		case E_ATR_POL_HBPRM		  : printf("vusotu npoleta BnPM"); break;
		case E_ATR_POL_RD_LBPRM	  : printf("chteNija passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_LBPRM	    : printf("passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_RD_HDPRM		: printf("chteNija vusotu npoleta DnPM"); break;
		case E_ATR_POL_HDPRM		  : printf("vusotu npoleta DnPM"); break;
		case E_ATR_POL_RD_LDPRM	  : printf("chteNija passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_LDPRM	    : printf("passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_RD_HVPR  	: printf("chteNija vusotu piNjatia pesheNia"); break;
		case E_ATR_POL_HVPR  		  : printf("vusotu piNjatia pesheNia"); break;
		case E_ATR_OD_POZOD       : printf("pozicioNipovaNija Na atpibytu noleta"); break;
		case E_ATR_OD_RD_HOUR    	: printf("chteNija chasov"); break;
		case E_ATR_OD_HOUR    	  : printf("chasov"); break;
		case E_ATR_OD_RD_MINUTE  	: printf("chteNija miNut"); break;
		case E_ATR_OD_MINUTE  	  : printf("miNut"); break;
		case E_ATR_OD_RD_SECOND  	: printf("chteNija sekuNd"); break;
		case E_ATR_OD_SECOND  	  : printf("sekuNd"); break;
		case E_ATR_OD_RD_DATE    	: printf("chteNija datu"); break;
		case E_ATR_OD_DATE    	  : printf("datu"); break;
		case E_ATR_OD_RD_MONTH   	: printf("chteNija mesjaca"); break;
		case E_ATR_OD_MONTH   	  : printf("mesjaca"); break;
		case E_ATR_OD_RD_YEAR    	: printf("chteNija goda"); break;
		case E_ATR_OD_YEAR    	  : printf("goda"); break;
		case E_ATR_OD_RD_REIS    	: printf("chteNija Nomepa peisa"); break;
		case E_ATR_OD_REIS    	  : printf("Nomepa peisa"); break;
		case E_ATR_OD_RD_BORT    	: printf("chteNija Nomepa bopta"); break;
		case E_ATR_OD_BORT    	  : printf("Nomepa bopta"); break;
		case E_ATR_CYCL_ATRFILE   : printf("nolycheNia atpibytov faila ciklogpammu"); break;
		case E_ATR_CYCL_EMPTYFILE : printf("nystoi fail ciklogpammu"); break;
		case E_ATR_CYCL_MEMFILE   : printf("vudeleNia namjati nod fail ciklogpammu"); break;
		case E_ATR_CYCL_FILETOMEM : printf("chteNia v namjat faila ciklogpammu"); break;
		case E_ATR_CYCL_NOLINE    : printf("Net strok v faile ciklogpammu"); break;
		case E_ATR_CYCL_MEMLINE   : printf("vudeleNia namjati nod massiv yKZT Na stpoki ciklogpammu"); break;
		case E_ATR_CYCL_MEMMASAn  : printf("vudeleNia namjati nod massiv yKZT Na stpyktypu An ciklogpammu"); break;
		case E_ATR_CYCL_MEMMASPK  : printf("vudeleNia namjati nod massiv yKZT Na stpyktypu PK ciklogpammu"); break;
		case E_ATR_CYCL_BORT      : printf("N bopta onozNavatelNux daNNux i ciklogpammu"); break;
		case E_ATR_CYCL_MEMSTPKTAn: printf("vudeleNia namjati Na stpyktypy An faila ciklogpammu"); break;
		case E_ATR_CYCL_IDAn      :	printf("vudeleNia namjati nod ideNtifikatop An faila ciklogpammu"); break;
		case E_ATR_CYCL_NAMEAn    :	printf("vudeleNia namjati nod NaimeNovaNie An faila ciklogpammu"); break;
		case E_ATR_CYCL_FIZAn     :	printf("vudeleNia namjati nod massiv fiziki v stpyktype An"); break;
		case E_ATR_CYCL_MEMSTPKTRK: printf("vudeleNia namjati Na stpyktypy PK faila ciklogpammu"); break;
		case E_ATR_CYCL_IDRK      :	printf("vudeleNia namjati nod ideNtifikatop PK faila ciklogpammu"); break;
		case E_ATR_CYCL_NAMERK    :	printf("vudeleNia namjati nod NaimeNovaNie PK faila ciklogpammu"); break;
		case E_ATR_CYCL_FIZRK     :	printf("vudeleNia namjati nod massiv fiziki v stpyktype PK"); break;
		case E_PARKDR_RW_NOFIZ    : printf("fail-konia v kodax (ReadFreeZone)"); break;
		case E_PARKDR_RW_READKDR  : printf("chteNia daNNux kadpa faila-konii (ReadKdr)"); break;
		case E_PARKDR_RW_WRFIZAP  : printf("zanisi fiziki An v free-zony kadpa (WriteFizAP)"); break;
		case E_PARKDR_RW_WRFIZRK  : printf("zanisi fiziki PK v free-zony kadpa (WriteFizRK)"); break;
		case E_PARKDR_RW_WRFREE   : printf("zanisi free-zoNu kadpa v file-koniy (WriteKdr)"); break;
		case E_PARKDR_RW_WRPARAM  : printf("zanis daNNux kaNala v kadp file-koniy (WriteParam)"); break;
		case E_ATRFK_RW_RDPOZSPB  : printf("pozicioNipovaNija Na Nachalo synepbloka (ReadSSFK)"); break;
		case E_ATRFK_RW_RD_RDSSFK : printf("chteNia slova sostojaNia faila-konii (ReadSSFK)"); break;
		case E_ATRFK_RW_RDSSFK    : printf("slova sostojaNia faila-konii (ReadSSFK)"); break;
		case E_ATRFK_RW_WRPOZSPB  : printf("pozicioNipovaNija Na Nachalo synepbloka (WriteSSFK)"); break;
		case E_ATRFK_RW_RD_WRSSFK : printf("chteNia slova sostojaNia faila-konii (WriteSSFK)"); break;
		case E_ATRFK_RW_WR_WRSSFK : printf("zanisi slova sostojaNia faila-konii (WriteSSFK)"); break;
		case E_LSEEK_READKDR	    : printf("nozicioNipovaNija Na kadp faila-konii (ReadKdr)"); break;
		case E_LSEEK_WRFIZAP			: printf("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizAP)"); break;
		case E_LSEEK_WRFIZRK			: printf("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizRK)"); break;
		case E_LSEEK_WRFREE       : printf("nozicioNipovaNija Na free-zoNy kadpa faila-konii (WriteKdr)"); break;
		case E_LSEEK_WRPARAM      : printf("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteParam)"); break;
		default                   :    ;    break;
	}
	if (n_err >= E_ATR_FK_BASE && n_err < E_ATR_POL_BASE)
		printf(" faila-konii v atpibytax faila-konii (PrintAtrFK)");
	if (n_err >= E_ATR_POL_BASE && n_err < E_ATR_OD_BASE)
		printf(" v atpibytax noleta (PrintAtrFlight)");
	if (n_err >= E_ATR_OD_BASE && n_err < E_ATR_CYCL_BASE)
		printf(" v atpibytax onozNavatelNux daNNux (PrintOD)");
	if (n_err >= E_ATR_CYCL_BASE && n_err < E_PARKDR_RW_BASE)
		printf(" (ReadCyclogram)");
	printf("\n Press any key to exit \n");
	_getch();
	exit(n_err);
}
