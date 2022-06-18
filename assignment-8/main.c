#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int	main(void)
{
	int	xs, seqlen, *seq;
	int	*loop, looplen;
	int	*histogram = (int *)calloc(9, sizeof(int));

	/* Generate sequence part */
	printf("Please enter the sequence lenght: ");
	scanf("%d", &seqlen);
	printf("Please enter the first element: ");
	scanf("%d", &xs);
	seq = (int *)calloc(seqlen, sizeof(int));

	generate_sequence(xs, 0, seqlen, seq);

	printf("Sequence: ");
	print_arr(seq, seqlen);
	/* Generate sequence part is finished */

	/* Loop part */
	looplen = seqlen / 2;
	loop = (int *)calloc(looplen, sizeof(int));
	check_loop_iterative(generate_sequence, xs, seqlen, loop, &looplen);
	if (loop[0] != 0)
	{
		printf("\nLoop: ");
		print_arr(loop, looplen);
	}
	else
		printf("\nNo loop found.\n");
	/* Loop part is finished */

	/* Histogram part */
	hist_of_firstdigits(generate_sequence, xs, seqlen, histogram, 0);
	printf("\nHistogram of the sequence: ");
	print_arr(histogram, 9);
	/* Histogram part is finished */

	free(seq);
	free(loop);
	free(histogram);
	return (0);
}