/*
 * quicksort.c
 *
 *  Created on: Sep 28, 2016
 *      Author: hp
 */

#include <stdio.h>
#include <stdlib.h>

void quick_sort(unsigned int left, unsigned int right){
	unsigned int i, mid;
	int pivot;

	if (left >= right)
	  return; /*nothing to sort*/
	/*pivot is midpoint; move to left side*/
	swap(arr+left, arr + (left+right)/2);
	  pivot = arr[mid = left];
	  /*separate into side < pivot (left + 1 to mid) and side
	   * and side >= pivot (mid+1 to right)
	   */
	for (i = left + 1; i <= right; i++)
		if (arr[i] < pivot)
		   swap(arr + ++mid, arr + i);

	/*Restoring Pivot; sort the sides separately*/
	swap(arr+left, arr+mid);

	/*Sorts two sides*/
	if (mid > left)
		quick_sort(left, mid - 1);
	if (mid < right)
		quick_sort(mid+1, right);
}

