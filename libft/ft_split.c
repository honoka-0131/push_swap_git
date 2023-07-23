/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_re.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:24:57 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/05 13:58:42 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;
	bool	check_front;

	i = 0;
	count = 0;
	check_front = false;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != c)
	{
		i ++;
		check_front = true;
	}
	if (check_front)
		count ++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count ++;
		i ++;
	}
	return (count);
}

static size_t	check_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c && s[i] != '\0')
		i ++;
	while (s[i] != c && s[i] != '\0')
	{
		i ++;
		len ++;
	}
	return (len);
}

static char	**ft_free(char **ans)
{
	size_t	i;

	i = 0;
	if (ans == NULL)
		return (NULL);
	while (ans[i] != NULL)
	{
		free(ans[i]);
		i ++;
	}
	free(ans);
	return (NULL);
}

static void	strcpy_for_split(char *ans, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i] != '\0')
		i ++;
	while (s[i] != c && s[i] != '\0')
	{
		ans[j] = s[i];
		i ++;
		j ++;
	}
	ans[j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	num_word;
	size_t	num_len;
	size_t	i;

	num_word = count_word(s, c);
	i = 0;
	ans = ft_calloc(num_word + 1, sizeof(char *));
	if (ans == NULL || s == NULL)
		return (ft_free(ans));
	while (i < num_word)
	{
		num_len = check_len(s, c);
		ans[i] = ft_calloc(num_len + 1, sizeof(char));
		if (ans[i] == NULL)
			return (ft_free(ans));
		strcpy_for_split(ans[i], s, c);
		while (*s == c)
			s ++;
		s += num_len;
		i ++;
	}
	ans[i] = NULL;
	return (ans);
}
