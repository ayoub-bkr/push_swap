#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->data < a->next->data && a->next->data > a->next->next->data)
		rra(&a);
	else if (a->data > a->next->data && a->data > a->next->next->data)
		ra(&a);
	if ((a->next->next->data > a->data && a->data > a->next->data))
		sa(&a);
}
int	*sorted_array(t_stack *a, int size)
{
	int		*sorted;
	t_stack	*tmp;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	tmp = a;
	while (tmp)
	{
		sorted[best_position(a, tmp->data)] = tmp->data;
		tmp = tmp->next;
	}
	return(sorted);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	mid;
	int	pos;
	while (*b)
	{
		mid = ft_lstsize(*b) / 2;
		pos = find_max(*b);
		if (pos <= mid)
			while(pos-- > 0)
				rb(b);
		else
			while(pos++ < ft_lstsize(*b))
				rrb(b);
		pa(a, b);
	}
}

void	push_to_b(t_stack **a, t_stack **b, int sort_min, int sort_max)
{
	pb(a, b);
	if (*a && (*a)->data <= sort_min)
		rb(b);
	else if (*a && (*a)->data <= sort_max)
	{
		if ((*b)->next && (*b)->data < (*b)->next->data)
	 		sb(b);
	}
}

void	sort_big(t_stack **a, t_stack **b, int size, int chunk)
{
	int min;
	int	max;
	int	*sorted;

	sorted = sorted_array(*a, size);
	min = 0;
	max = chunk;
	while (*a)
	{
		if ((*a)->data <= sorted[min] || (*a)->data <= sorted[max])
		{
			push_to_b(a, b, sorted[min], sorted[max]);
			if (min < max)
				min++;
			if (max < size - 1)
				max++;
		}
		else
			ra(a);
	}
	// t_stack *tmp = *a;
	// printf("----\n");
	// tmp = *a;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// printf("----\n");
	// tmp = *b;
	// while(tmp)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// }
	// printf("----\n");
	push_to_a(a, b);
	free(sorted);
}

// int	max_pos(t_stack *stb)
// {
// 	t_stack	*tmp;

// 	int (pos), (i), (max);
// 	i = 0;
// 	pos = 0;
// 	tmp = stb;
// 	max = tmp->data;
// 	while (tmp)
// 	{
// 		if (tmp->data > max)
// 		{
// 			max = tmp->data;
// 			pos = i;
// 		}
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (pos);
// }

// void	push_back_sta(t_stack	**sta, t_stack	**stb)
// {
// 	int (pos), (b_size);
// 	b_size = ft_lstsize(*stb);
// 	while (b_size > 0)
// 	{
// 		pos = max_pos(*stb);
// 		if (pos > b_size / 2)
// 			while (pos++ < b_size)
// 				rrb(stb);
// 		else if (pos <= b_size / 2)
// 			while (pos-- > 0)
// 				rb(stb);
// 		pa(sta, stb);
// 		b_size--;
// 	}
// }

// void	push_to_stb(t_stack **sta, t_stack **stb, int min, int max)
// {
// 	int	b_size;

// 	b_size = ft_lstsize(*stb);
// 	if (!*sta)
// 		return ;
// 	while (1)
// 	{
// 		if ((*sta)->data <= min)
// 		{
// 			pb(sta, stb);
// 			rb(stb);
// 			return ;
// 		}
// 		else if (*sta && (*sta)->data <= max)
// 		{
// 			pb(sta, stb);
// 			if (b_size > 1 && (*stb)->data < (*stb)->next->data)
// 				sb(stb);
// 			return ;
// 		}
// 		ra(sta);
// 	}
// }

// void	chunks_sorting(t_stack **sta, t_stack **stb)
// {
// 	int	*arr;

// 	int (min), (max), (size), (holder);
// 	size = ft_lstsize(*sta);
// 	arr = sorted_array(*sta, size);
// 	holder = size;
// 	if (size > 100)
// 		max = size / 13;
// 	else
// 		max = size / 6;
// 	min = 0;
// 	while (holder > 0)
// 	{
// 		push_to_stb(sta, stb, arr[min], arr[max]);
// 		if (min < max)
// 			min++;
// 		if (max < size - 1)
// 			max++;
// 		holder--;
// 	}
// 	t_stack *tmp = *sta;
// 	printf("----\n");
// 	while(tmp)
// 	{
// 		printf("%d\n", tmp->data);
// 		tmp = tmp->next;
// 	}
// 	printf("----\n");
// 	tmp = *stb;
// 	while(tmp)
// 	{
// 		printf("%d\n", tmp->data);
// 		tmp = tmp->next;
// 	}
// 	printf("----\n");
// 	push_back_sta(sta, stb);
// 	free(arr);
// }

void	sorting(t_stack *a, t_stack *b, int size)
{
	int	chunk;

	if (size >= 100)
		chunk = size / 13;
	else
		chunk = size / 6;
	if (size == 2)
	{
		if (a->data > a->next->data)
			sa(&a);
	}
	else if (size == 3)
		sort_3(a);
	else if (size < 10)
		sort_small(&a, &b);
	else
		sort_big(&a, &b, size, chunk);
		// chunks_sorting(&a, &b);
}