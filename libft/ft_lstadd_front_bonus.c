/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ampjimen <ampjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:43:09 by ampjimen          #+#    #+#             */
/*   Updated: 2024/07/03 21:21:24 by ampjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*int main(void)
{
	t_list list1;
	list1.next = 0;
	list1.content = "HOLA 1";

	
	t_list list2;
	list2.content = "HOLA 1sdfdf";
	list2.next = 0;
	
	t_list *tmp = &list1;
	ft_lstadd_front(&tmp, &list2);

	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}*/
