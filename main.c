#include <stdio.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#include <limits.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int
main(void)
{
	// int ret;
	// wchar_t wz [3] = L"@@";
	// ft_printf("%S\n", wz);
	// printf("%S\n", wz);
	test_s();
	test_ls();
	test_c();
	test_d();
	test_ld();
	test_x();
	test_zero();
	test_o();
	int i;

	printf("pf: %x\n", -0);
	ft_printf("ft: %x\n", -0);
}

int		test_ls( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	wchar_t wz [3] = L"@@";       // Zero-terminated
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_ls.in", "w+");
	//fprintf(fpin,"%ls", wz);   // Outputs 6 bytes
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_ls.out", "w+", stdout);
	ft_printf("%ls", wz);   // Outputs 6 bytes

	chmod("test_ls.out", 0644);
	fpin = fopen("test_ls.in", "r+");
	fpout = fopen("test_ls.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_S: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_S: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}

int		test_s( void )
{
	int			r00 = 0;
	char		*str = NULL;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	fgetpos(stdout, &pos);
	freopen("test_s.out", "w+", stdout);
	ft_printf("%s", "pouet");
	ft_printf(" pouet %s !!\n", "camembert");
	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	ft_printf("%s!\n", str);
	ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");



	chmod("test_s.out", 0644);
	fpin = fopen("test_s.in", "r+");
	fpout = fopen("test_s.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_s: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_s: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:42 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		test_d( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_d.in", "w+");
	//fprintf(fpin, "%d", 42);
	//fprintf(fpin, "Kashim a %d histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %d\n", -8000);
	//fprintf(fpin, "%d", -0);
	//fprintf(fpin, "%d", 0);
	//fprintf(fpin, "%d", INT_MAX);
	//fprintf(fpin, "%d", INT_MIN);
	//fprintf(fpin, "%d", INT_MIN - 1);
	//fprintf(fpin, "%d", INT_MAX + 1);
	//fprintf(fpin, "%%d 0000042 == |%d|\n", 0000042);
	//fprintf(fpin, "%%d \t == |%d|\n", '\t');
	//fprintf(fpin, "%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_d.out", "w+", stdout);
	ft_printf("%d", 42);
	ft_printf("Kashim a %d histoires à raconter", 1001);
	ft_printf("Il fait au moins %d\n", -8000);
	ft_printf("%d", -0);
	ft_printf("%d", 0);
	ft_printf("%d", INT_MAX);
	ft_printf("%d", INT_MIN);
	ft_printf("%d", INT_MIN - 1);
	ft_printf("%d", INT_MAX + 1);
	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	ft_printf("%%d \t == |%d|\n", '\t');
	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);

	chmod("test_d.out", 0644);
	fpin = fopen("test_d.in", "r+");
	fpout = fopen("test_d.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	if (r00 == 0) {
		printf("test_d: [ok]\n");
		return 1;
	}
	printf("test_d: [ko]\n");
	return 0;
}

int		test_ld( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_ld.in", "w+");
	//fprintf(fpin, "%D", 42);
	//fprintf(fpin, "Kashim a %D histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %D\n", -8000);
	//fprintf(fpin, "%D", -0);
	//fprintf(fpin, "%D", 0);
	//fprintf(fpin, "%D", INT_MAX);
	//fprintf(fpin, "%D", INT_MIN);
	//fprintf(fpin, "%D", INT_MIN - 1);
	//fprintf(fpin, "%D", INT_MAX + 1);
	//fprintf(fpin, "%%D 0000042 == |%D|\n", 0000042);
	//fprintf(fpin, "%%D \t == |%D|\n", '\t');
	//fprintf(fpin, "%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_ld.out", "w+", stdout);
	ft_printf("%D", 42);
	ft_printf("Kashim a %D histoires à raconter", 1001);
	ft_printf("Il fait au moins %D\n", -8000);
	ft_printf("%D", -0);
	ft_printf("%D", 0);
	ft_printf("%D", INT_MAX);
	ft_printf("%D", INT_MIN);
	ft_printf("%D", INT_MIN - 1);
	ft_printf("%D", INT_MAX + 1);
	ft_printf("%%D 0000042 == |%D|\n", 0000042);
	ft_printf("%%D \t == |%D|\n", '\t');
	ft_printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_ld.out", 0644);
	fpin = fopen("test_ld.in", "r+");
	fpout = fopen("test_ld.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_ld: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_ld: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}

int		test_n( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_n.in", "w+");
	int		nb = 42;
	//fprintf(fpin, "LALALALALAL\n%n", &nb);
	//fprintf(fpin, "%d\n", nb);
	//fprintf(fpin, "Kashim a %d histoires à raconter\n%n", 1001, &nb);
	//fprintf(fpin, "%d\n", nb);
	//fprintf(fpin, "%d%n", '\t', &nb);
	//fprintf(fpin, "%d\n", nb);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_n.out", "w+", stdout);
	int nb2 = 42;
	ft_printf("LALALALALAL\n%n", &nb2);
	ft_printf("%d\n", nb2);
	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &nb2);
	ft_printf("%d\n", nb2);
	ft_printf("%d%n", '\t', &nb2);
	ft_printf("%d\n", nb2);

	chmod("test_n.out", 0644);
	fpin = fopen("test_n.in", "r+");
	fpout = fopen("test_n.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_n: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_n: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}

int		test_c( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	// fpin = fopen("test_c.in", "w+");
	// fprintf(fpin, "%c", 42);
	// fprintf(fpin, "Kashim a %c histoires à raconter", 1001);
	// fprintf(fpin, "Il fait au moins %c\n", -8000);
	// fprintf(fpin, "%c", -0);
	// fprintf(fpin, "%c", 0);
	// fprintf(fpin, "%c\n", INT_MAX);
	// fprintf(fpin, "%c\n", 'c');
	// fprintf(fpin, "%c\n", '\n');
	// fprintf(fpin, "%c", 'l');
	// fprintf(fpin, "%c", 'y');
	// fprintf(fpin, "%c", ' ');
	// fprintf(fpin, "%c", 'e');
	// fprintf(fpin, "%c", 's');
	// fprintf(fpin, "%c", 't');
	// fprintf(fpin, "%c", ' ');
	// fprintf(fpin, "%c", 'f');
	// fprintf(fpin, "%c", 'a');
	// fprintf(fpin, "%c", 'n');
	// fprintf(fpin, "%c", 't');
	// fprintf(fpin, "%c", 'a');
	// fprintf(fpin, "%c", 's');
	// fprintf(fpin, "%c", 't');
	// fprintf(fpin, "%c", 'i');
	// fprintf(fpin, "%c", 'q');
	// fprintf(fpin, "%c", 'u');
	// fprintf(fpin, "%c", 'e');
	// fprintf(fpin, "%c\n", '!');
	// fprintf(fpin, "%c\n", '\r');
	// fprintf(fpin, "%c\n", '\t');
	// fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_c.out", "w+", stdout);
	ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c", 'l');
	ft_printf("%c", 'y');
	ft_printf("%c", ' ');
	ft_printf("%c", 'e');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", ' ');
	ft_printf("%c", 'f');
	ft_printf("%c", 'a');
	ft_printf("%c", 'n');
	ft_printf("%c", 't');
	ft_printf("%c", 'a');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", 'i');
	ft_printf("%c", 'q');
	ft_printf("%c", 'u');
	ft_printf("%c", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');

	chmod("test_c.out", 0644);
	fpin = fopen("test_c.in", "r+");
	fpout = fopen("test_c.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}
	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_c: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_c: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}

int		test_x( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_x.in", "w+");
	//fprintf(fpin, "%x", 42);
	//fprintf(fpin, "Kashim a %x histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %x\n", -8000);
	//fprintf(fpin, "%x", -0);
	//fprintf(fpin, "%x", 0);
	//fprintf(fpin, "%x", INT_MAX);
	//fprintf(fpin, "%x", INT_MIN);
	//fprintf(fpin, "%x", INT_MIN - 1);
	//fprintf(fpin, "%x", INT_MAX + 1);
	//fprintf(fpin, "%%x 0000042 == |%x|\n", 0000042);
	//fprintf(fpin, "%%x \t == |%x|\n", '\t');
	//fprintf(fpin, "%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_x.out", "w+", stdout);
	ft_printf("%x", 42);
	ft_printf("Kashim a %x histoires à raconter", 1001);
	ft_printf("Il fait au moins %x\n", -8000);
	ft_printf("%x", -0);
	ft_printf("%x", 0);
	ft_printf("%x", INT_MAX);
	ft_printf("%x", INT_MIN);
	ft_printf("%x", INT_MIN - 1);
	ft_printf("%x", INT_MAX + 1);
	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	ft_printf("%%x \t == |%x|\n", '\t');
	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_x.out", 0644);
	fpin = fopen("test_x.in", "r+");
	fpout = fopen("test_x.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_x: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_x: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
int		test_o( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	// fpin = fopen("test_o.in", "w+");
	// fprintf(fpin, "%o", 42);
	// fprintf(fpin, "Kashim a %o histoires à raconter", 1001);
	// fprintf(fpin, "Il fait au moins %o\n", -8000);
	// fprintf(fpin, "%o", -0);
	// fprintf(fpin, "%o", 0);
	// fprintf(fpin, "%o", INT_MAX);
	// fprintf(fpin, "%o", INT_MIN);
	// fprintf(fpin, "%o", INT_MIN - 1);
	// fprintf(fpin, "%o", INT_MAX + 1);
	// fprintf(fpin, "%%o 0000042 == |%o|\n", 0000042);
	// fprintf(fpin, "%%o \t == |%o|\n", '\t');
	// fprintf(fpin, "%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	// fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_o.out", "w+", stdout);
	ft_printf("%o", 42);
	ft_printf("Kashim a %o histoires à raconter", 1001);
	ft_printf("Il fait au moins %o\n", -8000);
	ft_printf("%o", -0);
	ft_printf("%o", 0);
	ft_printf("%o", INT_MAX);
	ft_printf("%o", INT_MIN);
	ft_printf("%o", INT_MIN - 1);
	ft_printf("%o", INT_MAX + 1);
	ft_printf("%%o 0000042 == |%o|\n", 0000042);
	ft_printf("%%o \t == |%o|\n", '\t');
	ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_o.out", 0644);
	fpin = fopen("test_o.in", "r+");
	fpout = fopen("test_o.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_o: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_o: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}

int		test_zero( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_zero.in", "w+");
	//fprintf(fpin, "%%04i 42 == |%04i|\n", 42);
	//fprintf(fpin, "%%05i 42 == |%05i|\n", 42);
	//fprintf(fpin, "%%0i 42 == |%0i|\n", 42);
	//fprintf(fpin, "%%0d 0000042 == |%0d|\n", 0000042);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_zero.out", "w+", stdout);
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

	chmod("test_zero.out", 0644);
	fpin = fopen("test_zero.in", "r+");
	fpout = fopen("test_zero.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}
	if (fdin != fdout)
		r00 = 1;

	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	if (r00 == 0) {
		printf("test_zero: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_zero: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}