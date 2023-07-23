/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:43:08 by hmakida           #+#    #+#             */
/*   Updated: 2023/02/05 13:56:30 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	check;
	size_t	cut_front;

	i = 0;
	cut_front = 0;
	while (s1[i])
	{
		j = 0;
		check = cut_front;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				cut_front ++;
				break ;
			}
			j ++;
		}
		if (check == cut_front)
			break ;
		i ++;
	}
	return (cut_front);
}

static size_t	back(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	check;
	size_t	cut_back;

	i = ft_strlen(s1) - 1;
	cut_back = 0;
	while (0 <= i)
	{
		j = 0;
		check = cut_back;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				cut_back ++;
				break ;
			}
			j ++;
		}
		if (check == cut_back)
			break ;
		i --;
	}
	return (cut_back);
}

static char	*make_ans(char *ans, char const *s1, char const *set, size_t len_s1)
{
	size_t	i;
	size_t	j;

	i = front(s1, set);
	j = 0;
	while (j < len_s1 - front(s1, set) - back(s1, set))
	{
		ans[j] = s1[i];
		i ++;
		j ++;
	}
	ans[j] = '\0';
	return (ans);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ans;
	size_t			len_s1;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	if (len_s1 - front((char *)s1, set) == 0)
	{
		ans = malloc(1);
		if (ans == NULL)
			return (NULL);
		*ans = '\0';
		return (ans);
	}
	ans = malloc((len_s1 - front(s1, set)
				- back(s1, set) + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	ans = make_ans(ans, s1, set, len_s1);
	return (ans);
}
