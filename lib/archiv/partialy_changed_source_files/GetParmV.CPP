// pazbivka tekstovoi stpoki Na polja no simvoly pazdelitelju
// *p_str - yKZT Na stpoky; *p_mpf[] - yKZT Na Nachalo nolja v stroke
//  sym   - simvol pazdelitel poley v stroke
short GetParmVec(char *p_str, char *p_mpf[], char sym)
{ char *p_str_b, *p_str_e; // yKZT Nachala/koNca stpoki
	short n_fld;             // kolichestvo noley

	p_str_b      = p_str;
	n_fld        = 0;
	p_mpf[n_fld] = p_str_b;
	while (1)
	{ while (*p_str_b == ' ')
			*p_str_b++ = 0;
		if (*p_str_b != sym)
		{ p_mpf[n_fld] = p_str_b;
			while ((*p_str_b!=sym)&&(*p_str_b!='\n')&&(*p_str_b!=0))
				p_str_b++;
			if (p_str_b != p_mpf[n_fld])
			{ p_str_e = p_str_b - 1;
				while (*p_str_e == ' ')
					*p_str_e-- = 0;
			}
			else
				p_mpf[n_fld] = (char *) 0;
		}
		else
			p_mpf[n_fld] = (char *) 0;
		if (*p_str_b == sym)
			n_fld++;
		if ((*p_str_b == '\n') || !(*p_str_b))
		{ *p_str_b = 0;
			return(n_fld);
		}
		*p_str_b++ = 0;
	}
}
