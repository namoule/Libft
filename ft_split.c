/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannelefevre <jeannelefevre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:37:39 by jealefev          #+#    #+#             */
/*   Updated: 2023/11/16 11:56:05 by jeannelefev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

int ft_countword(const char *str, char c)
{
    int i;
    int w;
    i = 0;
    w = 0;
    while(str[i])
    {
        if(str[i] == c)
            w++;
        i++;
    }
    w++;
    return(w);
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;
    i = 0;
    while(src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return(dest);
    
}

char *ft_strndup(const char *s, size_t n)
{
    char *str;
    str = (char *)malloc(sizeof(char *) + 1);
    if(str == NULL)
        return(NULL);
    str = ft_strncpy(str, s, n);
    str[n] = '\0';
    return(str);
}




char    **ft_split(char const *s, char c)
{
    int i;
    int j;
    int k;
    char **tab;

    i = 0;
    k = 0;
    tab = (char **)malloc(sizeof (char *) * (ft_countword(s, c)) +1);
    while(s[i])
    {
        while(s[i] == c)
            i++;
        j = i;
        while(s[i] && s[i] != c)
            i++;
        if(i > j)
        {
            tab[k] = ft_strndup(s + j, i - j);
            k++;
        }
    }
    tab[k] = NULL;
    return(tab);
}


// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     if(argc == 3)
//         printf("%c \n",ft_split(argv[1], argv[2]));
//     return(0);}
