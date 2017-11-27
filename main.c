/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:24:57 by lle-blev          #+#    #+#             */
/*   Updated: 2017/11/27 12:35:15 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include "tests.h"
#include <locale.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:07:05 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_a( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_a.in", "w+");
	//fprintf(fpin, "%a", (double)42);
	//fprintf(fpin, "Kashim a %a histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %a\n", (double)-8000);
	//fprintf(fpin, "%a", (double)-0);
	//fprintf(fpin, "%a", (double)0);
	//fprintf(fpin, "%a", (double)INT_MAX);
	//fprintf(fpin, "%a", (double)INT_MIN);
	//fprintf(fpin, "%a", (double)INT_MIN - 1);
	//fprintf(fpin, "%a", (double)INT_MAX + 1);
	//fprintf(fpin, "%%a 0000042 == |%a|\n", (double)0000042);
	//fprintf(fpin, "%%a \t == |%a|\n", (double)'\t');
	//fprintf(fpin, "%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%a 42.42 == |%a|\n", 42.42);
	//fprintf(fpin, "%A", (double)42);
	//fprintf(fpin, "Kashim a %A histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %A\n", (double)-8000);
	//fprintf(fpin, "%A", (double)-0);
	//fprintf(fpin, "%A", (double)0);
	//fprintf(fpin, "%A", (double)INT_MAX);
	//fprintf(fpin, "%A", (double)INT_MIN);
	//fprintf(fpin, "%A", (double)INT_MIN - 1);
	//fprintf(fpin, "%A", (double)INT_MAX + 1);
	//fprintf(fpin, "%%A 0000042 == |%A|\n", (double)0000042);
	//fprintf(fpin, "%%A \t == |%A|\n", (double)'\t');
	//fprintf(fpin, "%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%A 42.42 == |%A|\n", 42.42);
	//fprintf(fpin, "%%A 42.42 == |%.2A|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_a.out", "w+", stdout);
	ft_printf("%a", (double)42);
	ft_printf("Kashim a %a histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %a\n", (double)-8000);
	ft_printf("%a", (double)-0);
	ft_printf("%a", (double)0);
	ft_printf("%a", (double)INT_MAX);
	ft_printf("%a", (double)INT_MIN);
	ft_printf("%a", (double)INT_MIN - 1);
	ft_printf("%a", (double)INT_MAX + 1);
	ft_printf("%%a 0000042 == |%a|\n", (double)0000042);
	ft_printf("%%a \t == |%a|\n", (double)'\t');
	ft_printf("%%a Lydie == |%a|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%a 42.42 == |%a|\n", 42.42);
	ft_printf("%A", (double)42);
	ft_printf("Kashim a %A histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %A\n", (double)-8000);
	ft_printf("%A", (double)-0);
	ft_printf("%A", (double)0);
	ft_printf("%A", (double)INT_MAX);
	ft_printf("%A", (double)INT_MIN);
	ft_printf("%A", (double)INT_MIN - 1);
	ft_printf("%A", (double)INT_MAX + 1);
	ft_printf("%%A 0000042 == |%A|\n", (double)0000042);
	ft_printf("%%A \t == |%A|\n", (double)'\t');
	ft_printf("%%A Lydie == |%A|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%A 42.42 == |%A|\n", 42.42);
	ft_printf("%%A 42.42 == |%.2A|\n", 42.42);

	chmod("test_a.out", 0644);
	fpin = fopen("test_a.in", "r+");
	fpout = fopen("test_a.out", "r+");
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
		printf("test_a: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_a: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:39 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_c( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_c.in", "w+");
	//fprintf(fpin, "%c", 42);
	//fprintf(fpin, "Kashim a %c histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %c\n", -8000);
	//fprintf(fpin, "%c", -0);
	//fprintf(fpin, "%c", 0);
	//fprintf(fpin, "%c\n", INT_MAX);
	//fprintf(fpin, "%c\n", 'c');
	//fprintf(fpin, "%c\n", '\n');
	//fprintf(fpin, "%c", 'l');
	//fprintf(fpin, "%c", 'y');
	//fprintf(fpin, "%c", ' ');
	//fprintf(fpin, "%c", 'e');
	//fprintf(fpin, "%c", 's');
	//fprintf(fpin, "%c", 't');
	//fprintf(fpin, "%c", ' ');
	//fprintf(fpin, "%c", 'f');
	//fprintf(fpin, "%c", 'a');
	//fprintf(fpin, "%c", 'n');
	//fprintf(fpin, "%c", 't');
	//fprintf(fpin, "%c", 'a');
	//fprintf(fpin, "%c", 's');
	//fprintf(fpin, "%c", 't');
	//fprintf(fpin, "%c", 'i');
	//fprintf(fpin, "%c", 'q');
	//fprintf(fpin, "%c", 'u');
	//fprintf(fpin, "%c", 'e');
	//fprintf(fpin, "%c\n", '!');
	//fprintf(fpin, "%c\n", '\r');
	//fprintf(fpin, "%c\n", '\t');
	//fclose(fpin);

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
// #include "tests.h"

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
	printf(ANSI_COLOR_RED "test_d: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:45 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_e( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_e.in", "w+");
	//fprintf(fpin, "%e", (double)42);
	//fprintf(fpin, "Kashim a %e histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %e\n", (double)-8000);
	//fprintf(fpin, "%e", (double)-0);
	//fprintf(fpin, "%e", (double)0);
	//fprintf(fpin, "%e", (double)INT_MAX);
	//fprintf(fpin, "%e", (double)INT_MIN);
	//fprintf(fpin, "%e", (double)INT_MIN - 1);
	//fprintf(fpin, "%e", (double)INT_MAX + 1);
	//fprintf(fpin, "%%e 0000042 == |%e|\n", (double)0000042);
	//fprintf(fpin, "%%e \t == |%e|\n", (double)'\t');
	//fprintf(fpin, "%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%e 42.42 == |%e|\n", 42.42);
	//fprintf(fpin, "%E", (double)42);
	//fprintf(fpin, "Kashim a %E histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %E\n", (double)-8000);
	//fprintf(fpin, "%E", (double)-0);
	//fprintf(fpin, "%E", (double)0);
	//fprintf(fpin, "%E", (double)INT_MAX);
	//fprintf(fpin, "%E", (double)INT_MIN);
	//fprintf(fpin, "%E", (double)INT_MIN - 1);
	//fprintf(fpin, "%E", (double)INT_MAX + 1);
	//fprintf(fpin, "%%E 0000042 == |%E|\n", (double)0000042);
	//fprintf(fpin, "%%E \t == |%E|\n", (double)'\t');
	//fprintf(fpin, "%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%E 42.42 == |%E|\n", 42.42);
	//fprintf(fpin, "%%E 42.42 == |%.2E|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_e.out", "w+", stdout);
	ft_printf("%e", (double)42);
	ft_printf("Kashim a %e histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %e\n", (double)-8000);
	ft_printf("%e", (double)-0);
	ft_printf("%e", (double)0);
	ft_printf("%e", (double)INT_MAX);
	ft_printf("%e", (double)INT_MIN);
	ft_printf("%e", (double)INT_MIN - 1);
	ft_printf("%e", (double)INT_MAX + 1);
	ft_printf("%%e 0000042 == |%e|\n", (double)0000042);
	ft_printf("%%e \t == |%e|\n", (double)'\t');
	ft_printf("%%e Lydie == |%e|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%e 42.42 == |%e|\n", 42.42);
	ft_printf("%E", (double)42);
	ft_printf("Kashim a %E histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %E\n", (double)-8000);
	ft_printf("%E", (double)-0);
	ft_printf("%E", (double)0);
	ft_printf("%E", (double)INT_MAX);
	ft_printf("%E", (double)INT_MIN);
	ft_printf("%E", (double)INT_MIN - 1);
	ft_printf("%E", (double)INT_MAX + 1);
	ft_printf("%%E 0000042 == |%E|\n", (double)0000042);
	ft_printf("%%E \t == |%E|\n", (double)'\t');
	ft_printf("%%E Lydie == |%E|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%E 42.42 == |%E|\n", 42.42);
	ft_printf("%%E 42.42 == |%.2E|\n", 42.42);

	chmod("test_e.out", 0644);
	fpin = fopen("test_e.in", "r+");
	fpout = fopen("test_e.out", "r+");
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
		printf("test_e: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_e: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:04:48 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_f( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_f.in", "w+");
	//fprintf(fpin, "%f", (double)42);
	//fprintf(fpin, "Kashim a %f histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %f\n", (double)-8000);
	//fprintf(fpin, "%f", (double)-0);
	//fprintf(fpin, "%f", (double)0);
	//fprintf(fpin, "%f", (double)INT_MAX);
	//fprintf(fpin, "%f", (double)INT_MIN);
	//fprintf(fpin, "%f", (double)INT_MIN - 1);
	//fprintf(fpin, "%f", (double)INT_MAX + 1);
	//fprintf(fpin, "%%f 0000042 == |%f|\n", (double)0000042);
	//fprintf(fpin, "%%f \t == |%f|\n", (double)'\t');
	//fprintf(fpin, "%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%f 42.42 == |%f|\n", 42.42);
	//fprintf(fpin, "%F", (double)42);
	//fprintf(fpin, "Kashim a %F histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %F\n", (double)-8000);
	//fprintf(fpin, "%F", (double)-0);
	//fprintf(fpin, "%F", (double)0);
	//fprintf(fpin, "%F", (double)INT_MAX);
	//fprintf(fpin, "%F", (double)INT_MIN);
	//fprintf(fpin, "%F", (double)INT_MIN - 1);
	//fprintf(fpin, "%F", (double)INT_MAX + 1);
	//fprintf(fpin, "%%F 0000042 == |%F|\n", (double)0000042);
	//fprintf(fpin, "%%F \t == |%F|\n", (double)'\t');
	//fprintf(fpin, "%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%F 42.42 == |%F|\n", 42.42);
	//fprintf(fpin, "%%F 42.42 == |%.2F|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_f.out", "w+", stdout);
	ft_printf("%f", (double)42);
	ft_printf("Kashim a %f histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %f\n", (double)-8000);
	ft_printf("%f", (double)-0);
	ft_printf("%f", (double)0);
	ft_printf("%f", (double)INT_MAX);
	ft_printf("%f", (double)INT_MIN);
	ft_printf("%f", (double)INT_MIN - 1);
	ft_printf("%f", (double)INT_MAX + 1);
	ft_printf("%%f 0000042 == |%f|\n", (double)0000042);
	ft_printf("%%f \t == |%f|\n", (double)'\t');
	ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%f 42.42 == |%f|\n", 42.42);
	ft_printf("%F", (double)42);
	ft_printf("Kashim a %F histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %F\n", (double)-8000);
	ft_printf("%F", (double)-0);
	ft_printf("%F", (double)0);
	ft_printf("%F", (double)INT_MAX);
	ft_printf("%F", (double)INT_MIN);
	ft_printf("%F", (double)INT_MIN - 1);
	ft_printf("%F", (double)INT_MAX + 1);
	ft_printf("%%F 0000042 == |%F|\n", (double)0000042);
	ft_printf("%%F \t == |%F|\n", (double)'\t');
	ft_printf("%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%F 42.42 == |%F|\n", 42.42);
	ft_printf("%%F 42.42 == |%.2F|\n", 42.42);

	chmod("test_f.out", 0644);
	fpin = fopen("test_f.in", "r+");
	fpout = fopen("test_f.out", "r+");
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
		printf("test_f: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_f: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:16 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_g( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_g.in", "w+");
	//fprintf(fpin, "%g", (double)42);
	//fprintf(fpin, "Kashim a %g histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %g\n", (double)-8000);
	//fprintf(fpin, "%g", (double)-0);
	//fprintf(fpin, "%g", (double)0);
	//fprintf(fpin, "%g", (double)INT_MAX);
	//fprintf(fpin, "%g", (double)INT_MIN);
	//fprintf(fpin, "%g", (double)INT_MIN - 1);
	//fprintf(fpin, "%g", (double)INT_MAX + 1);
	//fprintf(fpin, "%%g 0000042 == |%g|\n", (double)0000042);
	//fprintf(fpin, "%%g \t == |%g|\n", (double)'\t');
	//fprintf(fpin, "%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%g 42.42 == |%g|\n", 42.42);
	//fprintf(fpin, "%G", (double)42);
	//fprintf(fpin, "Kashim a %G histoires à raconter", (double)1001);
	//fprintf(fpin, "Il fait au moins %G\n", (double)-8000);
	//fprintf(fpin, "%G", (double)-0);
	//fprintf(fpin, "%G", (double)0);
	//fprintf(fpin, "%G", (double)INT_MAX);
	//fprintf(fpin, "%G", (double)INT_MIN);
	//fprintf(fpin, "%G", (double)INT_MIN - 1);
	//fprintf(fpin, "%G", (double)INT_MAX + 1);
	//fprintf(fpin, "%%G 0000042 == |%G|\n", (double)0000042);
	//fprintf(fpin, "%%G \t == |%G|\n", (double)'\t');
	//fprintf(fpin, "%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%G 42.42 == |%G|\n", 42.42);
	//fprintf(fpin, "%%G 42.42 == |%.2G|\n", 42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_g.out", "w+", stdout);
	ft_printf("%g", (double)42);
	ft_printf("Kashim a %g histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %g\n", (double)-8000);
	ft_printf("%g", (double)-0);
	ft_printf("%g", (double)0);
	ft_printf("%g", (double)INT_MAX);
	ft_printf("%g", (double)INT_MIN);
	ft_printf("%g", (double)INT_MIN - 1);
	ft_printf("%g", (double)INT_MAX + 1);
	ft_printf("%%g 0000042 == |%g|\n", (double)0000042);
	ft_printf("%%g \t == |%g|\n", (double)'\t');
	ft_printf("%%g Lydie == |%g|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%g 42.42 == |%g|\n", 42.42);
	ft_printf("%G", (double)42);
	ft_printf("Kashim a %G histoires à raconter", (double)1001);
	ft_printf("Il fait au moins %G\n", (double)-8000);
	ft_printf("%G", (double)-0);
	ft_printf("%G", (double)0);
	ft_printf("%G", (double)INT_MAX);
	ft_printf("%G", (double)INT_MIN);
	ft_printf("%G", (double)INT_MIN - 1);
	ft_printf("%G", (double)INT_MAX + 1);
	ft_printf("%%G 0000042 == |%G|\n", (double)0000042);
	ft_printf("%%G \t == |%G|\n", (double)'\t');
	ft_printf("%%G Lydie == |%G|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%G 42.42 == |%G|\n", 42.42);
	ft_printf("%%G 42.42 == |%.2G|\n", 42.42);

	chmod("test_g.out", 0644);
	fpin = fopen("test_g.in", "r+");
	fpout = fopen("test_g.out", "r+");
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
		printf("test_g: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_g: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhhllljz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:21 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_hhhllljz( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));
	unsigned char a = -125;
	unsigned int b = -125;
	unsigned long c = -125;
	unsigned short d = -125;
	size_t e = -125;
	uintmax_t f = -125;
	unsigned long long	g = -125;

	unsigned char h = 0;
	unsigned int i = 0;
	unsigned long j = 0;
	unsigned short k = 0;
	size_t l = 0;
	uintmax_t m = 0;
	unsigned long long n = 0;

	unsigned char o = (unsigned char)~0U>>1;
	unsigned int p = ~0U>>1;
	unsigned long q = ~0U>>1;
	unsigned short r = (short)~0U>>1;
	size_t s = (size_t)~0U>>1;
	uintmax_t t = (uintmax_t)~0U>>1;
	unsigned long long u = (unsigned long long)~0U>>1;

	unsigned char v = -m-1;
	unsigned int w = -n-1;
	unsigned long x = -o-1;
	unsigned short y = -p-1;
	unsigned long z = -q-1;
	uintmax_t zz = -r-1;
	unsigned long long aa = -r-1;

	//fpin = fopen("test_hhhllljz.in", "w+");
	//fprintf(fpin, "unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	//fprintf(fpin, "unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	//fprintf(fpin, "unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	//fprintf(fpin, "unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	//fprintf(fpin, "size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	//fprintf(fpin, "uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	//fprintf(fpin, "unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));

	//fprintf(fpin, "unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	//fprintf(fpin, "unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	//fprintf(fpin, "unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	//fprintf(fpin, "unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	//fprintf(fpin, "size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	//fprintf(fpin, "uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	//fprintf(fpin, "unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));

	//fprintf(fpin, "unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	//fprintf(fpin, "unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	//fprintf(fpin, "unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	//fprintf(fpin, "unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	//fprintf(fpin, "size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	//fprintf(fpin, "uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	//fprintf(fpin, "unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));

	//fprintf(fpin, "unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	//fprintf(fpin, "unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	//fprintf(fpin, "unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	//fprintf(fpin, "unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	//fprintf(fpin, "size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	//fprintf(fpin, "uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	//fprintf(fpin, "unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_hhhllljz.out", "w+", stdout);
	ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", a,sizeof(a));
	ft_printf("unsigned int		b = %u sizeof b = %lu\n",b,sizeof(b));
	ft_printf("unsigned long		c = %lu sizeof c = %lu\n",c,sizeof(c));
	ft_printf("unsigned short		d = %hu sizeof d = %lu\n",d,sizeof(d));
	ft_printf("size_t			e = %zu sizeof e = %lu\n",e,sizeof(e));
	ft_printf("uintmax_t		f = %ju sizeof f = %lu\n",f,sizeof(f));
	ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n",g,sizeof(g));

	ft_printf("unsigned char		h = %hhu sizeof h = %lu\n", h,sizeof(h));
	ft_printf("unsigned int		i = %u sizeof i = %lu\n",i,sizeof(i));
	ft_printf("unsigned long		j = %lu sizeof j = %lu\n",j,sizeof(j));
	ft_printf("unsigned short		k = %hu sizeof k = %lu\n",k,sizeof(k));
	ft_printf("size_t			l = %zu sizeof l = %lu\n",l,sizeof(l));
	ft_printf("uintmax_t		m = %ju sizeof m = %lu\n",m,sizeof(m));
	ft_printf("unsigned long long	n = %llu sizeof n = %lu\n\n",n,sizeof(n));

	ft_printf("unsigned char		o = %hhu sizeof o = %lu\n", o,sizeof(o));
	ft_printf("unsigned int		p = %u sizeof p = %lu\n",p,sizeof(p));
	ft_printf("unsigned long		q = %lu sizeof q = %lu\n",q,sizeof(q));
	ft_printf("unsigned short		r = %hu sizeof r = %lu\n",r,sizeof(r));
	ft_printf("size_t			s = %zu sizeof s = %lu\n",s,sizeof(s));
	ft_printf("uintmax_t		t = %ju sizeof t = %lu\n",t,sizeof(t));
	ft_printf("unsigned long long	u = %llu sizeof u = %lu\n\n",u,sizeof(u));

	ft_printf("unsigned char		v = %hhu sizeof v = %lu\n", v,sizeof(v));
	ft_printf("unsigned int		w = %u sizeof w = %lu\n",w,sizeof(w));
	ft_printf("unsigned long		x = %lu sizeof x = %lu\n",x,sizeof(x));
	ft_printf("unsigned short		y = %hu sizeof y = %lu\n",y,sizeof(y));
	ft_printf("size_t			z = %zu sizeof z = %lu\n",z,sizeof(z));
	ft_printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zz,sizeof(zz));
	ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));

	chmod("test_hhhllljz.out", 0644);
	fpin = fopen("test_hhhllljz.in", "r+");
	fpout = fopen("test_hhhllljz.out", "r+");
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
		printf("test_hhhllljz: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_hhhllljz: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:26 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_i( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_i.in", "w+");
	//fprintf(fpin, "%i", 42);
	//fprintf(fpin, "Kashim a %i histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %i\n", -8000);
	//fprintf(fpin, "%i", -0);
	//fprintf(fpin, "%i", 0);
	//fprintf(fpin, "%i", INT_MAX);
	//fprintf(fpin, "%i", INT_MIN);
	//fprintf(fpin, "%i", INT_MIN - 1);
	//fprintf(fpin, "%i", INT_MAX + 1);
	//fprintf(fpin, "%%i 0000042 == |%i|\n", 0000042);
	//fprintf(fpin, "%%i \t == |%i|\n", '\t');
	//fprintf(fpin, "%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_i.out", "w+", stdout);
	ft_printf("%i", 42);
	ft_printf("Kashim a %i histoires à raconter", 1001);
	ft_printf("Il fait au moins %i\n", -8000);
	ft_printf("%i", -0);
	ft_printf("%i", 0);
	ft_printf("%i", INT_MAX);
	ft_printf("%i", INT_MIN);
	ft_printf("%i", INT_MIN - 1);
	ft_printf("%i", INT_MAX + 1);
	ft_printf("%%i 0000042 == |%i|\n", 0000042);
	ft_printf("%%i \t == |%i|\n", '\t');
	ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_i.out", 0644);
	fpin = fopen("test_i.in", "r+");
	fpout = fopen("test_i.out", "r+");
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
		printf("test_i: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_i: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:30 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_l( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_l.in", "w+");
	//fprintf(fpin, "%Le", (long double)42);
	//fprintf(fpin, "Kashim a %Le histoires à raconter", (long double)1001);
	//fprintf(fpin, "Il fait au moins %Le\n", (long double)-8000);
	//fprintf(fpin, "%Le", (long double)-0);
	//fprintf(fpin, "%Le", (long double)0);
	//fprintf(fpin, "%Le", (long double)INT_MAX);
	//fprintf(fpin, "%Le", (long double)INT_MIN);
	//fprintf(fpin, "%Le", (long double)INT_MIN - 1);
	//fprintf(fpin, "%Le", (long double)INT_MAX + 1);
	//fprintf(fpin, "%Le", (long double)LONG_MAX);
	//fprintf(fpin, "%Le", (long double)LONG_MIN);
	//fprintf(fpin, "%Le", (long double)LONG_MIN - 1);
	//fprintf(fpin, "%Le", (long double)LONG_MAX + 1);
	//fprintf(fpin, "%%Le 0000042 == |%Le|\n", (long double)0000042);
	//fprintf(fpin, "%%Le \t == |%Le|\n", (long double)'\t');
	//fprintf(fpin, "%%Le Lydie == |%Le|\n", (long double)'L'+'y'+'d'+'i'+'e');
	//fprintf(fpin, "%%Le 42.42 == |%Le|\n", (long double)42.42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_l.out", "w+", stdout);
	ft_printf("%Le", (long double)42);
	ft_printf("Kashim a %Le histoires à raconter", (long double)1001);
	ft_printf("Il fait au moins %Le\n", (long double)-8000);
	ft_printf("%Le", (long double)-0);
	ft_printf("%Le", (long double)0);
	ft_printf("%Le", (long double)INT_MAX);
	ft_printf("%Le", (long double)INT_MIN);
	ft_printf("%Le", (long double)INT_MIN - 1);
	ft_printf("%Le", (long double)INT_MAX + 1);
	ft_printf("%Le", (long double)LONG_MAX);
	ft_printf("%Le", (long double)LONG_MIN);
	ft_printf("%Le", (long double)LONG_MIN - 1);
	ft_printf("%Le", (long double)LONG_MAX + 1);
	ft_printf("%%Le 0000042 == |%Le|\n", (long double)0000042);
	ft_printf("%%Le \t == |%Le|\n", (long double)'\t');
	ft_printf("%%Le Lydie == |%Le|\n", (long double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%Le 42.42 == |%Le|\n", (long double)42.42);

	chmod("test_l.out", 0644);
	fpin = fopen("test_l.in", "r+");
	fpout = fopen("test_l.out", "r+");
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
		printf("test_L: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_L: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:33 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_lc( void )
{
	int			r00 = 0;
	wchar_t		c = L'\x82';
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	fpin = fopen("test_lc.in", "w+");
	fprintf(fpin, "%C\n", c);
	fprintf(fpin, "%C\n", L'ø');
	fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_lc.out", "w+", stdout);
	ft_printf("%C\n", c);
	ft_printf("%C\n", L'ø');

	chmod("test_lc.out", 0644);
	fpin = fopen("test_lc.in", "r+");
	fpout = fopen("test_lc.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fflush(stdout);
	dup2(fd, fileno(stdout));
	close(fd);
	clearerr(stdout);
	fsetpos(stdout, &pos);
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}
	if (fdin != fdout)
		r00 = 1;

	if (r00 == 0) {
		printf("test_C: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_C: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:39 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:42 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:47 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_minus( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_minus.in", "w+");
	//fprintf(fpin, "%%-i 42 == %-i\n", 42);
	//fprintf(fpin, "%%-d 42 == %-d\n", INT_MIN);
	//fprintf(fpin, "%%-i -42 == %-i\n", -42);
	//fprintf(fpin, "%%-4d 42 == |%-4d|\n", 42);
	//fprintf(fpin, "%%-5d -42 == |%-5d|\n", -42);
	//fprintf(fpin, "|%3i|%-3i|\n", 42, 42);
	//fprintf(fpin, "%%-4i 42 == |%-4i|\n", 42);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_minus.out", "w+", stdout);
	ft_printf("%%-i 42 == %-i\n", 42);
	ft_printf("%%-d 42 == %-d\n", INT_MIN);
	ft_printf("%%-i -42 == %-i\n", -42);
	ft_printf("%%-4d 42 == |%-4d|\n", 42);
	ft_printf("%%-5d -42 == |%-5d|\n", -42);
	ft_printf("|%3i|%-3i|\n", 42, 42);
	ft_printf("%%-4i 42 == |%-4i|\n", 42);

	chmod("test_minus.out", 0644);
	fpin = fopen("test_minus.in", "r+");
	fpout = fopen("test_minus.out", "r+");
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
		printf("test_minus: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_minus: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:21:35 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_mix( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	fpin = fopen("test_mix.in", "w+");
	fprintf(fpin, "Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);
	fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_mix.out", "w+", stdout);
	ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);

	chmod("test_mix.out", 0644);
	fpin = fopen("test_mix.in", "r+");
	fpout = fopen("test_mix.out", "r+");
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
		printf("test_mix: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_mix: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mix2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:52 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_mix2( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_mix2.in", "w+");
	//fprintf(fpin, "Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_mix2.out", "w+", stdout);
	ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");

	chmod("test_mix2.out", 0644);
	fpin = fopen("test_mix2.in", "r+");
	fpout = fopen("test_mix2.out", "r+");
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
		printf("test_mix2: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_mix2: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:55 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:05:59 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_o( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_o.in", "w+");
	//fprintf(fpin, "%o", 42);
	//fprintf(fpin, "Kashim a %o histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %o\n", -8000);
	//fprintf(fpin, "%o", -0);
	//fprintf(fpin, "%o", 0);
	//fprintf(fpin, "%o", INT_MAX);
	//fprintf(fpin, "%o", INT_MIN);
	//fprintf(fpin, "%o", INT_MIN - 1);
	//fprintf(fpin, "%o", INT_MAX + 1);
	//fprintf(fpin, "%%o 0000042 == |%o|\n", 0000042);
	//fprintf(fpin, "%%o \t == |%o|\n", '\t');
	//fprintf(fpin, "%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:24:46 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_p( void )
{
	int			r00 = 0;
	char		c = 0;
	char		*str = "pouet";
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	fpin = fopen("test_p.in", "w+");
	fgetpos(stdout, &pos);
	freopen("test_p.out", "w+", stdout);

	fprintf(fpin, "%p\n", &c);
	ft_printf("%p\n", &c);
	fprintf(fpin, "%p\n", str);
	ft_printf("%p\n", str);
	fprintf(fpin, "%p\n", &str);
	ft_printf("%p\n", &str);
	str = NULL;
	fprintf(fpin, "0x0\n");
	ft_printf("%p\n", str);
	str = (char *)malloc(sizeof(char) * 10);
	str = strdup("Coucou les haricots !");
	fprintf(fpin, "%p\n", str);
	ft_printf("%p\n", str);
	fclose(fpin);

	chmod("test_p.out", 0644);
	fpin = fopen("test_p.in", "r+");
	fpout = fopen("test_p.out", "r+");
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
		printf("test_p: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_p: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:13 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_plus( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_plus.in", "w+");
	//fprintf(fpin, "%%+i 42 == %+i\n", 42);
	//fprintf(fpin, "%%+d 42 == %+d\n", INT_MAX);
	//fprintf(fpin, "%%+i -42 == %+i\n", -42);
	//fprintf(fpin, "%%+04d 42 == %0+04d\n", 42);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_plus.out", "w+", stdout);
	ft_printf("%%+i 42 == %+i\n", 42);
	ft_printf("%%+d 42 == %+d\n", INT_MAX);
	ft_printf("%%+i -42 == %+i\n", -42);
	ft_printf("%%+04d 42 == %0+04d\n", 42);

	chmod("test_plus.out", 0644);
	fpin = fopen("test_plus.in", "r+");
	fpout = fopen("test_plus.out", "r+");
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
		printf("test_plus: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_plus: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:15 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_precision( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_precision.in", "w+");
	//fprintf(fpin, "%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	//fprintf(fpin, "%% 4.5i 42 == |% 4.5i|\n", 42);
	//fprintf(fpin, "%%04.5i 42 == |%04.5i|\n", 42);
	//fprintf(fpin, "%%04.3i 42 == |%04.3i|\n", 42);
	//fprintf(fpin, "%%04.2i 42 == |%04.2i|\n", 42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_precision.out", "w+", stdout);
	ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);
	ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	ft_printf("%%04.2i 42 == |%04.2i|\n", 42);

	chmod("test_precision.out", 0644);
	fpin = fopen("test_precision.in", "r+");
	fpout = fopen("test_precision.out", "r+");
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
		printf("test_precision: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_precision: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2016/02/03 12:04:16 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
// #include "tests.h"

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
/*   test_sharp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:44 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_sharp( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_sharp.in", "w+");
	//fprintf(fpin, "%%#X 42 ==  %#X\n", 42);
	//fprintf(fpin, "%%X 42 ==  %X\n", 42);
	//fprintf(fpin, "%%#o 0 ==  %#o\n", 0);
	//fprintf(fpin, "%%o 0 ==  %o\n", 0);
	//fprintf(fpin, "%%#o INT_MAX ==  %#o\n", INT_MAX);
	//fprintf(fpin, "%%o INT_MAX ==  %o\n", INT_MAX);
	//fprintf(fpin, "%%#o INT_MIN ==  %#o\n", INT_MIN);
	//fprintf(fpin, "%%o INT_MIN ==  %o\n", INT_MIN);
	//fprintf(fpin, "%%#X INT_MIN ==  %#X\n", INT_MIN);
	//fprintf(fpin, "%%X INT_MIN ==  %X\n", INT_MIN);
	//fprintf(fpin, "%%#X INT_MAX ==  %#X\n", INT_MAX);
	//fprintf(fpin, "%%X INT_MAX ==  %X\n", INT_MAX);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_sharp.out", "w+", stdout);
	ft_printf("%%#X 42 ==  %#X\n", 42);
	ft_printf("%%X 42 ==  %X\n", 42);
	ft_printf("%%#o 0 ==  %#o\n", 0);
	ft_printf("%%o 0 ==  %o\n", 0);
	ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
	ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
	ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
	ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);

	chmod("test_sharp.out", 0644);
	fpin = fopen("test_sharp.in", "r+");
	fpout = fopen("test_sharp.out", "r+");
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
		printf("test_sharp: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_sharp: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:47 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_space( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_space.in", "w+");
	//fprintf(fpin, "%%      i 42 == |%      i|\n", 42);
	//fprintf(fpin, "%% i -42 == |% i|\n", -42);
	//fprintf(fpin, "%% 4i 42 == |% 4i|\n", 42);

	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_space.out", "w+", stdout);
	ft_printf("%%      i 42 == |%      i|\n", 42);
	ft_printf("%% i -42 == |% i|\n", -42);
	ft_printf("%% 4i 42 == |% 4i|\n", 42);

	chmod("test_space.out", 0644);
	fpin = fopen("test_space.in", "r+");
	fpout = fopen("test_space.out", "r+");
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
		printf("test_space: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_space: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:50 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_star( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_star.in", "w+");
	//fprintf(fpin, "%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	//fprintf(fpin, "%% *.5i 42 == |% *.5i|\n", 4, 42);
	//fprintf(fpin, "%%*i 42 == |%*i|\n", 5, 42);
	//fprintf(fpin, "%%*i 42 == |%*i|\n", 3, 42);
	//fprintf(fpin, "%%*i 42 == |%*i|\n", 2, 42);
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_star.out", "w+", stdout);
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%*i|\n", 2, 42);

	chmod("test_star.out", 0644);
	fpin = fopen("test_star.in", "r+");
	fpout = fopen("test_star.out", "r+");
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
		printf("test_star: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_star: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:53 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

int		test_u( void )
{
	int			r00 = 0;
	fpos_t		pos;
	FILE		*fpin, *fpout;
	int			fdin, fdout;
	int			fd = dup(fileno(stdout));

	//fpin = fopen("test_u.in", "w+");
	//fprintf(fpin, "%u", 42);
	//fprintf(fpin, "Kashim a %u histoires à raconter", 1001);
	//fprintf(fpin, "Il fait au moins %u\n", -8000);
	//fprintf(fpin, "%u", -0);
	//fprintf(fpin, "%u", 0);
	//fprintf(fpin, "%u", INT_MAX);
	//fprintf(fpin, "%u", INT_MIN);
	//fprintf(fpin, "%u", INT_MIN - 1);
	//fprintf(fpin, "%u", INT_MAX + 1);
	//fprintf(fpin, "%%u 0000042 == |%u|\n", 0000042);
	//fprintf(fpin, "%%u \t == |%u|\n", '\t');
	//fprintf(fpin, "%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
	//fclose(fpin);

	fgetpos(stdout, &pos);
	freopen("test_u.out", "w+", stdout);
	ft_printf("%u", 42);
	ft_printf("Kashim a %u histoires à raconter", 1001);
	ft_printf("Il fait au moins %u\n", -8000);
	ft_printf("%u", -0);
	ft_printf("%u", 0);
	ft_printf("%u", INT_MAX);
	ft_printf("%u", INT_MIN);
	ft_printf("%u", INT_MIN - 1);
	ft_printf("%u", INT_MAX + 1);
	ft_printf("%%u 0000042 == |%u|\n", 0000042);
	ft_printf("%%u \t == |%u|\n", '\t');
	ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

	chmod("test_u.out", 0644);
	fpin = fopen("test_u.in", "r+");
	fpout = fopen("test_u.out", "r+");
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
		printf("test_u: [ok]\n");
		return 1;
	}
	printf(ANSI_COLOR_RED "test_u: [ko]\n" ANSI_COLOR_RESET);
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:06:57 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
/*   Updated: 2016/12/19 21:07:01 by mhurd            ###   ########.fr       */
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
// #include "tests.h"

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

int             main( void ) {

        unsigned int    count = 0;

        printf("Testing %%c\n");
        count += test_c();
        printf("Testing %%d\n");
        count += test_d();
        printf("Testing widths\n");
        count += test_hhhllljz();
        printf("Testing %%i\n");
        count += test_i();
        printf("Testing %%C\n");
        count += test_lc();
        printf("Testing %%S\n");
        count += test_ls();
        printf("Testing %%D\n");
        count += test_ld();
        printf("Testing minus\n");
        count += test_minus();
        printf("Testing mix (%%d %%s %%p)\n");
        count += test_mix();
        printf("Testing mix2 (%%d %%C %%s %%d %%u %%X %%c)\n");
        count += test_mix2();
        printf("Testing %%o\n");
        count += test_o();
        printf("Testing %%p\n");
        count += test_p();
        printf("Testing plus\n");
        count += test_plus();
        printf("Testing precision\n");
        count += test_precision();
        printf("Testing #\n");
        count += test_sharp();
        // printf(ANSI_COLOR_RED "SEG FAULT\n" ANSI_COLOR_RESET);
        printf("Testing space\n");
        count += test_space();
        printf("Testing %%u\n");
        count += test_u();
        printf("Testing %%x\n");
        count += test_x();
        printf("Testing 0\n");
        count += test_zero();
        printf("Testing %%s\n");
        count += test_s();

        printf("Bonus:\n\n");
        printf("Testing *\n");
        count += test_star();
        printf("Testing %%a\n");
        count += test_a();
        printf("Testing %%e\n");
        count += test_e();
        printf("Testing %%f\n");
        count += test_f();
        printf("Testing %%g\n");
        count += test_g();
        printf("Testing %%Le\n");
        count += test_l();
        printf("Testing %%n\n");
        count += test_n();
        return 0;
}

// #include <stdio.h>

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h>
// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <limits.h>

// #include <limits.h>
// #define ANSI_COLOR_RED     "\x1b[31m"
// #define ANSI_COLOR_GREEN   "\x1b[32m"
// #define ANSI_COLOR_YELLOW  "\x1b[33m"
// #define ANSI_COLOR_BLUE    "\x1b[34m"
// #define ANSI_COLOR_MAGENTA "\x1b[35m"
// #define ANSI_COLOR_CYAN    "\x1b[36m"
// #define ANSI_COLOR_RESET   "\x1b[0m"

// int
// main(void)
// {
// 	// int ret;
// 	// wchar_t wz [3] = L"@@";
// 	// ft_printf("%S\n", wz);
// 	// printf("%S\n", wz);
// 	test_s();
// 	test_ls();
// 	test_c();
// 	test_d();
// 	test_ld();
// 	test_x();
// 	test_zero();
// 	test_o();
// 	int i;

// 	printf("pf: %x\n", -0);
// 	ft_printf("ft: %x\n", -0);
// }

// int		test_ls( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	wchar_t wz [3] = L"@@";       // Zero-terminated
// 	int			fd = dup(fileno(stdout));

// 	//fpin = fopen("test_ls.in", "w+");
// 	//fprintf(fpin,"%ls", wz);   // Outputs 6 bytes
// 	//fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_ls.out", "w+", stdout);
// 	ft_printf("%ls", wz);   // Outputs 6 bytes

// 	chmod("test_ls.out", 0644);
// 	fpin = fopen("test_ls.in", "r+");
// 	fpout = fopen("test_ls.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_S: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_S: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }

// int		test_s( void )
// {
// 	int			r00 = 0;
// 	char		*str = NULL;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	fgetpos(stdout, &pos);
// 	freopen("test_s.out", "w+", stdout);
// 	ft_printf("%s", "pouet");
// 	ft_printf(" pouet %s !!\n", "camembert");
// 	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
// 	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
// 	ft_printf("%s!\n", str);
// 	ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");



// 	chmod("test_s.out", 0644);
// 	fpin = fopen("test_s.in", "r+");
// 	fpout = fopen("test_s.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_s: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_s: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test_d.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2016/02/03 13:07:15 by ly                #+#    #+#             */
// /*   Updated: 2016/12/19 21:04:42 by mhurd            ###   ########.fr       */
// /*                                                                            */
//  ************************************************************************** 
// int		test_d( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	//fpin = fopen("test_d.in", "w+");
// 	//fprintf(fpin, "%d", 42);
// 	//fprintf(fpin, "Kashim a %d histoires à raconter", 1001);
// 	//fprintf(fpin, "Il fait au moins %d\n", -8000);
// 	//fprintf(fpin, "%d", -0);
// 	//fprintf(fpin, "%d", 0);
// 	//fprintf(fpin, "%d", INT_MAX);
// 	//fprintf(fpin, "%d", INT_MIN);
// 	//fprintf(fpin, "%d", INT_MIN - 1);
// 	//fprintf(fpin, "%d", INT_MAX + 1);
// 	//fprintf(fpin, "%%d 0000042 == |%d|\n", 0000042);
// 	//fprintf(fpin, "%%d \t == |%d|\n", '\t');
// 	//fprintf(fpin, "%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
// 	//fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_d.out", "w+", stdout);
// 	ft_printf("%d", 42);
// 	ft_printf("Kashim a %d histoires à raconter", 1001);
// 	ft_printf("Il fait au moins %d\n", -8000);
// 	ft_printf("%d", -0);
// 	ft_printf("%d", 0);
// 	ft_printf("%d", INT_MAX);
// 	ft_printf("%d", INT_MIN);
// 	ft_printf("%d", INT_MIN - 1);
// 	ft_printf("%d", INT_MAX + 1);
// 	ft_printf("%%d 0000042 == |%d|\n", 0000042);
// 	ft_printf("%%d \t == |%d|\n", '\t');
// 	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);

// 	chmod("test_d.out", 0644);
// 	fpin = fopen("test_d.in", "r+");
// 	fpout = fopen("test_d.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	if (r00 == 0) {
// 		printf("test_d: [ok]\n");
// 		return 1;
// 	}
// 	printf("test_d: [ko]\n");
// 	return 0;
// }

// int		test_ld( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	//fpin = fopen("test_ld.in", "w+");
// 	//fprintf(fpin, "%D", 42);
// 	//fprintf(fpin, "Kashim a %D histoires à raconter", 1001);
// 	//fprintf(fpin, "Il fait au moins %D\n", -8000);
// 	//fprintf(fpin, "%D", -0);
// 	//fprintf(fpin, "%D", 0);
// 	//fprintf(fpin, "%D", INT_MAX);
// 	//fprintf(fpin, "%D", INT_MIN);
// 	//fprintf(fpin, "%D", INT_MIN - 1);
// 	//fprintf(fpin, "%D", INT_MAX + 1);
// 	//fprintf(fpin, "%%D 0000042 == |%D|\n", 0000042);
// 	//fprintf(fpin, "%%D \t == |%D|\n", '\t');
// 	//fprintf(fpin, "%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');
// 	//fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_ld.out", "w+", stdout);
// 	ft_printf("%D", 42);
// 	ft_printf("Kashim a %D histoires à raconter", 1001);
// 	ft_printf("Il fait au moins %D\n", -8000);
// 	ft_printf("%D", -0);
// 	ft_printf("%D", 0);
// 	ft_printf("%D", INT_MAX);
// 	ft_printf("%D", INT_MIN);
// 	ft_printf("%D", INT_MIN - 1);
// 	ft_printf("%D", INT_MAX + 1);
// 	ft_printf("%%D 0000042 == |%D|\n", 0000042);
// 	ft_printf("%%D \t == |%D|\n", '\t');
// 	ft_printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');

// 	chmod("test_ld.out", 0644);
// 	fpin = fopen("test_ld.in", "r+");
// 	fpout = fopen("test_ld.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_ld: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_ld: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }

// int		test_n( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	//fpin = fopen("test_n.in", "w+");
// 	int		nb = 42;
// 	//fprintf(fpin, "LALALALALAL\n%n", &nb);
// 	//fprintf(fpin, "%d\n", nb);
// 	//fprintf(fpin, "Kashim a %d histoires à raconter\n%n", 1001, &nb);
// 	//fprintf(fpin, "%d\n", nb);
// 	//fprintf(fpin, "%d%n", '\t', &nb);
// 	//fprintf(fpin, "%d\n", nb);
// 	//fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_n.out", "w+", stdout);
// 	int nb2 = 42;
// 	ft_printf("LALALALALAL\n%n", &nb2);
// 	ft_printf("%d\n", nb2);
// 	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &nb2);
// 	ft_printf("%d\n", nb2);
// 	ft_printf("%d%n", '\t', &nb2);
// 	ft_printf("%d\n", nb2);

// 	chmod("test_n.out", 0644);
// 	fpin = fopen("test_n.in", "r+");
// 	fpout = fopen("test_n.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_n: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_n: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }

// int		test_c( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	// fpin = fopen("test_c.in", "w+");
// 	// fprintf(fpin, "%c", 42);
// 	// fprintf(fpin, "Kashim a %c histoires à raconter", 1001);
// 	// fprintf(fpin, "Il fait au moins %c\n", -8000);
// 	// fprintf(fpin, "%c", -0);
// 	// fprintf(fpin, "%c", 0);
// 	// fprintf(fpin, "%c\n", INT_MAX);
// 	// fprintf(fpin, "%c\n", 'c');
// 	// fprintf(fpin, "%c\n", '\n');
// 	// fprintf(fpin, "%c", 'l');
// 	// fprintf(fpin, "%c", 'y');
// 	// fprintf(fpin, "%c", ' ');
// 	// fprintf(fpin, "%c", 'e');
// 	// fprintf(fpin, "%c", 's');
// 	// fprintf(fpin, "%c", 't');
// 	// fprintf(fpin, "%c", ' ');
// 	// fprintf(fpin, "%c", 'f');
// 	// fprintf(fpin, "%c", 'a');
// 	// fprintf(fpin, "%c", 'n');
// 	// fprintf(fpin, "%c", 't');
// 	// fprintf(fpin, "%c", 'a');
// 	// fprintf(fpin, "%c", 's');
// 	// fprintf(fpin, "%c", 't');
// 	// fprintf(fpin, "%c", 'i');
// 	// fprintf(fpin, "%c", 'q');
// 	// fprintf(fpin, "%c", 'u');
// 	// fprintf(fpin, "%c", 'e');
// 	// fprintf(fpin, "%c\n", '!');
// 	// fprintf(fpin, "%c\n", '\r');
// 	// fprintf(fpin, "%c\n", '\t');
// 	// fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_c.out", "w+", stdout);
// 	ft_printf("%c", 42);
// 	ft_printf("Kashim a %c histoires à raconter", 1001);
// 	ft_printf("Il fait au moins %c\n", -8000);
// 	ft_printf("%c", -0);
// 	ft_printf("%c", 0);
// 	ft_printf("%c\n", INT_MAX);
// 	ft_printf("%c\n", 'c');
// 	ft_printf("%c\n", '\n');
// 	ft_printf("%c", 'l');
// 	ft_printf("%c", 'y');
// 	ft_printf("%c", ' ');
// 	ft_printf("%c", 'e');
// 	ft_printf("%c", 's');
// 	ft_printf("%c", 't');
// 	ft_printf("%c", ' ');
// 	ft_printf("%c", 'f');
// 	ft_printf("%c", 'a');
// 	ft_printf("%c", 'n');
// 	ft_printf("%c", 't');
// 	ft_printf("%c", 'a');
// 	ft_printf("%c", 's');
// 	ft_printf("%c", 't');
// 	ft_printf("%c", 'i');
// 	ft_printf("%c", 'q');
// 	ft_printf("%c", 'u');
// 	ft_printf("%c", 'e');
// 	ft_printf("%c\n", '!');
// 	ft_printf("%c\n", '\r');
// 	ft_printf("%c\n", '\t');

// 	chmod("test_c.out", 0644);
// 	fpin = fopen("test_c.in", "r+");
// 	fpout = fopen("test_c.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}
// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_c: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_c: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }

// int		test_x( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	//fpin = fopen("test_x.in", "w+");
// 	//fprintf(fpin, "%x", 42);
// 	//fprintf(fpin, "Kashim a %x histoires à raconter", 1001);
// 	//fprintf(fpin, "Il fait au moins %x\n", -8000);
// 	//fprintf(fpin, "%x", -0);
// 	//fprintf(fpin, "%x", 0);
// 	//fprintf(fpin, "%x", INT_MAX);
// 	//fprintf(fpin, "%x", INT_MIN);
// 	//fprintf(fpin, "%x", INT_MIN - 1);
// 	//fprintf(fpin, "%x", INT_MAX + 1);
// 	//fprintf(fpin, "%%x 0000042 == |%x|\n", 0000042);
// 	//fprintf(fpin, "%%x \t == |%x|\n", '\t');
// 	//fprintf(fpin, "%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
// 	//fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_x.out", "w+", stdout);
// 	ft_printf("%x", 42);
// 	ft_printf("Kashim a %x histoires à raconter", 1001);
// 	ft_printf("Il fait au moins %x\n", -8000);
// 	ft_printf("%x", -0);
// 	ft_printf("%x", 0);
// 	ft_printf("%x", INT_MAX);
// 	ft_printf("%x", INT_MIN);
// 	ft_printf("%x", INT_MIN - 1);
// 	ft_printf("%x", INT_MAX + 1);
// 	ft_printf("%%x 0000042 == |%x|\n", 0000042);
// 	ft_printf("%%x \t == |%x|\n", '\t');
// 	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

// 	chmod("test_x.out", 0644);
// 	fpin = fopen("test_x.in", "r+");
// 	fpout = fopen("test_x.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_x: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_x: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }
// int		test_o( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	// fpin = fopen("test_o.in", "w+");
// 	// fprintf(fpin, "%o", 42);
// 	// fprintf(fpin, "Kashim a %o histoires à raconter", 1001);
// 	// fprintf(fpin, "Il fait au moins %o\n", -8000);
// 	// fprintf(fpin, "%o", -0);
// 	// fprintf(fpin, "%o", 0);
// 	// fprintf(fpin, "%o", INT_MAX);
// 	// fprintf(fpin, "%o", INT_MIN);
// 	// fprintf(fpin, "%o", INT_MIN - 1);
// 	// fprintf(fpin, "%o", INT_MAX + 1);
// 	// fprintf(fpin, "%%o 0000042 == |%o|\n", 0000042);
// 	// fprintf(fpin, "%%o \t == |%o|\n", '\t');
// 	// fprintf(fpin, "%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
// 	// fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_o.out", "w+", stdout);
// 	ft_printf("%o", 42);
// 	ft_printf("Kashim a %o histoires à raconter", 1001);
// 	ft_printf("Il fait au moins %o\n", -8000);
// 	ft_printf("%o", -0);
// 	ft_printf("%o", 0);
// 	ft_printf("%o", INT_MAX);
// 	ft_printf("%o", INT_MIN);
// 	ft_printf("%o", INT_MIN - 1);
// 	ft_printf("%o", INT_MAX + 1);
// 	ft_printf("%%o 0000042 == |%o|\n", 0000042);
// 	ft_printf("%%o \t == |%o|\n", '\t');
// 	ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');

// 	chmod("test_o.out", 0644);
// 	fpin = fopen("test_o.in", "r+");
// 	fpout = fopen("test_o.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}

// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_o: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_o: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }

// int		test_zero( void )
// {
// 	int			r00 = 0;
// 	fpos_t		pos;
// 	FILE		*fpin, *fpout;
// 	int			fdin, fdout;
// 	int			fd = dup(fileno(stdout));

// 	//fpin = fopen("test_zero.in", "w+");
// 	//fprintf(fpin, "%%04i 42 == |%04i|\n", 42);
// 	//fprintf(fpin, "%%05i 42 == |%05i|\n", 42);
// 	//fprintf(fpin, "%%0i 42 == |%0i|\n", 42);
// 	//fprintf(fpin, "%%0d 0000042 == |%0d|\n", 0000042);

// 	//fclose(fpin);

// 	fgetpos(stdout, &pos);
// 	freopen("test_zero.out", "w+", stdout);
// 	ft_printf("%%04i 42 == |%04i|\n", 42);
// 	ft_printf("%%05i 42 == |%05i|\n", 42);
// 	ft_printf("%%0i 42 == |%0i|\n", 42);
// 	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

// 	chmod("test_zero.out", 0644);
// 	fpin = fopen("test_zero.in", "r+");
// 	fpout = fopen("test_zero.out", "r+");
// 	if (!fpin || !fpout) {
// 		perror("error: ");
// 		return 0;
// 	}
// 	fdin = getc(fpin);
// 	fdout = getc(fpout);
// 	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
// 		fdin = getc(fpin);
// 		fdout = getc(fpout);
// 	}
// 	if (fdin != fdout)
// 		r00 = 1;

// 	fflush(stdout);
// 	dup2(fd, fileno(stdout));
// 	close(fd);
// 	clearerr(stdout);
// 	fsetpos(stdout, &pos);
// 	if (r00 == 0) {
// 		printf("test_zero: [ok]\n");
// 		return 1;
// 	}
// 	printf(ANSI_COLOR_RED "test_zero: [ko]\n" ANSI_COLOR_RESET);
// 	return 0;
// }