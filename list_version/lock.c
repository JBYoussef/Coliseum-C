/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:31:25 by jbofengo          #+#    #+#             */
/*   Updated: 2025/02/28 13:32:01 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

// Obtém o endereço inicial do bloco e valida se está dentro da arena
t_uch8	*get_addr_start(void **addr, size_t addr_size, t_arena *arena)
{
	t_uch8	*addr_start;

	if (!addr || !*addr || !arena || !arena->buffer)
		return (NULL);
	addr_start = (t_uch8 *)*addr;
	if (addr_start < arena->buffer || addr_start >= arena->buffer + arena->size)
		return (NULL);
	*addr = NULL; // Marca o ponteiro como utilizado
	return (addr_start);
}

// Remove um bloco do início de um bloco livre
bool	remove_addr_from_begin(t_free *current, size_t addr_size, t_arena *arena, t_free *prev)
{
	current->addr += addr_size;
	current->addr_size -= addr_size;
	if (current->addr_size == 0)
	{
		if (prev)
			prev->next = current->next;
		else
			arena->free_blocks = current->next; // Atualiza o início da lista
		free(current);
	}
	return (1);
}

// Remove um bloco do meio de um bloco livre, dividindo-o em dois
bool	remove_addr_from_middle(t_uch8 *addr_start, size_t addr_size, t_free *current)
{
	t_free	*new_current;
	size_t	current_size;

	current_size = (current->addr + current->addr_size) - (addr_start + addr_size);
	new_current = create_free_node(addr_start + addr_size, current_size);
	if (!new_current)
		return (0);
	current->addr_size -= addr_start - current->addr;
	new_current->next = current->next;
	current->next = new_current;
	return (1);
}

// Função principal para definir um bloco de memória na arena como ocupado
bool	lock_ptr_in_arena(void **addr, size_t addr_size, t_arena *arena)
{
	t_free	*current;
	t_uch8	*addr_start;
	t_free	*prev;

	addr_start = get_addr_start(addr, addr_size, arena);
	if (!addr_start)
		return (0);
	prev = NULL;
	current = arena->free_blocks;
	while (current)
	{
		if (address_on_current_block(addr_start, addr_size, current))
		{
			if (addr_start == current->addr) // Bloco no início do bloco livre
				return (remove_addr_from_begin(current, addr_size, arena, prev));
			else if ((addr_start + addr_size) < (current->addr + current->addr_size))// Bloco no meio do bloco livre
				return (remove_addr_from_middle(addr_start, addr_size, current));
		}
		else // Bloco no final do bloco livre
		{
			current->addr_size -= addr_size;
			return (1);
		}
		prev = current;
		current = current->next;
	}
	// Bloco não encontrado na lista de blocos livres
	return (0);
}
