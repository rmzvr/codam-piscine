/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzvir <rzvir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:59:14 by rmzvr             #+#    #+#             */
/*   Updated: 2024/07/16 13:52:51 by rzvir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#ifndef HAVE_STRLCAT
/*
 * '_cups_strlcat()' - Safely concatenate two strings.
 */

size_t					 /* O - Length of string */
strlcat(char *dst,		 /* O - Destination string */
		const char *src, /* I - Source string */
		size_t size)	 /* I - Size of destination string buffer */
{
	size_t srclen; /* Length of source string */
	size_t dstlen; /* Length of destination string */

	/*
	 * Figure out how much room is left...
	 */

	dstlen = strlen(dst);
	size -= dstlen + 1;

	if (!size)
		return (dstlen); /* No room, return immediately... */

	/*
	 * Figure out how much room is needed...
	 */

	srclen = strlen(src);

	/*
	 * Copy the appropriate amount...
	 */

	if (srclen > size)
		srclen = size;

	memcpy(dst + dstlen, src, srclen);
	dst[dstlen + srclen] = '\0';

	return (dstlen + srclen);
}
#endif /* !HAVE_STRLCAT */

#ifndef HAVE_STRLCPY
/*
 * '_cups_strlcpy()' - Safely copy two strings.
 */

size_t					 /* O - Length of string */
strlcpy(char *dst,		 /* O - Destination string */
		const char *src, /* I - Source string */
		size_t size)	 /* I - Size of destination string buffer */
{
	size_t srclen; /* Length of source string */

	/*
	 * Figure out how much room is needed...
	 */

	size--;

	srclen = strlen(src);

	/*
	 * Copy the appropriate amount...
	 */

	if (srclen > size)
		srclen = size;

	memcpy(dst, src, srclen);
	dst[srclen] = '\0';

	return (srclen);
}
#endif /* !HAVE_STRLCPY */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int ft_strlcat(char *dest, const char *src, unsigned int size) {
    unsigned int dest_len = 0;
    unsigned int src_len = 0;
    unsigned int i;

    // Calculate the length of dest and src
    while (dest[dest_len] != '\0' && dest_len < size) {
        dest_len++;
    }
    while (src[src_len] != '\0') {
        src_len++;
    }

    // If the size is less than or equal to the length of dest, return size + src_len
    if (size <= dest_len) {
        return size + src_len;
    }

    // Copy src to dest, ensuring not to exceed the size
    i = 0;
    while (src[i] != '\0' && dest_len + i < size - 1) {
        dest[dest_len + i] = src[i];
        i++;
    }

    // Null-terminate the destination string
    if (dest_len + i < size) {
        dest[dest_len + i] = '\0';
    }

    // Return the length of the string that was tried to be created
    return dest_len + src_len;
}

int main(void)
{
	char dest[] = "AAA";
	char src[] = "BBB";
	int res;

	unsigned int	result = ft_strlcat(dest, src, 6);
	printf("%d\n", result);
	return (0);
}
