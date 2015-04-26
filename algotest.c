/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algotest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 03:39:37 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/24 03:39:37 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void combinations (int v[], int start, int n, int k, int maxk) {
	int     i;

	/* k here counts through positions in the maxk-element v.
	 * if k > maxk, then the v is complete and we can use it.
	 */
	if (k > maxk) {
		/* insert code here to use combinations as you please */
		for (i=1; i<=maxk; i++) printf ("%i ", v[i]);
		printf("Kval= %d\n", k);
		printf ("==========RETURN==========\n\n");
		return;
	}

	/* for this k'th element of the v, try all start..n
	 * elements in that position
	 */
	for (i=start; i<=n; i++) {
		v[k] = i;

		/* recursively generate combinations of integers
		 * from i+1..n
		 // */
		 int j;
		 for (j=1; v[j] != 0; j++) printf ("%d ", v[j]);
		
		// printf("IN i %d\t|k\t%d\n", i, k);
		// printf("OUT i: %d\n", i);
		// printf("\n");
		if (i == n)
			printf("->[] ExiT===");
		printf("\n");
		combinations (v, i+1, n, k+1, maxk);
	}
	// printf("->[] ExiT\n");
}

int main (int argc, char *argv[]) {
		int     v[100], n, k;

		if (argc != 3) {
				printf ("Usage: %s n k\n", argv[0]);
				exit (1);
		}
		n = atoi (argv[1]);
		k = atoi (argv[2]);

		/* generate all combinations of n elements taken
		 * k at a time, starting with combinations containing 1
		 * in the first position.
		 */
		combinations (v, 1, n, 1, k);
		return (0);
}




// void			find_all(int r, int n)
// {
// 	int			i;
// 	int			j;
// 	int			m;
// 	int			max;
// 	char		*s;
// 	char		*d;

// 	d = "1234567";
// 	s = "     ";

// 	while (i < r)
// 	{
// 		s[i] = d[i];
// 		i++;
// 	}
// 	printf("1st: %s\n", s);

// 	i = 1;
// 	while (i <= (n - i))
// 	{
// 		m = r;
// 		max = n;
// 		while (s[m] == (n + '0'))
// 		{
// 			m--;
// 			max--;
// 		}
// 	}

// 5. for i = 2 to C(n,r) {
// 6. m = r
// 7. max val = n
// 8. while (sm == max val){
// // Find the rightmost element
// not at maximum value
// 9. m = m - 1
// 10. max val--
// 11. }
// // Increment the above rightmost
// element
// 12. sr++
// // All others are the successors
// of this element
// 13. for j = m + 1 to r
// 14. sj = sj−1 + 1
// // Print this new combination
// 15. print(s1, s2, ..., sr)
// 16. }
// 17. }


// int				main(int ac, char **av)
// {
// 	if (ac == 1)
// 	{
// 		find_all(5, 7);

// 	}
// 	printf("Name: %s\n", av[0]);
// 	return (0);
// }