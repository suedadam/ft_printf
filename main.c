#include <stdio.h>
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
	int ret;

	// ft_printf("ft: Hey dude %+8.5d\n", 42);
	// // printf("\n pf: Hey dude %+d\n", -42);
	// printf("pf: Hey dude %+8.5d\n", 42);
	// ft_printf("ft: Hey dude %+8.5d\n", -42);
	// // printf("\n pf: Hey dude %+d\n", -42);
	// printf("pf: Hey dude %+8.5d\n", -42);
	// ft_printf("ft: Hey dude %+6.5d\n", 42);
	// // printf("\n pf: Hey dude %+d\n", -42);
	// printf("pf: Hey dude %+6.5d\n", 42);
	// ft_printf("ft: Hey dude %+6.5d\n", -42);
	// // printf("\n pf: Hey dude %+d\n", -42);
	// printf("pf: Hey dude %+6.5d\n", -42);
	// ft_printf("ft: Hey dude %+d\n", 42);
	// // printf("\n pf: Hey dude %+d\n", -42);
	// printf("pf: Hey dude %+d\n", 42);
	// ft_printf("ft: Hey dude %+d\n", -42);
	// // printf("\n pf: Hey dude %+d\n", -42);
	// printf("pf: Hey dude %+d\n", -42);
	// ft_printf("ft: \"%-8.5d\"\n", -42);
	// printf("pf: \"%-8.5d\"\n", -42);
	// ft_printf("ft: \"%-6.5d\"\n", -42);
	// printf("pf: \"%-6.5d\"\n", -42);
	// ft_printf("ft: \"%-8.5d\"\n", 42);
	// printf("pf: \"%-8.5d\"\n", 42);
	// ft_printf("ft: \"%-6.5d\"\n", 42);
	// printf("pf: \"%-6.5d\"\n", 42);
	// ft_printf("%d", 42);
	// ft_printf("Kashim a %d histoires à raconter", 1001);
	// ft_printf("Il fait au moins %d\n", -8000);
	// ft_printf("%d", -0);
	// ft_printf("%d", 0);
	// ft_printf("%d", INT_MAX);
	// ft_printf("%d", INT_MIN);
	// ft_printf("%d", INT_MIN - 1);
	// ft_printf("%d", INT_MAX + 1);
	// ft_printf("%%d 0000042 == |%d|\n", 0000042);
	// ft_printf("%%d \t == |%d|\n", '\t');
	// ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("%d %%d\n", -8000, 42);
	// printf("pf: {%010d}\n", 42);
	// ft_printf("ft: {%010d}\n", 42);
	// printf("pf: {%-4d}\n", 10000);
	// ft_printf("ft: {%-4d}", 10000);
	test_d();
	test_ld();
	// test_n();
	// ret = printf("pf: \"%*.*d\"\n", 0, 3, 0);
	// printf("pf: %d\n", ret);
	// ret = ft_printf("ft: \"%*.*d\"\n", 0, 3, 0);
	// ft_printf("ft: %d\n", ret);
	// ret = printf("pf: {%+03d}\n", 0);
	// printf("pf: %d\n", ret);
	// ret = ft_printf("ft: {%+03d}\n", 0);
	// printf("ft: %d\n", ret);
	// ret = printf("pf: {%010d}\n", -42);
	// printf("pf: %d\n", ret);
	// ret = ft_printf("ft: {%010d}\n", -42);
	// printf("ft: %d\n", ret);
	// ret = printf("pf: {%D}\n", LONG_MAX);
	// printf("pf: %d\n", ret);
	// ret = ft_printf("ft: {%D}\n", LONG_MAX);
	// printf("ft: %d\n", ret);

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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

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
