/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findMedian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:23:35 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/24 22:05:21 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper function to extract elements of the same chunk into an array
void	extract_chunk_elements(t_list *list, int chunk, int *arr)
{
	int	index;
	
	index = 0;
	while (list)
	{
		if (list->chunk == chunk)
			arr[index++] = list->content;
		list = list->next;
	}
}

// Partition function for Quickselect
int	partition(int arr[], int left, int right, int pivot)
{
	int	pivot_value;
	int	temp;
	int	store_index;
	int	i;

	pivot_value= arr[pivot];
	temp = arr[pivot];
	arr[pivot] = arr[right];
	arr[right] = temp;
	store_index = left;
	i = left;
	while (i < right)
	{
		if (arr[i] < pivot_value)
		{
			temp = arr[i];
			arr[i] = arr[store_index];
			arr[store_index] = temp;
			store_index++;
		}
		i++;
	}
	temp = arr[store_index];
	arr[store_index] = arr[right];
	arr[right] = temp;
	return (store_index);
}

// Quickselect function
int	quickselect(int arr[], int left, int right, int k)
{
	int	pivot_index;

	if (left == right)
		return arr[left];
	pivot_index = left + rand() % (right - left + 1);
	if (pivot_index < left || pivot_index > right)
		exit(EXIT_FAILURE);
	pivot_index = partition(arr, left, right, pivot_index);
	if (k == pivot_index)
		return (arr[k]);
	else if (k < pivot_index)
		return quickselect(arr, left, pivot_index - 1, k);
	else
		return quickselect(arr, pivot_index + 1, right, k);
}

// Find the median of elements with the same chunk
int	findMedian(t_list *list, int chunk) 
{
	int	median;
	int	n;
	int	*arr;
	int	mid1;
	int	mid2;

	if (!list)
		return (-1);
	n = ft_chunksize(list, chunk);
	if (n <= 0)
		return (-1);
	arr = (int *)malloc(n * sizeof(int));
	extract_chunk_elements(list, chunk, arr);
	if (n % 2 == 1)
		median = quickselect(arr, 0, n - 1, n / 2);
	else
	{
		mid1 = quickselect(arr, 0, n - 1, n / 2 - 1);
		mid2 = quickselect(arr, 0, n - 1, n / 2);
		median = (mid1 + mid2) / 2;
	}
	ft_printf("findmedian: %d\n", median);
	return (free(arr), median);
}
